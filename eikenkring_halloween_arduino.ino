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
  pinMode(RELAY_LINE4_PIN, OUTPUT);                 // define relay pin 4 as output
  digitalWrite(RELAY_LINE1_PIN, LOW);               // Turn the relay 1 off
  digitalWrite(RELAY_LINE2_PIN, LOW);               // Turn the relay 2 off
  digitalWrite(RELAY_LINE3_PIN, LOW);               // Turn the relay 3 off
  digitalWrite(RELAY_LINE4_PIN, LOW);               // Turn the relay 4 off
  mp3.begin(9600);                                  // start mp3-communication
  delay(500);                                       // wait for init
  mp3.sendCommand(CMD_SEL_DEV, 0, 2);               // select sd-card
  delay(500);                                       // wait for init
  mp3.setVol(volume);                               // sound volume
}

void loop()
{
  currentMillis = millis();                         // get current time
  animation_timer.run();                            // run animation timer
  sound_timer.run();                                // run sound timer
  delay(30);                                        // Wait 30ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int distance = readDistance();           // Current distance of any object facing the ultrasonic sensor
  if (distance < minimalDistance) 
  {
    runAnimation();
  }
  else
  {
    runBackgroundSound();
  }
}

void runAnimation() {
  if (animationActivated) {
    animationRunTime = currentMillis - animationStartMillis;
    if (animationRunTime > animationDuration) {
      //Serial.println("Animation stopped!");
      animationActivated = false;
    }
  }
  else
  {
    animationStartMillis = millis();
    animationActivated = true;
    backgroundSoundActivated = false;
    Serial.println("Activating Animation!");
    activateAnimation();
  }
}

void runBackgroundSound() {
  if (backgroundSoundActivated) {
    backgroundSoundRunTime = currentMillis - backgroundSoundStartMillis;
    if (backgroundSoundRunTime > backgroundSoundDuration) {
      backgroundSoundActivated = false;
    }
  }
  else
  {
    if (animationActivated) {
      animationRunTime = currentMillis - animationStartMillis;
      //Serial.println(animationRunTime);
      if (animationRunTime > animationDuration) {
        animationActivated = false;
      }
    }
    else
    {
      backgroundSoundStartMillis = millis();
      backgroundSoundActivated = true;
      Serial.println("Activating background sound!");
      activateBackgroundSound();
    }
  }
}
