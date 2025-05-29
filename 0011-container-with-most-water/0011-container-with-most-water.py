class Solution:
    def maxArea(self, height: List[int]) -> int:
        l,r = 0,len(height)-1
        h = max(height)
        max_area = 0
        while l<r:
            width = r - l
            max_area = max(max_area, min(height[l], height[r])*width)

            if height[l]<height[r]:
                l += 1
            else:
                r -= 1
            if (r-l)*h < max_area:
                return max_area

        return max_area