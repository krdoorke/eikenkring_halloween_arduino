#include "definitions.h"
#include "functions.h"
#include "timers.h"

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
  mp3.setVol(volume);                               // set volume
  stopMillis = millis();                            // initial stop time;
}

void loop() {
  currentMillis = millis();                         // get current time
  timer.run();                                      // run simple timer
  delay(30);                                        // Wait 30ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int distance = readDistance();           // Current distance of any object facing the ultrasonic sensor
  if (Debug) {
    Serial.print("Seconds since last animation stopped:" );
    Serial.println((currentMillis-stopMillis)/1000);
    Serial.print("distance:");
    Serial.println(distance);
  }
  timeSinceLastRun = currentMillis - stopMillis;
  if (Debug) {
    Serial.print("timeSinceLastRun:");
    Serial.println(timeSinceLastRun/1000);
  }
  if (timeSinceLastRun > minimalInterval) 
    {
    if (AnimationRunning)
    {
      if (Debug) {
        Serial.println("Animation already running");
      }
    } 
    else
    {
       AnimationRunning = true;
       periodicalAnimation();                            // this keeps the audio device awake
    }
  }
  else
  {
    if (distance < minimalDistance) 
    {
       if (AnimationRunning)
       {
         if (Debug) {
           Serial.println("Animation already running");
         }
       } 
       else
       {
         if (currentMillis - stopMillis >= waitTime)
           {
             if (Debug) {
               Serial.println("Starting Animation");
             }
             AnimationRunning = true;
             runAnimation();
           }
           else
           {
             if (Debug) {
              Serial.println("Waiting few seconds before activating again");
             }
          }
       }
    }
  }
}
