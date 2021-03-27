#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/valid-mountain-array/
# Author: Miao Zhang
# Date:   2021-03-27

class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr) < 3: return False
        up = False
        down = False
        for i in range(1, len(arr)):
            if arr[i] > arr[i - 1]:
                if down: return False
                up = True
            elif arr[i] < arr[i - 1]:
                if not up: return False
                down = False
            else:
                return False
        return up and down
