#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
# Author: Miao Zhang
# Date:   2021-04-18

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        res = []
        t = '/*'
        for f in sorted(folder):
            if not f.startswith(t):
                res.append(f)
                t = f + '/'
        return res
