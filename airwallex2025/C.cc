#include <bits/stdc++.h> 

using namespace std; 

#define int64_t long long 

const int64_t oo = 1e18; 


int main(void) {
 int N;
 cin >> N; 
 vector<array<int64_t, 3>>a(N);
 vector<int>coord;  
 for(int i = 0; i < N; i++) { 
  cin >> a[i][0]; 
  coord.push_back(a[i][0]); 
 }
 for(int i = 0; i < N; i++) { 
  cin >> a[i][1] >> a[i][2]; 
 }
 sort(a.begin(), a.end());
 sort(coord.begin(), coord.end()); 
 int64_t sum_b = 0, sum_bll = 0, sum_bl = 0, sum_a = 0, sum_al = 0; 
 for(int i = 0; i < N; i++) { 
  sum_bll += 1LL * a[i][2] * a[i][0] * a[i][0]; 
  sum_bl  += 1LL * a[i][0] * a[i][2]; 
  sum_b  += a[i][2]; 
  sum_a  += a[i][1]; 
  sum_al += 1LL * a[i][0] * a[i][1]; 
 }
 vector<int64_t>prefix_al(N), prefix_a(N); 
 for(int i = 0; i < N; i++) { 
  prefix_a[i]  = (i ? prefix_a[i - 1] : 0) + a[i][1];
  prefix_al[i] = (i ? prefix_al[i - 1] : 0) + 1LL * a[i][1] * a[i][0]; 
 }
 int64_t ans = oo; 
 for(int p = 0; p <= 1000006; p++) { 
  int pos = upper_bound(coord.begin(), coord.end(), p) - coord.begin(); 
  pos--; 
  if(pos < 0) { 
    ans = min(ans, sum_al - 1LL * p * sum_a +  
                   1LL * sum_bll - 2LL * p * sum_bl + 1LL * sum_b * p * p); 
    continue; 
  }
  if(coord[pos] == p) continue;  
  ans = min(ans, -prefix_al[pos] + 1LL * prefix_a[pos]  * p + 
                 1LL * (sum_al - prefix_al[pos]) -  1LL * (sum_a - prefix_a[pos]) * p + 
                 1LL * sum_bll - 2LL * p * sum_bl + 1LL * sum_b * p * p); 
 }
 cout << ans << '\n'; 
 return 0;   
}