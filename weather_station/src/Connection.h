#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>

class Connection
{
private:
    WiFiServer  server_;
    WiFiClient  client_;
    bool        connected_  = false;
    uint32_t    timerTCP_   = 0;
    uint32_t    timerDHT_   = 0;
    String      message_;
    bool        debug_      = true;
    template    <typename Generic>
    void        DEBUG_C    (Generic);    


public:
            Connection      (int port);
            ~Connection     ();
    void    setDebug        (bool);
    void    begin           (void);
    void    update          (void);
    void    send            (String);
    void    recieve         (void);
};

#endif // CONNECTION_H_