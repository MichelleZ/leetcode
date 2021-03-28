#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reveal-cards-in-increasing-order/
# Author: Miao Zhang
# Date:   2021-03-28

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        n = len(deck)
        idx = collections.deque([i for i in range(n)])
        res = [None] * n
        
        for card in sorted(deck):
            res[idx.popleft()] = card
            if idx:
                idx.append(idx.popleft())
        return res
