#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-unique-elements/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        unique = []
        notUnique = []
        for num in nums:
            if num not in unique:
                unique.append(num)
            elif num not in notUnique:
                notUnique.append(num)
        return sum(unique) - sum(notUnique)
