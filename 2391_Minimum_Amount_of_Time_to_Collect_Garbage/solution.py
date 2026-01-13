class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        total_time = 0
        for garbage_type in ["M", "P", "G"]:
            pickup_time = 0
            last_house = -1

            for i, house_garbage in enumerate(garbage):
                count = house_garbage.count(garbage_type)
                if count > 0:
                    pickup_time += count
                    last_house = i

            if last_house != -1:
                travel_time = sum(travel[:last_house])
                total_time += pickup_time + travel_time

        return total_time
