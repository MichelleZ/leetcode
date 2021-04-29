#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
# Author: Miao Zhang
# Date:   2021-04-28

class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        '''
            0
            |
            |
        3--- --- 1
            |
            |
            2
        1: left or right
        2: upper or lower
        3: left lower
        4: right lower
        5: left upper
        6: right upper
        '''
        # refer the picture on the right side, street1-6 is key
        cell = {1 :{1, 3}, 2:{0, 2}, 3: {2, 3}, 4: {1, 2}, 5: {0, 3}, 6: {0, 1}}
        # keys means the 4th directions
        # original upper -> the next is down
        # original left -> the next is right
        dirs = {0: [-1, 0, 2], 1: [0, 1, 3], 2: [1, 0, 0], 3: [0, -1, 1]}
        m = len(grid)
        n = len(grid[0])
        q = collections.deque()
        q.append(0)
        seen = [0 for _ in range(m * n)]
        seen[0] = 1
        while q:
            cur = q.popleft()
            x = cur // n
            y = cur % n
            if x == m - 1 and y == n - 1: return True
            for c in cell[grid[x][y]]:
                tx = x + dirs[c][0]
                ty = y + dirs[c][1]
                if tx < 0 or tx >= m or ty < 0 or ty >= n or seen[tx * n + ty] or dirs[c][2] not in cell[grid[tx][ty]]: 
                    continue
                seen[tx * n + ty] = 1
                q.append(tx * n + ty)
        return False
