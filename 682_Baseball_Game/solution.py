class Solution:
    def calPoints(self, operations: List[str]) -> int:
        ops = []
        for operation in operations:
            if operation == "+":
                ops.append(ops[-2] + ops[-1])
            elif operation == "D":
                ops.append(2 * ops[-1])
            elif operation == "C":
                ops.pop()
            else:
                ops.append(int(operation))
        return sum(ops)
