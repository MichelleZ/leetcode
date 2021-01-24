#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
# Author: Miao Zhang
# Date:   2021-01-24

from collections import defaultdict

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        dic = defaultdict()
        for i in range(len(numbers)):
            if numbers[i] in dic.keys():
                return dic[numbers[i]], i + 1
            dic[target - numbers[i]] = i + 1
        return -1, -1

