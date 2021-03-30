#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/odd-even-jump/
# Author: Miao Zhang
# Date:   2021-03-30

class Solution:
    def oddEvenJumps(self, arr: List[int]) -> int:
        n = len(arr)
        
        def make(arr1):
            res = [None] * n
            stack = []
            for num in arr1:
                while stack and num > stack[-1]:
                    res[stack.pop()] = num
                stack.append(num)
            return res
        
        arr1 = sorted(range(n), key=lambda i: arr[i])
        oddnext = make(arr1)
        arr1.sort(key=lambda i: -arr[i])
        evennext = make(arr1)
        
        odd = [False] * n
        even = [False] * n
        odd[n - 1] = even[n - 1] = True
        for i in range(n - 2, -1, -1):
            if oddnext[i] is not None:
                odd[i] = even[oddnext[i]]
            if evennext[i] is not None:
                even[i] = odd[evennext[i]]
        return sum(odd)
