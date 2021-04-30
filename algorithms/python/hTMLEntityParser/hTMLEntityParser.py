#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/html-entity-parser/
# Author: Miao Zhang
# Date:   2021-04-30

class Solution:
    def entityParser(self, text: str) -> str:
        m = {'&quot;': '"', "&apos;": "'", "&amp;": "&", "&gt;": ">",
              "&lt;": "<", "&frasl;": "/"}
        res = ''
        buf = ''
        for c in text:
            buf += c
            if buf[-1] != ';': continue
            buflen = len(buf)
            for k, v in m.items():
                klen = len(k)
                if buflen >= klen and buf[buflen - klen:] == k:
                    res += buf[0: buflen - klen] + v
                    buf = ''
                    break
        return res + buf
