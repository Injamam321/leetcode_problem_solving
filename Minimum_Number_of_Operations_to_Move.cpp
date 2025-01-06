// 1769.Minimum Number of Operations to Move All Balls to Each Box
// cpp Solution! problem-1769

class Solution 
{

public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.size();
        vector<int> answer(n, 0);
        int balls = 0, operations = 0;

        // Left-to-Right pass
        for (int i = 0; i < n; ++i) 
        {
            answer[i] += operations;
            balls += (boxes[i] == '1') ? 1 : 0;
            operations += balls;
        }

        balls = 0, operations = 0;

        // Right-to-Left pass
        for (int i = n - 1; i >= 0; --i) 
        {
            answer[i] += operations;
            balls += (boxes[i] == '1') ? 1 : 0;
            operations += balls;
        }
        return answer;
    }
};