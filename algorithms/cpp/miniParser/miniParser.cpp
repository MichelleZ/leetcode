// Source: https://leetcode.com/problems/mini-parser/
// Author: Miao Zhang
// Date:   2021-02-06

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        return getNestedInteger(s);
    }

private:
    NestedInteger getNestedInteger(string s) {
        if (s.size() > 0 && s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        s = s.substr(1, s.size() - 2);
        NestedInteger res;
        int start = 0;
        int leftBrackets = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ',') {
                if (leftBrackets != 0) {
                    continue;
                }
                res.add(getNestedInteger(s.substr(start, i - start)));
                start = i + 1;
            }
            if (s[i] == '[') {
                leftBrackets++;
            }
            if (s[i] == ']') {
                leftBrackets--;
            }
        }
        if (start < s.size()) {
            res.add(getNestedInteger(s.substr(start, s.size() - start)));
        }
        return res;
    }
};
