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

pair<int, int> bulls(string target, string guess)
{

    vector<bool> bulled(guess.size(), false);
    int nbulls = 0;

    // check for bulls
    for (int i = 0; i < guess.size(); ++i)
    {
        if (guess[i] == target[i])
        {
            bulled[i] = true;
            nbulls += 1;
        }
    }

    vector<bool> cowed(guess.size(), false);
    int cows = 0;
    for (int i = 0; i < guess.size(); ++i)
    {
        if (bulled[i])
            continue;

        bool any = false;
        for (int j = 0; j < target.size(); ++j)
        {
            if (bulled[j] || cowed[j])
                continue;
            
            if (target[j] == guess[i])
            {
                cows += 1;
            cowed[j] = true;
            any = true;
            }
        }
    }

    return {nbulls, cows};
}

string cap(int n)
{
    if ( n == 1)
    {
        return "";
    }
    return "s";
}

int main()
{
    fast_cin();

    string target;
    cin >> target;

    int k = 0;
    for (;;)
    {
        k += 1;

        string text;
        cin >> text;

        if (text == "GIVE")
        {
            cout << "The word was not guessed. Answer: " << target << ".";
            return 0;
        }

        auto d = bulls(target, text);
        cout << text << " Score " << d.first << " bull" << cap(d.first) << " and " << d.second << " cow" << cap(d.second)  << "." << endl;

        if (d.first == text.size())
        {
            cout << "The word was guessed in " << k << ".";
            return 0;
        }
    }

    return 0;
}