class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels, has = "aeiouAEIOU", []
        for char in s:
            if char in vowels:
                has.append(char)

        has.reverse()
        s, index = list(s), 0
        for i in range(len(s)):
            if s[i] in vowels:
                s[i] = has[index]
                index += 1

        return "".join(s)
