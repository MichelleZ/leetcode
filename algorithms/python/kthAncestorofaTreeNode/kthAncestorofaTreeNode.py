#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
# Author: Miao Zhang
# Date:   2021-05-10

class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        maxlvl = ceil(log(n) / log(2))
        self.dp = [[0 for _ in range(n)] for _ in range(maxlvl)]
        self.dp[0] = parent
        for i in range(1, maxlvl):
            for j in range(n):
                self.dp[i][j] = -1 if self.dp[i - 1][j] == -1 else self.dp[i - 1][self.dp[i - 1][j]]

    def getKthAncestor(self, node: int, k: int) -> int:
        for i in range(len(self.dp)):
            if node == -1:
                break
            if k & (1 << i):
                node = self.dp[i][node]
        return node


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
