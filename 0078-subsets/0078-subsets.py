from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        self.backtrack(nums, 0, [], result)
        return result

    def backtrack(self, nums: List[int], index: int, current: List[int], result: List[List[int]]) -> None:
        result.append(list(current))

        for i in range(index, len(nums)):
            current.append(nums[i])
            self.backtrack(nums, i + 1, current, result)
            current.pop()
