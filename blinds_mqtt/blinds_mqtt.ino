#include <Arduino.h>
#include <Servo.h>
#include "EspMQTTClient.h"

int servoAngle = 90;

EspMQTTClient client(
  "",  //wifi ssid
  "",  //wifi password
  "",  // MQTT Broker server ip
  "",   // MQTTUsername
  "",   // MQTTPassword
  "",      // Client name
   // MQTT port
);

Servo servo;
int servoPos = 0;

void press()
{
  servo.attach(D4);
    for (servoPos = 0; servoPos <= servoAngle; servoPos += 1)
    {
        servo.write(servoPos);
        delay(15);
    }
    for (servoPos = servoAngle; servoPos >= 0; servoPos -= 1)
    {
        servo.write(servoPos);
        delay(15);
    }
  servo.detach();
}

void onConnectionEstablished() {
    client.subscribe("blinds/open", [] (const String &payload)  {
        client.publish("blinds/received", "Device received the open message.");
        press();
        delay(9000);
        press();
    });

    client.subscribe("blinds/close", [] (const String &payload)  {
        client.publish("blinds/received", "Device received the close message.");
        press();
    });
}

void setup()
{
    
}

void loop()
{
    client.loop();
}
