/**
 * @file main.cpp
 * @author Matias I. Martorano (matias.martorano@alumnos.frgp.utn.edu.ar)
 * @brief 
 * @version 0.1
 * @date 2023-04-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <Arduino.h>
#include <LittleFS.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const char *data = "/data";

DHT dht(D4, DHT22);

WiFiServer server(90);
WiFiClient client;
String message;
File file;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

bool connected = false;

void setup (void)
{
	WiFiManager wm;

	pinMode(D4, INPUT);

	Serial.begin(115200);
	dht.begin();

	wm.autoConnect("Wemos D1 mini");

	timeClient.begin();
	timeClient.setTimeOffset(-10800);

	server.begin();

	LittleFS.begin();
	
	LittleFS.remove(data);
	Serial.println(F("*LittleFS: deleting file..."));
	
	if (!LittleFS.exists(data))
	{
		Serial.println(F("*LittleFS: file does not exist creating..."));

		file = LittleFS.open(data, "w");
		if (!file)
		{
			Serial.println(F("*LittleFS: <ERROR file creation error>"));
			LittleFS.end();
			return;
		}
		
		auto bytesWritten = file.write("This is the saved data!");
		if (!bytesWritten)
		{
			Serial.println(F("*LittleFS: <ERROR writting failed>"));
		}
		Serial.printf("*LittleFS: %d bytes written...\n", bytesWritten);
		
		file.close();
	}
	
	else
	{
		Serial.println(F("*LittleFS: file already exists..."));
	}

	LittleFS.end();
}

uint32_t timerTCP = 0;
uint32_t timerFile = 0;
uint32_t timerDHT = 0;

void loop (void)
{	
	float t, h;

	if ((client.connected() == false) && ((timerTCP + 10000UL) < millis()))
	{
		Serial.println(F("*Server: client disconnected..."));
		timerTCP = millis();
	}

	if (!client)
	{
		client = server.available();
		if (client.connected())
		{
			Serial.println(F("*Server: client connected..."));
		}
	}

	if(client.available() > 0)
	{
		const char msg = client.read();
		message.concat(msg);
		if (client.available() == 0)
		{
			client.println(message);
			message.clear();
		}		
	}

	t = dht.readTemperature(false, false);
	h = dht.readHumidity(false);
	
	if (client.connected())
	{
		if ((timerDHT + 2000UL) < millis())
		{
			timeClient.update();
					
			time_t epochTime = timeClient.getEpochTime();
			struct tm *ptm =  gmtime((time_t*) &epochTime); 
			
			String currentDate = String(ptm->tm_mday) + "/" + String(ptm->tm_mon+1) + "/" + String(ptm->tm_year + 1900);
			
			client.printf("%s %s - t%0.01f;h%0.01f;\n", currentDate.c_str(), timeClient.getFormattedTime().c_str(), t, h);

			timerDHT = millis();
		}	
	}
}
