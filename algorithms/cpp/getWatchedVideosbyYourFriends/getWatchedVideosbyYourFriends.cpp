// Source: https://leetcode.com/problems/get-watched-videos-by-your-friends/
// Author: Miao Zhang
// Date:   2021-04-23

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<int> visited(n);
        queue<int> q;
        q.push(id);
        visited[id] = 1;
        while (level--) {
            int size = q.size();
            while (size--) {
                int u = q.front();
                q.pop();
                for (auto& v: friends[u]) {
                    if (visited[v]) continue;
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        unordered_map<string, int> cnt;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& w: watchedVideos[u]) {
                cnt[w]++;
            }
        }
        vector<pair<string, int>> videos(cnt.begin(), cnt.end());
        sort(begin(videos), end(videos), [] (const pair<string, int>& v1, const pair<string, int>& v2) {
            return v1.second == v2.second ? v1.first < v2.first : v1.second < v2.second ;
        });
        vector<string> res;
        for (auto& v: videos) {
            res.push_back(v.first);
        }
        return res;
    }
};
