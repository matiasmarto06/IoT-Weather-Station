#include "FileMeasurements.h"

FileMeasurements::FileMeasurements (const char *dir , int max, uint32_t frecuency)
{
	dir_ = dir;
	max_ = max;
	frecuency_ = frecuency;
}

FileMeasurements::~FileMeasurements()
{
	file_.close();
	LittleFS.end();
}

void FileMeasurements::record (String m)
{
	if ((timer_ + frecuency_) < millis())
    {
		println(m + '\n', max_);
		timer_ = millis();
	}
}

size_t FileMeasurements::size(void)
{
	return file_.size();
}

void FileMeasurements::update (uint32_t delay)
{
	file_ = LittleFS.open(dir_, "r");
	if (!file_)
	{
		DEBUG_FS(F("<ERROR file opening error>"));
		return;
	}

	if ((timerUpdate_ + delay) < millis())
    {
		DEBUG_FS(F("file size: "));
		DEBUG_FS(size());
		DEBUG_FS(F("record count: "));
		DEBUG_FS(count());
//		DEBUG_FS(F("current position: "));
//		DEBUG_FS(pos_);
		DEBUG_FS(F("last record:"));
		DEBUG_FS(read(pos_-1));
		DEBUG_FS(F("time to next record:"));
		DEBUG_FS(((frecuency_ - (millis()-timer_))/1000UL));
//		DEBUG_FS(F("record size: "));
//		DEBUG_FS(sizeof_());
		timerUpdate_ = millis();
	}

	file_.close();
}

String FileMeasurements::read (uint32_t pos)
{
	int32_t offset = (pos-1)*(uint32_t)sizeof_();
	file_.seek(offset, SeekSet);
	return file_.readStringUntil('\n');
}

String FileMeasurements::readAll (void)
{
	file_ = LittleFS.open(dir_, "r");
	if (!file_)
	{
		DEBUG_FS(F("<ERROR file opening error>"));
		return String("<ERROR file opening error>");
	}

	String res = file_.readString();
	//DEBUG_FS(res);
	file_.close();

	return res;
}

int FileMeasurements::sizeof_(void)
{
	if (pos_ == 0) 
		{ return 0; }
	else 
		{ return file_.readStringUntil('\n').length() + 1; }

	return 0;
}

int FileMeasurements::count (void)
{
	return (file_.size() / (file_.readStringUntil('\n').length() + 1));
}

void FileMeasurements::begin (void)
{
    LittleFS.begin();
	
	if (!LittleFS.exists(dir_))
	{
		DEBUG_FS(F("file does not exist creating..."));
		
		file_ = LittleFS.open(dir_, "w");
		if (!file_)
		{
			DEBUG_FS(F("<ERROR file creation error>"));
			LittleFS.end();
			return;
		}
		DEBUG_FS(F("success..."));
		file_.close();
	}
	else
	{
		file_ = LittleFS.open(dir_, "r");
		DEBUG_FS(F("file already exists..."));
		pos_ = count() % max_;
		file_.close();
	}
}

size_t FileMeasurements::println (String w, int max)
{
	file_ = LittleFS.open(dir_, "r+");
	if (!file_)
	{
		DEBUG_FS(F("<ERROR file opening error>"));
		return 0;
	}

	int32_t offset = (uint32_t)pos_*(uint32_t)sizeof_();
	file_.seek(offset, SeekSet);

	pos_ = (pos_ + 1) % max;
	size_t bytes = file_.write(w.c_str());
	file_.close();

	return bytes;
}

size_t FileMeasurements::append (String w)
{
	file_ = LittleFS.open(dir_, "a");
	if (!file_)
	{
		DEBUG_FS(F("<ERROR file opening error>"));
		return 0;
	}

	size_t bytes = file_.write(w.c_str());
	file_.close();

	return bytes;
}

void FileMeasurements::end(void)
{
	file_.close();
    LittleFS.end();
}

bool FileMeasurements::exists (void)
{
	return LittleFS.exists(dir_);
}

void FileMeasurements::remove (void)
{
	LittleFS.begin();
	DEBUG_FS(F("deleting file..."));
	LittleFS.remove(dir_);
	LittleFS.end();
}

void FileMeasurements::setDebug (bool debug)
{
	debug_ = debug;
}

template <typename Generic>
void FileMeasurements::DEBUG_FS(Generic text) {
  if (debug_) {
    Serial.print("*LittleFS: ");
    Serial.println(text);
  }
}