// 2466. Count Ways To Build Good Strings
// cpp Solution! problem-2466

#include <vector>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;  // Modulo value
        vector<long long> dp(high + 1, 0);  // DP array

        dp[0] = 1;  // Base case: one way to form an empty string

        // Update dp array
        for (int i = 1; i <= high; i++) {
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % MOD;  // Add '0'
            if (i >= one) dp[i] = (dp[i] + dp[i - one]) % MOD;    // Add '1'
        }

        long long result = 0;
        // Sum the results from low to high length
        for (int i = low; i <= high; i++) {
            result = (result + dp[i]) % MOD;  // Add dp[i] to result
        }

        return result;  // Return final result
    }
};
