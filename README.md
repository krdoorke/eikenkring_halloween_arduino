# eikenkring_halloween_arduino

Arduino sketch created for the halloween event @ Leefschool Eikenkring.
2019

# Required libraries:
- SimpleTimer
- NewPing
- SerialMP3Player

# Project goal
- As soon as someone is detected in less than 2,5m start halloween animation

# Halloween animation
- after 1 ms start sound 1
- after 3 seconds start stroboscoop
- after 5 seonds start smoke machine
- after 8 seonds start stroboscoop
- after 15 seonds stop smoke machine
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
