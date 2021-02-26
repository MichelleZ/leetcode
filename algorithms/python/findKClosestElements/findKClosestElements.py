#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-k-closest-elements/
# Author: Miao Zhang
# Date:   2021-02-26

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        while len(arr) > k:
            if x - arr[0] <= arr[-1] - x:
                arr.pop()
            else:
                arr.pop(0)
        return arr
