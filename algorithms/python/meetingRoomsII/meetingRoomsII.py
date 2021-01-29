#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/meeting-rooms-ii/
# Author: Miao Zhang
# Date:   2021-01-28

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
	    from collections import heapq

