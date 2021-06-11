// Source: https://leetcode.com/problems/seat-reservation-manager/
// Author: Miao Zhang
// Date:   2021-06-11

class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
    }

    int reserve() {
        int res = q.top();
        q.pop();
        return res;
    }

    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }

private:
    priority_queue<int, vector<int>, greater<int>> q;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
