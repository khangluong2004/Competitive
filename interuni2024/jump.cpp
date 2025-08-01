#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, x, y;
    cin >> n >> x >> y;

    int diff = abs(x - y);

    vector<int> v;

    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;
        v.push_back(p);
    }
    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;
        v.push_back(p);
    }

    vector<int> g;

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            g.push_back(__gcd(v[i], v[j]));
        }
    }

    int isit = 0;

    for(int i = 0; i < g.size(); i++) {
        if(diff % g[i] == 0) {
            isit = 1;
       }
    }
    if(isit) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}