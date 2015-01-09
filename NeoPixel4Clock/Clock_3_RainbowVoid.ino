int colorChoice = 0;

void rainbowVoidClock(){

  hourval *= 5;

  if (dimmer == 1 && toggle == 2){
    colorChoice = map(analogRead(POT),0,1023,0,11) * 5;  // allows rotation of colors based on POT reading
  }
  
  makeRainbow(colorChoice);                              // sets each 5 minute segment a different color 
  setColorSection(hourval - 1,hourval + 4,"black");      // removes the 5 minute segment where the hour resides
  whiteOrBlack(secondval);                                // if a second or minute goes "behind" the hour void, it turns white
  whiteOrBlack(minuteval);
}



void whiteOrBlack(int val){
  if (val > hourval - 2 && val < hourval + 6 || val == 59 && hourval == 0){ // allows seconds and mins to be seen when passing through hour
    setColorByName(val,"white");                                            

  }
  else{
    setColorByName(val,"black");
  }
}


void makeRainbow(int j){  // creates adjustable sectioned colorWheel.
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


