class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        friends, index = list(range(1, n + 1)), 0
        while len(friends) > 1:
            index = (index + k - 1) % len(friends)
            friends.pop(index)
        return friends[0]
