#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int s;
    cin >> s;

    for(int z=0; z < s; z++){
        int n, m;
        cin >> n;
        cin >> m;

        vector<vector<int>> matrix(n, vector<int>(m, -1));

        for (int i=0; i < n; i++){
            for (int j=0; j < m; j++){
                cin >> matrix[i][j];
            }
        }

        for (int i=0; i < n; i++){
            for (int j=0; j < m; j++){
                // Find max value from the neighbours
                int maxVal = -1;

                if (i > 0){
                    maxVal = max(maxVal, matrix[i-1][j]);
                }

                if (i < n - 1){
                    maxVal = max(maxVal, matrix[i+1][j]);
                }

                if (j > 0){
                    maxVal = max(maxVal, matrix[i][j-1]);
                }

                if (j < m - 1){
                    maxVal = max(maxVal, matrix[i][j+1]);
                }

                if (matrix[i][j] > maxVal){
                    matrix[i][j] = maxVal;
                }
            }
        }

        for (int i=0; i < n; i++){
            for (int j=0; j < m; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}