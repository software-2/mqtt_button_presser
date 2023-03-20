# mqtt_button_presser
Press a physical button using a NodeMCU and servo, over MQTT.

## MQTT Commands
### Subscriptions
- `blinds/open` *(no payload)* - Presses the button, waits some time, then presses the button again to halt the opening. This is because my blinds are dumb, and if you let them open all the way, they become see-through.
- `blinds/close` *(no payload)* - Presses the button once. This will retract the blinds if they're open at all, otherwise, it will fully open the blinds.
### Publishes
- blinds/received - Sent on receipt of the subscription. Useful for debugging.

## Parts
- NodeMCU - https://www.aliexpress.us/item/2251832152888289.html
- Micro Servo - https://www.amazon.com/gp/product/B072V529YD
- Project case - https://www.amazon.com/gp/product/B0725RDKDL/ (I bought a few of these before I had a 3d printer.)

## Assembly
Just plug the servo directly into the three adjacent pins. Super simple!
- Orange to D4
- Red to 3.3v
- Brown to Ground

## Reference Docs
- https://docs.arduino.cc/learn/electronics/servo-motors
- https://github.com/plapointe6/EspMQTTClient


