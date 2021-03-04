#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-atoms/
# Author: Miao Zhang
# Date:   2021-03-04

class Solution:
    def countOfAtoms(self, formula: str) -> str:
        self.i = 0
        res = ''
        cnt = self.countAtoms(formula)
        for k in sorted(cnt.keys()):
            res += k
            if cnt[k] > 1:
                res += str(cnt[k])
        return res
    
    def countAtoms(self, formula: str) -> dict:
        counts = collections.defaultdict(int)
        while self.i != len(formula):
            if formula[self.i] == '(':
                self.i += 1
                tmp_counts = self.countAtoms(formula)
                count = self.getCount(formula)
                for k, v in tmp_counts.items():
                    counts[k] += v * count
            elif formula[self.i] == ')':
                self.i += 1
                return counts
            else:
                name = self.getName(formula)
                counts[name] += self.getCount(formula)
        return counts
    
    def getName(self, formula: str) -> str:
        name = ''
        while self.i < len(formula) and formula[self.i].isalpha() and (not name or formula[self.i].islower()):
            name += formula[self.i]
            self.i += 1
        return name
    
    def getCount(self, formula: str) -> int:
        cnt_str = ''
        while self.i < len(formula) and formula[self.i].isdigit():
            cnt_str += formula[self.i]
            self.i += 1
        return 1 if not cnt_str else int(cnt_str)
