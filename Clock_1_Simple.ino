int hourInt = 0;

void simpleClock(){

    // removes color before updating
    strip.setPixelColor(secondval,strip.Color(0,0,0));
    strip.setPixelColor(hourval, strip.Color(0,0,0));
    strip.setPixelColor(minuteval, strip.Color(0,0,0));
    
    hourLightsOn();  //add hour markers if enabled
    updateTime();  // updates time
    
    hourval = hourval*5 + minuteval / 12;  //turns 0-11 hour value into 0-60 based on where minute is
    
    //sets current color locations
    strip.setPixelColor(secondval,strip.Color(0,0,mainLights));
    strip.setPixelColor(minuteval,strip.Color(0,mainLights,0));
    strip.setPixelColor(hourval,strip.Color(mainLights,0,0));
    
    // mixes colors if two or more colors overlap.
    
    if (secondval == minuteval && secondval == hourval){
      setColorByName(secondval, "white");
      //strip.setPixelColor(secondval,strip.Color(mainLights/3,mainLights/3,mainLights/3));
    }
    else if (secondval == minuteval){
      //strip.setPixelColor(secondval,strip.Color(0, mainLights/2, mainLights/2));
      setColorByName(secondval,"cyan");
    }
    else if (secondval == hourval){
      setColorByName(secondval, "magenta");
      //strip.setPixelColor(secondval,strip.Color(mainLights/2, 0,mainLights/2));
    }
    else if (minuteval == hourval){
      setColorByName(minuteval, "yellow");
      //strip.setPixelColor(minuteval,strip.Color(mainLights/2, mainLights/2 , 0));
    }
    
    strip.show();
}
