class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        candidates.sort()  
        result = []

        def backtrack(start, path, remaining):
            if remaining == 0:
                result.append(path)
                return
            if remaining < 0:
                return

            for i in range(start, len(candidates)):
                
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                
               
                backtrack(i + 1, path + [candidates[i]], remaining - candidates[i])

        backtrack(0, [], target)
        return result
