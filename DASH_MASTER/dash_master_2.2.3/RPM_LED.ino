void showLightCont(){                                 //Continuous Green to Red
  light=map(sRPM, 0,11000, 0,19);
  FastLED.clear();
  for (int i=0; i<=light; i++){
  
  leds[i]=CRGB(13.42*light,255-(13.42*light),0);
  }
FastLED.show();
}



void showLightDis(){                                //Discrete Blue to Green to Red
  ledDur=millis();
  if (ledDur-ledOldDur<=100)
  red =255;
  else
  red =0;
  if(ledDur-ledOldDur>=200)
  ledOldDur=ledDur;
  
  light=map(sRPM, 0,11000, 0,19);
  FastLED.clear();
  if(sRPM>=0&&sRPM<=3500){
    for (int i=0; i<=light; i++){
        leds[i]=CRGB(0,0,255);
     }
  }
  if(sRPM>3500&&sRPM<=7000){
    for (int i=0; i<=6; i++){
        leds[i]=CRGB(0,0,255);
     }
    for (int i=7; i<=light; i++){
        leds[i]=CRGB(0,255,0);
     }
  }
  if(sRPM>7000&&sRPM<=9500){
    for (int i=0; i<=6; i++){
        leds[i]=CRGB(0,0,255);
     }
    for (int i=7; i<=12; i++){
        leds[i]=CRGB(0,255,0);
     }
    for (int i=13; i<=light; i++){
        leds[i]=CRGB(255,0,0);
     }
   }
  if(sRPM>9500){
    for (int i=0; i<=light; i++){
        leds[i]=CRGB(red,0,0);
     }
     
  }
  
FastLED.show();
}
