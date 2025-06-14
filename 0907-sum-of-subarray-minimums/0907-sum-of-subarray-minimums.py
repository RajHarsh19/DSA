class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(arr)
        
        prev_less = [0] * n
        next_less = [0] * n

        stack = []
        for i in range(n):
            count = 1
            while stack and stack[-1][0] > arr[i]:
                count += stack.pop()[1]
            prev_less[i] = count
            stack.append((arr[i], count))

        stack = []
        for i in range(n-1, -1, -1):
            count = 1
            while stack and stack[-1][0] >= arr[i]:
                count += stack.pop()[1]
            next_less[i] = count
            stack.append((arr[i], count))

        result = 0
        for i in range(n):
            result = (result + arr[i] * prev_less[i] * next_less[i]) % MOD
        
        return result
