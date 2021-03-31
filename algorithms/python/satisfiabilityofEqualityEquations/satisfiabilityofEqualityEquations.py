#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/satisfiability-of-equality-equations/
# Author: Miao Zhang
# Date:   2021-03-31

class UnionFind:
    def __init__(self):
        self.root = list(range(26))
    
    def find(self, x):
        if self.root[x] != x:
            self.root[x] = self.find(self.root[x])
        return self.root[x]
    
    def union(self, x, y):
        self.root[self.find(x)] = self.find(y)

        
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        uf = UnionFind()
        for eq in equations:
            if eq[1] == '=':
                x = ord(eq[0]) - ord('a')
                y = ord(eq[3]) - ord('a')
                uf.union(x, y)
        for eq in equations:
            if eq[1] == '!':
                x = ord(eq[0]) - ord('a')
                y = ord(eq[3]) - ord('a')
                if uf.find(x) == uf.find(y):
                    return False
        return True
