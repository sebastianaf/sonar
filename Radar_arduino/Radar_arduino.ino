// Incluye la librería Servo
#include <Servo.h>
// Define los pines del sensor ultrasonico
const int trigPin = 10;
const int echoPin = 11;
// Variables para la duración y distancia
long duration;
int distance;
Servo myServo; // Crea una variable servo
void setup() {
  pinMode(trigPin, OUTPUT); // configura trigPin como una salida
  pinMode(echoPin, INPUT); // configura echoPin como una entrada
  Serial.begin(9600); // inicializa la comunicacion serial con la interfaz arduino
  myServo.attach(12); // Defines los pines del servo
}
void loop() {
  // rotacion del servo de  15 a 165 grados
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// calcular distancia

  //Hace el envio de los datos del sensor ultrasonico por el la conexión serial  
  Serial.print(i); 
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
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

// funcion que calcula la distancia del
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(1);
  //activa el emisor ultrasonico por 10 microsegundos
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW, 8000);
  duration = pulseIn(echoPin, HIGH,5000); // leer el echoPin, retorna la honda ultrasónica
  distance= duration*0.034/2;
  return distance;
}
