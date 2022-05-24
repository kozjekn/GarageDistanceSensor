// defines pins numbers
const int trigPin = 8; //NOTE: trig pin and echo pin had to be reversed for some reason
const int echoPin = 10;
const int relayPin = 9;

// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(relayPin, OUTPUT); // Sets the relay pin to OUTPUT
Serial.begin(9600); // Starts the serial communication
}

void loop() {
  distance = GetDistance();
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  
  Serial.println(distance);
  if(distance <= 10)
  {
    digitalWrite(relayPin,HIGH);
    delay(10000);
    digitalWrite(relayPin,LOW);
    distance = GetDistance();
    while(distance < 20)
    {
      distance = GetDistance();
      Serial.println(distance);
      delay(1000);
    }
  }
}

 

int GetDistance(){
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    int distanceMesured = duration*0.034/2;

    return distanceMesured;
}
