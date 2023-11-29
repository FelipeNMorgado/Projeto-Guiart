#include <SoftwareSerial.h>

// Codigo de Sensor de LED-RGB
const int PINO_SENSOR_S0 = 8;
const int PINO_SENSOR_S1 = 9;
const int PINO_SENSOR_S2 = 11;
const int PINO_SENSOR_S3 = 12;
const int PINO_SENSOR_OUT = 10;

const int PINO_LED_VERMELHO = 2;
const int PINO_LED_VERDE = 3;
const int PINO_LED_AZUL = 4;

String cmd = "";
float sensor_val = 0;

int vermelho = 0;
int verde = 0;
int azul = 0;

bool sensorAtivado = true;

SoftwareSerial SerialBT(19, 18); // RX, TX

void setup() {
  pinMode(PINO_SENSOR_S0, OUTPUT);
  pinMode(PINO_SENSOR_S1, OUTPUT);
  pinMode(PINO_SENSOR_S2, OUTPUT);
  pinMode(PINO_SENSOR_S3, OUTPUT);
  pinMode(PINO_SENSOR_OUT, INPUT);

  pinMode(PINO_LED_VERMELHO, OUTPUT);
  pinMode(PINO_LED_VERDE, OUTPUT);
  pinMode(PINO_LED_AZUL, OUTPUT);

  digitalWrite(PINO_SENSOR_S0, HIGH);
  digitalWrite(PINO_SENSOR_S1, LOW);

  Serial.begin(9600);
  SerialBT.begin(9600);

  Serial.println("Arduino pronto");
  SerialBT.println("bt pronto");
}

void loop() {
  if (sensorAtivado) {
    leitura_cores();
  }

  if (vermelho < azul && vermelho < verde) {
    digitalWrite(PINO_LED_VERMELHO, LOW);
    digitalWrite(PINO_LED_VERDE, LOW);
    digitalWrite(PINO_LED_AZUL, LOW);
    if (cmd != "vermelho") {
      cmd = "vermelho";
      SerialBT.println("parar");
      SerialBT.println('3');
    }
  } else if (azul < vermelho && azul < verde) {
    digitalWrite(PINO_LED_VERMELHO, LOW);
    digitalWrite(PINO_LED_VERDE, LOW);
    digitalWrite(PINO_LED_AZUL, HIGH);
    if (cmd != "azul") {
      cmd = "azul";
      SerialBT.println('1');
    }
  } else if (verde < vermelho && verde < azul) {
    digitalWrite(PINO_LED_VERMELHO, LOW);
    digitalWrite(PINO_LED_VERDE, HIGH);
    digitalWrite(PINO_LED_AZUL, LOW);
    if (cmd != "verde") {
      cmd = "verde";
      SerialBT.println('2');
    }
  }

  delay(100);
}

void leitura_cores() {
  digitalWrite(PINO_SENSOR_S2, LOW);
  digitalWrite(PINO_SENSOR_S3, LOW);

  if (digitalRead(PINO_SENSOR_OUT) == HIGH) {
    vermelho = pulseIn(PINO_SENSOR_OUT, LOW);
  } else {
    vermelho = pulseIn(PINO_SENSOR_OUT, HIGH);
  }

  digitalWrite(PINO_SENSOR_S3, HIGH);

  if (digitalRead(PINO_SENSOR_OUT) == HIGH) {
    azul = pulseIn(PINO_SENSOR_OUT, LOW);
  } else {
    azul = pulseIn(PINO_SENSOR_OUT, HIGH);
  }

  digitalWrite(PINO_SENSOR_S2, HIGH);

  if (digitalRead(PINO_SENSOR_OUT) == HIGH) {
    verde = pulseIn(PINO_SENSOR_OUT, LOW);
  } else {
    verde = pulseIn(PINO_SENSOR_OUT, HIGH);
  }
}