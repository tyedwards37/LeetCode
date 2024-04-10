/* Daily Question: 950. Reveal Cards In Increasing Order
 * by Tyler Edwards | April 9th, 2024 
 * Code Credit: lee215
 * You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].
 * You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.
 * You will do the following steps repeatedly until all cards are revealed:
 * 1. Take the top card of the deck, reveal it, and take it out of the deck.
 * 2. If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
 * 3. If there are still unrevealed cards, go back to step 1. Otherwise, stop.
 * Return an ordering of the deck that would reveal the cards in increasing order. */

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend()); // sorts the integers in the array
        deque<int> d; // creates a queue that we can use to store cards from the deck
        d.push_back(deck[0]); // pushes the top card of the deck to the back of the queue 
        for (int i = 1; i < deck.size(); i++) { // loop for the size of the deck
            d.push_front(d.back()); // takes the value at the back of the queue and pushes it to the front
            d.pop_back(); // pops the last value in the queue 
            d.push_front(deck[i]); // pushes the value at the current index of the deck to the front of the queue 
        }
        vector<int> res(d.begin(), d.end()); // creates a final array which contains the sorted queue 
        return res; // return the final ordered deck 
    }
};