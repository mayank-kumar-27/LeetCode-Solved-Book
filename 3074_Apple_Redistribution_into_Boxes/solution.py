class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        total_apples = sum(apple)
        capacity.sort(reverse=True)
        current_capacity = 0
        for i in range(1, len(capacity) + 1):
            current_capacity += capacity[i - 1]
            if current_capacity >= total_apples:
                return i
