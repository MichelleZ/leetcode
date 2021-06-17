#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-space-wasted-from-packaging/
# Author: Miao Zhang
# Date:   2021-06-17

class Solution:
    def minWastedSpace(self, packages: List[int], boxes: List[List[int]]) -> int:
        kMod = 10 ** 9 + 7
        packages.sort()
        sums = list(accumulate(packages, initial=0))
        get = lambda left, right: sums[right + 1] - sums[left]
        res = float("inf")
        for box in boxes:
            box.sort()
            if packages[-1] > box[-1]:
                continue
            pt = 0
            total = 0
            for y in box:
                if y < packages[pt]:
                    continue
                ptnxt = bisect_right(packages, y, pt) - 1
                total += (ptnxt - pt + 1) * y - get(pt, ptnxt)
                pt = ptnxt + 1
                if pt == len(packages):
                    break
            res = min(res, total)
        return -1 if res == float("inf") else res % kMod

