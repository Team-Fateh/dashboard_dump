
#include "FS.h"
#include "SD.h"
#include "SPI.h"


void setup(){
    Serial.begin(115200);
   // if(!SD.begin()){
    //    Serial.println("Card Mount Failed");
       // return 0 ;
    //}

    //if(cardType == CARD_NONE){
      //  Serial.println("No SD card attached");
        //return 0 ;
    //}

    // Serial.print("SD Card Type: ");
    // if(cardType == CARD_MMC){
    //     Serial.println("MMC");
    // } else if(cardType == CARD_SD){
    //     Serial.println("SDSC");
    // } else if(cardType == CARD_SDHC){
    //     Serial.println("SDHC");
    // } else {
    //     Serial.println("UNKNOWN");
    // }

    //uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    //Serial.printf("SD Card Size: %lluMB\n", cardSize);

   // listDir(SD, "/", 0);
    //createDir(SD, "/mydir");
    //listDir(SD, "/", 0);
    //removeDir(SD, "/mydir");
    //listDir(SD, "/", 2);
    writeFile(SD, "/hello.txt", "Val1,Val2,Val3,Val4,Gear");
    //appendFile(SD, "/hello.txt", "World!\n");
    readFile(SD, "/hello.txt");
    //deleteFile(SD, "/foo.txt");
    //renameFile(SD, "/hello.txt", "/foo.txt");
    //readFile(SD, "/foo.txt");
    //testFileIO(SD, "/test.txt");
    //Serial.printf("Total space: %lluMB\n", SD.totalBytes() / (1024 * 1024));
    //Serial.printf("Used space: %lluMB\n", SD.usedBytes() / (1024 * 1024));
}

void loop(){
  int a = millis();
  String b = ",1111,1111,1111,1111,N";
 String mystr = a+b;
  const char * input = mystr.c_str();
  appendFile(SD, "/hello.txt", "World!\n");


}
