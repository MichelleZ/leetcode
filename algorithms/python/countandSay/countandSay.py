#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-and-say/
# Author: Miao Zhang
# Date:   2021-01-08

class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        
        prestr = self.countAndSay(n - 1)
        count = 1
        res = ""
        for i in range(1, len(prestr)):
            if prestr[i] == prestr[i - 1]:
                count += 1
            else:
                res += str(count) + prestr[i - 1]
                count = 1
        res += str(count) + prestr[-1]
        return res
