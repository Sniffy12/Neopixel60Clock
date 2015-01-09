boolean tickOn = true;

//  Chooses dimmer functionality.  
// mainLights/hourLights/nothing for simpleClock
// mainLights/nothing/nothing for onlineClock
// mainlLights/colorChoice/nothing for rainbowClock.
// adjusting POT during colorChoice in rainbowClock
// rotates the colors.
void dimmerButtonCheck(){
  if (digitalRead(DIMMER) == HIGH){
    int i = 0;
    while (digitalRead(DIMMER) == HIGH){
      if (i > 750){
        
        tickOn = !tickOn;
        return;
      }
      
      i++;
      delay(1);
    }
    
      dimmer++;
      dimmer %= 3;
    }
  }

// incremements toggle by one.  Resets at 4.  Decides clock to show.
// if held down for 3/4 of a second, it resets the PhotoResistors min/max
// values.  Helpful if it received a darker or brighter than normal light level.
void toggleButtonCheck(){
  if (digitalRead(TOGGLE) == HIGH){
    int i = 0;
    
    while (digitalRead(TOGGLE) == HIGH){
      if (i > 750){
        photoResistMin = 500;
        photoResistMax = 501;
        
        verifiedSmiley("blue");                            
        return;
      }
      
      i++;
      delay(1);
    }
    
      dimmer = 2;
      toggle++;
      toggle %= 4;
      strip.clear();
  }
}

// Increments minute by 1.  Hold down for fast speed.
void minuteButtonCheck(){
    if (digitalRead(MINBUTTON) == HIGH){
      while (digitalRead(MINBUTTON) == HIGH){
        setColorByName(minuteval,"black");
      
        if (minuteval == 59) {
          minuteval = 0;
        }

        else{
          minuteval++; 
        }
    
        setColorByName(minuteval,"green");
        strip.show();
        delay(150);
     }
     clock.setTime(clock.getHour(),minuteval,clock.getSec());
}
}

// Pressing hour button increments the hour by one.
// Holding hour button, then holding MINBUTTON or DIMMERbutton and releasing hour button
// will set the seconds to zero or reset the clock to a working state, respectively.
// resetting the clock would be used after removing the clocks battery.
void hourButtonCheck(){
    if (digitalRead(HOURBUTTON) == HIGH){
      while (digitalRead(HOURBUTTON)== HIGH){
        if (digitalRead(MINBUTTON) == HIGH){
          clock.setTime(clock.getHour(),clock.getMin(),0);
          verifiedSmiley("cyangreen");
          return;
      }
    }
     
     updateTimeValues();
     clock.setTime(hourval+1,clock.getMin(),clock.getSec());
     setColorByName(hourval*5 + minuteval/12,"red");
     strip.show();
    }
}


//updates min, sec, and hour values
void updateTimeValues(){
  secondval = clock.getSec();  // get seconds
  minuteval = clock.getMin();  // get minutes
  hourval = clock.getHour();  	// get hours
  if(hourval > 11) hourval -= 12;
}




