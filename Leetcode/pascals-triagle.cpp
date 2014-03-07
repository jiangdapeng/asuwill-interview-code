#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        vector<int> lastrow;
        for(int i=0;i<numRows; ++i) {
            vector<int> row;
            row.push_back(1);
            int n = lastrow.size();
            if (n > 1){
              for(int j=0;j<lastrow.size() - 1;++j) {
                  row.push_back(lastrow[j] + lastrow[j+1]);
              }
            }
            if (lastrow.size() > 0) {
                row.push_back(1);
            }
            result.push_back(row);
            lastrow = row;
        }
        return result;
    }
};

int main() {
  Solution s;
  vector<vector<int> > r = s.generate(1);
  for(int i=0; i<r.size(); ++i) {
    for (int j = 0; j < r[i].size() ; j++) {
      /* code */
      cout << r[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
