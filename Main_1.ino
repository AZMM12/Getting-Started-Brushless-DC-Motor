#include <Servo.h>

Servo ESC;  // create servo object to control ESC

int Sensor; // variable to save the value recieved from analog pin

void setup()
{
  pinMode(A0, INPUT); //set A0 pin as input from potentiometer
  ESC.attach(9, 1000, 2000); //(pin, min pulse width in miliseconds , max pulse width in milliseconds)
}

void loop()
{
  Sensor = analogRead(A0); // read value from potentiometer
  Sensor = map(Sensor, 0, 1023, 0, 180); // scale the potentiometer vale into motor acceptable value
  ESC.write(Sensor); // Send signal to ESC
  delay(10); // Delay a little bit to improve simulation performance
}