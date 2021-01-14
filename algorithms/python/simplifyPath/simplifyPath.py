#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/simplify-path/
# Author: Miao Zhang
# Date:   2021-01-13

class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = list()
        dirs = path.split('/')
        for dir in dirs:
            if not dir or dir == '.':
                continue
            elif dir == '..':
                if stack:
                    stack.pop()
            else:
                stack.append(dir)
        return '/' + '/'.join(stack)
