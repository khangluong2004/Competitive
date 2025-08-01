#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> numbers(3, -1);

    for (int i=0; i < n; i++){
        cin >> numbers[0];
        cin >> numbers[1];
        cin >> numbers[2];

        sort(numbers.begin(), numbers.end());
        cout << abs(numbers[1] - numbers[0]) + abs(numbers[2] - numbers[1]) << endl;
    }

}