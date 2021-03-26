// Source: https://leetcode.com/problems/number-of-recent-calls/
// Author: Miao Zhang
// Date:   2021-03-26

class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        while (!q.empty() && t - q.front() > 3000) q.pop();
        q.push(t);
        return q.size();
    }

private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
