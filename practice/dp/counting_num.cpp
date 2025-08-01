#include <iostream>
#include <cmath>

using namespace std;

typedef long long i64;
#define fastcin()\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL)

int check_adj(i64 n){
    int post = 1;
    int pre = n%10;
    int cur = 0;
    n /= 10;

    while (n > 0){
        cur = n%10;
        if (cur == pre){
            return post;
        }

        pre = cur;
        post++;
        n /= 10; 
    }

    return 0;
}

int main(){
    fastcin();

    i64 a;
    i64 b;
    cin >> a;
    cin >> b;

    
    i64 count = 0;
    i64 check = a;
    while(check <= b){
        int adj_post = check_adj(check);
        // cout << adj_post << endl;
        if (adj_post == 0){
            ++check;
        } else {
            // cout << adj_post << endl;
            i64 degree = (i64) pow(10.0, adj_post - 1);
            i64 increment = min(degree - check%degree, b - check + 1);
            count += increment;
            check += increment;
        }
    }

    cout << (b - a + 1 - count) << endl;
    return 0;    
}