#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
# Author: Miao Zhang
# Date:   2021-02-03

class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        stack = []
        for node in preorder.split(','):
            stack.append(node)
            while len(stack) >= 3 and stack[-1] == stack[-2] == '#' and stack[-3] != '#':
                stack.pop();
                stack.pop();
                stack.pop();
                stack.append('#')
        return len(stack) == 1 and stack.pop() == '#'
