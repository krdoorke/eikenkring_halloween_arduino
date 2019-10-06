# Eikenkring_halloween_arduino

Arduino sketch created for the halloween event @ Leefschool Eikenkring.
2019

Author: Kristof Van Doorsselaere

# Required libraries:
- SimpleTimer
- NewPing
- SerialMP3Player

# Project goal
- As soon as someone is detected in less than 2,5m start halloween animation

# Halloween animation
- after 1 ms start sound 1
- after 3 seconds start stroboscoop
- after 5 seconds start smoke machine
- after 8 seconds start stroboscoop
- after 15 seconds stop smoke machine
- after 20 seconds start sound 2
- after 30 seconds stop animation

# Remarks
- animation will maximum run once every 45 seconds (param period)
- Sound volume is set to maximem (param Volume)

# Required hardware
- arduino Uno
- 8 channel relay board
- ultrasonic sensor 
- serialmp3player
- sound box
- ausio cable
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
-
