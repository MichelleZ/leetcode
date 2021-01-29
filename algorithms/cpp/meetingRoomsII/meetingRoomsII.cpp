// Source: https://leetcode.com/problems/meeting-rooms-ii/
// Author: Miao Zhang
// Date:   2021-01-28

/********************************************************
 * create map, if start time, map += 1;
 * if end time, map -= 1
 * from small to big traverse, get max value
********************************************************/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto a : intervals) {
            ++m[a[0]];
            --m[a[1]];
        }
        int rooms = 0, res = 0;
        for (auto it : m) {
            res = max(res, rooms += it.second);
        }
        return res;
    }
};

/*********************************************************
 * sort according to start time
 * small top heap
 * put end time to heap, if cur heap min val < new start time, pop()
*********************************************************/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto interval : intervals) {
            if (!q.empty() && q.top() <= interval[0]) q.pop();
            q.push(interval[1]);
        }
        return q.size();
    }
};
