// Source: https://leetcode.com/problems/my-calendar-ii/
// Author: Miao Zhang
// Date:   2021-03-04

class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        delta[start]++;
        delta[end]--;
        int cnt = 0;
        for (auto kv: delta) {
            cnt += kv.second;
            if (cnt == 3) {
                delta[start]--;
                delta[end]++;
                return false;
            }
            if (kv.first > end) break;
        }
        return true;
    }

private:
    map<int, int> delta;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
