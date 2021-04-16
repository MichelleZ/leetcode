// Source: https://leetcode.com/problems/day-of-the-week/
// Author: Miao Zhang
// Date:   2021-04-16

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> names = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> days = {31, 28 + leapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sums = 0;
        for (int i = 1970; i < year; i++) {
            sums += 365 + leapYear(i);
        }
        for (int i = 1; i < month; i++) {
            sums += days[i - 1];
        }
        sums += day;
        return names[(sums + 3) % 7];
    }

private:
    bool leapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
};
