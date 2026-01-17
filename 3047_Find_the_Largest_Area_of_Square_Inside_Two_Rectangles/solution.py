class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        max_area, n = 0, len(bottomLeft)
        for i in range(n):
            for j in range(i + 1, n):
                left, right = max(bottomLeft[i][0], bottomLeft[j][0]), min(topRight[i][0], topRight[j][0])
                bottom,top =  max(bottomLeft[i][1], bottomLeft[j][1]), min(topRight[i][1], topRight[j][1])

                if left < right and bottom < top:
                    side = min(right - left, top - bottom)
                    max_area = max(max_area, side * side)

        return max_area
