#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
# Author: Miao Zhang
# Date:   2021-01-06

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        digits2chars = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        
        res = [i for i in digits2chars[digits[0]]]
        
        for i in digits[1:]:
            res = [m + n for m in res for n in digits2chars[i]]
            print(res)
        return res
