#ifndef DATE_H
#define DATE_H
enum Month{
    Jan,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
};
struct Date{
    int day;
    int month;
    int year;
    Date(int d,int m,int y):day{d},month{m},year{y}{};
};
#endif