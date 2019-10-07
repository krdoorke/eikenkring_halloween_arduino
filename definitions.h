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
unsigned long stopMillis;                           // animation last stop time
unsigned long currentMillis;                        // current time
unsigned long timeSinceLastRun;                     // time since last run

const unsigned long waitTime = 10000;               // wait at least x miliseconds to start again
const unsigned long minimalInterval = 240000;       // play animation at least once every x milliseconds (to prevent audio box to go into sleep mode)
const unsigned int minimalDistance = 180;           // minimal dinstance for object to be detected
const unsigned int volume = 30;                     // MP3 player volume (30 = maximum)

bool Debug = false;
