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

#define MAX 2e18
#define MIN -2e18
#define fast_cin()                                                                                                     \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)


int find_max(int *lengths, int n){
    int max_length = -1;
    for (int i=0; i < n; i++){
        if (lengths[i] > max_length){
            max_length = lengths[i];
        }
    }
    return max_length;
}

int check_equal(int *length, int n){
    for (int i = 0; i < n; i++){
        if (length[i] != length[0]){
            return 0;
        }
    }
    return 1;
}



int
main(int argc, char *argv[]){
    int n, k;
    cin >> n;
    
    int lengths[n];
    for (int i = 0; i < n; i++){
        cin >> lengths[i];
    }

    if (n == 2){
        cout << lengths[0] + lengths[1];
        return 0;
    }

    if (check_equal(lengths, n)){
        cout << 1 + find_max(lengths, n);
        return 0;
    }

    cout << find_max(lengths, n);

    return 0;
}