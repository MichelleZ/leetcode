#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/random-flip-matrix/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:

    def __init__(self, n_rows: int, n_cols: int):
        self.rows = n_rows
        self.cols = n_cols
        self.n = n_rows * n_cols
        self.dic = dict()

    def flip(self) -> List[int]:
        s = random.randint(0, self.n - 1)
        self.n -= 1
        index = self.dic.get(s, s)
        self.dic[s] = self.dic.get(self.n, self.n)
        return [index // self.cols, index % self.cols]

    def reset(self) -> None:
        self.dic.clear()
        self.n = self.rows * self.cols


# Your Solution object will be instantiated and called as such:
# obj = Solution(n_rows, n_cols)
# param_1 = obj.flip()
# obj.reset()
