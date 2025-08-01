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

#define fast_cin()                                                                                                     \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

int
main(){
    fast_cin();
    int n;
    cin >> n;
    
    vector<int> time(n, -1);
    for (int i=0; i < n; i++){
        cin >> time[i];
    }

    sort(time.begin(), time.end());

    int timePassed = 0;
    int totalPen = 0;
    int totalProb = 0;

    for (int i=0; i < n; i++){
        timePassed += time[i];
        if (timePassed > 300){
            break;
        }

        totalPen += timePassed;
        totalProb++;
    }

    cout << totalProb << " " << totalPen << endl;
}