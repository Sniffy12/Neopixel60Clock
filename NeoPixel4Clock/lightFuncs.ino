//allows quick setting of colors by name.  Uses POT value to set brightness.
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

// sets section between two indexes (inclusive) to the specified color.
void setColorSection(int start, int last, String color){
  int i = start;
  while (i <= last){
   setColorByName(i,color);
   i++;
  }
}

//adjusts the minimum and maximum values for room brightness
void brightnessRangeUpdate(){
  int temp = analogRead(PHOTORES);
  if (photoResistMin > temp){
    photoResistMin = temp - 25;
    if (photoResistMin < 0){
      photoResistMin = 0;
    }
  }
  else if (photoResistMax < temp){
    photoResistMax = temp;
  }
}


// adjust light brightness based on photosresistor and pot values.
void updateLightBright(){
        if (dimmer == 0){
    maxBright = map(analogRead(POT), 0, 1023, 2, 255);
  }
  
  else if (dimmer == 1 && toggle == 0){
    maxBrightTick = map(analogRead(POT),0,1023,1, 255);
  }
  
  int sensorValue = analogRead(PHOTORES);
  hourLights = map(sensorValue, photoResistMin, photoResistMax, 1, maxBrightTick);
  mainLights = map(sensorValue, photoResistMin, photoResistMax, 3, maxBright);
}


// decides if hour tickmarks should be shown on simpleClock
void hourLightsOn(){
  int i = 0;
  while (i < 60){
    if (tickOn){
        strip.setPixelColor(i,strip.Color(hourLights,hourLights,hourLights));
    }
    else{
        setColorByName(i,"black");
    }
  i += 5;
  }
}

//displays a smiley to signify that the button action was completed.
void verifiedSmiley(String color){
        setColorByName(5,color);
        setColorByName(55,color);
        setColorSection(15,45,color);
        strip.show();
        delay(1000);
        strip.clear();      
}

