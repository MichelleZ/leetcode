#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/richest-customer-wealth/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max(sum(row) for row in accounts)
