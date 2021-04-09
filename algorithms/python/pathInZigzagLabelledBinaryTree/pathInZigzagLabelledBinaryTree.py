#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
# Author: Miao Zhang
# Date:   2021-04-09

class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        res = []
        while label != 1:
            res.append(label)
            label >>= 1
            label = label ^ (1 << (label.bit_length() - 1)) - 1
        return [1] + res[::-1]
