/*
 * @author jiangdapeng
 * @date 2014-10-12
 * @desc 计算九宫格密码的个数（至少经过两个数字且不允许重复经过同一个数字）
 * @algorithm 深度优先遍历
 *
 */
#include <iostream>

const int MAX_ROW = 3;
const int MAX_COL = 3;

bool visited[MAX_ROW][MAX_COL];
int delta[][2] = { // 相邻的8 个位置
  {0,-1},
  {-1,-1},
  {-1,0},
  {-1,1},
  {0,1},
  {1,1},
  {1,0},
  {1,-1}, // 不相邻的位置
  {-1,-2},
  {-1,2},
  {1,-2},
  {1,2}
};

bool valid(int i,int j) {
  return i>=0 && i < MAX_ROW && j>=0 && j < MAX_COL;
}

void init(){
  for(int i=0;i<MAX_ROW; ++i) {
    for(int j=0;j<MAX_COL;++j) {
      visited[i][i] = false;
    }
  }
}

int dfs(int r,int c, int step) {
  int count = 0;
  if (step >= 2) count++;
  visited[r][c] = true;
  for(int i=0;i<12;++i) {
    int nr = r + delta[i][0];
    int nc = c + delta[i][1];
    if (valid(nr,nc) && !visited[nr][nc]) {
      count += dfs(nr,nc,step+1);
    }
  }
  visited[r][c] = false;
  return count;
}

int main(){
  int total = 0;
  for(int i=0;i<MAX_ROW;++i){
    for(int j=0;j<MAX_COL;++j) {
      init();
      int count = dfs(i,j,1);
      total += count;
      std::cout << count << std::endl;
    }
  }
  std::cout << total << std::endl;
  return 0;
}
