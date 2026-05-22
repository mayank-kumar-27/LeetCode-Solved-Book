Vclass Solution:
    def search(self, a: List[int], t: int) -> int:
        return -1 if t not in a else a.index(t)
