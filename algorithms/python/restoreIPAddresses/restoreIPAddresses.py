#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/restore-ip-addresses/
# Author: Miao Zhang
# Date:   2021-01-15

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        self.dfs(s, res, [])
        return res
    
    def dfs(self, s: str, res: List[str], path: List[str]) -> None:
        if len(s) > (4 - len(path)) * 3:
            return
        if not s and len(path) == 4:
            res.append('.'.join(path))
            return
        for i in range(min(3, len(s))):
            cur = s[:i + 1]
            if (cur[0] == '0' and len(cur) >= 2) or int(cur) > 255:
                continue
            self.dfs(s[i + 1:], res, path + [s[:i + 1]])
