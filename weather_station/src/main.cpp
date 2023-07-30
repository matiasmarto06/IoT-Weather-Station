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
#include "Ota.h"

#define MAX_RECORDINGS 		30*24
#define RECORD_FRECUENCY_MS 1000UL*60*60

FileMeasurements f("/test", MAX_RECORDINGS, RECORD_FRECUENCY_MS);
Measurement m(D4, DHT22);
Connection 	c(90);
WiFiManager wm;
Ota ota;

void setup (void)
{
	Serial.begin(115200);

	wm.autoConnect("ESP8266 Wemos D1 mini");
	ota.setup();

	m.begin();
	c.begin();
	f.begin();
	ota.begin();
}

void loop (void)
{
	int response = false;

	ota.handle();
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

		case RESPONSE_DELETE_FILE:
			f.remove();
			f.begin();
			f.record(m.toString());
			break;

		default:
			break;
		}
	}

	f.record(m.toString());
	f.update(120000UL);
}