// 1422. Maximum Score After Splitting a String
// cpp Solution! problem-1422

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) 
    {
        int n = s.size();
        int maxScore = 0;

        // Step 1: Count total '1's in the string for the initial right count
        int rightOnes = 0;
        for (char c : s) 
        {
            if (c == '1') rightOnes++;
        }

        // Step 2: Calculate score while iterating
        int leftZeros = 0;
        for (int i = 0; i < n - 1; i++) 
        {
            if (s[i] == '0') leftZeros++;
            if (s[i] == '1') rightOnes--;

            maxScore = max(maxScore, leftZeros + rightOnes);
        }

        return maxScore;
    }
};

int main() 
{
    // Input example
    string s;
    cout << "Enter a binary string (0s and 1s): ";
    cin >> s;

    // Create an instance of Solution class
    Solution solution;
    int result = solution.maxScore(s);

    // Output the result
    cout << "Maximum Score After Splitting: " << result << endl;

    return 0;
}
