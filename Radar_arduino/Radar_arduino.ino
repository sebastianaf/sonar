// Incluye la librería Servo
#include <Servo.h>. 
// Defines Tirg y Echo del Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
// Variables para la duración y distancia
long duration;
int distance;
Servo myServo; // Creas una variable servo
void setup() {
  pinMode(trigPin, OUTPUT); // Sets el trigPin como un Output
  pinMode(echoPin, INPUT); // Sets el echoPin como uun Input
  Serial.begin(9600);
  myServo.attach(12); // Defines los pines del servo
}
void loop() {
  // rotacion del servo de  15 a 165 grados
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// calcular distancia
  
  Serial.print(i); // (inglés)Sends the current degree into the Serial Port
  Serial.print(","); // (inglés)Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); //(inglés) Sends the distance value into the Serial Port
  Serial.print("."); // (inglés)Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // repetición
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// calcular distancia
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(1);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH,5000); // leer el echoPin, retorna la honda ultrasónica
  distance= duration*0.034/2;
  return distance;
}
