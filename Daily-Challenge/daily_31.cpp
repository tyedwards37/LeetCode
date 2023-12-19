/* Daily Question: 661. Image Smoother
 * by Tyler Edwards | December 18th, 2023 (Christmas! Just a week away!)
 * Code Credit: coderaky
 * An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). 
 * If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).
 * Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it. */

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
{
        vector<vector<int>>res = img;
        int m = img.size(), n = img[0].size();
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j<n; j++)
            {
                int avg = 0, c = 0;
                for (int x = max(i - 1, 0); x < min(i + 2, m); x++)
                    for (int y = max(j - 1, 0); y < min(j + 2, n); y++)
                        avg += img[x][y], c++;
                
                res[i][j] = avg/c;
            }
        }
        return res;
    }
};