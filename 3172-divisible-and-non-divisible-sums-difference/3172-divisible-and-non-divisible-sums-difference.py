class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        total_sum = n * (n + 1) // 2
        k = n // m
        num2 = m * k *(k + 1) // 2
        result = total_sum - 2  * num2
        return result