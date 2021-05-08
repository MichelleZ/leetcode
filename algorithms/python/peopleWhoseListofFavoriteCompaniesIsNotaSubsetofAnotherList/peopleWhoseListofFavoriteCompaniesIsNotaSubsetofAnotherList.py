#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/
# Author: Miao Zhang
# Date:   2021-05-08

class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        res = []
        n = len(favoriteCompanies)
        favoriteCompanies = list(set(f) for f in favoriteCompanies)
        for i in range(n):
            for j in range(n):
                if i != j and favoriteCompanies[i].issubset(favoriteCompanies[j]):
                    break
            else:
                res.append(i)
        return res
