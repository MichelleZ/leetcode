// Source: https://leetcode.com/problems/integer-to-english-words/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<int> nums;
        vector<string> res;
        vector<string> levels{"", "Thousand ", "Million ", "Billion "};
        while (num > 0) {
            nums.push_back(num % 1000);
            num /= 1000;
        }
        for (int i = 0; i < nums.size(); i++) {
            string cur = convert(nums[i]);
            if (nums[i] != 0) cur += levels[i];
            res.push_back(cur);
        }
        reverse(res.begin(), res.end());
        string ret;
        for (auto r: res) {
            ret += r;
        }
        return ret.erase(ret.find_last_not_of(" ") + 1);
    }
    
    string convert(int n) {
        vector<string> less_than_20{"Zero", "One ", "Two ", "Three ", 
                                    "Four ", "Five ", "Six ", "Seven ", 
                                    "Eight ", "Nine ", "Ten ", "Eleven ", 
                                    "Twelve ", "Thirteen ", "Fourteen ", 
                                    "Fifteen ", "Sixteen ", "Seventeen ", 
                                    "Eighteen ", "Nineteen "};
        vector<string> less_than_100{"Twenty ", "Thirty ", "Forty ", "Fifty ", 
                                      "Sixty ", "Seventy ", "Eighty ", "Ninety "};
        
        string cur = "";
        if (n == 0) return "";
        if (n < 20) cur += less_than_20[n];
        else if (n < 100) {
            cur += less_than_100[n / 10 - 2];
            cur += convert(n % 10);
        } else {
            cur += less_than_20[n / 100] + "Hundred ";
            cur += convert(n % 100);
        }
        return cur;
    }
};
