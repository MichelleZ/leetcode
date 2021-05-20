#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/design-parking-system/
# Author: Miao Zhang
# Date:   2021-05-20

class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.park = [None, big, medium, small]

    def addCar(self, carType: int) -> bool:
        if self.park[carType]:
            self.park[carType] -= 1
            return True
        return False


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
