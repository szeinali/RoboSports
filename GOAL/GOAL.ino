// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;

// defines variables
long duration;
double distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(leftForward , OUTPUT);
pinMode(leftBackward , OUTPUT);
pinMode(rightForward , OUTPUT);
pinMode(rightBackward , OUTPUT);
Serial.begin(9600); // Starts the serial communication

}
void loop() {
// Clears the trigPin
digitalWrite(leftForward , HIGH);
digitalWrite(leftBackward , LOW);
digitalWrite(rightForward , LOW);
digitalWrite(rightBackward , HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if (distance < 52.0) {
  Serial.println("WORKS FINE");
  digitalWrite(leftForward , LOW);
  digitalWrite(leftBackward , LOW);
  digitalWrite(rightForward , LOW);
  digitalWrite(rightBackward , LOW);
  delay(15000);
  

  
  }
}
