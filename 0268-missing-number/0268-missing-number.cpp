class Solution {
public:


int cycsort(vector<int>&arr){
    int i=0;
    while(i<arr.size()){
        int correctind=arr[i];
       
        if(i != correctind && arr[i] <arr.size())
        swap(arr[i],arr[correctind]);

        else 
        i++;
    }

    for(int i=0;i<arr.size();i++){
        if(arr[i] != i){
            return i;
        }
    }
    return arr.size();
}
    int missingNumber(vector<int>& nums) {

        return cycsort(nums);
    }
};