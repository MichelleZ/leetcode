// Source: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Author: Miao Zhang
// Date:   2021-03-06

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return letters[l % letters.size()];
    }
};
