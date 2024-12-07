# 1760. Minimum Limit of Balls in a Bag
# Python3 Solution! problem-1760

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
    
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;

        
        auto canDivide = [&](int x) {
            int operations = 0;
            for (int num : nums) {
                operations += (num - 1) / x; 
                if (operations > maxOperations) return false; 
            }
            return true;
        };

      
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDivide(mid)) {
                result = mid; 
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }

        return result;
    }
};

