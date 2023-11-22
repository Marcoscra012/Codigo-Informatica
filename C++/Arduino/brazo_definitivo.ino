//Codigo para un brazo robótico que hicimos un amigo y yo en 4º ESO para el final de la asignatura de Tecnología, aunque tambien lo presentamos para la Feria de la Ciencia de ese año
//El brazo funciona con 2 joysticks que controlan 2 servomotores para mover el brazo y doblarlo

#include <AsyncStepper.hpp>
#include <Servo.h>

#define base A0
#define brazo1 A1
#define brazo2 A2

Servo Sbrazo1;
Servo Sbrazo2;

const int dir = 8;
const int stepp = 9;
int pos1 = 0;
int pos2 = 0;

AsyncStepper stepper1(200 , dir , stepp); //se configura la lib, el primer numero son las revoluciones por min

void setup() {
  Serial.begin(9600);
  //Joystick
  pinMode(base, INPUT); 
  pinMode(brazo1, INPUT);
  pinMode(brazo2, INPUT);

  //Stepper
  stepper1.SetSpeedDegreesBySecond(10);
  stepper1.SetAcceleration(50, 50);

  //Servos
  Sbrazo1.attach(9);
  Sbrazo2.attach(10);
}

void loop() {
  if (analogRead(base) > 530) { //joystick base derecha
    if (stepper1.GetCurrentAngle() > 239){ //si ha alcanzado el tope
      stepper1.Stop();
    }
    else{
      stepper1.RotateContinuous(AsyncStepper::CW); //establecemos que rote en la direccion de las agujas del reloj
      stepper1.Update(); //hacemos que rote
      if(stepper1.GetCurrentAngle() > 239){ //comprueba que no nos hemos pasado del limite (creo que se podria quitar)
        stepper1.Stop();
      }
    }
  }
  else if(analogRead(base) < 490) { //joystick base izquierda
    if (stepper1.GetCurrentAngle() > -239){ //si ha alcanzado el tope
      stepper1.Stop();
    }
    else{
      stepper1.RotateContinuous(AsyncStepper::CCW); //establecemos que rote en la direccion contraria a las agujas del reloj
      stepper1.Update(); //hacemos que rote
      if(stepper1.GetCurrentAngle() > -239){ //comprueba que no nos hemos pasado del limite (creo que se podria quitar)
        stepper1.Stop();
      }
    }
  }
  delay(10);
  while (analogRead(brazo1) > 530) { //joystick brazo 1 arriba
    Sbrazo1.write(pos1);
    if (pos1 == 180){ 
    }
    else {
      pos1++;
    }
    delay(25);
  }
  while (analogRead(brazo1) < 490) { //joystick brazo 1 abajo
    Sbrazo1.write(pos1);
    if (pos1 == 0){ 
    }
    else {
      pos1--;
    }
    delay(25);
  }
  delay(10);
  while (analogRead(brazo2) > 530) { //joystick brazo 2 arriba
    Sbrazo2.write(pos2);
    if (pos2 == 180){ 
    }
    else {
      pos2++;
    }
    delay(25);
  }
  while (analogRead(brazo2) < 490) { //joystick brazo 2 abajo
    Sbrazo2.write(pos2);
    if (pos2 == 0){ 
    }
    else {
      pos2--;
    }
    delay(25);
  }
}
