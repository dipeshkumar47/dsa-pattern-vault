
1. Pure Recursion (Brute Force) ❌ Not DP
// Time  : O(2^n)
// Space : O(n)  (Recursion Stack)

// Recurrence Relation:
// Ways(n) = Ways(n-1) + Ways(n-2)

class Solution {

    public int climbStairs(int n) {

        // Base Cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
}



2. Memoization (Top Down DP) ✅ DP + Recursion
    // Memoization = Recursion + Cache
    // "If already solved, don't solve again."

class Solution {

    int[] dp;

    public int climbStairs(int n) {

        dp = new int[n + 1];

        return solve(n);
    }

    private int solve(int n) {

        // Base Cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        // If answer already exists, return it.
        // This avoids repeated recursive calls.
        if (dp[n] != 0)
            return dp[n];

        // Store answer before returning.
        dp[n] = solve(n - 1) + solve(n - 2);

        return dp[n];
    }
}



3. Tabulation (Bottom Up DP) ✅ DP + Iteration
    // Tabulation = Bottom Up DP
    // Build answers from smallest problem to biggest.
    // No recursion is used.

class Solution {

    public int climbStairs(int n) {

        if (n == 1)
            return 1;

        int[] dp = new int[n + 1];

        // Base Cases
        dp[1] = 1;
        dp[2] = 2;

        // Build the table from bottom to top.
        for (int i = 3; i <= n; i++) {

            // Same recurrence relation
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
}


4. Space Optimized DP ✅
    // Space Optimization
    // Observe:
    // dp[i] depends only on dp[i-1] and dp[i-2].
    // So, no need to store the whole DP array.

class Solution {

    public int climbStairs(int n) {

        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        int prev2 = 1; // dp[1]
        int prev1 = 2; // dp[2]

        for (int i = 3; i <= n; i++) {

            int current = prev1 + prev2;

            // Shift values for next iteration
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
}





/*

Remember
Space Optimization is possible only when the current state depends on a few previous states.
Here:
dp[i]
    depends on
dp[i-1]
dp[i-2]
So only two variables are enough.




One final tip
Don't try to memorize these four codes. Instead, practice converting one into the next:
Recursion → Memoization → Tabulation → Space Optimization

If you can perform those transformations yourself on new problems, you've truly started thinking in 
DP rather than just remembering solutions. That's the skill interviewers are looking for.

*/


/*

① Understand the problem.

↓

② Write Pure Recursion.

↓

③ Identify the State.

↓

④ Identify the Choices.

↓

⑤ Write the Recurrence Relation. ⭐⭐⭐⭐⭐

↓

⑥ Add Memoization.

↓

⑦ Convert it to Tabulation.

↓

⑧ Optimize Space (if possible).

↓

*/




