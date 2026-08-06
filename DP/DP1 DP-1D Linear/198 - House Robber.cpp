//==============================================================
// LeetCode 198 - House Robber
// Pattern: Take / Not Take DP
//==============================================================

/*
--------------------------------------------------------------
1. RECURSION
Time  : O(2^n)
Space : O(n)
--------------------------------------------------------------
*/

class Solution {
public:

    int solve(int i, vector<int>& nums)
    {
        int n = nums.size();

        if(i >= n)                                // base
            return 0;

        int take = nums[i] + solve(i + 2, nums);   // take 

        int notTake = solve(i + 1, nums);          // skip

        return max(take, notTake);
    }

    int rob(vector<int>& nums)
    {
        return solve(0, nums);
    }
};


// 1st call of the solve() : take: at '0' + take at '2' 
//                       not take: go next, 0 + 1 = 1

// two possibility at each step: "rob current and the next to next house" or "skip".





/*
--------------------------------------------------------------
2. MEMOIZATION (Top Down DP)
Time  : O(n)
Space : O(n) + O(n) recursion stack
--------------------------------------------------------------
*/

class Solution {
public:

    int solve(int i, vector<int>& nums, vector<int>& dp)
    {
        int n = nums.size();

        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(i + 2, nums, dp);

        int notTake = solve(i + 1, nums, dp);

        return dp[i] = max(take, notTake);
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(0, nums, dp);
    }
};


/*
--------------------------------------------------------------
3. TABULATION (Bottom Up DP)
Time  : O(n)
Space : O(n)
--------------------------------------------------------------
*/

class Solution {
public:

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> dp(n + 2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            int take = nums[i] + dp[i + 2];

            int notTake = dp[i + 1];

            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};


/*
--------------------------------------------------------------
4. SPACE OPTIMIZATION
Time  : O(n)
Space : O(1)
--------------------------------------------------------------
*/

class Solution {
public:

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        int next1 = 0;
        int next2 = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            int take = nums[i] + next2;

            int notTake = next1;

            int curr = max(take, notTake);

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};




// House Robber II

//==============================================================
// LeetCode 213 - House Robber II
// Pattern: Circular House Robber
//
// Idea:
// Since first and last house are adjacent, we cannot rob both.
//
// Answer = max(
//      Rob houses [0 ... n-2],
//      Rob houses [1 ... n-1]
// )
//==============================================================



/*
--------------------------------------------------------------
1. RECURSION
Time  : O(2^n)
Space : O(n)
--------------------------------------------------------------
*/

class Solution {
public:

    int solve(int i, int end, vector<int>& nums)
    {
        if(i > end)
            return 0;

        int take = nums[i] + solve(i + 2, end, nums);  // Exclude last house

        int notTake = solve(i + 1, end, nums);  // Exclude first house

        return max(take, notTake);
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        int case1 = solve(0, n - 2, nums);

        int case2 = solve(1, n - 1, nums);

        return max(case1, case2);
    }
};



/*
--------------------------------------------------------------
2. MEMOIZATION (Top Down DP)
Time  : O(n)
Space : O(n)
--------------------------------------------------------------
*/

class Solution {
public:

    int solve(int i, int end, vector<int>& nums, vector<int>& dp)
    {
        if(i > end)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(i + 2, end, nums, dp); // Exclude last house

        int notTake = solve(i + 1, end, nums, dp);  // Exclude first house

        return dp[i] = max(take, notTake);
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = solve(0, n - 2, nums, dp1);

        int case2 = solve(1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};



/*
--------------------------------------------------------------
3. TABULATION (Bottom Up DP)
Time  : O(n)
Space : O(n)
--------------------------------------------------------------
*/

class Solution {
public:

    int solve(vector<int>& nums, int start, int end)
    {
        int size = end - start + 1;

        vector<int> dp(size + 2, 0);    

        for(int i = size - 1; i >= 0; i--)
        {
            int take = nums[start + i] + dp[i + 2];

            int notTake = dp[i + 1];

            dp[i] = max(take, notTake);
        }

        return dp[0];
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        int case1 = solve(nums, 0, n - 2);

        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};



/*
--------------------------------------------------------------
4. SPACE OPTIMIZATION (Most Optimal)
Time  : O(n)
Space : O(1)
--------------------------------------------------------------
*/

class Solution {
public:

    int solve(vector<int>& nums, int start, int end)
    {
        int next1 = 0;
        int next2 = 0;

        for(int i = end; i >= start; i--)
        {
            int take = nums[i] + next2;

            int notTake = next1;

            int curr = max(take, notTake);

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        int case1 = solve(nums, 0, n - 2);

        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};









