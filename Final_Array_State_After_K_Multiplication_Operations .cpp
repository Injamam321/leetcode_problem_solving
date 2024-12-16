// 3264. Final Array State After K Multiplication Operations
// cpp Solution! problem-3264


#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        
        for (int op = 0; op < k; ++op) {
            // Step 1: Find the index of the minimum value
            int minIndex = 0;
            for (int i = 1; i < n; ++i) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }
            
            // Step 2: Multiply the minimum value by the multiplier
            nums[minIndex] *= multiplier;
        }
        
        // Return the final state of nums
        return nums;
    }
};
