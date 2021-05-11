#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
# Author: Miao Zhang
# Date:   2021-05-11

class Solution:
    def average(self, salary: List[int]) -> float:
        low = min(salary)
        high = max(salary)
        sums = sum(salary)
        return (sums - low - high) / (len(salary) - 2)        
