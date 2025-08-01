#include <iostream>
#include <cmath>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

// For this problem: https://codeforces.com/gym/540206/problem/D
int getDistance(pair<int, int>& p1, pair<int, int>& p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int travellingRecurc(vector<pair<int, int>>& listPoints, vector<vector<long long>>& memo, 
int endNode, long long mask){
    // cout << "Node: " << endNode << endl;
    // cout << "Path: " << bitset<16>(mask) << endl;

    // The first node to visit (must always start at 0)
    if (mask == 0){
        return 0;
    }

    // Getting from first node to the endNode
    if (mask == 1){
        memo[endNode][mask] = getDistance(listPoints[endNode], listPoints[0]);
        return memo[endNode][mask];
    }

    if (memo[endNode][mask] != -1){
        return memo[endNode][mask];
    }

    int mini = -1;
    for (int j=1; j < listPoints.size(); j++){
        if (j == endNode){
            continue;
        }

        // Check if j is in the mask
        if ((mask & (1 << j)) == 0){
            continue;
        }

        int currentPathLength = travellingRecurc(listPoints, memo, j, mask - (1 << j)) 
            + getDistance(listPoints[j], listPoints[endNode]);

        if (mini == -1){
            mini = currentPathLength;
        } else {
            mini = min(mini, currentPathLength);
        }
    }

    memo[endNode][mask] = mini;
    return mini;
}


int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> listPoints(n + 1, pair<int, int>());

    listPoints[0].first = 0;
    listPoints[0].second = 0;

    for (int i=0; i < n; i++){
        cin >> listPoints[i].first;
    }

    for (int i=0; i < n; i++){
        cin >> listPoints[i].second;
    }

    // Each memo entry finds the shortest path to travel through all the nodes in mask
    // and end at node n (which is not in mask, except for the starting point)
    // 1st dimension - n: The node to be end at
    // 2nd dimension - mask: The node used to reach node n
    vector<vector<long long>> memo(n + 1, vector<long long>(1 << (n + 1), -1));
    int shortest = travellingRecurc(listPoints, memo, 0, ((1 << (n+1)) - 1));

    cout << shortest << endl;

    return 0;
}