#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
# Author: Miao Zhang
# Date:   2021-03-24

class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        cnt = collections.Counter(deck)
        for i in range(2, len(deck) + 1):
            if len(deck) % i: continue
            ok = True
            for k, v in cnt.items():
                if v % i:
                    ok = False
                    break
            if ok: return True
        return False
