class Solution(object):
    def productExceptSelf(self, nums):
        n = len(nums)
        answer = [1] * n
        count = 1 
        for i in range(0, n):
            for j in range(0, n - 1):
                count *= nums[j]
            answer[i] = count
        #print(answer)

solution = Solution()
nums = [1,2,3,4]
answer = solution.productExceptSelf(nums)
print(answer)
