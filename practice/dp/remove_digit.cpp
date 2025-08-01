#include <iostream>

using namespace std;

typedef long long i64;
#define fastcin() \
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL); \
    cout.tie(NULL)

int max_digit(int n){
    int max = -1;
    while (n > 0){
        int remain = n%10;
        if (remain > max){
            max = remain;
        }
        n /= 10;
    }
    return max;
}

int main(){
    int n;
    cin >> n;

    int dp[n+1];
    for (int i=0; i < 10; i++){
        dp[i] = 1;
    }

    for (int i=10; i<=n; i++){
        dp[i] = dp[i - max_digit(i)] + 1;
    }

    cout << dp[n] << endl;
    return 0;
}