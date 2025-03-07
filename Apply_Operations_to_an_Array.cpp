// 2460. Apply Operations to an Array
// cpp Solution! problem-2460

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = i + 1;
        while (j <= n - 1 && i <= n)
        {
            if (nums[i] == nums[j])
            {
                nums[i] *= 2;
                nums[j] = 0;
            }

            i++;
            j++;
        }
        int notZero = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[notZero] = nums[i];
                if (notZero != i)
                {
                    nums[i] = 0;
                }
                notZero++;
            }
        }
        return nums;
    }
};