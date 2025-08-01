#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long i64;
typedef long double f64;
typedef vector<i64> v64;
typedef vector<size_t> v32;
f64 eps = 1e-12;

#define MAX 2e18
#define MIN -2e18
#define fast_cin()                                                                                                     \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

int
main(){
    fast_cin();
    int n;
    int x;
    int mod = 1e9 + 7;
    cin >> n;
    cin >> x;

    int coins[n];
    for (int i=0; i < n; i++){
        cin >> coins[i];
    }
    
    long long dp[x+1];
    for (int i=0; i < x+1; i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int sum=1; sum <= x; sum++){
        for (int coin: coins){
            if (sum >= coin){
                dp[sum] += dp[sum -coin]; 
                dp[sum] %= mod;
            } 
        }
        // cout << dp[sum] << endl;
    }

      
   
    cout << dp[x] << '\n'; 
    return 0;
}