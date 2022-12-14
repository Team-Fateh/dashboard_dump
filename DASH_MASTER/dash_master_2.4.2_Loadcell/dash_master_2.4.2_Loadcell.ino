#include<CAN.h>
#include <FastLED.h>
#include <SD.h>
#include <SPI.h>
#include "HX711.h"

#define LOADCELL_DOUT_PIN  18  //Loadcell pins
#define LOADCELL_SCK_PIN  19
#define crank_pin 28          //crank pins
#define kill_pin 26
#define undefined_pin 24
#define cs_sd    53         //sd
#define cs 10             //CAN
#define in 2
#define clockFreq 8E6
#define canFreq   500E3
#define gear_pin 21       //gear
#define LED_PIN     7    //LED
#define NUM_LEDS    19

#define SPEED_PIN   3     //speed
#define wheelRadius  0.117
#define spokeangle  60

HX711 scale;            //Loadcell
float load_cell_val = 0;
float calibration_factor = -13400; //-7050 worked for my 440lb max scale setup
File sdcard_file;             //sd
unsigned long RPM = 0;        //CAN
float TEMP = 0 , VOLT = 0 ;
unsigned long can_check_time = 2000, last_can_check_time = 0;
int can_available = 0;// toggled in can green and can red
int gear;                     //gear
long dur;
CRGB leds[NUM_LEDS];          //LED
int light=0;
int ledDur,ledOldDur,red;//
 char comm;


  float value=0,srev=0;                //Speed
long unsigned int srpm,oldtime=0,tim,wheelSpeed;
long unsigned int newStime,Stime,oldStime;


void setup(){
  loadcellInit();
  xbeeInit();
    Serial.begin(9600);
    Serial3.begin(9600);

    engineSetup();                //Engine
    sdInit();                     //sd
    canSetup(cs,in,canFreq,clockFreq);        //CAN
    pinMode(gear_pin,INPUT);                  //gear
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);//LED

    attachInterrupt(digitalPinToInterrupt(SPEED_PIN),speedISR2,RISING);
}
    
void loop(){
  loadcellCheck();
   xbeeCheck();               //xbee
   xbeeDataSend();
   
   dur= pulseIn(21,HIGH);     //gear
    hmiGear();
   
   sdData();
   getCAN(&RPM,&TEMP,&VOLT);    //CAN
    hmiCAN();   
    
   showLightDis();               //  //LED
//getSpeed2();
hmiSpeed();
// Serial.print(wheelSpeed);

canCheck();
}
