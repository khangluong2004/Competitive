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

string cap(int n)
{
    if (n == 1)
        return "";
    return "s";
}

int main()
{
    fast_cin();

    int n;
    cin >> n;

    unordered_map<string, int> votes;
    for (int i = 0; i < n; ++i)
    {
        string name;
        cin >> name;

        votes[name] += 1;
    }

    int highest = 0;
    vector<string> names;
    for (auto &item : votes)
    {
        if (item.second > highest)
        {
            highest = item.second;
            names.clear();
            names.push_back(item.first);
        }
        else if (item.second == highest)
        {
            names.push_back(item.first);
        }
    }

    // second highest
    int secondhighest = 0;
    for (auto &item : votes)
    {
        if (find(names.begin(), names.end(), item.first) != names.end())
        {
            continue;
        }
        secondhighest = std::max(secondhighest, item.second);
    }

    if (names.size() == 1)
    {
        int by = highest - secondhighest;
        cout << names[0] << " won by " << by << " vote" << cap(by) << ".";
        return 0;
    }

    cout << "Tie between ";
    std::sort(names.begin(), names.end());
    for (int i = 0; i < names.size(); ++i)
    {
        cout << names[i];
        if (i + 1 < names.size())
        {
            cout << ", ";
        }
        else {
            cout << ".";
        }
    }

    return 0;
}