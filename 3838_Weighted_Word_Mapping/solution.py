class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        r = []
        for w in words:
            s = 0
            for c in w:
                s += weights[ord(c) - ord("a")]
            r.append(chr(ord("z") - s % 26))
        return "".join(r)
