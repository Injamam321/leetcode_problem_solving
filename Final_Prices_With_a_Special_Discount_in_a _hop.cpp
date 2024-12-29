// 1475. Final Prices With a Special Discount in a Shop
// cpp Solution! problem-1475

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> result(prices);
        stack<int> s; // Monotonic stack to store indices
        
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && prices[s.top()] >= prices[i]) 
            {
                result[s.top()] -= prices[i];
                s.pop();
            }
            s.push(i);
        }
        
        return result;
    }
};
