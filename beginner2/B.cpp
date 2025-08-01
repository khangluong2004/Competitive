#include <iostream>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Return the first length to reach the endPoint
int bfs(unordered_map<int, vector<int>> &graph, int endPoint, int startPoint){
    queue<pair<int, int>> bfsQueue;
    unordered_set<int> visited;
    bfsQueue.emplace(startPoint, 0);

    while (!bfsQueue.empty()){
        // Get top point
        pair<int, int> topPoint = bfsQueue.front();
        bfsQueue.pop();

        visited.insert(topPoint.first);

        // Add the child
        for (auto child: graph[topPoint.first]){
            if (child == endPoint){
                return topPoint.second + 1;
            }

            if (visited.count(child) == 1){
                continue;
            }

            bfsQueue.emplace(child, topPoint.second + 1);
        }
    }

    return -1;
}

int main(){
    int t, n, d;
    cin >> t;
    for (int z=0; z < t; z++){
        cin >> n;
        cin >> d;

        unordered_map<int, vector<int>> graph;

        int rack, weight;

        for (int i=0; i < n; i++){
            cin >> rack;
            cin >> weight;
            graph[rack].push_back(weight); 
        }

        int shortestDistance = bfs(graph, 0, d);
        cout << shortestDistance << endl;
    }
}