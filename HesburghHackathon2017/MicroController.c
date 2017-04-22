/*
web_client_test.ino
Language: C, Compiled in Arduino IDE-- file name 
must end in either .pde or .ino

Taylor Hernandez, Zac Cendejas, Tommy Lynch
University of Notre Dame

Written for Hackathon 2017
Last Modified: April 02, 2017

Notes: More buttons can be added, need separate function
for connecting to wifi, and need to put in loop so that the 
connection does not time out.
 */

#include <ESP8266WiFi.h>

const char* ssid = "ND-guest";
const char* host = "dweet.io";
const int buttonPin = D2;     
const int ledPin =  D1;  

int buttonState = 0;
int flag=0;

void setup() 
{
  Serial.begin(115200);
  delay(100);

  //Connect to pins on ESP
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT_PULLUP);  

  //Connect to a wifi Network, can make private if
  //Argument for password is included
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid);
  
    while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;
void loop() 
{
  checkButton();
  delay(500);
  ++value;
  //Program will crash without this component
  ESP.wdtFeed();
}

void checkButton(void) 
{

// WiFiClient class has been created. Use create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if ( !client.connect(host, httpPort)) 
  {
    Serial.println("connection failed");
    return;
  }
  
  Serial.print("connecting to ");
  Serial.println(host);

  while (client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
  
  // Read button State
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) 
  { 
    if ( flag == 0)
    {
      digitalWrite(ledPin,HIGH);
      flag=1; 
        // We now create a URI for the request
      String url = "/dweet/for/openSeat288?table=taken";
      Serial.print("Requesting URL: ");
      Serial.println(url);
      client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
      
    }
    // Button is pressed for the second time
    else if ( flag == 1)
    {
      digitalWrite(ledPin, LOW);
      flag=0; //change flag variable again
      String url = "/dweet/for/openSeat288?table=open";
      Serial.print("Requesting URL: ");
      Serial.println(url);
      client.print(String("GET ") + url + " HTTP/1.1\r\n" +
              "Host: " + host + "\r\n" + 
              "Connection: close\r\n\r\n"); 
    }    
  }
  
}
