#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/parsing-a-boolean-expression/
# Author: Miao Zhang
# Date:   2021-04-09

class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        self.pos = 0
        return self.parse(expression)
    
    def parse(self, expression: str) -> bool:
        ch = expression[self.pos]
        self.pos += 1
        if ch == 't': return True
        if ch == 'f': return False
        if ch == '!':
            self.pos += 1
            res = not self.parse(expression)
            self.pos += 1
            return res
        isand = (ch == '&')
        res = isand
        self.pos += 1
        while True:
            if isand:
                res &= self.parse(expression)
            else:
                res |= self.parse(expression)
            if expression[self.pos] == ')':
                self.pos += 1
                break
            self.pos += 1
        return res
