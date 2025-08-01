#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;

class Solution {
public:
    int mod = 1e9 + 7;

    // Since n (=1e9 + 7) is prime, using Fermat's little theorem to find the 
    // multiplicative inverse of the divisior b: (A / B) mod n = (A * B^(n - 2)) mod n

    llint binPower(llint num, int power){
        if (power == 0){
            return 1;
        }

        if (power == 1){
            return num % mod;
        }

        llint half = binPower(num, power/2) % mod;
        if (power % 2 == 0){
            return (half * half) % mod;
        } else {
            return (((half * half) % mod) * (num % mod)) % mod;
        }
    }

    llint factorial(int n){
        llint start = 1;
        for (int i=1; i <= n; i++){
            start = (start * i) % mod;
        }
        return start;
    }

    llint findComb(string& s){
        unordered_map<char, int> freqCount;
        for (int i=0; i < s.size(); i++){
            freqCount[s[i]]++;
        }

        llint comb = factorial(s.size());
        for (auto& pair: freqCount){
            comb = ((comb % mod) * (binPower(factorial(pair.second), mod - 2) % mod)) % mod;
        }
        return comb;
    }

    int countAnagrams(string s) {
        string current = "";
        llint total = 1;
        for (int i=0; i < s.size(); i++){
            if (s[i] == ' '){
                total = ((total % mod) * (findComb(current) % mod)) % mod;
                current = "";
                continue;
            } else {
                current += s[i];
            }
        }

        total = ((total % mod) * (findComb(current) % mod)) % mod;

        return total;
    }
};


int main(){
    string s;
    Solution sol;
    cin >> s;
    cout << sol.countAnagrams(s) << endl;
}