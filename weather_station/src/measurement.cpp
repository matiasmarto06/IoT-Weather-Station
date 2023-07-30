#include "Measurement.h"

Measurement::Measurement(int pin, int type) : dht_(pin, type), timeClient_(ntpUDP_), ph_(A0)
{
    pinMode(D4, INPUT);
}

Measurement::Measurement (void) : dht_(D4, DHT22), timeClient_(ntpUDP_), ph_(A0)
{
    ;
}

void Measurement::set (float t, float h, Date timeStamp)
{
    t_ = t;
    h_ = h;
    timestamp_ = timeStamp;
}

void Measurement::update(unsigned long delay = 1000UL)
{
    if ((timer_ + delay) < millis())
    {    
        h_ = dht_.readHumidity();
        t_ = dht_.readTemperature();
        l_ = ph_.readLightness();

        timeClient_.update();

        time_t epochTime = timeClient_.getEpochTime();
        struct tm *ptm =  gmtime((time_t*) &epochTime);

        timestamp_.setDate(ptm->tm_mday, ptm->tm_mon+1, ptm->tm_year+1900, timeClient_.getHours(), timeClient_.getMinutes(), timeClient_.getSeconds());
        
        timer_ = millis();
    }
}

Measurement::~Measurement()
{
    timeClient_.end();
}

void Measurement::begin(void)
{
    dht_.begin();

    timeClient_.begin();
	timeClient_.setTimeOffset(UTC_3);
}

String Measurement::toString(void)
{
    const size_t bufferSize = snprintf(nullptr, 0, "%s;%.1f;%.1f;%.1f", timestamp_.getFormattedDateTime().c_str(), t_, h_, l_) + 1;
    char *buffer = new char [bufferSize];

    snprintf(buffer, bufferSize, "%s;%.1f;%.1f;%.1f", timestamp_.getFormattedDateTime().c_str(), t_, h_, l_);
    
    String result(buffer);
    
    delete[] buffer;

    return result;
}

template <typename Generic>
void Measurement::DEBUG_M(Generic text) {
  if (_debug) {
    Serial.print("*M: ");
    Serial.println(text);
  }
}

void Measurement::setDebugOutput(boolean debug) {
  _debug = debug;
}