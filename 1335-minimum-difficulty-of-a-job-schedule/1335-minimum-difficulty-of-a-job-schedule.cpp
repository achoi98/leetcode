class Solution {
public:
    int n, d;
    int memo[302][12];
    int hardestJobRemaining[302];
    
    int dp(int i, int day, vector<int>& jobDifficulty) {
        if (day == d) {
            return hardestJobRemaining[i];
        }
        
        if (memo[i][day] == -1) {
            int best = INT_MAX;
            int hardest = 0;
            
            // iterate through options, choose the best
            for (int j = i; j < n - (d - day); j++) {
                hardest = max(hardest, jobDifficulty[j]);
                best = min(best, hardest + dp(j + 1, day + 1, jobDifficulty));
                
            }
            memo[i][day] = best;
        }
        return memo[i][day];
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if (n < d) return -1;
        
        this->d = d;
        
        int hardestJob = 0;
        for (int i = n - 1; i >= 0; i--) {
            hardestJob = max(hardestJob, jobDifficulty[i]);
            hardestJobRemaining[i] = hardestJob;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                memo[i][j] = -1;
            }
        }
        return dp(0, 1, jobDifficulty);
    }
};