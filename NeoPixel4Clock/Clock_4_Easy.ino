int paletteChoice;

String palette[6][4] = {
{"red","green","blue","yellow"},
{"red","blue","green","magenta"},
{"blue","green","red","cyan"},
{"blue","red","green","magenta"},
{"green","blue","red","cyan"},
{"green","red","blue","yellow"}};

void easyClock(){
  
    if (dimmer == 1 && toggle == 3){
    paletteChoice = map(analogRead(POT),0,1023,0,5);
    }
    
    strip.clear();
    setColorSection((minuteval/10) * 10,minuteval, palette[paletteChoice][2]);  //sets minutes within 10 min sections
    setColorByName((minuteval/10) * 10, palette[paletteChoice][1 ]); // gives 5 minute marks within section a unique color
    setColorByName((minuteval/5) * 5, palette[paletteChoice][1]);    // gives 5 minute marks within section a unique color
    hours();  //sets hour lights.  If minutes occupy the same pixel, colors mix

}


void hours(){ // Lights each hour mark up to and including the current hour
  int i = 5;
  if (hourval == 0) hourval = 12; 
  while (i <= hourval * 5){
   i %= 60;
   
   if (i == (minuteval/10)*10){
     setColorByName(i,palette[paletteChoice][3]); //mixes colors on even numbers if hour/min use same pixel
   }
   
   else if (i == (minuteval/5) * 5){
     setColorByName(i,palette[paletteChoice][3]); //mixes colors on odd numbers if hour/min use same pixel
   }
   
   else setColorByName(i,palette[paletteChoice][0]); //sets hours to red
   
   if (i == 0){
     return; // pixel 0 is 12 which required the i = 5 offset, this allows pixel 0 to be set last and escape the possible infinite loop.
   }
   i += 5;
  }
}

