//Codigo para un uascensor que hicimos entre 3 en la asignatura de Tecnología en 4º ESO

const int subir = 7;
const int bajar = 8;
int piso = 1;
const int piso1 = 2; //boton planta 1
const int piso2 = 3; //boton planta 2
const int piso3 = 4; //boton planta 3
const int tiempo1 = 1000; //tiempo para 1 planta
const int tiempo2 = 2000; //tiempo para 2 plantas

void setup() {
pinMode(subir, OUTPUT);
pinMode(bajar, OUTPUT);
pinMode(2, INPUT);
pinMode(3, INPUT);
pinMode(4, INPUT);
pinMode(9, OUTPUT);
}

void loop() {
  if(digitalRead(piso1) == HIGH){ //boton piso 1 pulsado
    if(piso == 2){ //estamos en el piso 2
      digitalWrite(bajar, HIGH);
      delay(tiempo1);
      digitalWrite(bajar, LOW);
    }
    else if(piso == 3){ //estamos en el piso 3
      digitalWrite(bajar, HIGH);
      delay(tiempo2);
      digitalWrite(bajar, LOW);
    }
    piso = 1;
  }
  else if(digitalRead(piso2) == HIGH){ //boton piso 2 pulsado
    if (piso == 1){ //estamos en el piso 1
      digitalWrite(subir, HIGH);
      delay(tiempo1);
      digitalWrite(subir, LOW);
    }
    else if (piso == 3){ //estamos en el piso 3
      digitalWrite(bajar, HIGH);
      delay(tiempo2);
      digitalWrite(bajar, LOW);
    }
    piso = 2;
  }
  else if(digitalRead(piso3) == HIGH){ //boton piso 3 pulsado
    if(piso == 1){ // estamos en el piso 1
      digitalWrite(subir, HIGH);
      delay(tiempo2);
      digitalWrite(subir, LOW);
    }
    else if(piso == 2){ //estamos en el piso 2
      digitalWrite(subir, HIGH);
      delay(tiempo1);
      digitalWrite(subir, LOW);
    }
    piso = 3;
  }
}
