// Source: https://leetcode.com/problems/course-schedule-iii/
// Author: Miao Zhang
// Date:   2021-02-25

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(begin(courses), end(courses), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        priority_queue<int> q; //big heap
        int d = 0;
        for (auto& c: courses) {
            if (d + c[0] <= c[1]) {
                d += c[0];
                q.push(c[0]);
            } else if(q.size() && q.top() > c[0]) {
                d += c[0] - q.top();
                q.pop();
                q.push(c[0]);
            }
        }
        return q.size();
    }
};
