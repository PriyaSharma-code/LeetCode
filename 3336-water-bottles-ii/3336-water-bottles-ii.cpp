class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = 0;
        int empty = 0;
        if (numBottles == 0 && numExchange == 0) {
            return drunk;
        }
        drunk += numBottles;
        empty = numBottles;
        while (empty >= numExchange) {

            empty -= numExchange;
            numExchange++;
            drunk += 1;
            empty++;
        }
        return drunk;
    }
};