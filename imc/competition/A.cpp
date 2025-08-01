#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, S, D, M;
    cin >> T;
    cin >> S;
    cin >> D;
    cin >> M;

    vector<vector<int>> priceMatrix; // By day and by stock

    for (int i=0; i < D; i++){
        priceMatrix.emplace_back(S, 0);

        for (int j=0; j < S; j++){
            cin >> priceMatrix[i][j];
        }
    }

    vector<int> minSoFar(S, 0);
    vector<int> maxGain(S, 0);
    int gain = -1;
    int finalGain = 0;

    for (int j=0; j < S; j++){
        minSoFar[j] = priceMatrix[0][j];
    }

    for (int j=0; j < S; j++){
        for (int i=1; i < D; i++){
            minSoFar[j] = min(minSoFar[j], priceMatrix[i][j]);
            gain = ((int) (M / minSoFar[j])) * (priceMatrix[i][j] - minSoFar[j]); 
            maxGain[j] =  max(maxGain[j], gain);
            finalGain = max(finalGain, maxGain[j]);
        }
    }

    cout << finalGain + M << endl;
    return 0;
}