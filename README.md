# Eikenkring_halloween_arduino

Arduino sketch created for the halloween event @ Leefschool Eikenkring.
2019

Author: Kristof Van Doorsselaere

# Required libraries:
- SimpleTimer
- NewPing
- SerialMP3Player

# Project goal
- As soon as someone is detected in less than 2m start halloween animation

# Halloween animation
- after 10 ms start sound 2 (Wolf scream)
- after 3 seconds start smoke machine
- after 5.5 seconds stop sound
- after 10 seconds start stroboscoop
- after 18 seconds stop stroboscoop
- after 13 seconds stop smoke machine
- after 15.5 seconds start sound 1  (bats flying nearby)
- after 17 seconds start leafblower
- after 25 seconds stop leafblower
- after 20 seconds start light effects
- after 35 seconds start sound (exit count down)
- after 37 seconds stop light effects
- after 45 seconds stop sound

# Remarks
- Sound volume is set to maximum (param Volume = 30)
- when no one is detected, a background sound is activated (blowing wind)

# Required hardware
- arduino Uno
- 8 channel relay board
- ultrasonic sensor 
- serialmp3player
- sound box
- audio cable
- prototype board

# Pin layout
- pin 2: relay 1  (used for stroboscoop)
- pin 3: relay 2  (used for stroboscoop)
- pin 4: relay 3  (used for smoke machine)
- pin 5: echo pin (ultrasonic sensor)
- pin 6: trigger pin (ultrasonic sensor)
- pin 9: TX (mp3player)
- pin 10: RX (mp3player)

# Casing
- All components will be housed in a birdhouse, with ultrasonic sensor placed in front of the hole, see pictures
