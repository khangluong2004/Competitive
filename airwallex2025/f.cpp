#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);  
    
    int r, c;
    cin >> r >> c;
    int a[r][c];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    int m;
    cin >> m;
    int thing = 1;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(i % 2 == 0) {
            if(a[x][y] == 1) {
                thing = 0;
                break;
            }
        } else {
            if(a[x][y] == 0) {
                thing = 0;
                break;
            }
        }
    }
    if(thing) {
        cout << "Air-Wall-Exit" << endl;
    } else {
        cout << "DEAD" << endl;
    }
}