#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> dist(n, 0);
    vector<int> tree(n, 0);
    vector<int> buffer(n, 0);

    for (int i=0; i < n; i++){
        cin >> dist[i];
        cin >> tree[i];
        cin >> buffer[i];
    }

    vector<int> minLeft(n, 0);
    vector<int> minRight(n, 0);

    minLeft[0] = tree[0];
    minRight[n - 1] = tree[n - 1];

    for (int i=1; i < n; i++){
        minLeft[i] = min(minLeft[i-1], tree[i]);
    }

    for (int i=n-2; i >= 0; i--){
        minRight[i] = min(minRight[i+1], tree[i]);
    }

    // Find min
    int minTotal = 2000000000;

    for (int i=0; i < n; i++){
        // To the left
        int lower = dist[i] - buffer[i] - 1;
        int upper = dist[i] + buffer[i] + 1;

        // cout << "Elem " << i << " " << lower << " " << upper << endl;

        if (lower >= 0){
            auto it = lower_bound(dist.begin(), dist.end(), lower);
            int index = distance(dist.begin(), it);
            // cout << "Left bound " << index << endl; 
            
            if (dist[index] <= lower){
                minTotal = min(minTotal, tree[i] + minLeft[index]);
            } else {
                if (index > 0){
                    minTotal = min(minTotal, tree[i] + minLeft[index - 1]);
                }
            }
        }
        

        // To the right
        auto itR = lower_bound(dist.begin(), dist.end(), upper);
        if (itR != dist.end()){
            int index = distance(dist.begin(), itR);
            // cout << "Right bound " << index << endl; 
            minTotal = min(minTotal, tree[i] + minRight[index]);
        }

        // cout << "Minimum " << minTotal << endl;
    }

    if (minTotal == 2000000000){
        cout << "Delay" << endl;
    } else {
        cout << "Proceed" << endl;
        cout << minTotal << endl;
    }

    return 0;
}