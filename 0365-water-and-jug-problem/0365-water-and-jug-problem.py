class Solution:
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        if target > x+y:
            return False
        if x==0 or y==0:
            return target ==0 or target ==x + y
        from math import gcd
        return target % gcd(x, y) == 0