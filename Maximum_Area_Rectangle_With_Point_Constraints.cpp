// 3380. Maximum Area Rectangle With Point Constraints I
// cpp Solution! problem-3380

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRectangleArea(vector<vector<int>> &nums)
    {
        int n = nums.size();
        unordered_set<string> mpp;

        // Step 1: Storing points in hashmap
        for (auto &i : nums)
        {
            mpp.insert(to_string(i[0]) + "," + to_string(i[1]));
        }

        int maxi = -1;

        // Step 2: Traversing over all points to find if a rectangle is valid using i as pivot
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x1 = nums[i][0], y1 = nums[i][1];
                int x2 = nums[j][0], y2 = nums[j][1];

                // Step 3: Making sure x and y is different
                if (x1 != x2 && y1 != y2)
                {
                    string s = to_string(x1) + "," + to_string(y2);
                    string s1 = to_string(x2) + "," + to_string(y1);

                    // Step 4: Check if the other two corners of the rectangle exist in the map.
                    if (mpp.count(s) && mpp.count(s1))
                    {
                        int area = abs(x1 - x2) * abs(y1 - y2);

                        // Step 5: Checking if no points are between the rectangle
                        if (valid(nums, x1, y1, x2, y2))
                        {
                            maxi = max(maxi, area);
                        }
                    }
                }
            }
        }

        // Step 6: Return max area
        return maxi;
    }

private:
    bool valid(vector<vector<int>> &nums, int x1, int y1, int x2, int y2)
    {
        int minx = min(x1, x2);
        int maxx = max(x1, x2);
        int miny = min(y1, y2);
        int maxy = max(y1, y2);
        // just checks that no points lie inside our rectangle cords
        for (auto &i : nums)
        {
            int px = i[0], py = i[1];
            if ((px > minx && px < maxx && py > miny && py < maxy) ||
                ((px == minx || px == maxx) && (py > miny && py < maxy)) ||
                ((py == miny || py == maxy) && (px > minx && px < maxx)))
            {
                return false;
            }
        }

        return true;
    }
};