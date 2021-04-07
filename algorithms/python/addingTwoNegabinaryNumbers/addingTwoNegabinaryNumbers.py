#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/adding-two-negabinary-numbers/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        res = []
        carry = 0
        i = len(arr1) - 1
        j = len(arr2) - 1
        while i >= 0 or j >= 0 or carry:
            if i >= 0: 
                carry += arr1[i]
                i -= 1
            if j >= 0:
                carry += arr2[j]
                j -= 1
            res.append(carry & 1)
            carry = -(carry >> 1)
        while len(res) > 1 and res[-1] == 0:
            res.pop()
        res.reverse()
        return res
    
