class Solution {
public:
    bool digit(int num){
        int count=0;
        while(num>0){
            int rem = num%10;
            count++;
            num /=10;
        }
        return count%2==0;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        if(nums.size()==0){
            return 0;
        }
        for(int i = 0 ; i < nums.size();i++){
            if(digit(nums[i])){
                count++;
            }
        }
        return count;
    }
};