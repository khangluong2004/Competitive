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

bool check_range(vector<pair<int, int>> &ranges, int start, int end){
    if (start >= end){
        return true;
    }

    int found_house = -1;
    for (int i=start; i <= end; i++){
        if (ranges[i].first <= start && ranges[i].second >= end){
            found_house = i;
            break;
        }

        // Traverse backward
        int back = end - (i-start);
        if (ranges[back].first <= start && ranges[back].second >= end){
            found_house = back;
            break;
        }
    }

    // cout << start << " " << end << endl;
    // cout << found_house << endl;

    if (found_house == -1){
        cout << "No " << start + 1 << " " << end + 1 << endl;
        exit(0);
        return false;
    }

    return check_range(ranges, start, found_house-1) && check_range(ranges, found_house + 1, end);
}

int 
main(){
    fast_cin();
    int n;
    cin >> n;

    int start;
    int end;
    vector<pair<int, int>> ranges(n);

    for (int i=0; i < n; i++){
        cin >> start;
        cin >> end;
        pair<int, int> cur_pair(start - 1, end - 1);
        ranges[i] =  cur_pair;
    }

    

    check_range(ranges, 0, n-1);
    cout << "Yes" << endl;
    return 0;

}

// Try to use binary search for searching interval
// Further complication, recheck later. Prob just use the for loop way

// int binary_less(vector<int> &arr, int start, int end, int elem){
//     // Find the index of first elem larger than elem
//     while (start <= end){
//         int mid = start + (end - start)/2;
//         if (arr[mid] > elem){
//             if (mid == 0){
//                 return 0;
//             }

//             if (arr[mid - 1] <= elem){
//                 return mid;
//             } else {
//                 end = mid - 1;
//             }
//         } else {
//             start = mid + 1;
//         }
//     }

//     return arr.size();
// }

// int binary_more(vector<int> &arr, int start, int end, int elem){
//     // Find the index of first elem smaller than elem
//     while (start <= end){
//         int mid = start + (end - start)/2;
//         if (arr[mid] < elem){
//             if (mid == arr.size() - 1){
//                 return arr.size();
//             }

//             if (arr[mid + 1] >= elem){
//                 return mid;
//             } else {
//                 start = mid + 1;
//             }
//         } else {
//             end = mid - 1;
//         }
//     }

//     return 0;
// }

// bool find_trader(unordered_map<int, vector<int>> &intervals, vector<int> &starts, 
//                     int start, int end){
//     // Find all start lower or equal to start
//     int lower_bound = 0;
//     if (start != 1){
//         lower_bound = binary_less(starts, 0, starts.size() - 1, start) - 1;
//     }

//     if (lower_bound == -1){
//         cout << "NO" << 1 << 2;
//     }

//     // Searching valid intervals for all elems larger than end
//     for (int i=0; i <= lower_bound; i++){
//         vector<int> &cur_list = intervals[starts[i]];
//         //
//     }
    
//     return true;
// }

// int
// main(){
//     fast_cin();
//     int n;
//     cin >> n;

//     // Map start val to vector of end vals
//     unordered_map<int, vector<pair<int, int>>> intervals;
    

//     int start;
//     int end;
//     for (int i=0; i<n; i++){
//         cin >> start;
//         cin >> end;
//         pair<int, int> cur_pair(i, end);
        
//         intervals[start].push_back(cur_pair);
//     }

//     // Sorted value of start val
//     vector<int> starts(intervals.size());

//     // Sort start and end vals
//     int i = 0;
//     sort(starts.begin(), starts.end());
//     for (auto& interval: intervals){
//         starts[i] = interval.first;
//         i++;
//         sort(interval.second.begin(), interval.second.end());
//     }
//     sort(starts.begin(), starts.end());


//     return 0;
// }