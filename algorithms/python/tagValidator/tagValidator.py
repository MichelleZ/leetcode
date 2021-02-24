#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/tag-validator/
# Author: Miao Zhang
# Date:   2021-02-24

class Solution:
    def isValid(self, code: str) -> bool:
        stack = []
        i = 0
        while i < len(code):
            if i > 0 and stack == []:
                print('stack empty')
                return False
            if code[i: i + 9] == '<![CDATA[':
                j = i + 9;
                i = code.find(']]>', j)
                if i == -1:
                    print('cdata')
                    return False
                i += 2
            elif code[i: i+ 2] == '</':
                j = i + 2
                i = code.find('>', j)
                if i == -1: return False
                tag = code[j: i]
                if not stack or stack[-1] != tag: return False
                stack.pop()
            elif code[i] == '<':
                j = i + 1
                i = code.find('>', j)
                if i == -1 or i == j or i - j > 9: return False
                for k in range(j, i):
                    if ord(code[k]) < ord('A') or ord(code[k]) > ord('Z'):
                        print('upper')
                        return False
                tag = code[j: i]
                stack.append(tag)
            i+= 1
        return not stack
