#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
    if (b == 0){
        return 0;
    }

    if (a % b == 0){
        return b;
    }

    return gcd(b, a%b);
}

int main(){
    long long t;
    cin >> t;

    for (long long z=0; z < t; z++){
        long long n;
        cin >> n;
        // cout << n << endl;
        vector<long long> valToIndex(n + 1, -1);
        vector<long long> vals(n + 1, -1);

        for (long long i=1; i <= n; i++){
            cin >> vals[i];
            valToIndex[vals[i]] = i;
        }

        long long totalPair = 0;
        for (long long i=1; i <= n - 1; i++){
            // for (long long j=i+1; j <= n; j++){
            //     if ((vals[i] * vals[j]) % (i * j) == 0){
            //         totalPair += 1;
            //     }
            // }

            if (vals[i] % i != 0){
                long long step = i / gcd(vals[i], i);

                for (long long l=step; l <= n; l+=step){
                    if (valToIndex[l] <= i){
                        continue;
                    }

                    if ((vals[i] * l) % (i * valToIndex[l]) == 0){
                        // cout << i << " " << valToIndex[l] << endl;
                        totalPair += 1;
                    }
                }
            } else {
                for (long long j=i+1; j <= n; j++){
                    if ((vals[i] * vals[j]) % (i * j) == 0){
                        // cout << i << " " << j << endl;
                        totalPair += 1;
                    }
                }
            }
        }

        cout << totalPair << endl;
    }


    return 0;
}