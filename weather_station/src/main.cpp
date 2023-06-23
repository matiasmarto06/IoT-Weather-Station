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

uint32_t timer = 0;
int i = 0;

void loop (void)
{	
	
	m.update(1000UL);
	
	c.update();
	c.send(m.toString());
	
	f.record(m.toString());
	f.update(120000UL);
}