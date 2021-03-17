#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/flipping-an-image/
# Author: Miao Zhang
# Date:   2021-03-16

class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        for i in range(len(image)):
            image[i] = image[i][::-1]
            for j in range(len(image[0])):
                image[i][j] ^= 1
        return image
