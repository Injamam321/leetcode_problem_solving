// 2559. Count Vowel Strings in Ranges
// cpp Solution! problem-2559

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        // Step 1: Define a set of vowels
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();

        // Step 2: Create a prefix sum array
        vector<int> prefixSum(n + 1, 0);

        for (int i = 0; i < n; ++i) 
        {
            // Check if the word starts and ends with vowels
            char first = words[i][0];
            char last = words[i].back();
            
            if (vowels.count(first) && vowels.count(last)) 
            {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } 
            else 
            {
                prefixSum[i + 1] = prefixSum[i];
            }
        }

        // Step 3: Answer the queries
        vector<int> result;
        for (const auto& query : queries) {
            int li = query[0], ri = query[1];
            result.push_back(prefixSum[ri + 1] - prefixSum[li]);
        }

        return result;
    }
};

int main() 
{
    // Input example
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};

    // Solve the problem
    Solution solution;
    vector<int> result = solution.vowelStrings(words, queries);

    // Output the result
    for (int res : result) 
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
