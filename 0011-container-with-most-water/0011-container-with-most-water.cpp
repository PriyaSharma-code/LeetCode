class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int j= height.size()-1;
        int i=0;
        while(i <= j){
            int area = abs(i-j)*min(height[i],height[j]);
            maxArea = max(maxArea,area);
            if(height[i]>=height[j]){
                j--;
                continue;
            }
            else{
                i++;
                continue;
            }
        }
        return maxArea;
    }
};