#include "PCF8575.h"
#include <Wire.h>
#include "Mux.h"

   
  GPIO signal_01_1(1, 2, 3, 4, 5, 6, 7);
  GPIO signal_01_2(8, 9, 10, 11, 12 ,13, 14);
  GPIO1 signal_01_3(1, 2, 3, 4, 5, 6, 7);
  GPIO1 signal_01_4(8, 9, 10, 11, 12 ,13, 14);    


const int g_common_pin = A0;
int offset_1[8] = {-2, 0, 2, 0, 0, -1, -1, 2}, offset_2[8] = {-3, 1, 1, 1, -1, -2, 0, 3};
int pin1,pin2,pin3,pin4,pin5,pin6,y,x,z,a,b,data;
int get__8__channel1(int pin1) {
  int x = pin1 % 8;
  if ((pin1 / 32) % 2) {
    return (x - offset_2[x]);
  } else {
    return (x - offset_1[x]);
  }
}
int get__8__channel2(int pin2) {
  int x = pin2 % 8;
  if ((pin2 / 32) % 2) {
    return (x - offset_2[x]);
  } else {
    return (x - offset_1[x]);
  }
}
int get__8__channel3(int pin3) {
  int x = pin3 % 8;
  if ((pin3 / 32) % 2) {
    return (x - offset_2[x]);
  } else {
    return (x - offset_1[x]);
  }
}
int get__8__channel4(int pin4) {
  int x = pin4 % 8;
  if ((pin4 / 32) % 2) {
    return (x - offset_2[x]);
  } else {
    return (x - offset_1[x]);
  }
}
  int get__16__channel1(int pin1) {
  return (pin1 / 8);
}
int get__16__channel2(int pin2) {
  return (pin2 / 8);
}
 int get__16__channel3(int pin3) {
  return (pin3 / 8);
}
int get__16__channel4(int pin4) {
  return (pin4 / 8);
}

int get__128__channel1(int pin1) {
  return (get__8__channel1(pin1) << 4) | (get__16__channel1(pin1));
  }
int get__128__channel2(int pin2) {
  return (get__8__channel2(pin2) << 4) | (get__16__channel2(pin2));
  }
int get__128__channel3(int pin3) {
  return (get__8__channel3(pin3) << 4) | (get__16__channel3(pin3));
  }
int get__128__channel4(int pin4) {
  return (get__8__channel4(pin4) << 4) | (get__16__channel4(pin4));
  }

//const int mux1;
void setup() {
  PCF8575 pcf8575[] = {
                   0x20, 0x21, 0x22, 0x23,
                   0x24, 0x25, 0x26, 0x27
                  };
   
  pcf8575[0].begin();
  pcf8575[1].begin();
  
   
                 
                 
                 
  
 }

void loop() {
   pin1=124; 
   pin2=125;
   pin3=126; 
   pin4=127;
   signal_01_1.channel(get__128__channel1(pin1));
   signal_01_2.channel(get__128__channel2(pin2));
   signal_01_3.channel2(get__128__channel3(pin3));
   signal_01_4.channel2(get__128__channel4(pin4));
  
 
   
    }
 

  
