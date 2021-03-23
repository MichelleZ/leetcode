#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/orderly-queue/
# Author: Miao Zhang
# Date:   2021-03-23

class Solution:
    def orderlyQueue(self, S: str, K: int) -> str:
        if K == 1:
            return min(S[i:] + S[:i] for i in range(len(S)))
        return ''.join(sorted(S))
