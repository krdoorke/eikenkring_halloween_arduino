#include <SimpleTimer.h>                            // non standard library, download and define here
SimpleTimer animation_timer;                        // create object SimpleTimer named timer
SimpleTimer sound_timer;                        // create object SimpleTimer named timer


#define RELAY_LINE1_PIN 2                           // relay 1 pin used to poweron the leaf blower
#define RELAY_LINE2_PIN 3                           // relay 2 pin used to poweron the stroboscoop
#define RELAY_LINE3_PIN 4                           // relay 3 pin used to activate the light effects
#define RELAY_LINE4_PIN 5                           // relay 4 pin used to activate the smoke machine


#define ECHO_PIN     9                              // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN  10                             // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define MAX_DISTANCE 400                            // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm. [this is an arbitrary number]

#include "NewPing.h"                                // non standard library, download and define here
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

#include "SerialMP3Player.h"                        // non standard library, download and define here
#define TX 11                                       // mp3player tx pin
#define RX 12                                       // mp3player rx pin
SerialMP3Player mp3(RX,TX);                         // SerialMP3Player 

bool animationActivated = false;                    // boolean used to define if animation is already running
bool backgroundSoundActivated = false;              // boolean used to define if background sound is already running

unsigned long animationStartMillis;                 // animation last start time
unsigned long backgroundSoundStartMillis;           // background sound last start time
unsigned long currentMillis;                        // current time
unsigned long animationRunTime;                     // time since animation is running
unsigned long backgroundSoundRunTime;               // time since background sound is activated
const unsigned long animationDuration = 65000;      // duration of 1 animation run time
const unsigned long backgroundSoundDuration = 60000;// duration of 1 animation run time
const unsigned int minimalDistance = 180;           // minimal dinstance for object to be detected
const unsigned int volume = 30;                     // MP3 player volume used during Animation(30 = maximum)

bool Debug = true;

// To do: use logging library to have different levels of debugging
#include <ArduinoLog.h>
