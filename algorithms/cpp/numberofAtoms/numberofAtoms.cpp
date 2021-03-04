// Source: https://leetcode.com/problems/number-of-atoms/
// Author: Miao Zhang
// Date:   2021-03-04

class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0;
        string res;
        for (const auto& kv: countOfAtoms(formula, i)) {
            res += kv.first;
            if (kv.second > 1) res += std::to_string(kv.second);
        }
        return res;
    }

private:
    map<string, int> countOfAtoms(const string& formula, int& i) {
        map<string, int> counts;
        while (i != formula.length()) {
            if (formula[i] == '(') {
                const auto& tmp_counts = countOfAtoms(formula, ++i);
                int count = getCount(formula, i);
                for (const auto& kv: tmp_counts) {
                    counts[kv.first] += kv.second * count;
                }
            } else if (formula[i] == ')') {
                i++;
                return counts;
            } else {
                const string& name = getName(formula, i);
                counts[name] += getCount(formula, i);
            }
        }
        return counts;
    }

    string getName(const string& formula, int& i) {
        string name;
        while (isalpha(formula[i]) &&
               (name.empty() || islower(formula[i]))) {
            name += formula[i++];
        }
        return name;
    }

    int getCount(const string& formula, int& i) {
        string cnt_str;
        while (isdigit(formula[i])) cnt_str += formula[i++];
        return cnt_str.empty() ? 1 : std::stoi(cnt_str);
    }
};
