#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/search-suggestions-system/
# Author: Miao Zhang
# Date:   2021-04-20

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        res = []
        products.sort()
        for i in range(1, len(searchWord) + 1):
            products = list(filter(lambda x: x.startswith(searchWord[: i]), products))
            res.append(products[:3])
        return res
