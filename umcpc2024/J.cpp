// Dd's solution
// The idea is to keep repeating the most profitable segment
// However, since the number of days might not be able to fit all full cycles,
// the naive dp used in I is still applied for the first 10k days, to cover those
// extra part-cycle

#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, x;
int a[1005];
int dp[10005][1005], maxdp[10005][1005];

void solve() {
    cin>>n>>m>>x;
    for(int i=0; i<m; i++) {
        cin>>a[i];
    }
    for(int i=1; i<m; i++) {
        dp[0][i] = -1000000000000000000;
        maxdp[0][i] = -1000000000000000000;
    }
    dp[0][0] = a[0];
    maxdp[0][0] = a[0];
    for(int i=1; i<=min(n-1, 10000ll); i++) {
        for(int j=m-1; j>=0; j--) {
            dp[i][j] = max(dp[i-1][j-1] + a[j], maxdp[i-1][j] + a[j] - x);
            if(j==m-1) dp[i][j] = max(dp[i][j], dp[i-1][j]);
            maxdp[i][j] = dp[i][j];
            if(j<m-1) maxdp[i][j] = max(maxdp[i][j], maxdp[i][j+1]);
        }
    }
    if(n-1 <= 10000) {
        cout<<maxdp[n-1][0];
    }
    else {
        int ans = maxdp[10000][0];
        for(int i=0; i<m; i++) {
            int ssum = 0;
            for(int j=i; j<m; j++) {
                ssum += a[j];
                int len = j-i+1;
                for(int pos=10000; pos>=9800; pos--) {
                    int cyccnt = (n - pos - 1) / len;
                    ans = max(ans, maxdp[pos][i] + cyccnt*(ssum - x));
                }
            }
        }
        cout<<ans;
    }
    cout<<endl;
}

signed main() {
    int tests;
    cin>>tests;
    for(int test=1; test<=tests; test++) {
        solve();
    }
}