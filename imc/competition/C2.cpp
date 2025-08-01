#include <bits/stdc++.h>

using namespace std;

void updateSegTree(vector<int>& tree, int i, int x, int n){
    i += n;
    tree[i] = x;

    int start = i;
    int next;
    while (start > 1){
        next = start/2;
        tree[next] = min(tree[next * 2], tree[next * 2 + 1]);
        start = next;
    }
}

int rangeQuery(vector<int>& tree, int a, int b, int n){
    // cout << "Range query 1 " << a << " " << b << endl;
    a += n;
    b += n;
    int mini = tree[a];

    // cout << "Range query 2 " << a << " " << b << endl;
    if (a == b){
        return mini;
    }

    while (a <= b){
        // cout << a << " " << b << " " << mini << endl;
        if (a % 2 == 0){
            a = a/2;
        } else {
            mini = min(mini, tree[a]);
            a = (a + 1) / 2;
        }

        if (b % 2 == 1){
            b = b / 2;
        } else {
            mini = min(mini, tree[b]);
            b = (b - 1) / 2;
        }
    }

    return mini;
}

int main(){
    int n;
    cin >> n;

    int size = 1;
    while (size < n){
        size *= 2;
    }
    int paddN = size;
    size = size * 2 - 1;

    vector<int> segTree(size + 1, 2000000001);

    vector<int> dist(n, 0);
    vector<int> tree(n, 0);
    vector<int> buffer(n, 0);

    vector<pair<int, int>> sortBuffer;

    for (int i=0; i < n; i++){
        cin >> dist[i];
        cin >> tree[i];
        cin >> buffer[i];

        updateSegTree(segTree, i, tree[i], paddN);
        sortBuffer.emplace_back(buffer[i], i);
    }

    // for (int i=1; i <= size; i++){
    //     cout << segTree[i] << " ";
    // }

    // cout << endl << endl;

    sort(sortBuffer.begin(), sortBuffer.end());

    // cout << rangeQuery(segTree, 0, 2, paddN) << endl;
    // return 0;

    // Find min
    int minTotal = 2000000001;

    for (int bufferIndex=n-1; bufferIndex > 0; bufferIndex--){
        int i = sortBuffer[bufferIndex].second;

        // To the left
        int lower = dist[i] - buffer[i] - 1;
        int upper = dist[i] + buffer[i] + 1;

        // cout << "Elem " << i << " " << lower << " " << upper << endl;

        if (lower >= 0){
            auto it = lower_bound(dist.begin(), dist.end(), lower);
            int index = distance(dist.begin(), it);
            
            if (dist[index] <= lower){
                minTotal = min(minTotal, tree[i] + rangeQuery(segTree, 0, index, paddN));
                // cout << "Left bound " << index << " " << rangeQuery(segTree, 0, index, paddN) << endl;
            } else {
                if (index > 0){
                    minTotal = min(minTotal, tree[i] + rangeQuery(segTree, 0, index - 1, paddN));
                    // cout << "Left bound less " << index - 1 << " " << rangeQuery(segTree, 0, index - 1, paddN) << endl;
                }
            }
        }
        

        // To the right
        auto itR = lower_bound(dist.begin(), dist.end(), upper);
        if (itR != dist.end()){
            int index = distance(dist.begin(), itR);
            // cout << "Right bound " << index << " " << rangeQuery(segTree, index, n - 1, paddN) << endl;
            minTotal = min(minTotal, tree[i] + rangeQuery(segTree, index, n - 1, paddN));
        }

        // Remove the index from seg tree
        updateSegTree(segTree, i, 2000000001, paddN);

        // cout << "Minimum " << minTotal << endl;
    }

    if (minTotal >= 2000000001){
        cout << "Delay" << endl;
    } else {
        cout << "Proceed" << endl;
        cout << minTotal << endl;
    }



    
    return 0;
}