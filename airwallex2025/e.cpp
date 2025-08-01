#include <bits/stdc++.h> 
using namespace std;

int a[4000][4000], vis[4000][4000]; 

const int OFFSET = 2000;
const int dirx[4] = {0, 1, 0, -1};
const int diry[4] = {1, 0, -1, 0};     
int cc = 0; 

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    
    int N; 
    cin >> N; 
    vector<char>c(N); 
    for(int i = 0; i < N; i++) { 
     cin >> c[i];      
    }
    pair<int, int>st = {0, 0}; 
    a[OFFSET + st.first][OFFSET + st.second] = 1; 
    int dir = 0; 
    for(int i = 0; i < N; i++) { 
     if(c[i] == 'F') { 
      a[OFFSET + st.first + dirx[dir]][OFFSET + st.second + diry[dir]] = 1; 
      st.first += dirx[dir];
      st.second += diry[dir]; 
     } 
     if(c[i] == 'L') { 
      dir += 3;
      dir %= 4;
     }
     if(c[i]  == 'R') {
        dir++;
        dir %= 4;
     }
    }
    int ans = 0;
    for(int i = 0; i < 4000; i++) { 
        for(int j = 0; j < 4000; j+=3999) { 
            if(vis[i][j] || a[i][j]) continue; 
            cc = 0; 
            queue<pair<int, int>>q; 
            vis[i][j] = -2; 
            q.push({i, j});  
            while(q.size()) { 
            cc++; 
            auto [cur_x, cur_y] = q.front(); 
            q.pop(); 
            for(int k = 0; k < 4; k++) { 
            int nx = cur_x + dirx[k]; 
            int ny = cur_y + diry[k]; 
            if(0 <= nx && nx < 4000 && 0 <= ny && ny < 4000) { 
            if(vis[nx][ny] || a[nx][ny]) continue; 
            vis[nx][ny] = -2; 
            q.push({nx, ny}); 
            } 
            }
            }

        }
    }

    for(int i = 0; i < 4000; i+=3999) { 
        for(int j = 0; j < 4000; j++) { 
            if(vis[i][j] || a[i][j]) continue; 
            cc = 0; 
            queue<pair<int, int>>q; 
            vis[i][j] = -2; 
            q.push({i, j});  
            while(q.size()) { 
            cc++; 
            auto [cur_x, cur_y] = q.front(); 
            q.pop(); 
            for(int k = 0; k < 4; k++) { 
            int nx = cur_x + dirx[k]; 
            int ny = cur_y + diry[k]; 
            if(0 <= nx && nx < 4000 && 0 <= ny && ny < 4000) { 
            if(vis[nx][ny] || a[nx][ny]) continue; 
            vis[nx][ny] = -2; 
            q.push({nx, ny}); 
            } 
            }
            }

        }
    }
    
    for(int i = 0; i < 4000; i++) { 
     for(int j = 0; j < 4000; j++) { 
      if(vis[i][j] || a[i][j]) continue; 
      cc = 0; 
      queue<pair<int, int>>q; 
      vis[i][j] = true; 
      q.push({i, j});  
      while(q.size()) { 
       cc++; 
       auto [cur_x, cur_y] = q.front(); 
       q.pop(); 
       for(int k = 0; k < 4; k++) { 
        int nx = cur_x + dirx[k]; 
        int ny = cur_y + diry[k]; 
        if(0 <= nx && nx < 4000 && 0 <= ny && ny < 4000) { 
         if(vis[nx][ny] || a[nx][ny]) continue; 
         vis[nx][ny] = true; 
         q.push({nx, ny}); 
        } 
       }
      }

      ans = max(ans, cc); 
     }
    }
    cout << (ans == 0 ? -1 : ans) << '\n'; 
    return 0;
}