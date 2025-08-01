#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    vector<int> start(n, 0);

    // Value of 1st column
    int maximum = -2000000;
    int minimum = 2000000;

    for (int i=0; i < n; i++){
        cin >> nums[i];
        start[i] = nums[i] - i;
        maximum = max(maximum, start[i]);
        minimum = min(minimum, start[i]);
    }

    maximum += 1;
    minimum -= 1;

    // Sort from largest to smallest
    // by retracting to the start of the line
    sort(start.rbegin(), start.rend());
    long long cur_total = 0;

    for (int i=0; i < n; i++){
        cur_total += (maximum - start[i]);
    }

    long long min_cost = cur_total;
    int start_ptr = 0;
    int num_past = 0;


    for (int i=maximum; i >= minimum; i--){
        while (start_ptr < start.size() && start[start_ptr] == i){
            num_past += 1;
            start_ptr += 1;
        }

        cur_total += num_past;
        cur_total -= (n - num_past);
        min_cost = min(min_cost, cur_total);
    }

    cout << min_cost << "\n";

    return 0;
}
