#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/expression-add-operators/
# Author: Miao Zhang
# Date:   2021-01-30

class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        res = []
        for i in range(1, len(num) + 1):
            if i == 1 or (i > 1 and num[0] != '0'):
                self.dfs(num[i:], num[: i], int(num[:i]), int(num[:i]), res, target)
        return res
    
    def dfs(self, num: str, path: str, cur: int, last: int, res: List[str], target: int) -> None:
        '''
        path: The intermediate process of each calculation
        cur: the result of current path
        last: the last num
        res: return value
        eg. num: 3, path: '1+2', cur: 3, last: 2
        '+': num, path: '1+2+3', cur: cur + int(3) = 6, last: 3
        '-': num, path: '1+2-3', cur: cur - int(3) = 0, last: -3
        '*': num, path: '1+2*3', cur: cur - last + last * int(3) = 7, last: last * int(3) = 6
        '''
        if not num:
            if cur == target:
                res.append(path)
                return
        for i in range(1, len(num) + 1):
            val = num[: i]
            if i == 1 or (i > 1 and num[0] != '0'):
                self.dfs(num[i:], path + '+' + val, cur + int(val), int(val), res, target)
                self.dfs(num[i:], path + '-' + val, cur - int(val), -int(val), res, target)
                self.dfs(num[i:], path + '*' + val, cur - last + last * int(val), last * int(val), res, target)
