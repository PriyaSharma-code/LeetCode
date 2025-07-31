class Solution {
public:
       int subarrayBitwiseORs(vector<int>& A) {
      unordered_set<int> ans;
      unordered_set<int> prev;
      prev.insert(0);
      for(auto x:A){
        unordered_set<int> curr;
        for(int y:prev){
          curr.insert(x|y);
        }
        curr.insert(x);
        prev = curr;
        ans.insert(curr.begin(), curr.end());
      }
      return ans.size();
    }
};