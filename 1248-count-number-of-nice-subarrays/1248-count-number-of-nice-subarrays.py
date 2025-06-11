class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        from collections import defaultdict

        count = defaultdict(int)
        count[0] = 1
        prefix_sum = 0
        result = 0

        for num in nums:
            prefix_sum += num % 2  # count odd numbers
            result += count[prefix_sum - k]
            count[prefix_sum] += 1

        return result
