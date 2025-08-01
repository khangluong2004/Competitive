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

using v2 = pair<int, int>;

#define WALK_SPEED (166.667)
#define TRAM_SPEED (666.667)

double times(v2 start, v2 end, bool tram)
{
    double dist = sqrt(pow((double)start.first - end.first, 2) + pow((double)start.second - end.second, 2));
    // print(dist);
    // print(start.first);
    // print(start.second);
    // print(end.first);
    // print(end.second);
    if (tram)
    {
        return dist / TRAM_SPEED;
    }

    return dist / WALK_SPEED;
}

int main()
{
    fast_cin();

    v2 start, end;
    int n;
    cin >> start.first >> start.second >> end.first >> end.second >> n;

    // print(times(start, end, false));

    // lines[c] = {stops}
    unordered_map<int, int> mapping;
    vector<vector<int>> lines;
    vector<v2> coords;

    for (int i = 0; i < n; ++i)
    {

        lines.push_back({});
        while (true)
        {
            v2 coord;
            cin >> coord.first >> coord.second;

            if (coord.first == -1 && coord.second == -1)
            {
                break;
            }

            mapping[coords.size()] = i;
            lines[i].push_back(coords.size());
            coords.push_back(coord);
        }
    }

    int N = coords.size();
    coords.push_back(start);
    coords.push_back(end);

    vector<double> distances(N + 2, 0);
    vector<bool> visited(N + 2, false);

    for (int i = 0; i < N + 2; ++i)
    {
        distances[i] = times(start, coords[i], false);
    }

    visited[N] = true;
    // distances[n + 1] = 0.0f;

    // for remaining
    while (true)
    {
        int closest = 0;
        double distance = 1e9;
        for (int i = 0; i < N + 2; ++i)
        {
            if (visited[i])
                continue;

            if (distances[i] < distance)
            {
                closest = i;
                distance = distances[i];
            }
        }

        // print(closest);

        if (closest == N + 1)
        {
            
            cout << (int) round(distance);
            // cout << distance;
            return 0;
        }

        visited[closest] = true;

        vector<int> stops = lines[mapping[closest]];

        // update for all others
        for (int j = 0; j < N + 2; ++j)
        {
            if (visited[j])
                continue;

            // update times
            // if on the same tram
            // find the index
            bool ontram = false;
            for (int i = 0; i < stops.size(); ++i)
            {
                if (stops[i] == closest)
                {
                    if ((i-1 >= 0 && stops[i-1] == j) || (i+1 < stops.size() && stops[i+1] == j))
                    {
                        ontram = true;
                        break;
                    }
                }
            }


            if (ontram)
            {
                distances[j] = min(distances[j], distance + times(coords[closest], coords[j], true));
            }
            else
            {
                distances[j] = min(distances[j], distance + times(coords[closest], coords[j], false));
            }
        }
    }

    return 0;
}