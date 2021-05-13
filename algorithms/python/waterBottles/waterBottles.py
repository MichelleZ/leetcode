#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/water-bottles/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        return (numBottles - numExchange) // (numExchange - 1) + 1 + numBottles if numBottles >= numExchange else numBottles
