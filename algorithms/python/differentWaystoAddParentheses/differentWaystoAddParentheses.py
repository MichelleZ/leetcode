#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/different-ways-to-add-parentheses/
# Author: Miao Zhang
# Date:   2021-01-28

class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        if input.isdigit():
            return [int(input)]
        
        res = []
        for i in range(len(input)):
            if input[i] in '+-*':
                left = self.diffWaysToCompute(input[:i])
                right = self.diffWaysToCompute(input[i + 1:])
                for l in left:
                    for r in right:
                        if input[i] == '+':
                            res.append(l + r)
                        elif input[i] == '-':
                            res.append(l - r)
                        else:
                            res.append(l * r)
        return res
