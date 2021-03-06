#include "Mux.h"
#include "PCF8575.h"
#include "Wire.h"
 
PCF8575 pcf8575[] = {
                   0x20, 0x21, 0x22, 0x23,
                   0x24, 0x25, 0x26, 0x27
                  };


#include "Arduino.h"


int _g_channel_truth_table1[128][7] = {
  // s0, s1, s2, s3, s4, s5, s6     channel
  // 1,  2,  4,  8,  16, 32, 64 
    {0,  0,  0,  0,  0,  0,  0}, // 0
    {1,  0,  0,  0,  0,  0,  0 }, // 1
    {0,  1,  0,  0,  0,  0,  0}, // 2
    {1,  1,  0,  0,  0,  0,  0}, // 3
    {0,  0,  1,  0,  0,  0,  0}, // 4
    {1,  0,  1,  0,  0,  0,  0}, // 5
    {0,  1,  1,  0,  0,  0,  0}, // 6
    {1,  1,  1,  0,  0,  0,  0}, // 7
    {0,  0,  0,  1,  0,  0,  0}, // 8
    {1,  0,  0,  1,  0,  0,  0}, // 9
    {0,  1,  0,  1,  0,  0,  0}, // 10
    {1,  1,  0,  1,  0,  0,  0}, // 11
    {0,  0,  1,  1,  0,  0,  0}, // 12
    {1,  0,  1,  1,  0,  0,  0}, // 13
    {0,  1,  1,  1,  0,  0,  0}, // 14
    {1,  1,  1,  1,  0,  0,  0},  // 15
    {0,  0,  0,  0,  1,  0,  0}, // 16
    {1,  0,  0,  0,  1,  0,  0 }, // 17
    {0,  1,  0,  0,  1,  0,  0}, // 18
    {1,  1,  0,  0,  1,  0,  0}, // 19
    {0,  0,  1,  0,  1,  0,  0}, // 20
    {1,  0,  1,  0,  1,  0,  0}, // 21
    {0,  1,  1,  0,  1,  0,  0}, // 22
    {1,  1,  1,  0,  1,  0,  0}, // 23
    {0,  0,  0,  1,  1,  0,  0}, // 24
    {1,  0,  0,  1,  1,  0,  0}, // 25
    {0,  1,  0,  1,  1,  0,  0}, // 26
    {1,  1,  0,  1,  1,  0,  0}, // 27
    {0,  0,  1,  1,  1,  0,  0}, // 28
    {1,  0,  1,  1,  1,  0,  0}, // 29
    {0,  1,  1,  1,  1,  0,  0}, // 30
    {1,  1,  1,  1,  1,  0,  0},  // 31
    {0,  0,  0,  0,  0,  1,  0}, //32
    {1,  0,  0,  0,  0,  1,  0 }, //33
    {0,  1,  0,  0,  0,  1,  0}, // 34
    {1,  1,  0,  0,  0,  1,  0}, // 35
    {0,  0,  1,  0,  0,  1,  0}, // 36
    {1,  0,  1,  0,  0,  1,  0}, // 37
    {0,  1,  1,  0,  0,  1,  0}, // 38
    {1,  1,  1,  0,  0,  1,  0}, // 39
    {0,  0,  0,  1,  0,  1,  0}, // 40
    {1,  0,  0,  1,  0,  1,  0}, // 41
    {0,  1,  0,  1,  0,  1,  0}, // 42
    {1,  1,  0,  1,  0,  1,  0}, // 43
    {0,  0,  1,  1,  0,  1,  0}, // 44
    {1,  0,  1,  1,  0,  1,  0}, // 45
    {0,  1,  1,  1,  0,  1,  0}, // 46
    {1,  1,  1,  1,  0,  1,  0},  // 47
    {0,  0,  0,  0,  1,  1,  0}, // 48
    {1,  0,  0,  0,  1,  1,  0 }, // 49
    {0,  1,  0,  0,  1,  1,  0}, // 50
    {1,  1,  0,  0,  1,  1,  0}, // 51
    {0,  0,  1,  0,  1,  1,  0}, // 52
    {1,  0,  1,  0,  1,  1,  0}, // 53
    {0,  1,  1,  0,  1,  1,  0}, // 54
    {1,  1,  1,  0,  1,  1,  0}, // 55
    {0,  0,  0,  1,  1,  1,  0}, // 56
    {1,  0,  0,  1,  1,  1,  0}, // 57
    {0,  1,  0,  1,  1,  1,  0}, // 58
    {1,  1,  0,  1,  1,  1,  0}, // 59
    {0,  0,  1,  1,  1,  1,  0}, // 60
    {1,  0,  1,  1,  1,  1,  0}, // 61
    {0,  1,  1,  1,  1,  1,  0}, // 62
    {1,  1,  1,  1,  1,  1,  0},  // 63
    {0,  0,  0,  0,  0,  0,  1}, // 64
    {1,  0,  0,  0,  0,  0,  1 }, // 65
    {0,  1,  0,  0,  0,  0,  1}, // 66
    {1,  1,  0,  0,  0,  0,  1}, // 67
    {0,  0,  1,  0,  0,  0,  1}, // 68
    {1,  0,  1,  0,  0,  0,  1}, // 69
    {0,  1,  1,  0,  0,  0,  1}, // 70
    {1,  1,  1,  0,  0,  0,  1}, // 71
    {0,  0,  0,  1,  0,  0,  1}, // 72
    {1,  0,  0,  1,  0,  0,  1}, // 73
    {0,  1,  0,  1,  0,  0,  1}, // 74
    {1,  1,  0,  1,  0,  0,  1}, // 75
    {0,  0,  1,  1,  0,  0,  1}, // 76
    {1,  0,  1,  1,  0,  0,  1}, // 77
    {0,  1,  1,  1,  0,  0,  1}, // 78
    {1,  1,  1,  1,  0,  0,  1},  // 79
    {0,  0,  0,  0,  1,  0,  1}, // 80
    {1,  0,  0,  0,  1,  0,  1 }, // 81
    {0,  1,  0,  0,  1,  0,  1}, // 82
    {1,  1,  0,  0,  1,  0,  1}, // 83
    {0,  0,  1,  0,  1,  0,  1}, // 84
    {1,  0,  1,  0,  1,  0,  1}, // 85
    {0,  1,  1,  0,  1,  0,  1}, // 86
    {1,  1,  1,  0,  1,  0,  1}, // 87
    {0,  0,  0,  1,  1,  0,  1}, // 88
    {1,  0,  0,  1,  1,  0,  1}, // 89
    {0,  1,  0,  1,  1,  0,  1}, // 90
    {1,  1,  0,  1,  1,  0,  1}, // 91
    {0,  0,  1,  1,  1,  0,  1}, // 92
    {1,  0,  1,  1,  1,  0,  1}, // 93
    {0,  1,  1,  1,  1,  0,  1}, // 94
    {1,  1,  1,  1,  1,  0,  1},  // 95
    {0,  0,  0,  0,  0,  1,  1}, // 96
    {1,  0,  0,  0,  0,  1,  1 }, // 97
    {0,  1,  0,  0,  0,  1,  1}, // 98
    {1,  1,  0,  0,  0,  1,  1}, // 99
    {0,  0,  1,  0,  0,  1,  1}, // 100
    {1,  0,  1,  0,  0,  1,  1}, // 101
    {0,  1,  1,  0,  0,  1,  1}, // 102
    {1,  1,  1,  0,  0,  1,  1}, // 103
    {0,  0,  0,  1,  0,  1,  1}, // 104
    {1,  0,  0,  1,  0,  1,  1}, // 105
    {0,  1,  0,  1,  0,  1,  1}, // 106
    {1,  1,  0,  1,  0,  1,  1}, // 107
    {0,  0,  1,  1,  0,  1,  1}, // 108
    {1,  0,  1,  1,  0,  1,  1}, // 109
    {0,  1,  1,  1,  0,  1,  1}, // 110
    {1,  1,  1,  1,  0,  1,  1},  // 111
    {0,  0,  0,  0,  1,  1,  1}, // 112
    {1,  0,  0,  0,  1,  1,  1 }, // 113
    {0,  1,  0,  0,  1,  1,  1}, // 114
    {1,  1,  0,  0,  1,  1,  1}, // 115
    {0,  0,  1,  0,  1,  1,  1}, // 116
    {1,  0,  1,  0,  1,  1,  1}, // 117
    {0,  1,  1,  0,  1,  1,  1}, // 118
    {1,  1,  1,  0,  1,  1,  1}, // 119
    {0,  0,  0,  1,  1,  1,  1}, // 120
    {1,  0,  0,  1,  1,  1,  1}, // 121
    {0,  1,  0,  1,  1,  1,  1}, // 122
    {1,  1,  0,  1,  1,  1,  1}, // 123
    {0,  0,  1,  1,  1,  1,  1}, // 124
    {1,  0,  1,  1,  1,  1,  1}, // 125
    {0,  1,  1,  1,  1,  1,  1}, // 126
    {1,  1,  1,  1,  1,  1,  1},  // 127

};

GPIO::GPIO(byte s0, int s1, int s2, int s3, int s4, int s5, int s6)
{
 
  pcf8575[0].pinMode(s0, OUTPUT);
  pcf8575[0].pinMode(s1, OUTPUT);
  pcf8575[0].pinMode(s2, OUTPUT);
  pcf8575[0].pinMode(s3, OUTPUT);
  pcf8575[0].pinMode(s4, OUTPUT);
  pcf8575[0].pinMode(s5, OUTPUT);
  pcf8575[0].pinMode(s6, OUTPUT);
  
  _s0 = s0;
  _s1 = s1;
  _s2 = s2;
  _s3 = s3;
  _s4 = s4;
  _s5 = s5;
  _s6 = s6;
 
}
GPIO1::GPIO1(byte s0, int s1, int s2, int s3, int s4, int s5, int s6)
{
  pcf8575[1].pinMode(s0, OUTPUT);
  pcf8575[1].pinMode(s1, OUTPUT);
  pcf8575[1].pinMode(s2, OUTPUT);
  pcf8575[1].pinMode(s3, OUTPUT);
  pcf8575[1].pinMode(s4, OUTPUT);
  pcf8575[1].pinMode(s5, OUTPUT);
  pcf8575[1].pinMode(s6, OUTPUT);
  _s0 = s0;
  _s1 = s1;
  _s2 = s2;
  _s3 = s3;
  _s4 = s4;
  _s5 = s5;
  _s6 = s6;
}
void GPIO::channel(int channel)
{
   pcf8575[0].digitalWrite(_s0, _g_channel_truth_table1[channel][0]);
   pcf8575[0].digitalWrite(_s1, _g_channel_truth_table1[channel][1]);
   pcf8575[0].digitalWrite(_s2, _g_channel_truth_table1[channel][2]);
   pcf8575[0].digitalWrite(_s3, _g_channel_truth_table1[channel][3]);
   pcf8575[0].digitalWrite(_s4, _g_channel_truth_table1[channel][4]);
   pcf8575[0].digitalWrite(_s5, _g_channel_truth_table1[channel][5]);
   pcf8575[0].digitalWrite(_s6, _g_channel_truth_table1[channel][6]);
   
 }
int  GPIO1::channel2(int channel2)
{  
   pcf8575[1].digitalWrite(_s0, _g_channel_truth_table1[channel2][0]);
   pcf8575[1].digitalWrite(_s1, _g_channel_truth_table1[channel2][1]);
   pcf8575[1].digitalWrite(_s2, _g_channel_truth_table1[channel2][2]);
   pcf8575[1].digitalWrite(_s3, _g_channel_truth_table1[channel2][3]);
   pcf8575[1].digitalWrite(_s4, _g_channel_truth_table1[channel2][4]);
   pcf8575[1].digitalWrite(_s5, _g_channel_truth_table1[channel2][5]);
   pcf8575[1].digitalWrite(_s6, _g_channel_truth_table1[channel2][6]);
   
 }
 
