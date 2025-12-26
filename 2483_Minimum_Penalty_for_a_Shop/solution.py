class Solution:
    def bestClosingTime(self, customers: str) -> int:
        penalty = customers.count("Y")
        min_penalty, best_hour = penalty, 0

        for i in range(len(customers)):
            penalty += -1 if customers[i] == "Y" else 1
            if penalty < min_penalty:
                min_penalty = penalty
                best_hour = i + 1

        return best_hour
