#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-k-digits/
# Author: Miao Zhang
# Date:   2021-02-08

class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for n in num:
            while stack and k and int(stack[-1]) > int(n):
                stack.pop()
                k -= 1
            stack.append(n)
        while k:
            stack.pop()
            k -= 1
        if not stack: return '0'
        return str(int(''.join(stack)))
