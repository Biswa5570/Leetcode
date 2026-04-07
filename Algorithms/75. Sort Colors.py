class Solution:
    def sortColors(self, nums):
        n = len(nums)
        whitecount = 0
        redcount = 0
        bluecount = 0

        for i in range(n):
            if nums[i] == 0:
                whitecount += 1
            elif nums[i] == 1:
                redcount += 1
            else:
                bluecount += 1

        i = 0

        while i < whitecount:
            nums[i] = 0
            i += 1

        while i < whitecount + redcount:
            nums[i] = 1
            i += 1

        while i < n:
            nums[i] = 2
            i += 1
