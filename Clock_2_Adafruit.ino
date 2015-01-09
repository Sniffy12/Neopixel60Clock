void onlineClock(){
  updateTime();
  hourval = (hourval*60 + minuteval) / 12;  //each red dot represent 24 minutes.

  for(uint8_t i=0; i<strip.numPixels(); i++) {
 
	if (i <= secondval) {
  	pixelColorBlue = mainLights;
	}
	else {
  	pixelColorBlue = 0;
	}
 
	if (i <= minuteval) {
  	pixelColorGreen = mainLights;  
	}
	else {
  	pixelColorGreen = 0;
	}
 
	if (i <= hourval) {
  	pixelColorRed = mainLights;   
	}
	else {
  	pixelColorRed = 0;
	}
 
	strip.setPixelColor(i, strip.Color(pixelColorRed, pixelColorGreen, pixelColorBlue));
  }
 
  //display
  strip.show();
 
  // wait
  delay(100);
}
 
 
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
	strip.setPixelColor(i, c);
	strip.show();
	delay(wait);
  }
}
