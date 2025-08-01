// Question F

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

int modulo = (int) 1e9 + 7; 

#define prsize_t(x) cout << #x << " = " << x << '\n'
#define MAX 2e18
#define MIN -2e18
#define fast_cin()                                                                                                     \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

// void print_arr(int arr[], int n){
//     for (int i=0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

int main(){
    fast_cin();

    int n;
    cin >> n;
    string ans;
    cin >> ans;
    string solution;
    cin >> solution;

    int initial_score = 0;

    for (int i = 0; i < n; i++){
        if (ans[i] == solution[i]){
            initial_score++;
        }
    }

    int change = 0;
    char choice = 'A'-1;
    for (int i = 0; i < 5; i++){
        choice += 1;
        char another = 'A'-1;
        for (int j = 0; j < 5; j++){
            another += 1;
            if (choice == another){
                continue;
            }

            int temp = 0;
            for (int c=0; c < n; c++){
                if (ans[c] == choice){
                    if (choice == solution[c]){
                        temp--;
                    } else if (another == solution[c]){
                        temp++;
                    }
                }
            }

            // cout << choice << " " << another << " " << temp << endl;

            if (temp > change){
                change = temp;
            }
        }
        
    }

    cout << initial_score + change << endl;
    return 0;

}