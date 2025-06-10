class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        from collections import defaultdict

        prefix_sum_count = defaultdict(int)
        prefix_sum_count[0] = 1
        current_sum = 0
        result = 0

        for num in nums:
            current_sum += num
            result += prefix_sum_count.get(current_sum - goal, 0)
            prefix_sum_count[current_sum] += 1

        return result
