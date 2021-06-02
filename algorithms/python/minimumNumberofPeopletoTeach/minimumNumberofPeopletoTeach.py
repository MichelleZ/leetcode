#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-people-to-teach/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        m = len(languages)
        def insection(i, j):
            for li in languages[i - 1]:
                for lj in languages[j - 1]:
                    if li == lj:
                        return True
            return False

        nonInsection = set()
        for i, j in friendships:
            if not insection(i, j):
                nonInsection.add(i)
                nonInsection.add(j)
        if len(nonInsection) == 0:
            return 0
        cnt = collections.defaultdict(int)
        for x in nonInsection:
            for l in languages[x - 1]:
                cnt[l] += 1
        return len(nonInsection) - max(cnt.values())
