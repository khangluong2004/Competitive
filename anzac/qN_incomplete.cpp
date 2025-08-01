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

    int L, R;
    cin >> L >> R;

    int size = (R - L) / 2 + 1;

    vector<int> heights(size);
    for (int i = 0; i < size; ++i)
    {
        cin >> heights[i];
    }

    // middle is
    int left = (-L) / 2;
    int right = left + 1;

    // print(left);
    // print(right);
    vector<int> weights(size - 1, 0);
    while (left >= 0 && right < size)
    {

        if (heights[right] < heights[left])
        {
            // fill all the way til left or equal
            for (int i = right - 1; i >= left; --i)
            {
                weights[i] = heights[right];
                if (heights[i] >= heights[right])
                {
                    break;
                }
            }

            right += 1;
        }
        else if (heights[left] < heights[right])
        {
            for (int i = left + 1; i <= right; ++i)
            {
                weights[i - 1] = heights[left];
                if (heights[i] >= heights[left])
                {
                    break;
                }
            }

            left -= 1;
        }
        else
        {
            int term = 0;
            for (int i = left + 1; i <= right; ++i)
            {
                weights[i - 1] = heights[left];
                if (heights[i] >= heights[left])
                {
                    term = i;
                    break;
                }
            }


             for (int i = right - 1; i >= term; --i)
            {
                weights[i] = heights[right];
                if (heights[i] >= heights[right])
                {
                    break;
                }
            }

            left -= 1;
            right += 1;
        }
    }

    int total = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        total += weights[i];
    }

    cout << total * 2 << endl;
    return 0;
}