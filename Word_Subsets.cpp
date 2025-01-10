// 916. Word Subsets
// cpp Solution! problem-916

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<int> maxFreq(26, 0); // Maximum frequency required for each character

        // Calculate maximum frequency for each character from words2
        for (const string& word : words2) 
        {
            vector<int> freq(26, 0);
            for (char c : word) 
            {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) 
            {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> result;

        // Check each word in words1
        for (const string& word : words1) 
        {
            vector<int> freq(26, 0);
            for (char c : word) 
            {
                freq[c - 'a']++;
            }

            // Check if word satisfies maxFreq requirement
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) 
            {
                if (freq[i] < maxFreq[i]) 
                {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) 
            {
                result.push_back(word);
            }
        }

        return result;
    }
};
