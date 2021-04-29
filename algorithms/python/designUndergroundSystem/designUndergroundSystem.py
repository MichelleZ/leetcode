#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/design-underground-system/
# Author: Miao Zhang
# Date:   2021-04-29

class UndergroundSystem:

    def __init__(self):
        # id -> station, t
        self.id = {}
        # from_to: sums, cnt
        self.stations = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.id[id] = [stationName, t]

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        s0, t0 = self.id[id]
        key = s0 + '_' + stationName
        if key not in self.stations:
            self.stations[key] = [(t - t0), 1]
        else:
            self.stations[key][0] += (t - t0)
            self.stations[key][1] += 1

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        sums, cnt = self.stations[startStation + "_" + endStation]
        return sums / cnt


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
