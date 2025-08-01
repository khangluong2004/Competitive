#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long i64;
typedef long double f64;
typedef vector<i64> v64;
typedef vector<size_t> v32;
f64 eps = 1e-12;

#define prsize_t(x) cout << #x << " = " << x << '\n'
#define MAX 2e18
#define MIN -2e18
#define fast_cin()                                                                                                     \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)


int main(){
    fast_cin();
    int n;
    cin >> n;

    int grid[5][15];

    for (int i=0; i < 5; i++){
        for (int j = 0; j < 15; j++){
            grid[i][j] = 0;
        }
    }

    for (int i=0; i < n; i++){
        char save;
        int horizon;
        int vert;

        cin >> save;
        cin >> horizon;
        cin >> vert;

        if (save == 'G'){
            grid[4 - vert][horizon] += 1;
        } else {
            grid[4 - vert][horizon] -= 1;
        }
    }

    vector<pair<int, int>> places;
    int max = -1;
    for (int i=0; i < 5; i++){
        for (int j = 0; j < 15; j++){
            if (grid[i][j] > max){
                max = grid[i][j];
            }
        }
    }

    for (int j=0; j < 15; j++){
        for (int i=4; i >= 0; i--){
            if (grid[i][j] == max){
                places.push_back({4-i, j});
            }
        }
    }

    if (places.size() <= 1){
        cout << "Best place ";
    } else {
        cout << "Best places ";
    }

    for (int i =0; i < places.size() - 1; i++){
        cout << places[i].second << " " << places[i].first << ", "; 
    }

    pair<int, int> last = places[places.size() - 1];
    cout << last.second << " " << last.first << "." << endl;

    return 0;

}