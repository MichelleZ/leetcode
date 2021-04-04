#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/video-stitching/
# Author: Miao Zhang
# Date:   2021-04-03

class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        lastend = -1
        end = 0
        res = 0
        for i, j in sorted(clips, key = lambda x: (x[0], x[-1])):
            if end >= T or i > end:
                break
            if lastend < i <= end:
                res += 1
                lastend = end
            end = max(end, j)
        return res if end >= T else -1
