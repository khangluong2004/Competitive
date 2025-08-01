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

    int n;
    cin >> n;

    unordered_map<int, int> cache;

    for (int i = 0; i < n; ++i)
    {
        int size;
        cin >> size;
        cache[size] += 1;
    }

    int nlargest = 0;
    int largest;
    for (auto &item : cache)
    {
        if (item.second > nlargest)
        {
            nlargest = item.second;
            largest = item.first;
        }
    }

    vector<vector<int>> output(nlargest);
    for (int i = 0; i < nlargest; ++i)
    {
        output[i] = {largest};
    }

    vector<int> sizes(nlargest, 1);

    for (auto &item : cache)
    {
        if (item.first == largest)
            continue;
        
        vector<int> indices;
        for (int i = 0; i < nlargest; ++i)
        {
            indices.push_back(i);
        }

        std::sort(indices.begin(), indices.end(), [&](int a, int b) { return sizes[a] < sizes[b]; });

        int totalitems = item.second;
        for (auto i : indices)
        {
            if (totalitems == 0)
                break;

            sizes[i] += 1;
            output[i].push_back(item.first);
            totalitems -= 1;
        }
    }

    cout << nlargest << endl;
    for (auto &o : output)
    {
        for (auto &i : o)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}