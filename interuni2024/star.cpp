#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> stars;

    for (int i=0; i < n; i++){
        int x, y;
        cin >> x;
        cin >> y;
        stars.emplace_back(x, y);
    }

    sort(stars.begin(), stars.end());

    map<int, int> shooting;
    int count = 0;

    for (int i=0; i <n; i++){
        pair<int, int> curStar = stars[i];

        if (shooting.empty()){
            shooting[curStar.second] = 1;
            count += 1;
            continue;
        }

        // Otherwise, get the min star
        int highest = (*(--shooting.end())).first;
        if (curStar.second > highest){
            count += 1;
            shooting[curStar.second] = 1;
            continue;
        }

        int upper = (*(shooting.upper_bound(curStar.second))).first;
        shooting[upper] -= 1;
        if (shooting[upper] < 0){
            shooting.erase(upper);
        }

        shooting[curStar.second] += 1;     

         
    }

    cout << count << endl;


    return 0;
}