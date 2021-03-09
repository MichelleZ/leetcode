#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/special-binary-string/
# Author: Miao Zhang
# Date:   2021-03-08

class Solution:
    def makeLargestSpecial(self, S: str) -> str:
        cnt = 0
        i = 0
        v = []
        for j in range(len(S)):
            cnt += 1 if S[j] == '1' else -1
            if cnt == 0:
                v.append('1' + self.makeLargestSpecial(S[i + 1: j]) + '0')
                i = j + 1
        v.sort(reverse=True)
        return ''.join(v)
