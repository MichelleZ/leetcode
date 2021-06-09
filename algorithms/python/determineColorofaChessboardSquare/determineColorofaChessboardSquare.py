#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/determine-color-of-a-chessboard-square/
# Author: Miao Zhang
# Date:   2021-06-09

class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        return ((ord(coordinates[0]) - ord('a')) + int(coordinates[1])) % 2 == 0
