#include "MyTime.h"
#include <iostream>

MyTime::MyTime()
{
    hour = 0; min = 0; sec = 0;
}

MyTime::MyTime(int _hour, int _min, int _sec)
{
    hour = _hour;
    min = _min;
    sec = _sec;
}

void MyTime::info()
{
    std::cout << "(" << hour << ":" << min << ":" << sec << ")\n";
}

MyTime MyTime::add(int _sec)
{
    MyTime result;
    int totalSec = hour*60*60 + min*60 + sec + _sec;
    result.sec = totalSec % 60;
    result.min = totalSec/60 % 60;
    result.hour = totalSec/60/60;
    return result;
}


MyTime MyTime::subtract(int _sec)
{
    MyTime result;
    int totalSec = hour*60*60 + min*60 + sec - _sec;
    result.sec = totalSec % 60;
    result.min = totalSec/60 % 60;
    result.hour = totalSec/60/60;
    return result;
}

MyTime MyTime::add(MyTime other)
{
    MyTime result;
    int totalSec = hour*60*60 + min*60 + sec + other.hour*60*60 + other.min*60 + other.sec;
    result.sec = totalSec % 60;
    result.min = totalSec/60 % 60;
    result.hour = totalSec/60/60;
    return result;
}

MyTime MyTime::subtract(MyTime other)
{
    MyTime result;
    int totalSec = hour*60*60 + min*60 + sec - (other.hour*60*60 + other.min*60 + other.sec);
    result.sec = totalSec % 60;
    result.min = totalSec/60 % 60;
    result.hour = totalSec/60/60;
    return result;
}