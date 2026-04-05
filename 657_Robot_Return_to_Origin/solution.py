class Solution:
    def judgeCircle(self, moves: str) -> bool:
        u, d, l, r =  moves.count("U"), moves.count("D"), moves.count("L"), moves.count("R"),
        return u == d and l == r
