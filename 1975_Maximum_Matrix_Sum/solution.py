class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        total_sum, negatives, minimum_sum = 0, 0, float("inf")
        
        for row in matrix:
            for val in row:
                abs_val = abs(val)
                total_sum += abs_val
                minimum_sum = min(minimum_sum, abs_val)
                if val < 0:
                    negatives += 1

        if negatives % 2 == 1:
            return total_sum - 2 * minimum_sum
        else:
            return total_sum
