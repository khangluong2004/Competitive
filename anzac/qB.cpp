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

int main()
{
    fast_cin();

    int moves;
    for (int i = 0; i < 3; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        moves = t1 + t2;

        if (t1 == t2)
        {
            cout << "Doubles. "
                 << "Move forwards " << moves << " squares.";
            return 0;
        }
    }

    string yn;
    cin >> yn;

    if (yn == "n")
    {
        cout << "$50 fine. Move forwards " << moves << " squares.";
    }
    else
    {
        cout << "Use card. Move forwards " << moves << " squares.";
    }

    return 0;
}