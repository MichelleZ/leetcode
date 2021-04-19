#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/circular-permutation-in-binary-representation/
# Author: Miao Zhang
# Date:   2021-04-19

class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        '''
        binary code      gray code
        0 000             0 000
        1 001             1 001
        2 010             3 011
        3 011             2 010
        4 100             6 110
        5 101             7 111
        6 110             5 101
        7 111             4 100
        '''
        graycode = [i ^ (i // 2) for i in range(2 ** n)]
        for i in range(len(graycode)):
            if graycode[i] == start:
                return graycode[i:] + graycode[:i]
