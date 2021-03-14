#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/ambiguous-coordinates/
# Author: Miao Zhang
# Date:   2021-03-14

class Solution:
    def ambiguousCoordinates(self, S: str) -> List[str]:
        def make(string):
            n = len(string)
            for d in range(1, n + 1):
                left = string[:d]
                right = string[d:]
                if (not left.startswith('0') or left == '0') \
                   and (not right.endswith('0')):
                    yield left + ('.' if d != n else '') + right
        S = S[1:-1]
        res = []
        for i in range(1, len(S)):
            for left in make(S[:i]):
                for right in make(S[i:]):
                    res.append('({}, {})'.format(left, right))
        return res
