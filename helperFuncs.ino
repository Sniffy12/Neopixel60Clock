boolean tickOn = true;

//  Chooses dimmer functionality.  
// mainLights/hourLights/nothing for simpleClock
// mainLights/nothing/nothing for onlineClock
// mainlLights/colorChoice/nothing for rainbowClock.
// adjusting POT during colorChoice in rainbowClock
// rotates the colors.
void dimmerCheck(){
  if (digitalRead(DIMMER) == HIGH){
    int j = 0;
    int time =0;
    while (digitalRead(DIMMER) == HIGH){
      if (time > 750){
        tickOn = !tickOn;
        return;
      }
      time++;
      delay(1);
    }
      dimmer++;
      dimmer %= 3;
    }

  }

// incremements toggle by one.  Resets at 4.  Decides clock to show.
void toggleCheck(){
  if (digitalRead(TOGGLE) == HIGH){
    bounce(TOGGLE);
      toggle++;
      toggle %= 4;
      strip.clear();
  }
}

// waits for release of button to run button functions
void bounce(int button){
  while (digitalRead(button) == HIGH){
    delay(5);
    Serial.println("f");
  }
}

// decides if hour tickmarks should be shown on simpleClock
void hourLightsOn(){
  int i = 0;
  while (i < 60){
    if (tickOn){
        strip.setPixelColor(i,strip.Color(hourLights,hourLights,hourLights));
    }
    else{
        strip.setPixelColor(i,strip.Color(0,0,0));
    }
  i += 5;
  }
}

// Increments minute by 1.  Hold down for fast speed.
void minuteCheck(){
    if (digitalRead(MINBUTTON) == HIGH){
      while (digitalRead(MINBUTTON) == HIGH){
     strip.setPixelColor(minuteval,strip.Color(0,0,0));
     clock.setTime(clock.getHour(),minuteval+1,clock.getSec());
     minuteval = clock.getMin();
     strip.setPixelColor(clock.getMin(),strip.Color(0,255,0));
     strip.show();
     delay(150);
    }
}
}

// Pressing hour button increments the hour by one.
// Holding hour button, then holding MINBUTTON or DIMMERbutton and releasing hour button
// will set the seconds to zero or reset the clock to a working state, respectively.
// resetting the clock would be used after removing the clocks battery.
void hourCheck(){
    if (digitalRead(HOURBUTTON) == HIGH){
     bounce(HOURBUTTON);
     
     if (digitalRead(MINBUTTON) == HIGH){
       clock.setTime(clock.getHour(),clock.getMin(),0);
       delay(1000);
       return;
     }
     
     if (digitalRead(DIMMER) == HIGH){
       resetClock();
       delay(1000);
      return;
     }
     
     updateTime();
     strip.setPixelColor(hourval*5 + minuteval/12,strip.Color(0,0,0));
     clock.setTime(hourval+1,clock.getMin(),clock.getSec());
     hourval = clock.getHour()*5 + minuteval/12;
     strip.setPixelColor(hourval,strip.Color(mainLights,0,0));
     strip.show();
    }
}

// adjust light brightness based on photosresistor and pot values.
void updateLightBright(){
        if (dimmer == 0){
    maxBright = map(analogRead(POT), 0, 1023, 2, 128);
  }
  else if (dimmer == 1){
    maxBrightTick = map(analogRead(POT),0,1023,1, 128);
  }
  sensorValue = analogRead(PHOTORES);
  hourLights = map(sensorValue, photoResistMin, photoResistMax, 1, maxBrightTick);
  brightness = map(sensorValue, photoResistMin, photoResistMax, 2, maxBright);
}

//updates min, sec, and hour values
void updateTime(){
  secondval = clock.getSec();  // get seconds
  minuteval = clock.getMin();  // get minutes
  hourval = clock.getHour();  	// get hours
  if(hourval > 11) hourval -= 12;
}

//adjusts the minimum and maximum values for room brightness
void brightnessRangeUpdate(){
  int temp = analogRead(PHOTORES);
if (photoResistMin > temp){
  photoResistMin = temp - 25;
  if (photoResistMin < 0) photoResistMin = 0;
}
else if (photoResistMax < temp){
  photoResistMax = temp;
}
}

//resets clock with values to restore clock functionality after battery change
void resetClock(){
  clock.setTime(0,1,0);
}

void setColorByName(int index, String color){
  if (color == "red"){
       strip.setPixelColor(index,strip.Color(mainLights,0,0));
  }
  else if (color == "orange"){
       strip.setPixelColor(index,strip.Color(mainLights,mainLights/2,0));
  }
  else if (color == "yellow"){
       strip.setPixelColor(index,strip.Color(mainLights,mainLights,0));
  }
  else if (color == "yellowgreen"){
       strip.setPixelColor(index,strip.Color(mainLights/2,mainLights,0));
  }
  else if (color == "green"){
       strip.setPixelColor(index,strip.Color(0,mainLights,0));
  }
  else if (color == "cyangreen"){
       strip.setPixelColor(index,strip.Color(0,mainLights,mainLights/2));
  }
  else if (color == "cyan"){
       strip.setPixelColor(index,strip.Color(0,mainLights,mainLights));
  }
  else if (color == "cyanblue"){
       strip.setPixelColor(index,strip.Color(0,mainLights/2,mainLights));
  }
  else if (color == "blue"){
       strip.setPixelColor(index,strip.Color(0,0,mainLights));
  }
  else if (color == "bluemagenta"){
       strip.setPixelColor(index,strip.Color(mainLights/2,0,mainLights));
  }
  else if (color == "magenta"){
       strip.setPixelColor(index,strip.Color(mainLights,0,mainLights));
  }
  else if (color == "redmagenta"){
       strip.setPixelColor(index,strip.Color(mainLights,0,mainLights/2));
  }
  else if (color == "black"){
       strip.setPixelColor(index,strip.Color(0,0,0)); 
  }
  else if (color == "white"){
      strip.setPixelColor(index,strip.Color(mainLights,mainLights,mainLights)); 
  }
}

