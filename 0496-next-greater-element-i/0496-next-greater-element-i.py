# Brute Force
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        for num in nums1:
            found = False
            next_greater = -1
            for i in range(len(nums2)):
                if nums2[i] == num:
                    for j in range(i + 1, len(nums2)):
                        if nums2[j] > num:
                            next_greater = nums2[j]
                            break
                    break
            res.append(next_greater)
        return res
