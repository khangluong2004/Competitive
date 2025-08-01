#include <bits/stdc++.h> 
using namespace std;


int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<long long>> amount(n);

    long long tempIn;
    for (int i=0; i < n; i++){
        for (int j=0; j < 4; j++){
            cin >> tempIn;
            amount[i].push_back(tempIn);
        }
    }

    vector<vector<long long>> price(n);
    long long sum = 0;
    for (int i=0; i < n; i++){
        for (int j=0; j < 4; j++){
            cin >> tempIn;
            price[i].push_back(tempIn);
            sum += tempIn * amount[i][j];
        }
    }

    vector<long long> cheapSoFar(4, -1);
    for (int j=0; j < 4; j++){
        cheapSoFar[j] = price[0][j];
    }


    long long gain = 0;
    vector<pair<long long, int>> temp(4);
    for (int i=1; i < n; i++){
        // cout << "DAY" << i << endl;
        for (int j=0; j < 4; j++){
            if (price[i][j] <= cheapSoFar[j]){
                cheapSoFar[j] = price[i][j];
                pair<long long, int> myPair(-1, j);
                temp[j] = myPair;
                continue;
            }

            if (amount[i][j] == 0){
                pair<long long, int> myPair(-1, j);
                temp[j] = myPair;
                continue;
            }

            pair<long long, int> myPair(price[i][j] - cheapSoFar[j], j);
            cheapSoFar[j] = price[i][j];
            temp[j] = myPair;
        }

        sort(temp.begin(), temp.end());
        for (int j=1; j < 4; j++){
            if (temp[j].first <= -1){
                continue;
            }

            // cout << j << " " << temp[j].first << " " << temp[j].second << endl;

            gain += temp[j].first;
        }
        
    }

    cout << sum - gain << endl;
    return 0;
}