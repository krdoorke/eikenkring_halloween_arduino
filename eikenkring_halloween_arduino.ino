
#include <SimpleTimer.h>                            // non standard library, download and define here
SimpleTimer timer;                                  // create object SimpleTimer named timer

#define RELAY_LINE1_PIN 2                           // relay 1 pin used to poweron the stroboscoop
#define RELAY_LINE2_PIN 3                           // relay 2 pin used to poweron the stroboscoop
#define RELAY_LINE3_PIN 4                           // relay 3 pin used to activate the smoke machine

#define ECHO_PIN     5                              // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN  6                              // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define MAX_DISTANCE 400                            // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm. [this is an arbitrary number]

#include "NewPing.h"                                // non standard library, download and define here
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

#include "SerialMP3Player.h"                        // non standard library, download and define here
#define TX 9                                        // mp3player tx pin
#define RX 10                                       // mp3player rx pin
SerialMP3Player mp3(RX,TX);                         // SerialMP3Player 

bool AnimationRunning = false;                      // boolean used to define if animation is already running
unsigned long startMillis;                          // animation start time
unsigned long currentMillis;                        // current time
const unsigned long period = 45000;                 // 30 seconds
const unsigned Volume = 30;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                               // start serial communication
  Serial.println("Launching Halloween Animation!");
  pinMode(RELAY_LINE1_PIN, OUTPUT);                 // define relay pin 1 as output
  pinMode(RELAY_LINE2_PIN, OUTPUT);                 // define relay pin 2 as output
  pinMode(RELAY_LINE3_PIN, OUTPUT);                 // define relay pin 3 as output
  digitalWrite(RELAY_LINE1_PIN, LOW);               // Turn the relay 1 off
  digitalWrite(RELAY_LINE2_PIN, LOW);               // Turn the relay 2 off
  digitalWrite(RELAY_LINE3_PIN, LOW);               // Turn the relay 3 off
  mp3.begin(9600);                                  // start mp3-communication
  delay(500);                                       // wait for init
  mp3.sendCommand(CMD_SEL_DEV, 0, 2);               // select sd-card
  delay(500);                                       // wait for init
  mp3.setVol(Volume);                               // set Volume
  startMillis = millis();                           // initial start time;
}

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis = millis();                         // get current time
  timer.run();                                      // run simple timer
  delay(30);                                        // Wait 30ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int distance = readDistance();           // Current distance of any object facing the ultrasonic sensor
  //Serial.print("Seconds since last start:" );
  //Serial.println((currentMillis-startMillis)/1000);
  //Serial.print("distance:");
  //Serial.println(distance);
  if (distance < 250) 
  {
     if (AnimationRunning)
     {
       //Serial.println("Animation already running");
     } 
     else
     {
       if (currentMillis - startMillis >= period)
         {
           //Serial.println("Starting Animation");
           AnimationRunning = true;
           startMillis = currentMillis;
           runAnimation();
         }
         else
         {
           //Serial.println("Waiting till period is greater then 45 seconds");
         }
     }
  }
}

// Updates the value of the Ultrasonic reading
unsigned int readDistance() {
  // Read 7 values from the ultrasonic and get the median value ( median filter )
  // Gets rid of noisy reading
  unsigned int distance = sonar.convert_cm(sonar.ping_median(7));

  // The value 0 indicates that the ultrasonic sensor is reading nothing in front of it
  // Set this distance to max distance so the light doesn't switch unnecessarily
  if (distance == 0)
  {
    distance = MAX_DISTANCE;
  }
  
  return distance;
}


// Setup timers for animation
void runAnimation() {
    timer.setTimeout(1, activate_sound1);
    timer.setTimeout(3000, activate_stroboscoop);
    timer.setTimeout(5000, activate_smoke);
    timer.setTimeout(8000, stop_stroboscoop);
    timer.setTimeout(15000, stop_smoke);
    timer.setTimeout(20000, activate_sound2);
    timer.setTimeout(30000, stop_Animation);
}

// Function to activate smoke machine
void activate_smoke() {
  //Serial.println("Starting Smoke Machine");
  digitalWrite(RELAY_LINE3_PIN, HIGH); // Turn the smoke on
}

// Function to stop smoke machine
void stop_smoke() {
  //Serial.println("Stopping Smoke Animation");
  digitalWrite(RELAY_LINE3_PIN, LOW); // Turn the soke off
}

// Function to activate stroboscoop
void activate_stroboscoop() {
  //Serial.println("Starting Stroboscoop Animation");
  digitalWrite(RELAY_LINE1_PIN, HIGH); // Turn the strobo on
  digitalWrite(RELAY_LINE2_PIN, HIGH); // Turn the strobo on

}

// Function to activate stroboscoop
void stop_stroboscoop() {
  //Serial.println("Stopping Stroboscoop");
  digitalWrite(RELAY_LINE1_PIN, LOW); // Turn the strobo off
  digitalWrite(RELAY_LINE2_PIN, LOW); // Turn the strobo ff
}

// Function to activate first sound effect
void activate_sound1() {
  //Serial.println("Starting Sound 1");
  mp3.wakeup();
  mp3.playF(1);
}

// Function to activate second sound effect
void activate_sound2() {
  //Serial.println("Starting Sound 2");
  mp3.wakeup();
  mp3.playF(2);
}

// Function to finalyse animation
void stop_Animation() {
  //Serial.println("Stopping sound");
  mp3.stop();
  mp3.sleep();
  AnimationRunning = false;
  //Serial.println("Animation done");
}
