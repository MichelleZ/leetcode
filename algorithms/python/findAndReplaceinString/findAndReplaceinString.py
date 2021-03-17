#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-and-replace-in-string/
# Author: Miao Zhang
# Date:   2021-03-16

class Solution:
    def findReplaceString(self, S: str, indexes: List[int], sources: List[str], targets: List[str]) -> str:
        S = list(S)
        for i, s, t in sorted(zip(indexes, sources, targets), reverse=True):
            if all(i + k < len(S) and S[i + k] == s[k] for k in range(len(s))):
                S[i : i + len(s)] = list(t)
        return ''.join(S)
