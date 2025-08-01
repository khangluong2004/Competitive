#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

void markIslands(int* checked, vector<vector<char>>& grid, int cur_row, int cur_col, 
    int row_num, int col_num){

    if (checked[cur_row * col_num + cur_col] == 1 || grid[cur_row][cur_col] == '0'){
        return;
    }

    checked[cur_row * col_num + cur_col] = 1;

    if (cur_row > 0){
        markIslands(checked, grid, cur_row - 1, cur_col, row_num, col_num);
    }

    if (cur_row + 1 < row_num){
        markIslands(checked, grid, cur_row + 1, cur_col, row_num, col_num);
    }

    if (cur_col > 0){
        markIslands(checked, grid, cur_row, cur_col - 1, row_num, col_num);
    }

    if (cur_col + 1 < col_num){
        markIslands(checked, grid, cur_row, cur_col + 1, row_num, col_num);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int checked[grid.size()][grid[0].size()];

    for (int i=0; i < grid.size(); i++){
        for (int j=0; j < grid[0].size(); j++){
            checked[i][j] = 0;
        }
    }
    
    int total = 0;
    for (int i=0; i < grid.size(); i++){
        for (int j=0; j < grid[0].size(); j++){
            if (checked[i][j] == 0 && grid[i][j] == '1'){
                total++;
                markIslands(&checked[0][0], grid, i, j, grid.size(), grid[0].size());
            }
        }
    }

    return total;
}

int main(){
    vector<vector<char>> grid;

    grid.emplace_back(initializer_list<char>{'1','1','0','0','0'});
    grid.emplace_back(initializer_list<char>{'1','1','0','0','0'});
    grid.emplace_back(initializer_list<char>{'0','0','1','0','0'});
    grid.emplace_back(initializer_list<char>{'0','0','0','1','1'});


    cout << numIslands(grid) << endl;
    return 0;
}

