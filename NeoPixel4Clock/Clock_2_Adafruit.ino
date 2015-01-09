/**************************************************************************
 *                                                                     	*  	 
 *   NeoPixel Ring Clock                                               	*
 *   Copyright (C) 2014  Andy Doro (mail@andydoro.com)                 	*
 *                                                                     	*
 ***************************************************************************
 *                                                                     	*
 * This program is free software; you can redistribute it and/or modify	*
 * it under the terms of the GNU General Public License as published by	*
 * the Free Software Foundation; either version 2 of the License, or   	*
 * (at your option) any later version.                                 	*
 *                                                                     	*
 * This program is distributed in the hope that it will be useful,     	*
 * but WITHOUT ANY WARRANTY; without even the implied warranty of      	*
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the       	*
 * GNU General Public License for more details.                        	*
 *                                                                     	*
 * You should have received a copy of the GNU General Public License   	*
 * along with this program; if not, write to the Free Software         	*
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,               	*
 * MA  02111-1307  USA                                                 	*
 *                                                                     	*
 ***************************************************************************
 *
 *
 * Revision History
 *
 * Date 	 By    What
 * 20140320 	AFD 	First draft
 * 20150102     JBB     updated with new library, lightlevels chosen by POT
 */

void adafruitClock(){
 
  hourval = hourval*5 + minuteval / 12;  //each red dot represent 24 minutes.
  
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

}
