// Source: https://leetcode.com/problems/random-pick-with-blacklist/
// Author: Miao Zhang
// Date:   2021-03-03

class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        unordered_set<int> st;
        int blen = 0;
        if (!blacklist.empty()) {
            blen = blacklist.size();
        }
        wlen = N - blen;
        cout << wlen << endl;
        for (int i = wlen; i < N; i++) {
            st.insert(i);
        }
        for (int n: blacklist) st.erase(n);
        auto it = st.begin();
        for (int n: blacklist) {
            if (n < wlen) m[n] = *it++;
        }
    }

    int pick() {
        int k = rand() % wlen;
        return m.count(k) ? m[k] : k;
    }
private:
    unordered_map<int, int> m;
    int wlen;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
