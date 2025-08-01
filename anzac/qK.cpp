#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
typedef vector<int> v32;
f64 eps = 1e-12;

#define print(x) cout << #x << " = " << x << '\n'
#define MAX 2e18
#define MIN -2e18
#define fast_cin()                                                                                                     \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

// void print_arr(int arr[], int n){
//     for (int i = 0; i < n; i++){
//         cout << arr[i] << "  ";
//     }
//     cout << endl;
// }

int main(){
    fast_cin();
    
    int capac;
    int time;
    int total_car;
    cin >> capac;
    cin >> time;
    cin >> total_car;

    // schedule
    int sched[total_car + 1];
    sched[0] = 0;
    for (int i=1; i <= total_car; i++){
        cin >> sched[i];
    }

    // time
    int dp[total_car+1];
    // trip
    int trip[total_car+1];

    for (int i=0; i <= total_car; i++){
        dp[i] = -1;
        trip[i] = 0;
    }

    dp[0] = 0;

    for (int i=1; i <= total_car; i++){
        int start = max(i-capac, 0);
        for (int j=start; j < i; j++){
            int cur_time = max(sched[i], dp[j]) + 2 * time;
            if (dp[i] == -1){
                dp[i] = cur_time;
                trip[i] = trip[j] + 1;
            } else{
                if (cur_time < dp[i]){
                    dp[i] = cur_time;
                    trip[i] = trip[j] + 1;
                } else if (cur_time == dp[i]){
                    trip[i] = min(trip[i], trip[j] + 1);
                }
            }
        }
    }

    // cout << "Time" << endl;
    // print_arr(dp, total_car + 1);
    // cout << "Trip" << endl;
    // print_arr(trip, total_car + 1);

    cout << dp[total_car] - time << " " << trip[total_car];
    return 0;
}