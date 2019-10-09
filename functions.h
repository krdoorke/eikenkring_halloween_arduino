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

// Function to activate smoke machine
void activate_smoke() {
  Serial.println("Starting Smoke Machine");
  digitalWrite(RELAY_LINE3_PIN, HIGH); // Turn the smoke on
}

// Function to stop smoke machine
void stop_smoke() {
  Serial.println("Stopping Smoke Animation");
  digitalWrite(RELAY_LINE3_PIN, LOW); // Turn the soke off
}

// Function to activate stroboscoop
void activate_stroboscoop() {
  Serial.println("Starting Stroboscoop Animation");
  digitalWrite(RELAY_LINE1_PIN, HIGH); // Turn the strobo on
  digitalWrite(RELAY_LINE2_PIN, HIGH); // Turn the strobo on

}

// Function to activate stroboscoop
void stop_stroboscoop() {
  Serial.println("Stopping Stroboscoop");
  digitalWrite(RELAY_LINE1_PIN, LOW); // Turn the strobo off
  digitalWrite(RELAY_LINE2_PIN, LOW); // Turn the strobo ff
}

// Function to activate first sound effect
void activate_sound1() {
  Serial.println("Starting Sound 1");
  mp3.playF(1);
}

// Function to activate second sound effect
void activate_sound2() {
  Serial.println("Starting Sound 2");
  mp3.playF(2);
}

// Function to activate third sound effect
void activate_sound3() {
  Serial.println("Starting Background Sound");
  mp3.playF(3);
}

// Function to stop third sound effect
void stop_sound() {
  Serial.println("Stopping Sound");
  mp3.stop();
}
