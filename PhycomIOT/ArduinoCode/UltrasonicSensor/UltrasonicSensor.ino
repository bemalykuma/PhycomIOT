const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

void setup() {
    Serial.begin(9600); // Initialize serial communication at 9600 bits per second
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    // Clear the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Set the trigPin HIGH for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Read the echoPin, return the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculate the distance in cm and inches
    distanceCm = duration * 0.034 / 2;
    distanceInch = duration * 0.0133 / 2;

    // Print the distances to the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
    
    delay(1000); // Wait 1 second before the next measurement
}
