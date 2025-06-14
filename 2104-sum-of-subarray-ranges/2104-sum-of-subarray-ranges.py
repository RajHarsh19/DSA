class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        n = len(nums)

        def sumOfSubarrayMaximums():
            stack = []
            res = 0
            for i in range(n + 1):
                cur = nums[i] if i < n else float('inf')
                while stack and nums[stack[-1]] < cur:
                    j = stack.pop()
                    k = stack[-1] if stack else -1
                    res += nums[j] * (j - k) * (i - j)
                stack.append(i)
            return res

        def sumOfSubarrayMinimums():
            stack = []
            res = 0
            for i in range(n + 1):
                cur = nums[i] if i < n else float('-inf')
                while stack and nums[stack[-1]] > cur:
                    j = stack.pop()
                    k = stack[-1] if stack else -1
                    res += nums[j] * (j - k) * (i - j)
                stack.append(i)
            return res

        return sumOfSubarrayMaximums() - sumOfSubarrayMinimums()
