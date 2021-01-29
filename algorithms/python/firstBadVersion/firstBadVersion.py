#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/first-bad-version/
# Author: Miao Zhang
# Date:   2021-01-29

# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        l = 1
        r = n
        while l < r:
            mid = (l + r) // 2
            if isBadVersion(mid):
                r = mid
            else:
                l = mid + 1
        return l
