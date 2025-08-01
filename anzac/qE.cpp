#include "bits/stdc++.h"
using namespace std;
signed main(void)
{
    string s;
    cin >> s;
    int N = s.length();
    string ans;
    for (int i = 0; i < N; i++)
    {
        if (isdigit(s[i]))
        {
            int time = (s[i] - '0');
            int j = i + 1;
            while(j < N && isdigit(s[j]))
            {
                time = time * 10 + (s[j] - '0');
                j++; 
            }
            string temp;
            if (j < N && s[j] == '(')
            {
                j++;
                while(j < N && s[j] != ')')
                {
                     temp += s[j]; 
                     j++; 
                }
                for (int k = 0; k < time; k++)
                {
                     ans += temp;
                }
                i = j;
            }
            else if (j < N)
            {
                for (int k = 0; k < time; k++)
                {
                    ans += s[j]; 
                }
                i = j;
            }
        }
        else
        {
            ans += s[i];
        }
    }
    cout << ans << endl;
    map<char, int>mp; 
    for(int i = 0; i < ans.length(); i++)
    {
        mp[ans[i]]++; 
    }
    cout << mp['S'] << " " << mp['T'] << " " << mp['R'] <<  " " << mp['L'] << endl;
    return 0;
}