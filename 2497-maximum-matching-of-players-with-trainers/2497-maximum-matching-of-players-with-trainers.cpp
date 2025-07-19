class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        int i = players.size() - 1;
        int j = trainers.size() - 1;
        int ans = 0;
        while(i >= 0 && j >= 0){
            if(players[i] <= trainers[j])
                ans++, j--;
            i--;
        }
        return ans;
    }
};