#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.length();
        string minval(s);
        string maxval(s);
        int i = 0;
        int j = 0;
        while (i < n && (s[i] == '0' || s[i] == '1')) i++;
        while (j < n && s[j] == '9') j++;
        for (char& c: minval) {
            if (c == s[i])
                c = i ? '0' : '1';
        }
        for (char& c: maxval) {
            if (c == s[j]) {
                c = '9';
            }
        }
        return stoi(maxval) - stoi(minval);
    }
};
