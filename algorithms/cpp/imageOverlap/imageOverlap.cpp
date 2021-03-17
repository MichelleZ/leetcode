// Source: https://leetcode.com/problems/image-overlap/
// Author: Miao Zhang
// Date:   2021-03-16

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int res = 0;
        int n = img1.size();
        vector<int> imga, imgb;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n * n; i++) {
            if (img1[i / n][i % n]) imga.push_back(i / n * 100 + i % n);
            if (img2[i / n][i % n]) imgb.push_back(i / n * 100 + i % n);
        }
        for (int x: imga) {
            for (int y: imgb) {
                cnt[x - y]++;
            }
        }
        for (auto& kv: cnt) {
            res = max(res, kv.second);
        }
        return res;
    }
};
