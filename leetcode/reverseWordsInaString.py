import string 
import re

class Solution(object):
    
    def reverseWords(self, s):
         
        d = s.split(" ")
        str = []
        for i in range(0, len(d)):
            str.append(d[-1-i])
        
        str = [word for word in str if word]
        
        result = " ".join(str)
        result = '"' + result + '"'
        return(result)
solution = Solution()
s = input("")
answer = solution.reverseWords(s)
print(answer)
        
        