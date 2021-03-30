#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
int months[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

struct Timer
{
    int year, month, day, hour, minute, week;
    Timer(string str)
    {
        sscanf(str.c_str(), "%04d%02d%02d%02d%02d", &year, &month, &day, &hour, &minute);
    }
    bool operator< (const Timer& t) const
    {
        if (year != t.year) return year < t.year;
        if (month != t.month) return month < t.month;
        if (day != t.day) return day < t.day;
        if (hour != t.hour) return hour < t.hour;
        return minute < t.minute;
    }
    int is_leap()
    {
        if (year % 4 == 0 && year % 100 || year % 400 == 0)
            return 1;
        return 0;
    }
    int get_days()
    {
        if (month == 2) return months[2] + is_leap();
        return months[month];
    }
    void next()
    {
        if ( ++ minute == 60)
        {
            minute = 0;
            if ( ++ hour == 24)
            {
                hour = 0;
                week = (week + 1) % 7;
                if ( ++ day > get_days())
                {
                    day = 1;
                    if ( ++ month > 12)
                    {
                        month = 1;
                        year ++ ;
                    }
                }
            }
        }
    }
    string to_string()
    {
        char str[20];
        sprintf(str, "%04d%02d%02d%02d%02d", year, month, day, hour, minute);
        return str;
    }
};

struct Task {
    bool minutes[60], hours[24], day_of_month[32], month[13], day_of_week[7];
    string name;
    bool check(Timer& t) {
        return minutes[t.minute] && hours[t.hour] && day_of_month[t.day] &&
            month[t.month] && day_of_week[t.week];
    }
}task[20];

