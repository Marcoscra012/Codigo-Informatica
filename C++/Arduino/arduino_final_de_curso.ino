#include <LiquidCrystal.h>
#define pinHorizontal A0
#define pinVertical A1
#define pinSeleccion 11
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

//variables
int pos = 0;
String colores[] = {"Rojo", "Azul", "Verde", "Amarillo", "Morado", "Blanco"};

void setup() {
  //led 10 = R,  9 = G,  8 = B
  pinMode(10 , OUTPUT); //R
  pinMode(9 , OUTPUT); //G
  pinMode(6 , OUTPUT); //B
  
  //joystick
  pinMode(pinHorizontal , INPUT);
  pinMode(pinVertical , INPUT);
  pinMode(pinSeleccion , INPUT_PULLUP);

  //lcd
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  //joystick
  int horizontal = analogRead(pinHorizontal);
  int vertical = analogRead(pinVertical);
  bool seleccion = digitalRead(pinSeleccion) == LOW;
 
  if (horizontal < 512) {
    pos++;
    if (pos > 5) {
    pos = 0;
  } 
    
  }
  if (horizontal > 512) {
    pos--;
    if (pos < 0) {
      pos = 5;
    }
  }

  //led
  int led = pos;
  if (seleccion == HIGH) {
    if (led == 0) {
      analogWrite(10 , 0);
      analogWrite(9 , 255);
      analogWrite(6 , 255);
    }
    else if (led == 1) {
      analogWrite(10 , 255);
      analogWrite(9 , 255);
      analogWrite(6 , 0);
    }
    else if (led == 2) {
      analogWrite(10 , 255);
      analogWrite(9 , 0);
      analogWrite(6 , 255);
    }
    else if (led == 3) {
      analogWrite(10 , 0);
      analogWrite(9 , 0);
      analogWrite(6 , 255);
    }
    else if (led == 4) {
      analogWrite(10 , 0);
      analogWrite(9 , 255);
      analogWrite(6 , 0);
    }
    else if (led == 5) {
      analogWrite(10 , 0);
      analogWrite(9 , 0);
      analogWrite(6 , 0);
    }
  }

  //lcd
  String color = colores[pos];
  lcd.clear();
  lcd.setCursor(5 , 0);
  lcd.print("Color:");
  if (pos == 0) {
    lcd.setCursor(6,  1);
  }
  else if (pos == 1) {
    lcd.setCursor(6, 1);
  }
  else if (pos == 2) {
    lcd.setCursor(5, 1);
  }
  else if (pos == 3) {
    lcd.setCursor(4,  1);
  }
  else if (pos == 4) {
    lcd.setCursor(5, 1);
  }
  else if (pos == 5) {
    lcd.setCursor(5, 1);
  }
  lcd.print(color);
  delay(600);
}