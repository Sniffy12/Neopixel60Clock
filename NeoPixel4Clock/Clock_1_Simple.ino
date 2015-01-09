void simpleClock(){

    // removes color before updating
    strip.clear();
    
    hourLightsOn();  //add hour markers if enabled
    hourval = hourval*5 + minuteval / 12;  //turns 0-11 hour value into 0-59 based on where minute is
    
    //sets current color locations
    setColorByName(secondval,"blue");
    setColorByName(minuteval,"green");
    setColorByName(hourval,"red");
    
    // mixes colors if two or more values overlap.
    if (secondval == minuteval && secondval == hourval){
      setColorByName(secondval, "white");
    }
    else if (secondval == minuteval){
      setColorByName(secondval,"cyan");
    }
    else if (secondval == hourval){
      setColorByName(secondval, "magenta");
    }
    else if (minuteval == hourval){
      setColorByName(minuteval, "yellow");
    }
}
