#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-genetic-mutation/
# Author: Miao Zhang
# Date:   2021-02-11

class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        from collections import deque
        q = deque()
        q.append((start, 0))
        bankset = set(bank)
        while q:
            gene, mutation = q.popleft()
            if gene == end:
                return mutation
            for i in range(len(gene)):
                for c in "ACGT":
                    newGene = gene[: i] + c + gene[i + 1:]
                    if newGene in bank and newGene != gene:
                        q.append((newGene, mutation + 1))
                        bank.remove(newGene)
        return -1 
