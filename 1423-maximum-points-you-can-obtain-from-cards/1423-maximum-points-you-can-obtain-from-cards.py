class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        total = sum(cardPoints)
        window_size = n - k
        window_sum = sum(cardPoints[:window_size])
        min_subarray_sum = window_sum

        for i in range(window_size, n):
            window_sum += cardPoints[i] - cardPoints[i - window_size]
            min_subarray_sum = min(min_subarray_sum, window_sum)

        return total - min_subarray_sum
