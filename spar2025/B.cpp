#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, H;
    cin >> n;
    cin >> H;

    vector<long long> temp(3, 0);
    bool possible = true;
    long long total = 0;
    for (int i=0; i < n; i++){
        cin >> temp[0];
        cin >> temp[1];
        cin >> temp[2];

        sort(temp.begin(), temp.end());

        if (temp[1] <= H){
            total += temp[0];
        } else if (temp[0] <= H){
            total += temp[1];
        } else {
            possible = false;
            break;
        }
    }

    if (!possible){
        cout << "impossible" << "\n";
    } else {
        cout << total << "\n";
    }
    return 0;
}