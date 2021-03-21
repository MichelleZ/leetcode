#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/boats-to-save-people/
# Author: Miao Zhang
# Date:   2021-03-21

class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        i = 0
        j = len(people) - 1
        res = 0
        while i <= j:
            res += 1
            if people[i] + people[j] <= limit:
                i += 1
            j -= 1
        return res
