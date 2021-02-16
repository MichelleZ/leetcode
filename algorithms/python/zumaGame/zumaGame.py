#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/zuma-game/
# Author: Miao Zhang
# Date:   2021-02-16

class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        cnt = collections.Counter(hand)
        self.res = len(hand) + 1
        
        def update(board):
            i = 0
            for j, ball in enumerate(board):
                if ball == ball[i]: continue
                if j - i >= 3: return update(board[0: i] + balls[j:])
                else: i = j
            return board
        
        def dfs(board):
            board = update(board)
            if board == '#':
                self.res = min(self.res, len(hand) - sum(list(cnt.values())))
            i = 0
            for j in range(len(board)):
                if board[i] == board[j]: continue
                need = 3 - (j - i)
                if cnt[board[i]] >= need:
                    cnt[board[i]] -= need
                    dfs(board[0:i] + board[j:])
                    cnt[board[i]] += need
                i = j
        
        dfs(list(board+'#'))
        return -1 if self.res > len(hand) else self.res
