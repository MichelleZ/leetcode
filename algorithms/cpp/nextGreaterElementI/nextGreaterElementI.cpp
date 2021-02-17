// Source: https://leetcode.com/problems/next-greater-element-i/
// Author: Miao Zhang
// Date:   2021-02-17

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> dic;
        for (int n: nums2) {
            while (!st.empty() && n > st.top()) {
                dic[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        vector<int> res;
        for (int n: nums1) {
            res.push_back(dic.count(n) ? dic[n] : -1);
        }
        return res;
    }
};
