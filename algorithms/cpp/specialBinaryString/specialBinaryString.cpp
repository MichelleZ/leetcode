// Source: https://leetcode.com/problems/special-binary-string/
// Author: Miao Zhang
// Date:   2021-03-08

class Solution {
public:
    string makeLargestSpecial(string S) {
        int cnt = 0, i = 0;
        vector<string> v;
        for (int j = 0; j < S.size(); j++) {
            cnt += (S[j] == '1') ? 1 : -1;
            if (cnt == 0) {
                v.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(v.begin(), v.end(), greater<string>());
        string res = "";
        for (int i = 0; i < v.size(); i++)  res += v[i];
        return res;
    }
};
