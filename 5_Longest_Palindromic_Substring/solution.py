class Solution:
    def longestPalindrome(self, s: str) -> str:
        def isPalindrome(sub: str) -> bool:
            return sub == sub[::-1]

        n = len(s)
        max_palindrome = s[0]

        for i in range(n):
            for j in range(i, n):
                substring = s[i : j + 1]
                if isPalindrome(substring):
                    if len(substring) > len(max_palindrome):
                        max_palindrome = substring

        return max_palindrome
