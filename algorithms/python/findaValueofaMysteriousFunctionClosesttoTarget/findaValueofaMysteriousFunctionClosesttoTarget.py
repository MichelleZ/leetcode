#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def closestToTarget(self, arr: List[int], target: int) -> int:
        res = abs(arr[0] - target)
        valid = {arr[0]}
        for num in arr:
            valid = {x & num for x in valid} | {num}
            res = min(res, min(abs(x - target) for x in valid))
        return res

