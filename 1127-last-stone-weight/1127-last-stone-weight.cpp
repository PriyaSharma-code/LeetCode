class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1){
            return stones[0];
        }
        if(stones.size()==0){
            return 0;
        }
        priority_queue<int> pq;

        //vector.sort(stones.begin(),stones.end(),greater<>());
        for( int stone: stones){
            pq.push(stone);
        }

        while(pq.size()>1){
            int one = pq.top();
            pq.pop();
            int two = pq.top();
            pq.pop();
            if(one != two){
                pq.push(one - two);
            }
        }
        return pq.size() == 1 ? pq.top() : 0;
    }
};