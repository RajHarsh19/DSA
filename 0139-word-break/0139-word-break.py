class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        word_set = set(wordDict)
        memo = {}

        def canBreak(start):
            if start == len(s):
                return True
            if start in memo:
                return memo[start]

            for end in range(start + 1, len(s) + 1):
                if s[start:end] in word_set and canBreak(end):
                    memo[start] = True
                    return True

            memo[start] = False
            return False

        return canBreak(0)
