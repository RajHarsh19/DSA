class Solution:
    def is_palin(self, s: str) -> bool:
        return s == s[::-1]

    def get_all_parts(self, s: str, partitions: list, ans: list):
        if not s:
            ans.append(partitions[:])  # Make a copy of partitions and add to ans
            return
        
        for i in range(len(s)):
            part = s[:i + 1]
            if self.is_palin(part):
                partitions.append(part)
                self.get_all_parts(s[i + 1:], partitions, ans)
                partitions.pop()

    def partition(self, s: str) -> list:
        ans = []
        self.get_all_parts(s, [], ans)
        return ans
