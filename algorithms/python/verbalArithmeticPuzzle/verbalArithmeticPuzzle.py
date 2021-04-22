#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/verbal-arithmetic-puzzle/
# Author: Miao Zhang
# Date:   2021-04-22

class Solution:
    def isSolvable(self, words: List[str], result: str) -> bool:
        chars = [-1 for _ in range(128)]
        visited = [0 for _ in range(10)]
        result = result[::-1]
        for word in words:
            if len(word) > len(result): return False
        words = [word[::-1] for word in words]
            
        def dfs(i: int, j: int, sums: int) -> bool:
            if j == len(result):
                if sums != 0:
                    return False
                if len(result) > 1 and chars[ord(result[-1])] == 0:
                    return False
                return True
            
            if i == len(words):
                ch = ord(result[j])
                if chars[ch] != -1:
                    if chars[ch] != sums % 10:
                        return False
                    return dfs(0, j + 1, sums // 10)
                else:
                    if visited[sums % 10] == 1:
                        return False
                    chars[ch] = sums % 10
                    visited[sums % 10] = 1
                    if dfs(0, j + 1, sums // 10):
                        return True
                    chars[ch] = -1
                    visited[sums % 10] = 0
                    return False
            
            if j >= len(words[i]):
                return dfs(i + 1, j, sums)
            
            ch = ord(words[i][j])
            if chars[ch] != -1:
                if len(words[i]) > 1 and j == len(words[i]) - 1 and chars[ch] == 0:
                    return False
                return dfs(i + 1, j, sums + chars[ch])
            else:
                for d in range(10):
                    if visited[d] == 1:
                        continue
                    if d == 0 and len(words[i]) > 1 and j == len(words[i]) - 1:
                        continue
                    chars[ch] = d
                    visited[d] = 1
                    if dfs(i + 1, j, sums + d):
                        return True
                    chars[ch] = -1
                    visited[d] = 0
                return False
            return True
    
        res = dfs(0, 0, 0)
        for i, c in enumerate(chars):
            if c != -1:
                print(chr(i), c)
        return res
