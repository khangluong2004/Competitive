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
typedef vector<size_t> v32;
f64 eps = 1e-12;

#define prsize_t(x) cout << #x << " = " << x << '\n'
#define MAX 2e18
#define MIN -2e18
#define fast_cin()                                                                                                     \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

void merge(size_t originalArr[], size_t start, size_t mid, size_t end, unordered_map<size_t, size_t> &L,
           unordered_map<size_t, size_t> &swaps)
{
    // sort the lower and upper range
    vector<size_t> lower;
    for (size_t i = start; i < mid; ++i)
        lower.push_back(originalArr[i]);

    vector<size_t> top;
    for (size_t i = mid; i < end; ++i)
        top.push_back(originalArr[i]);

    std::sort(lower.begin(), lower.end());
    std::sort(top.begin(), top.end());

    // this computes the number of (large, small) pairs
    // where large is in lower, small is in top
    size_t i = 0, j = 0;
    while (i < lower.size() && j < top.size())
    {
        if (lower[i] < top[j])
        {
            ++i;
            continue;
        }

        if (L.count(top[j]) == 0)
            L[top[j]] = 0;
        else
            swaps[L[top[j]]] -= 1;

        // this adds the number of elements larger than top[j] to L[i]
        L[top[j]] += lower.size() - i;

        // and this increments the number of elements with L[i]
        swaps[L[top[j]]] += 1;

        ++j;
    }
}

// but with swaps instead
void inversion_count(size_t originalArr[], size_t start, size_t end, unordered_map<size_t, size_t> &L,
               unordered_map<size_t, size_t> &swaps)
{
    if (start + 1 < end)
    {
        size_t mid = start + (end - start) / 2;
        merge(originalArr, start, mid, end, L, swaps);
        inversion_count(originalArr, start, mid, L, swaps);
        inversion_count(originalArr, mid, end, L, swaps);
    }
}

int main()
{
    fast_cin();

    size_t n;
    cin >> n;

    vector<size_t> series(n);
    for (size_t i = 0; i < n; ++i)
        cin >> series[i];

    // better way

    // L[i] represents the number of elements before x_i which are larger
    unordered_map<size_t, size_t> L;
    // swaps[i] represents number of elements with L[i] = i
    unordered_map<size_t, size_t> swaps;
 
    inversion_count(series.data(), 0, series.size(), L, swaps);

    // the largest L[i]
    size_t max = 0;
    for (auto &e : L)
        max = std::max(e.second, max);

    cout << max << "\n";

    // to compute the top down accumulation of L[i]s to get swaps
    // newswaps[i] = swaps[i] + swaps[i+1] + swaps[i+2] + ...
    vector<int> newswaps(max);
    int accum = 0;
    for (size_t i = max; i > 0; --i)
    {
        accum += swaps[i];
        newswaps[i-1] = accum;
    }

    for (size_t i = 0; i < max; ++i)
    {
        cout << newswaps[i] << "\n";
    }
    return 0;
}