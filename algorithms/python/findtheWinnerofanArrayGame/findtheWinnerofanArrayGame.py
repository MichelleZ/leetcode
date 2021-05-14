#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-winner-of-an-array-game/
# Author: Miao Zhang
# Date:   2021-05-14

class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        winner = arr[0]
        win = 0
        for i in range(1, len(arr)):
            if arr[i] > winner:
                winner = arr[i]
                win = 0
            win += 1
            if win == k: break
        return winner
