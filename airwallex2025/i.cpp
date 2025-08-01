#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int sum = 0;
    int mini = 100;
    int temp;
    for (int i=0; i < N; i++){
        cin >> temp;
        sum += temp;
        mini = min(temp, mini);
    }

    double discount = sum;
    if (N >= 3){
        discount -= mini;
    }

    if (5 <= N && N < 7){
        discount = discount * 0.9;
    }

    if (N >= 7){
        discount = discount * 0.85;
    }

    int fee = 0;
    if (sum <= 20){
        fee = 5;
    }

    if (20 < sum && sum < 50){
        fee = 3;
    }

    if (sum >= 50){
        fee = 0;
    }
    
    double result = discount + fee;
    printf("%.2lf", result);
    return 0;
}