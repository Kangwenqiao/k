//小蓝每天都锻炼身体。

//正常情况下，小蓝每天跑 11 千米。如果某天是周一或者月初（11 日），为了激励自己，小蓝要跑 22 千米。如果同时是周一或月初，小蓝也是跑 22 千米。

//小蓝跑步已经坚持了很长时间，从 20002000 年 11 月 11 日周六（含）到 20202020 年 1010 月 11 日周四（含）。请问这段时间小蓝总共跑步多少千米？
#include <iostream>
using namespace std;
int main()
{
    int weekflag = 6, dayflag = 1, monthflag = 1, yearflag = 1; int day=1;
    int sumday = 7580;//日期总共天数
    int mile = 0, flag = 0;
    for (yearflag = 2000; yearflag <= 2020; yearflag++)
    {
        for (monthflag = 1; monthflag <= 12; monthflag++)
        {
            for (dayflag = 1; dayflag <= 31; dayflag++)
            {
                if (day >= sumday) break;
                if (weekflag > 7) weekflag = 1;
                if (monthflag == 2 && yearflag % 4 == 0)//闰年
                {
                    if (dayflag == 30) { flag = 1; continue; }
                }
                else if (monthflag == 2 && yearflag % 4 != 0)//平年
                {
                    if (dayflag == 29) { flag = 1; continue; }
                }
                if (monthflag <= 7 && monthflag % 2 == 0)//七月以前的小月
                {
                    if (dayflag == 31) continue;
                }
                else if (monthflag <= 12 && monthflag % 2 == 1)//七月以后的小月
                {
                    if (dayflag == 31) continue;
                }
                if (weekflag == 1 || dayflag == 1) mile++;//只考虑跑2公里天数
                weekflag++;
                day++;
                
            }
        }
    }


    cout << sumday + mile;//两公里天数与总天数相加就是总公里数
    return 0;
}
