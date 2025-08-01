#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;
#define fast_cin()\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL)


int main(){
    fast_cin();

    int N;
    int limit;
    cin >> N;
    cin >> limit;

    vector<pair<int, int>> gpu_inf(N);
    for (int i=0; i < N; i++){
        cin >> gpu_inf[i].first;
        cin >> gpu_inf[i].second;
    }

    // sort(gpu_inf.begin(), gpu_inf.end(), [](pair<int, int> s1, pair<int, int> s2) -> bool
    //     {
    //         return s1.first > s2.first;
    //     });


    int dp[limit+1];
    
    for (int i=0; i <= limit; i++){
        dp[i] = -1;
    }

    dp[0] = 0;

    for (int i=0; i < N; i++){

        for (int j=limit - gpu_inf[i].second; j >= 0; j--){
            if (dp[j] != -1){
                int cur_cost = dp[j] + gpu_inf[i].first;

                if (dp[j + gpu_inf[i].second] == -1){
                    dp[j + gpu_inf[i].second] = cur_cost;
                } else {
                    dp[j + gpu_inf[i].second] = min(cur_cost, dp[j + gpu_inf[i].second]);
                }

            }
        }

    }

   

    for (int i=limit; i>=0; i--){
        if (dp[i] != -1){
            cout << dp[i];
            return 0;
        }
    }


    return 0;
}