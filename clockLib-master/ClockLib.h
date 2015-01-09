
#ifndef _CLOCKLIB_H_
#define _CLOCKLIB_H_

#include <Arduino.h>

class Clock
{
public:
    void setTime(int h, int m, int s);
    int getSec();
    int getMin();
    int getHour();
};


#endif // _CLOCKLIB_H_
