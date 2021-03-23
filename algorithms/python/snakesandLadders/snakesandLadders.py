#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/snakes-and-ladders/
# Author: Miao Zhang
# Date:   2021-03-23

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        q = collections.deque()
        n = len(board)
        
        def get(s):
            x, y = divmod(s - 1, n)
            row = n - 1 - x
            col = n - 1 - y if x % 2 else y
            return row, col
        
        dist = {1: 0}
        q.append(1)
        while q:
            s = q.popleft()
            if s == n * n:
                return dist[s]
            for s2 in range(s + 1, min(s + 6, n * n) + 1):
                r, c = get(s2)
                if board[r][c] != -1:
                    s2 = board[r][c]
                if s2 not in dist:
                    dist[s2] = dist[s] + 1
                    q.append(s2)
        return -1
                
