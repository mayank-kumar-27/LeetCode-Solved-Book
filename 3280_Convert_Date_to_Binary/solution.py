class Solution:
    def convertDateToBinary(self, date: str) -> str:
        y, m, d = map(int, date.split("-"))
        return f"{bin(y)[2:]}-{bin(m)[2:]}-{bin(d)[2:]}"
