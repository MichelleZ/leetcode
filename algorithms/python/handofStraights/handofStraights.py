#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/hand-of-straights/
# Author: Miao Zhang
# Date:   2021-03-17

class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        counter = collections.Counter(hand)
        while counter:
            start = min(counter)
            for i in range(start, start+W):
                val = counter[i]
                if not val:
                    return False
                if val == 1:
                    del counter[i]
                else:
                    counter[i] -= 1
        return True
