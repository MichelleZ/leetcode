// Source: https://leetcode.com/problems/my-calendar-i/
// Author: Miao Zhang
// Date:   2021-03-04

class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto it = booked_.lower_bound(start);
        if (it != booked_.cend() && it->first < end) {
            return false;
        }
        if (it != booked_.cbegin() && (--it)->second > start) {
            return false;
        }
        booked_[start] = end;
        return true;
    }

private:
    map<int, int> booked_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
