#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;


int main(){
    long long t;
    cin >> t;

    for (long long z=0; z < t; z++){
        long long n, m, x;
        cin >> n;
        cin >> m;
        cin >> x;

        vector<long long> profitGain(max(m, n), 0);

        for (long long i=0; i < m; i++){
            cin >> profitGain[i];
        }


        // Dp: 1st dim = Day, 2nd dim = hair length
        vector<vector<long long>> dp(n, vector<long long>(m + 1, 0));

        dp[0][0] = profitGain[0];

        for (long long i=1; i < n; i++){
            long long maxFromTop = dp[i-1][m];
            long long maxHairLength = m;

            for (long long j=min(i, m); j >= 1; j--){
                if (j == m){
                    dp[i][j] = dp[i-1][j];
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                    continue;
                }

                // Update maxFromTop
                if (dp[i-1][j] > maxFromTop){
                    maxFromTop = dp[i-1][j];
                    maxHairLength = j;
                }

                // Keep hair
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + profitGain[j]);

                // Cut hair
                dp[i][j] = max(dp[i][j], dp[i-1][maxHairLength] + profitGain[j] - x);
            }

            // Check for zero
            if (dp[i-1][0] > maxFromTop){
                maxFromTop = dp[i-1][0];
                maxHairLength = 0;
            }
            dp[i][0] = dp[i-1][maxHairLength] + profitGain[0] - x;
        }

        // for (int i=0; i < n; i++){
        //     for (int j=0; j <= m; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        long long maxProfit = -1;
        for (long long i=0; i <= m; i++){
            maxProfit = max(maxProfit, dp[n-1][i]);
        }
        cout << maxProfit << endl;

    }

}