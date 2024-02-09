/**
 *        @file: 10-21-22 clock class
 *      @author: Drew VanAtta
 *        @date: October 21, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


class Clock
{
public:
    Clock();

    int get_hour() const { return hour; }
    int get_minute() const { return minute; }

    void set_time(int h, int m);
    void advance(int amt = 1);
    void output() const { cout << hour << ":" << setw(2) << setfill('0') << minute << endl; }

    bool is_equal(const Clock& other) {return hour == other.hour && minute == other.minute;}

protected: //so that we can access hour and minute in our Alarm class
    int hour;
    int minute;
};


class Alarm:public Clock //if {} empty, it would be an exact copy of clock. includes the clock class
{
    public:
    Alarm();

    void set_alarm(int ah, int am);
    bool is_ringing() const{return hour == alarm_h && minute == alarm_m;} //able to do this because PROTECTED rather than PRIVATE

    void output() const {Clock::output(); cout << alarm_h << ":" << setw(2) << setfill('0') << alarm_m << endl; }
    bool is_equal(const Alarm& other) {return Clock::is_equal(other) && alarm_h == other.alarm_h && alarm_m == other.alarm_m;}


    private:
        int alarm_h;
        int alarm_m;
};