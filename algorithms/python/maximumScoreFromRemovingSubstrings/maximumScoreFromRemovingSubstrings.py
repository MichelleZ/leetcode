#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-score-from-removing-substrings/
# Author: Miao Zhang
# Date:   2021-05-31

class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        st1, st2 = [], []
        res = 0
        if x > y:
            x, y = y, x
            s = s[::-1]
        # ba
        for c in s:
            if c != 'a':
                st1.append(c)
            else:
                if st1 and st1[-1] == 'b':
                    st1.pop()
                    res += y
                else:
                    st1.append(c)
        
        while st1:
            c = st1.pop()
            if c != 'a':
                st2.append(c)
            else:
                if st2 and st2[-1] == 'b':
                    st2.pop()
                    res += x
                else:
                    st2.append(c)
        return res
