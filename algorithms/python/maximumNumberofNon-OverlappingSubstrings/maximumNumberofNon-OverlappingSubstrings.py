#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        n = len(s)
        l = [float('inf')] * 26
        r = [float('-inf')] * 26
        for i in range(n):
            l[ord(s[i]) - ord('a')] = min(l[ord(s[i]) - ord('a')], i)
            r[ord(s[i]) - ord('a')] = max(r[ord(s[i]) - ord('a')], i)
        
        def extend(i):
            p = r[ord(s[i]) - ord('a')]
            j = i
            while j <= p:
                if l[ord(s[j]) - ord('a')] < i:
                    return -1
                p = max(p, r[ord(s[j]) - ord('a')])
                j += 1
            return p
        
        res = []
        last = -1
        for i in range(n):
            if i != l[ord(s[i]) - ord('a')]:
                continue
            p = extend(i)
            if p == -1: continue
            if i > last:
                res.append('')
            res[-1] = s[i: p + 1]
            last = p
        return res
