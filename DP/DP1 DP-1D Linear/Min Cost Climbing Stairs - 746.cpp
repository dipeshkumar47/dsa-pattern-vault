
// 1: Recursive Code

class Solution {
public:

    int solve(int i, vector<int>& cost)
    {
        int n = cost.size();

        if(i >= n)
            return 0;

        return cost[i] + min(solve(i + 1, cost),
                             solve(i + 2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {

        return min(solve(0, cost),
                   solve(1, cost));
    }
};


// 2: Memoization (Top-Down DP)
class Solution {
public:

    int solve(int i, vector<int>& cost, vector<int>& dp)
    {
        int n = cost.size();

        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        return dp[i] = cost[i] +
               min(solve(i + 1, cost, dp),
                   solve(i + 2, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n, -1);

        return min(solve(0, cost, dp),
                   solve(1, cost, dp));
    }
};


// 3: Tabulation (Bottom-Up)
class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n + 2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }

        return min(dp[0], dp[1]);
    }
};



// 4: Space Optimization
class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        int next1 = 0; // dp[i+1]
        int next2 = 0; // dp[i+2]

        for(int i = n - 1; i >= 0; i--)
        {
            int curr = cost[i] + min(next1, next2);

            next2 = next1;
            next1 = curr;
        }

        return min(next1, next2);
    }
};

