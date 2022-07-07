/*-
 * Project: arduino-ad-mux-lib
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 *
 * Copyright (c) 2018-2020 Stefano Chizzolini (arduino-ad-mux-lib)
 * Copyright (c) 2014 Nick Lamprianidis (MUX74HC4067)
 *
 * License:
 *    This library is licensed under the MIT license
 *    http://www.opensource.org/licenses/mit-license.php
 */

#ifndef GPIO_MUX_H
#define GPIO_MUX_H


  #include "Arduino.h"
  #include "pcf8575.h"

extern int _g_channel_truth_table1[128][7];

class GPIO
{
  public:
    GPIO(byte s0, int s1, int s2, int s3, int s4, int s5, int s6);
    void channel(int channel);
  private:
    int _s0;
    int _s1;
    int _s2;
    int _s3;
    int _s4;
    int _s5;
    int _s6;
    int _channel;
};
class GPIO1
{
  public:
    GPIO1(byte s0, int s1, int s2, int s3, int s4, int s5, int s6);
    int channel2(int channel2);
  private:
    int _s0;
    int _s1;
    int _s2;
    int _s3;
    int _s4;
    int _s5;
    int _s6;
    int _channel;
};


#endif // GPIO_MUX_H
