#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> countMap(100005, 0);

    int cur;
    for (int i=0; i < 3 * n; i++){
        cin >> cur;
        countMap[cur] += 1;
    }

    int start = 1;
    for (; start <= 100000; start++){
        if (countMap[start] != 0){
            break;
        }
    }

    string result = "";
    for (int i=start; i <= 100000; i++){
        if (countMap[i] == 0){
            continue;
        }

        int group3 = countMap[i] / 3;
        int remain3 = countMap[i] % 3;

        for (int j=0; j < group3; j++){
            result += to_string(i) + " " + to_string(i) + " " + to_string(i) + "\n";
        }

        if (countMap[i + 1] < remain3 || countMap[i + 2] < remain3){
            cout << "Impossible" << endl;
            return 0;
        }

        countMap[i+1] -= remain3;
        countMap[i+2] -= remain3;

        for (int j=0; j < remain3; j++){
            result += to_string(i) + " " + to_string(i + 1) + " " + to_string(i + 2) + "\n";
        }
    }

    cout << "Forgiven" << endl;
    cout << result;
    
    return 0;
}