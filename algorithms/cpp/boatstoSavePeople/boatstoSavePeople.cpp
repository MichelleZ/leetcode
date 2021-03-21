// Source: https://leetcode.com/problems/boats-to-save-people/
// Author: Miao Zhang
// Date:   2021-03-21

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int i = 0;
        int j = people.size() - 1;
        int res = 0;
        while (i <= j) {
            res++;
            if (people[i] + people[j] <= limit) {
                i++;
            }
            j--;
        }
        return res;
    }
};
