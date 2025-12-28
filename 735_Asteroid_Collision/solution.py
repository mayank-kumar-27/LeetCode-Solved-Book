class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        result = []
        for asteroid in asteroids:
            while result and asteroid < 0 and result[-1] > 0:
                if result[-1] < abs(asteroid):
                    result.pop()
                    continue
                elif result[-1] == abs(asteroid):
                    result.pop()
                break
            else:
                result.append(asteroid)

        return result
