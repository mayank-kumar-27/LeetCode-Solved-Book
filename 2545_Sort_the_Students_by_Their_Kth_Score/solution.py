class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        result = {}
        for i in range(len(score)):
            result[score[i][k]] = score[i]
        return [result[key] for key in sorted(result.keys(), reverse=True)]