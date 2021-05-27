// Source: https://leetcode.com/problems/minimize-deviation-in-array/
// Author: Miao Zhang
// Date:   2021-05-27

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int low = INT_MAX;
        for (int num: nums) {
            num = num & 1 ? num * 2: num;
            q.push(num);
            low = min(low, num);
        }
        int res = q.top() - low;
        while (q.top() % 2 == 0) {
            int x = q.top(); q.pop();
            q.push(x / 2);
            low = min(low, x / 2);
            res = min(res, q.top() - low);
        }
        return res;
    }
};
