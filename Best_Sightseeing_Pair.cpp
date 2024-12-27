// 1014. Best Sightseeing Pair
// cpp Solution! problem-1014

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int maxScore = 0;  
        int bestPrev = values[0];  

        for (int j = 1; j < values.size(); j++) 
        {
            maxScore = max(maxScore, bestPrev + values[j] - j);
            bestPrev = max(bestPrev, values[j] + j);
        }

        return maxScore;
    }
};
