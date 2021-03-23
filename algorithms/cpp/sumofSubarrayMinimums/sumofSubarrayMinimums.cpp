// Source: https://leetcode.com/problems/sum-of-subarray-minimums/
// Author: Miao Zhang
// Date:   2021-03-23

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int kMod = 1e9 + 7;
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left = 0;
            for (int j = i - 1; j >= 0 && arr[j] > arr[i]; j--, left++);
            int right = 0;
            for (int j = i + 1; j < arr.size() && arr[j] >= arr[i]; j++, right++);
            res = (res + static_cast<long>(arr[i]) * (left + 1) * (right + 1)) % kMod;
        }
        return res;
    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int kMod = 1e9 + 7;
        stack<pair<int, int>> st;
        int res = 0;
        int dot = 0;
        for (int j = 0; j < arr.size(); j++) {
            int cnt = 1;
            while (!st.empty() && st.top().first >= arr[j]) {
                auto p = st.top();
                st.pop();
                int val = p.first;
                int c = p.second;
                cnt += c;
                dot -= val * c;
            }
            st.push({arr[j], cnt});
            dot += arr[j] * cnt;
            res += dot;
            res %= kMod;
        }
        return res % kMod;
    }
};
