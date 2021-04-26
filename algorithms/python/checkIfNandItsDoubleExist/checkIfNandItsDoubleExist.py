#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-n-and-its-double-exist/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        dic = {}
        for i in arr:
            if i * 2 in dic or (i % 2 == 0 and i / 2 in dic):
                return True
            dic[i] = 1

        return False
