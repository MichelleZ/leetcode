#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/validate-stack-sequences/
# Author: Miao Zhang
# Date:   2021-03-28

class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        for p in pushed:
            stack.append(p)
            while stack and stack[-1] == popped[0]:
                    stack.pop()
                    popped.pop(0)
        return len(stack) == 0
