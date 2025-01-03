// 2270. Number of Ways to Split Array
// cpp Solution! problem-2270

#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0, prefixSum = 0;
        int count = 0;

        // Step 1: Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Step 2: Iterate through the array and calculate prefixSum and suffixSum
        for (int i = 0; i < n - 1; ++i) {
            prefixSum += nums[i];             // Update prefix sum
            long long suffixSum = totalSum - prefixSum; // Calculate suffix sum

            // Step 3: Check the condition
            if (prefixSum >= suffixSum) {
                count++;
            }
        }

        return count; // Return the total number of valid splits
    }
};
