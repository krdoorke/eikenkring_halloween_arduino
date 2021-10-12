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

// Function to activate leaf blower
void activate_leaf_blower() {
  Serial.println("Starting leaf blower Animation");
  digitalWrite(RELAY_LINE1_PIN, HIGH); // Turn the leaf blower on
}

// Function to stop the leaf blower
void stop_leaf_blower() {
  Serial.println("Stopping leaf blower");
  digitalWrite(RELAY_LINE1_PIN, LOW); // Turn the leaf blower off
}

// Function to activate stroboscoop
void activate_stroboscoop() {
  Serial.println("Starting Stroboscoop Animation");
  digitalWrite(RELAY_LINE2_PIN, HIGH); // Turn the strobo on
}

// Function to stop the stroboscoop
void stop_stroboscoop() {
  Serial.println("Stopping Stroboscoop");
  digitalWrite(RELAY_LINE2_PIN, LOW); // Turn the strobo off
}


// Function to activate light effects
void activate_light_effects() {
  Serial.println("Starting light effects Animation");
  digitalWrite(RELAY_LINE3_PIN, HIGH); // Turn the light effects on
}

// Function to stop light effects
void stop_light_effects() {
  Serial.println("Stopping light effects");
  digitalWrite(RELAY_LINE3_PIN, LOW); // Turn the light effects off
}

// Function to activate smoke machine
void activate_smoke() {
  Serial.println("Starting Smoke Machine");
  digitalWrite(RELAY_LINE4_PIN, HIGH); // Turn the smoke machine on
}

// Function to stop smoke machine
void stop_smoke() {
  Serial.println("Stopping Smoke Animation");
  digitalWrite(RELAY_LINE4_PIN, LOW); // Turn the smoke machine off
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
  Serial.println("(re)Starting Background Sound");
  mp3.playF(3);
}

// Function to activate third sound effect
void activate_sound4() {
  Serial.println("Starting Countdown Sound");
  mp3.playF(4);
}

// Function to stop third sound effect
void stop_sound() {
  Serial.println("Stopping Sound");
  mp3.stop();
}
