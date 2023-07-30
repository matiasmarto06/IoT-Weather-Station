#include "Ota.h"

void Ota::begin (void)
{
    if ((WiFi.status() == WL_CONNECTED))
	{
	    ArduinoOTA.begin();
	}
    else DEBUG_OTA("Failed to connect");
}

void Ota::setup (void)
{
    ArduinoOTA.onStart([this]() {		
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
		DEBUG_OTA("Start updating " + type);
	});

  	ArduinoOTA.onEnd([this]() 
	{
    	DEBUG_OTA("End");
  	});
  
  	ArduinoOTA.onProgress([this](unsigned int progress, unsigned int total) 
	{
    	Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  	});

	ArduinoOTA.onError([this](ota_error_t error) 
	{
		DEBUG_OTA("Error [" + String(error) + "]: ");
		
        switch (error)
        {
        case OTA_AUTH_ERROR:
            DEBUG_OTA("Auth Failed");
            break;
        
        case OTA_BEGIN_ERROR:
            DEBUG_OTA("Begin Failed");
            break;

        case OTA_CONNECT_ERROR:
            DEBUG_OTA("Connect Failed");
            break;

        case OTA_RECEIVE_ERROR:
            DEBUG_OTA("Receive Failed");
            break;
        
        case OTA_END_ERROR:
            DEBUG_OTA("End Failed");
            break;
        
        default:
            break;
        }
	});
}

void Ota::handle(void)
{
    ArduinoOTA.handle();
}

void Ota::setDebug(bool debug)
{
	debug_ = debug;
}

template <typename Generic>
void Ota::DEBUG_OTA(Generic text) {
  if (debug_) {
    Serial.print("*OTA: ");
    Serial.println(text);
  }
}

Ota::Ota(/* args */)
{
    ;
}

Ota::~Ota()
{
    ;
}