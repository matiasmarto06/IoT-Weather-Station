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

#include "Measurement.h"
#include "Connection.h"
#include "FileMeasurements.h"

#define MAX_RECORDINGS 30*24
#define RECORD_FRECUENCY_MS 1000UL*60*60

FileMeasurements f("/test", MAX_RECORDINGS, RECORD_FRECUENCY_MS);
Measurement m(D4, DHT22);
Connection 	c(90);

void setup (void)
{
	WiFiManager wm;

	pinMode(D4, INPUT);

	Serial.begin(115200);

	wm.autoConnect("Wemos D1 mini");

	m.begin();
	
	c.begin();
	
	//f.remove();
	f.begin();
}

void loop (void)
{
	bool download_request = false;

	m.update(1000UL);
	
	download_request = c.update();
	
	if (!download_request) 
	{
		c.send(m.toString(), 2000UL);
	}

	else 
	{
		c.send(f.readAll());
		c.setDownloadRequest(false);
	}

	f.record(m.toString());
	f.update(120000UL);
}