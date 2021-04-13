// Source: https://leetcode.com/problems/day-of-the-year/
// Author: Miao Zhang
// Date:   2021-04-13

class Solution {
public:
    int dayOfYear(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8));
        int res = 0;
        for (int i = 0; i < m - 1; i++) {
            res += days[i];
        }
        res += d;
        if (leap(y) && m > 2) res += 1;
        return res;
    }
    
private:
    vector<int> days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    bool leap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
};
