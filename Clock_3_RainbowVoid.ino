int colorChoice = 0;

void rainbowClock(){
  updateTime();  


// allows rotation of colors based on POT reading
  if (dimmer == 1){
    colorChoice = map(analogRead(POT),0,1023,0,11) * 5;
  }
  
  makeRainbow(colorChoice); // sets each 5 minute segment a different color 
  hourVoid(hourval);        // removes the 5 minute segment where the hour resides
  whiteOrVoid(secondval);   // if a second or minute goes "behind" the hour void, it turns white
  whiteOrVoid(minuteval);
  strip.show();
}

// sets the entire hour segment black.
void hourVoid(int hr){
    int i = hr*5;
  while (i <= hr*5 + 4){
   strip.setPixelColor(i,strip.Color(0,0,0)); 
   i++;
  }
}

// if second or minutes goes inside the hourVoid (black strip showing hour)
// they turn white starting at the edges of the void.
void whiteOrVoid(int val){
  if (val > hourval*5 - 2 && val < hourval*5 + 6){
    setColorByName(val,"white");
  }
  else{
    setColorByName(val,"black");
  }
}

// creates colorWheel based on numbered section 1-12, parameter determines where red starts
void makeRainbow(int j){
  int i = 0;
  while (i < 12) {
    switch (i) {
      case 0: setColorSection(j,j+4,"red"); break;
      case 1: setColorSection(j,j+4,"orange"); break;
      case 2: setColorSection(j,j+4,"yellow"); break;
      case 3: setColorSection(j,j+4,"yellowgreen"); break;
      case 4: setColorSection(j,j+4,"green"); break;
      case 5: setColorSection(j,j+4,"cyangreen"); break;
      case 6: setColorSection(j,j+4,"cyan"); break;
      case 7: setColorSection(j,j+4,"cyanblue"); break;
      case 8: setColorSection(j,j+4,"blue"); break;
      case 9: setColorSection(j,j+4,"bluemagenta"); break;
      case 10: setColorSection(j,j+4,"magenta"); break;
      default: setColorSection(j,j+4,"redmagenta");
    }
   i++;
   j+=5;
   j%=60;
  }
}

// creates sections of each specified color.
void setColorSection(int start, int last, String color){
  int i = start;
  while (i <= last){
   setColorByName(i,color);
   //strip.setPixelColor(i, strip.Color(mainLights,0,0)); 
   i++;
  }
}
