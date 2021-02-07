#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/decode-string/
# Author: Miao Zhang
# Date:   2021-02-07

class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        res = ''
        num = 0
        for c in s:
            if  c.isdigit():
                num = num * 10 + int(c)
            elif c == '[':
                stack.append(res)
                stack.append(num)
                res = ''
                num = 0
            elif c.isalpha():
                res += c
            elif c == ']':
                pre_num = stack.pop()
                pre_str = stack.pop()
                res = pre_str + pre_num * res
        return res
