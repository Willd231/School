class Solution(object):
    def romanToInt(self, s): 
        count = 0
        i = 0 
        romanDict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        
        while i < len(s):   
            # Check if the next numeral is larger (subtractive notation)
            if i + 1 < len(s) and romanDict[s[i]] < romanDict[s[i + 1]]:
                count += romanDict[s[i + 1]] - romanDict[s[i]]
                i += 2  # Skip the next numeral
            else:
                count += romanDict[s[i]]
                i += 1
        
        return count  # Return only the calculated integer value

# Example usage
solution = Solution()
input_str = input("Enter the Roman numeral you want converted: ")
result = solution.romanToInt(input_str)
print(result)  # This will print only the final integer result
