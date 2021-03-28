#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/bag-of-tokens/
# Author: Miao Zhang
# Date:   2021-03-28

class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        tokens.sort()
        res = 0
        scores = 0
        i = 0
        j = len(tokens) - 1
        while i <= j:
            if P >= tokens[i]:
                P -= tokens[i]
                scores += 1
                i += 1
                res = max(res, scores)
            elif scores > 0:
                P += tokens[j]
                j -= 1
                scores -= 1
            else:
                break
        return res
