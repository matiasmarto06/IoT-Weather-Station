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

void Connection::update (void)
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

	if(client_.available() > 0)
	{
		const char msg = client_.read();
		message_.concat(msg);
		
		if (client_.available() == 0)
		{
			DEBUG_C(message_);
			message_.clear();
		}		
	}
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
			message_.clear();
		}		
	}
}

void Connection::send (String m)
{
    if (client_.connected())
	{
		if ((timerDHT_ + 2000UL) < millis())
		{
			client_.print(m);
			timerDHT_ = millis();
		}
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