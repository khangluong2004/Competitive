#include "stdc++.h"

using namespace std;

class UnionFind{
private:
    vector<int> link;
    vector<int> size;
public:
    UnionFind(int n): link(n, 0), size(n, 0){
        // Input the number of node
        // Initialize each node to link to itself

        for (int i=0; i < n; i++){
            link[i] = i;
            size[i] = 1;
        }
    }

    bool same(int a, int b){
        return link[a] == link[b];
    }

    int find(int a){
        // Find the root of the set containing a
        if (link[a] == a) return a;
        link[a] = find(link[a]);
        return link[a];
    }

    void unite(int a, int b){
        // Join the set containing a and b
        a = find(a);
        b = find(b);

        if (size[a] < size[b]){
            int temp = a;
            a = b;
            b = temp;
        }

        link[b] = a;
        size[a] += size[b];

    }

    void printList(vector<int> list){
        for (auto elem: list){
            cout << elem << " ";
        }
        cout << endl;
    }
};

vector<tuple<int, int, int>> kruskal(vector<tuple<int, int, int>> edges, int n){
    sort(edges.begin(), edges.end(), [](auto const& edge1, auto const& edge2){
        return (get<2>(edge1) < get<2>(edge2));
    });

    vector<tuple<int, int, int>> spanningTree;
    UnionFind unionFind(n + 1);

    for (auto& edge: edges){
        int from, to, weight;
        tie(from, to, weight) = edge;

        cout << from << " " << to << " " << weight << endl;

        if (!unionFind.same(from, to)){
            cout << "Unite" << endl;
            unionFind.unite(from, to);
            spanningTree.emplace_back(from, to, weight);
        }
    }

    cout << "Finish Kruskal" << endl;

    return spanningTree;
}

int main(int argc, char* argv[]){
    vector<tuple<int, int, int>> edges;

    int n = 4;
    edges.emplace_back(1, 2, 3);
    edges.emplace_back(2, 3, 4);
    edges.emplace_back(2, 4, 5);
    edges.push_back({3, 4, 6});

    cout << (get<2>(edges[0]) < get<2>(edges[1])) << endl;

    vector<tuple<int, int, int>> spanningTree = kruskal(edges, n);

    cout << spanningTree.size() << endl;

    for (auto &edge: spanningTree){
        cout << get<0>(edge) << " " << get<1>(edge) << " " << get<2>(edge) << endl;
    }

    return 0;
}