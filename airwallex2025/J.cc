#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;  
    cin >> N >> K;
    vector<int>a(2 * N); 
    for(int i = 0; i < N; i++) { 
     cin >> a[i]; 
     a[N + i] = a[i]; 
    } 
    int64_t ans = 0; 
    int64_t sum = 0; 
    for(int i = 0; i < K; i++) { 
     sum += a[i]; 
    }
    ans = sum; 
    for(int i = K; i < 2 * N; i++) { 
     sum = sum - a[i - K]; 
     sum = sum + a[i]; 
     ans = max(ans, sum); 
    }
    cout << ans << '\n'; 
    return 0;
}