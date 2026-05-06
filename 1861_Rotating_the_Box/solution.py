class Solution:
    def rotateTheBox(self, b: List[List[str]]) -> List[List[str]]:
        m,n = len(b),len(b[0])
        r = [["" for _ in range(m)] for _ in range(n)]
        for i in range(n):
            for j in range(m):
                r[i][j] = b[j][i]
        for i in range(n):
            r[i].reverse()

        for j in range(m):
            for i in range(n - 1, -1, -1):
                if (r[i][j] == "."):
                    rw = -1
                    for k in range(i - 1, -1, -1):
                        if r[k][j] == "*":
                            break 
                        if (r[k][j] == "#"):  
                            rw = k
                            break
                    if rw != -1:
                        r[rw][j] = "."
                        r[i][j] = "#"
        return r
