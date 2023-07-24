#include "Connection.h"

Connection::Connection(int port) : server_(port)
{
    ;
}

Connection::~Connection(void)
{
    server_.close();
}

void Connection::begin(void)
{
    server_.begin();
}

int Connection::update (void)
{    
	if ((client_.connected() == false) && ((timerTCP_ + 10000UL) < millis()))
	{
		DEBUG_C(F("client disconnected..."));
		timerTCP_ = millis();
	}

	if (!client_)
	{
		client_ = server_.available();
		if (client_.connected())
		{
			DEBUG_C(F("client connected..."));
		}
	}

	recieve();
	
	return response_;
}


void Connection::recieve (void)
{
	if(client_.available() > 0)
	{
		const char msg = client_.read();
		message_.concat(msg);
		
		if (client_.available() == 0)
		{
			DEBUG_C(message_);

			if (!strcmp(message_.c_str(), "download request"))
			{
				//DEBUG_C("download requested...");
				response_ = RESPONSE_DOWNLOAD;
			}
			else if (!strcmp(message_.c_str(), "reset wifi request"))
			{
				//DEBUG_C("reset wifi requested...");
				response_ = RESPONSE_RESET_WIFI;
			}

			message_.clear();
		}
	}
}

void Connection::resetResponse (void)
{
	response_ = 0;
}

void Connection::send (String m, unsigned long delay_)
{
    if (client_.connected())
	{
		if ((timerDHT_ + delay_) < millis())
		{
			client_.print(m);
			timerDHT_ = millis();
		}
	}
}

void Connection::send (String m)
{
    if (client_.connected())
	{
		DEBUG_C("downloading...");
		client_.print(m);
	}
}

void Connection::setDebug (bool debug)
{
	debug_ = debug;
}

template <typename Generic>
void Connection::DEBUG_C(Generic text) {
  if (debug_) {
    Serial.print("*Connection: ");
    Serial.println(text);
  }
}