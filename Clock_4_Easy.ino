
void easyClock(){
    updateTime();
    hours();
}


void hours(){
  int i = 0;
  while (i <= hourval*5){
   strip.setPixelColor(i, strip.Color(60,60,60));
   i += 5;
  }
  strip.show();
}


/*void setGreen(int index){
  strip.setPixelColor(index,strip.Color(0,mainLights,0); 
}*/

