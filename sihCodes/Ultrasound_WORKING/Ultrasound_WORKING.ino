const int TriggerPin = 8; //Trig pin
const int EchoPin = 9; //Echo pin
const int Trig2 = 6; //Trig pin
const int Echo2 = 7;
long Duration = 0;
long Duration2 = 0;

const int power2 = 5;

void setup(){
pinMode(TriggerPin,OUTPUT); // Trigger is an output pin
pinMode(EchoPin,INPUT); // Echo is an input pin
pinMode(Trig2,OUTPUT); // Trigger is an output pin
pinMode(Echo2,INPUT);
pinMode(power2,OUTPUT);
Serial.begin(9600); // Serial Output
}

void loop(){
digitalWrite(power2, HIGH);

digitalWrite(TriggerPin, LOW);
delayMicroseconds(2);
digitalWrite(TriggerPin, HIGH); // Trigger pin to HIGH
delayMicroseconds(10); // 10us high
digitalWrite(TriggerPin, LOW); // Trigger pin to HIGH

digitalWrite(Trig2, LOW);
delayMicroseconds(2);
digitalWrite(Trig2, HIGH); // Trigger pin to HIGH
delayMicroseconds(10); // 10us high
digitalWrite(Trig2, LOW);

Duration = pulseIn(EchoPin,HIGH); // Waits for the echo pin to get high
// returns the Duration in microseconds
Duration2 = pulseIn(Echo2,HIGH);


long Distance_mm1 = Distance(Duration); // Use function to calculate the distance
long Distance_mm2 = Distance(Duration2);
//Serial.print("Duration = ");
//Serial.print(Duration);
//Serial.print(" ");
Serial.print("Distance1 = "); // Output to serial
Serial.print(Distance_mm1);
Serial.print(",");
Serial.print("Distance2 = ");
Serial.println(Distance_mm2);
//Serial.println(" mm");

delay(1000); // Wait to do next measurement
}

long Distance(long time)
{
// Calculates the Distance in mm
// ((time)*(Speed of sound))/ toward and backward of object) * 10

long DistanceCalc; // Calculation variable
DistanceCalc = ((time /2.9) / 2); // Actual calculation in mm
//DistanceCalc = time / 74 / 2; // Actual calculation in inches
return DistanceCalc; // return calculated value
}