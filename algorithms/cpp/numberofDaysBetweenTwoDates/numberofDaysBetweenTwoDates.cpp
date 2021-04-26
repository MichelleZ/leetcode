// Source: https://leetcode.com/problems/number-of-days-between-two-dates/
// Author: Miao Zhang
// Date:   2021-04-26

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        vector<int> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        auto isLeap = [] (int year) {
            return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        };
        auto dateToInt = [&] (const string& date) {
            int year = stoi(date.substr(0, 4));
            int month = stoi(date.substr(5, 2));
            int day = stoi(date.substr(8, 2));
            for (int i = 1971; i < year; i++) {
                day += 365 + isLeap(i);
            }
            for (int i = 1; i < month; i++) {
                day += months[i - 1];
            }
            day += month > 2 && isLeap(year);
            return day;
        };
        return abs(dateToInt(date1) - dateToInt(date2));
    }
};
