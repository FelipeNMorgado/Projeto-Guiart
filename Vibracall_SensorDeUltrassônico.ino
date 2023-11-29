const int trigPin = 6; // Pino TRIG conectado ao pino 9 do Arduino
const int echoPin = 7; // Pino ECHO conectado ao pino 10 do Arduino
long duration;
int distance;
const int vibraCallPin = 12; // Pino para controlar o Vibra Call

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(vibraCallPin, OUTPUT); // Pino para controlar o Vibra Call
}

void loop() {
  // Limpe o pino TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Emita um pulso de ultrassom
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Meça a duração do pulso ECHO
  duration = pulseIn(echoPin, HIGH);

  // Defina a distância de aviso desejada (por exemplo, 50 centímetros)
  int distanciaAviso = 75;

  if (distance <= distanciaAviso) {
    Serial.println("Aviso: Distância abaixo de 50 cm!");
    digitalWrite(vibraCallPin, HIGH); // Ative o Vibra Call
  } else {
    Serial.print("Distância: ");
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(vibraCallPin, LOW); // Desative o Vibra Call
  }
  delay(1000); // Espere 1 segundo antes da próxima leitura
}