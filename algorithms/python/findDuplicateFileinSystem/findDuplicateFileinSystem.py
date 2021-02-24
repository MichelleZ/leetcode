#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-duplicate-file-in-system/
# Author: Miao Zhang
# Date:   2021-02-24

class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        from collections import defaultdict
        filemap = defaultdict(list)
        for p in paths:
            plist = p.split()
            folder, files = plist[0], plist[1:]
            for f in files:
                flist = f.split('(')
                filename, content = flist[0], flist[1][:-1]
                filemap[content].append(folder + '/' + filename)
        return [f for f in filemap.values() if len(f) > 1]
