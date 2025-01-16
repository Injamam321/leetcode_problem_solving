// 2425. Bitwise XOR of All Pairings
// cpp Solution! problem-2425

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int result = 0;

        // Check if the length of nums1 is odd
        if (nums1.size() % 2 == 1)
        {
            // If nums1 size is odd, XOR all elements of nums2 with the result
            for (int num : nums2)
            {
                result ^= num;
            }
        }

        // Check if the length of nums2 is odd
        if (nums2.size() % 2 == 1)
        {
            // If nums2 size is odd, XOR all elements of nums1 with the result
            for (int num : nums1)
            {
                result ^= num;
            }
        }

        return result;
    }
};
