#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/accounts-merge/
# Author: Miao Zhang
# Date:   2021-03-04

class UnionFind:
    def __init__(self):
        self.p = [ i for i in range(10001)]
    
    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]
    
    def union(self, x: int, y: int):
        self.p[self.find(x)] = self.find(y)
    
    
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        unionfind = UnionFind()
        email_to_name = {}
        email_to_id = {}
        i = 0
        for acc in accounts:
            name = acc[0]
            for email in acc[1:]:
                email_to_name[email] = name
                if email not in email_to_id:
                    email_to_id[email] = i
                    i += 1
                unionfind.union(email_to_id[acc[1]], email_to_id[email])
        
        res = collections.defaultdict(list)
        for email in email_to_name:
            res[unionfind.find(email_to_id[email])].append(email)
        return [[email_to_name[v[0]]] + sorted(v) for v in res.values()]
