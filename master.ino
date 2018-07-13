// based on https://gist.github.com/yaqwsx/ac662c9b600ef39a802da0be1b25d32d
// 2018.07.14 jnogues@gmail.com
// This sketch shows the use of 802.11 LR (Low Rate)
// master.ino

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <esp_wifi.h>

const char* ssid = "kkkkk";//AP ssid
const char* password = "12345678";//AP password
const char* ssidRouter = "MySSID";//STA router ssid
const char* passwordRouter = "MyPASSWORD";//STA router password
WiFiUDP udp;

void setup() {
    pinMode(5, OUTPUT);//builtin Led, for debug
    digitalWrite(5, HIGH);
    Serial.begin( 115200 );
    Serial.println( "Master" );

    //first, we start STA mode and connect to router
    WiFi.mode( WIFI_AP_STA );
    WiFi.begin(ssidRouter,passwordRouter); 
    
    //Wifi connection
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }

    Serial.println("Router WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  
    //second, we start AP mode with LR protocol
    //This AP ssid is not visible whith our regular devices
    WiFi.mode( WIFI_AP );//for AP mode
    //here config LR mode
    int a= esp_wifi_set_protocol( WIFI_IF_AP, WIFI_PROTOCOL_LR );
    Serial.println(a);
    WiFi.softAP(ssid, password);
    Serial.println( WiFi.softAPIP() );
    Serial.println("#");//for debug
    delay( 1000 );
    digitalWrite(5, LOW); 
    udp.begin( 8888 );
}

void loop() 
{
    udp.beginPacket( { 192, 168, 4, 255 }, 8888 );//send a broadcast message
    udp.write( 'b' );//the payload
    digitalWrite(5, !digitalRead(5));
    
    if ( !udp.endPacket() ){
        Serial.println("NOT SEND!");
        delay(100);
        ESP.restart(); // When the connection is bad, the TCP stack refuses to work
    }
    else{
          Serial.println("SEND IT!!"); 
    }     
    
    delay( 1000 );//wait a second for the next message
}


