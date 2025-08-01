#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
typedef vector<int> v32;
f64 eps = 1e-12;

#define print(x) cout << #x << " = " << x << '\n'
#define MAX 2e18
#define MIN -2e18
#define fast_cin()                                                                                                     \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

// void print_arr(int arr[], int n){
//     for (int i = 0; i < n; i++){
//         cout << arr[i] << "  ";
//     }
//     cout << endl;
// }

int main(){
    fast_cin();
    int time_red;
    int time_green;

    cin >> time_green;
    cin >> time_red;

    int pre_car;
    int pre_time;
    cin >> pre_car;
    cin >> pre_time;

    int light_phase;
    cin >> light_phase;


    int car_group[light_phase + 1];
    int time_group[light_phase + 1];
    for (int i = 0; i <= light_phase; i++){
        car_group[i] = 0;
        time_group[i] = 0;
    }

    car_group[0] = pre_car;
    time_group[0] = pre_time;
    // Car group
    int cur_ptr = 0;
    int new_ptr = 1;

    // Time pointer
    int time_ptr = 0;

    int max_queue = pre_car;
    int queue = pre_car;
    int time = 0;

    for (int i=0; i < light_phase; i++){
        char col;
        int num_car;
        cin >> col;
        cin >> num_car;

        // cout << "Car" << endl;
        // print_arr(car_group, light_phase + 1);
        // cout << "Time" << endl;
        // print_arr(time_group, light_phase + 1);

        if (col == 'G'){
            queue -= num_car;
            if (queue > max_queue){
                max_queue = queue;
            }
            if (car_group[cur_ptr] > num_car){
                car_group[cur_ptr] -= num_car;
            } else {
                car_group[cur_ptr] -= num_car;
                while (car_group[cur_ptr] <= 0){
                    time_group[time_ptr] += time;
                    // cout << time_ptr << " " <<  time_group[time_ptr] << endl;
                    car_group[cur_ptr + 1] += car_group[cur_ptr];
                    cur_ptr++;
                    time_ptr++;
                }
                
            }
            time += time_green;
        } else {
            queue += num_car;
            if (queue > max_queue){
                max_queue = queue;
            }
            car_group[new_ptr] = num_car;
            time_group[new_ptr] -= time;
            new_ptr++;
            time += time_red;
        }
    }

    cout << "Longest queue was " << max_queue;
    
    if (max_queue > 1){
        cout << " vehicles." << endl;
    } else {
        cout << " vehicle." << endl;
    }
    

    int max_time = -1;
    for (int i=0; i < light_phase; i++){
        // cout << "Time:"<< i <<" " << time_group[i] << endl;
        if (time_group[i] > max_time){
            max_time = time_group[i];
        }
    }

    int minutes = max_time / 60;
    int seconds = max_time % 60;

    cout << "Longest through time was ";
    if (minutes != 1){
        cout << minutes << " minutes and ";
    } else {
        cout << minutes << " minute and ";
    }

    if (seconds != 1){
        cout << seconds << " seconds." << endl;
    } else {
        cout << seconds << " second." << endl;
    }
    return 0;

}