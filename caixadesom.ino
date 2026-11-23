\\programaçao LED
#include <VARSTEP_ultrasonic.h>

#define trigger_pin 13
#define echo_pin 12

VARSTEP_ultrasonic my_HCSR04(trigger_pin, echo_pin);

int vermelho = 9;
int verde = 10;
int azul = 11;

double distance_cm;

void setup() {
  Serial.begin(9600);

  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop() {
  distance_cm = my_HCSR04.distance_cm();

  Serial.print("Distancia: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  if (distance_cm < 10 && distance_cm != -1) {

    // Azul ligado
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(azul, HIGH);

  } else {

    // LED desligado
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(azul, LOW);
  }

  delay(500);
}


