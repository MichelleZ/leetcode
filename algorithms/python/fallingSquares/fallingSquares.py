#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/falling-squares/
# Author: Miao Zhang
# Date:   2021-03-02

class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        coords = set()
        for left, size in positions:
            coords.add(left)
            coords.add(left + size - 1)
        index = {x: i for i, x in enumerate(sorted(coords))}
        
        res = []
        heights = [0] * len(index)
        for l, s in positions:
            start = index[l]
            end = index[l + s - 1]
            
            maximum_height = max(heights[start:end + 1])
            
            for i in range(start, end+1):
                heights[i] = maximum_height + s
                 
            res.append(max(heights))
        return res
            
