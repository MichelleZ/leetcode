#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/next-greater-element-i/
# Author: Miao Zhang
# Date:   2021-02-17

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []
        dic = {}
        for n in nums2:
            while stack and n > stack[-1]:
                dic[stack.pop()] = n
            stack.append(n)
        for i in range(len(nums1)):
            nums1[i] = dic.get(nums1[i], -1)
        return nums1
