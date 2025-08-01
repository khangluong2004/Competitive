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

bool isset(string c1, string c2, string c3)
{
    for (int i = 0; i < 4; ++i)
    {
        unordered_set<char> chars;
        chars.emplace(c1[i]);
        chars.emplace(c2[i]);
        chars.emplace(c3[i]);

        if (!(chars.size() == 1 || chars.size() == 3))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    fast_cin();

    vector<string> cards(12);
    for (int i = 0; i < 12; ++i)
    {
        cin >> cards[i];
    }


    using p3 = vector<int>;
    vector<p3> sets;
    for (int a = 0; a < 12; ++a)
    {
        for (int b = a + 1; b < 12; ++b)
        {
            for (int c = b + 1; c < 12; ++c)
            {
                if (isset(cards[a], cards[b], cards[c]))
                {
                    p3 text = {a+1, b+1, c+1};
                    if (find(sets.begin(), sets.end(), text) == sets.end())
                    {
                        sets.push_back(text);
                    }

                    if (sets.size() == 6)
                    {
                        goto end;
                    }
                }
            }
        }
    }

end:
    sort(sets.begin(), sets.end());

    for (auto &text : sets)
    {
        for (auto &c : text)
        {
            cout << c << " ";
        }

        cout << endl;
    }


    return 0;
}