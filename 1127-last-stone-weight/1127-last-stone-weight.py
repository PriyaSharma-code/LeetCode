class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort(reverse=True)

        while len(stones) > 1:
            stone1 = stones.pop(0)
            stone2 = stones.pop(0)

            new_weight = abs(stone1 - stone2)

            if new_weight == 0: continue

            insert_index = len(stones)
            for i in range(len(stones)):
                if stones[i] < new_weight:
                    insert_index = i
                    break

            stones.insert(insert_index, new_weight)

        if len(stones) == 0: return 0

        return stones[0]