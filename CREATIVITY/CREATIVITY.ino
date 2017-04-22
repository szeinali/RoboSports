const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;
const int trigPin = 9;
const int echoPin = 10;
const int redled = 12;
const int greenled = 13;
long duration;
double distance;

void setup() 
{
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(leftForward , OUTPUT);
pinMode(leftBackward , OUTPUT);
pinMode(rightForward , OUTPUT);
pinMode(rightBackward , OUTPUT);
pinMode(redled, OUTPUT);
pinMode(greenled, OUTPUT);
Serial.begin(9600); // Starts the serial communication

}


void loop()
{
  digitalWrite(greenled, HIGH);   
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
  if (18.0<distance && distance< 40.0) {
   digitalWrite(greenled, HIGH);   
   delay(100);
   digitalWrite(greenled, LOW);  
   digitalWrite(redled, HIGH);  
   delay(100);
   digitalWrite(redled, LOW);  
  }
  else if(distance<18){
   digitalWrite(greenled, LOW);  
   digitalWrite(redled, HIGH); 
   digitalWrite(leftForward , LOW);
   digitalWrite(leftBackward , LOW);
   digitalWrite(rightForward , LOW);
   digitalWrite(rightBackward , LOW);
   delay(3000);
   digitalWrite(leftForward , LOW);
  digitalWrite(leftBackward , HIGH);
  digitalWrite(rightForward , HIGH);
  digitalWrite(rightBackward , LOW);
  delay(3000);
  //left
  digitalWrite(leftForward , HIGH);
  digitalWrite(leftBackward , HIGH);
  digitalWrite(rightForward , LOW);
  digitalWrite(rightBackward , HIGH);  
  delay(3000);
    }
  }

