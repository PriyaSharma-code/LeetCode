class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        left,right = 0,len(height)-1

        for i in range(len(height)):
            area = (right- left)*min(height[left],height[right])
            max_area = max(max_area, area)
            if height[right] > height[left]:
                left +=1
            else:
                right -=1
        return max_area