#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/implement-rand10-using-rand7/
# Author: Miao Zhang
# Date:   2021-02-14

# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        index = float('inf')
        while index >= 40:
            index = (rand7() - 1) * 7 + rand7() - 1
        return index % 10 + 1;
