#include <iostream>

using namespace std;

long double combination(int n, int k){
    // Can't use direct form
    // Use long double for boosted range lmao :D
    if (k > n-k){
        k = n - k;
    }
    long double top = 1.0;
    long double under = 1.0;
    for (int i=1; i <= k; i++){
        top *= (n + 1 - i);
        under *= i;
    }
    
    return top/under;
}

int main(){
    int num;
    cin >> num;

    long double boundary = 1000000000.0;
    long double total = 1;
    long double temp = 1;
    int n;
    int k;

    for (int i=0; i<num; i++){
        cin >> n;
        cin >> k;
        temp = combination(n, k);
        if (temp > boundary || temp != temp){
            cout << "BIG ENOUGH";
            return 0;
        }

        total *= temp;
        if (total > boundary || total != total){
            cout << "BIG ENOUGH";
            return 0;
        }
        
    }


    cout << (long long int) total;
    return 0;
}