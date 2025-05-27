class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        sum1=0
        sum2=0
        for i in range(n+1):
            if i%m==0:
                sum1 = sum1+i
            else:
                sum2 = sum2+i
        return sum2 - sum1