class Solution:
    def sortSentence(self, s: str) -> str:
        res = [""] * 10
        for w in s.split():
            res[int(w[-1])] = w[:-1]
        return " ".join(res[1 : len(s.split()) + 1])
