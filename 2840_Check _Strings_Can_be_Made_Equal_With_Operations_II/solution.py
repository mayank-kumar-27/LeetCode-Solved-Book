class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        freq = [0] * 52
        for i in range(len(s1)):
            off = 26 if i % 2 == 1 else 0
            a = s1[i]
            b = s2[i]
            freq[ord(a) - 97 + off] += 1
            freq[ord(b) - 97 + off] -= 1
        for c in freq:
            if c != 0: return False
        return True