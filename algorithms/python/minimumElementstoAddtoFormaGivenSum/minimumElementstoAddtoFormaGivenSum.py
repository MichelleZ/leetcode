#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def minElements(self, nums: List[int], limit: int, goal: int) -> int:
        return ceil(abs(goal - sum(nums)) / limit)
