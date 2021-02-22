// Source: https://leetcode.com/problems/student-attendance-record-i/
// Author: Miao Zhang
// Date:   2021-02-21

class Solution {
public:
    bool checkRecord(string s) {
        return !std::regex_search(s, std::regex("A.*A|LLL"));
    }
};
