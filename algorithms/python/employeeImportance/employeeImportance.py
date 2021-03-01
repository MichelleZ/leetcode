#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/employee-importance/
# Author: Miao Zhang
# Date:   2021-03-01

"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        dic = collections.defaultdict(object)
        for e in employees:
            dic[e.id] = e
        res = 0
        q = collections.deque()
        q.append(id)
        while q:
            n = len(q)
            for _ in range(n):
                eid = q.popleft()
                e = dic[eid]
                res += e.importance
                for sid in e.subordinates:
                    q.append(sid)
        return res
