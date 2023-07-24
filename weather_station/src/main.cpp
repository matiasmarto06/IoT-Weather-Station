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
#include <WiFiManager.h>
#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>

#include "Measurement.h"
#include "Connection.h"
#include "FileMeasurements.h"

#define MAX_RECORDINGS 		30*24
#define RECORD_FRECUENCY_MS 1000UL*60*60

FileMeasurements f("/test", MAX_RECORDINGS, RECORD_FRECUENCY_MS);
Measurement m(D4, DHT22);
Connection 	c(90);
WiFiManager wm;

void setupArduinoOTA (void)
{
	ArduinoOTA.onStart([]() {
		
		String type;
		
		if (ArduinoOTA.getCommand() == U_FLASH) 
		{
			type = "sketch";
		} 
		
		else 
		{ // U_FS
			type = "filesystem";
    	}
		// NOTE: if updating FS this would be the place to unmount FS using FS.end()
		Serial.println("Start updating " + type);
	});

  	ArduinoOTA.onEnd([]() 
	{
    	Serial.println("\nEnd");
  	});
  
  	ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) 
	{
    	Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  	});
	ArduinoOTA.onError([](ota_error_t error) 
	{
		Serial.printf("Error[%u]: ", error);
		
		if (error == OTA_AUTH_ERROR) 
		{
			Serial.println("Auth Failed");
		} 
		
		else if (error == OTA_BEGIN_ERROR) 
		{
			Serial.println("Begin Failed");
		} 
		
		else if (error == OTA_CONNECT_ERROR) 
		{
			Serial.println("Connect Failed");
		} 
		
		else if (error == OTA_RECEIVE_ERROR) 
		{
			Serial.println("Receive Failed");
		} 
		
		else if (error == OTA_END_ERROR) 
		{
			Serial.println("End Failed");
		}
	});
}

void setup (void)
{
	setupArduinoOTA();

	pinMode(D4, INPUT);

	Serial.begin(115200);

	wm.autoConnect("ESP8266 Wemos D1 mini");
		
	m.begin();
	
	c.begin();

	f.begin();

	if ((WiFi.status() == WL_CONNECTED))
	{
	//	ElegantOTA.begin(&s);	
	//	s.begin();
		ArduinoOTA.begin();
	}
}

void loop (void)
{
	int response = false;

	//s.handleClient();
	ArduinoOTA.handle();
	
	m.update(1000UL);
	
	response = c.update();
	
	if (response == 0) 
	{
		c.send(m.toString(), 2000UL);
	}

	else 
	{
		switch (response)
		{
		case RESPONSE_DOWNLOAD:
			c.send(f.readAll());
			break;
		
		case RESPONSE_RESET_WIFI:
			wm.resetSettings();
			ESP.eraseConfig(); 
			delay(2000);
			ESP.reset();
			break;

		default:
			break;
		}
		
	}

	c.resetResponse();
	f.record(m.toString());
	f.update(120000UL);
}