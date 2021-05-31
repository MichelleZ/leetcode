// Source: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
// Author: Miao Zhang
// Date:   2021-05-31

class Trie {
public:
    Trie(): children{nullptr, nullptr} {}
    Trie* children[2];
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            queries[i].push_back(i);
        }
        sort(begin(queries), end(queries), [] (const auto& q1, const auto& q2) {
            return q1[1] < q2[1];
        });
        Trie root;

        auto insert = [&] (int num) {
            Trie* node = &root;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (!node->children[bit]) {
                    node->children[bit] = new Trie();
                }
                node = node->children[bit];
            }
        };

        auto query = [&] (int num) {
            Trie* node = &root;
            int sums = 0;
            for (int i = 31; i >= 0; i--) {
                if (!node) return -1;
                int bit = (num >> i) & 1;
                if (node->children[1 - bit]) {
                    sums |= (1 << i);
                    node = node->children[1 - bit];
                } else {
                    node = node->children[bit];
                }
            }
            return sums;
        };

        vector<int> res(m);
        int i = 0;
        for (auto& q: queries) {
            while (i < n && nums[i] <= q[1])
                insert(nums[i++]);
            res[q[2]] = query(q[0]);
        }
        return res;
    }
};
