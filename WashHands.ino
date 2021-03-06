/*** --- WashHand Project --- ***/
/** Author: Nilson Sales **/


// Loading ultrasonic library
#include <Ultrasonic.h>


// Defining pins for echo, trigger, leds and buzz
#define TRIGGER_PIN  4
#define ECHO_PIN     5

#define RED_PIN      9
#define YELLOW_PIN  10
#define GREEN_PIN   11

#define BUZZ         3


// Initialising the sensor
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup() {
  // code to run once:
  
  Serial.begin(9600);
  Serial.println("Reading sensor data...");

  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  pinMode(BUZZ, OUTPUT); 
}

void loop() {
  // code to run repeatedly:
  
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  //inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Serial.print("MS: ");
  //Serial.print(microsec);
  //Serial.print(", CM: ");   /* Uncomment these lines to test the ultrasonic sensor */
  //Serial.print(cmMsec);
  //Serial.print(", IN: ");
  //Serial.println(inMsec);
  

  if(cmMsec <= 20){ // If detects object closer to 20 cm, activate
    start_counter();
  }

  delay(1000);
  
}

void start_counter(){
  
  // Confirmation blink and buzz
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  tone(BUZZ, 330, 800);
  delay(1500);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);

  
  for(int i = 0; i <= 18; ++i){ // blink for 18 sec
    digitalWrite(RED_PIN, HIGH);
    delay(700);
    digitalWrite(RED_PIN, LOW);
    delay(300);
  }

  digitalWrite(YELLOW_PIN, HIGH); // blink for 2 sec
  delay(2000);
  digitalWrite(YELLOW_PIN, LOW);

  for(int i = 0; i <= 3; ++i){  // blink 3 times and buzz
    digitalWrite(GREEN_PIN, HIGH);
    tone(BUZZ, 349, 500); // 330
    delay(1000);
    digitalWrite(GREEN_PIN, LOW);
    delay(200);
  }
  
}
