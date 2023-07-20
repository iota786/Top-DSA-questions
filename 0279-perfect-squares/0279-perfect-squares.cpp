class Solution {
public:
    int numSquares(int n) {
        vector<int> memo(n+1, -1);
        return solve(n, memo); 
    }

private:
    int solve(int n, vector<int>& memo) {
        if (n == 0) return 0;
        if (memo[n] != -1) return memo[n];
        int result = INT_MAX;
        for (int i = 1; i*i <= n; i++) {
            result = min(result, 1 + solve(n - i*i, memo));
        }
        return memo[n] = result;
    }
};