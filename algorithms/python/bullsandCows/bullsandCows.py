#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/bulls-and-cows/
# Author: Miao Zhang
# Date:   2021-01-31

class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        from collections import defaultdict
        bulls = 0
        cows = 0
        dic = defaultdict(int)
        for s, g in zip(secret, guess):
            if s == g: 
                bulls += 1
            else:
                dic[s] += 1
        for i in range(len(guess)):
            if guess[i] != secret[i] and guess[i] in dic and dic[guess[i]] != 0:
                cows += 1
            dic[guess[i]] -= 1
        return str(bulls) + 'A' + str(cows) + 'B'
