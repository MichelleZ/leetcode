#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/flood-fill/
# Author: Miao Zhang
# Date:   2021-03-05

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if image[sr][sc] == newColor: return image
        self.fill(image, sr, sc, image[sr][sc], newColor)
        return image

    def fill(self, image: List[List[int]], i: int, j: int, orgColor: int, newColor: int) -> None:
        if i < 0 or i >= len(image) or j < 0 or j >= len(image[0]) or image[i][j] != orgColor:
            return
        image[i][j] = newColor
        self.fill(image, i + 1, j, orgColor, newColor)
        self.fill(image, i - 1, j, orgColor, newColor)
        self.fill(image, i, j + 1, orgColor, newColor)
        self.fill(image, i, j - 1, orgColor, newColor)
