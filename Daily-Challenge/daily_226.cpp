/* Daily Question: 1518. Water Bottles
 * by Tyler Edwards | July 6th, 2024 
 * There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.
 * The operation of drinking a full water bottle turns it into an empty bottle.
 * Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.*/

 class Solution {
    public:
        int numWaterBottles(int numBottles, int numExchange) {
            if (numExchange > numBottles) return numBottles;
            return numExchange + numWaterBottles((numBottles - numExchange) + 1, numExchange);
        }
    };