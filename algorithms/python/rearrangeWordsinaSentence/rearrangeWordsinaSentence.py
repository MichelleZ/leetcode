#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rearrange-words-in-a-sentence/
# Author: Miao Zhang
# Date:   2021-05-08

class Solution(object):
    def arrangeWords(self, text):
        """
        :type text: str
        :rtype: str
        """
        text = text.lower()
        txtlist = text.split()
        txtlist.sort(key=lambda x: len(x))
        res = ' '.join(txtlist)
        return res.capitalize()
