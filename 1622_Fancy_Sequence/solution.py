class Fancy:
    def __init__(self):
        self.s = []
        self.a = 0
        self.m = 1
        self.M = 10**9 + 7

    def append(self, v: int) -> None:
        x = ((v - self.a) % self.M * pow(self.m, self.M - 2, self.M)) % self.M
        self.s.append(x)

    def addAll(self, i: int) -> None:
        self.a = (self.a + i) % self.M

    def multAll(self, k: int) -> None:
        self.m = (self.m * k) % self.M
        self.a = (self.a * k) % self.M

    def getIndex(self, i: int) -> int:
        if i >= len(self.s): return -1
        return (self.s[i] * self.m + self.a) % self.M