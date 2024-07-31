/* Daily Question: 1105. Filling Bookcase Shelves
 * by Tyler Edwards | July 30th, 2024 
 * Code Credit: Bug_Exceeded
 * You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.
 * We want to place these books in order onto bookcase shelves that have a total width shelfWidth.
 * We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, 
 * then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. 
 * We repeat this process until there are no more books to place. 
 * Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books. 
 * - For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf. 
 * Return the minimum possible height that the total bookshelf can be after placing shelves in this manner. */

 class Solution {
    public:
        void print_dp(vector<int>& dp)
        {
            for(auto &x : dp)
            {
                printf("%d ", x);
            }
            printf("\n");
        }
        int minHeightShelves(vector<vector<int>>& books, int sw) 
        {
            int n = books.size();
            // init
            vector<int> dp(n + 1, 0);  // min height for book up to i (starting from 0)
            dp[0] = 0;
            
            // doing dp
            for(int i = 0; i < n; i++)
            {
                dp[i + 1] = dp[i] + books[i][1]; // Step 2- 1: on the new layer
                int sum = 0, h = 0;
                for(int j = i; j >= 0; j--)
                {
                    sum += books[j][0]; // try to put on current layer, rather than the new one
                    if(sum > sw) // the sum of width exceeds the shift width, unable to squeeze
                    {
                        break;
                    }
                    else // Step 2- 2: keep squeezing
                    {
                        h = max(h, books[j][1]); // get the tallest book for this layer
                        dp[i + 1] = min(dp[j] + h, dp[i + 1]); // for i + 1 th book it can either be the next layer, or this layer(try the combination to make 'one layer' as short as possible)
                        // printf("sum %d booksj_h %d h %d j %d dp[j] %d i %d dp[i + 1] %d\n", sum, books[j][1], h, j, dp[j], i, dp[i + 1]);
                    }
                }
                // print_dp(dp);
            }
            // print_dp(dp);
            return dp[n];
        }
    };