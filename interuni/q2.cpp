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

// int find_max(int *lengths, int n){
//     int max_length = -1;
//     for (int i=0; i < n; i++){
//         if (lengths[i] > max_length){
//             max_length = lengths[i];
//         }
//     }
//     return max_length;
// }

// void print_arr(int *lengths, int n){
//     for (int i=0; i<n; i++){
//         cout << lengths[i] << " ";
//     }
//     cout << endl;
// }

int
main(int argc, char *argv[]){
    int n, k;
    cin >> n;
    
    int lengths[n];
    for (int i = 0; i < n; i++){
        cin >> lengths[i];
    }

    // cout << lengths[0] << endl;

    // int finish = 0;
    int one_done = 0;
    int count = 0;

    int min_length = 1000000001;
    int min_val = -1;

    int max_length = -1;
    int max_val = -1;

    for (int i=0; i < n; i++){
        if (min_length > lengths[i]){
            min_length = lengths[i];
            min_val = i;
        }

        if (max_length < lengths[i]){
            max_length = lengths[i];
            max_val = i;
        }

        if (lengths[i] == 0){
            one_done = 1;
            break;
        }
    }



    while (!one_done){
        // for (int i=0; i < n; i++){
        //     if (lengths[i] == 0){
        //         one_done = 1;
        //         break;
        //     }

        //     if (min_length > lengths[i]){
        //         min_length = lengths[i];
        //         min_val = i;
        //         break;
        //     }
            
        // }

        // if (one_done){
        //     break;
        // }

        int pre_min_val = min_val;
        for (int i=0; i < n; i++){
            if (i != pre_min_val){
                lengths[i] -= 1;
                
                if (lengths[i] == 0){
                    one_done = 1;
                }

                if (min_length > lengths[i]){
                    min_length = lengths[i];
                    min_val = i;
                }
            }
        }

        count++;

        if (one_done){
            break;
        }

    }

    if (one_done){
        count += max_val - count;
    }
    
    cout << count;

    return 0;

}