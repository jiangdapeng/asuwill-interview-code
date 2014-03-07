#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum State {
    NORMAL,
    SLASH,
    DOT,
    DOUBLEDOT,
    CUR,
    UP,
    ERROR
};

class Solution {
public:
    string simplifyPath(string path) {
        State state = NORMAL;
        vector<char> result(path.size());
        int p = -1;
        char c;
        for(int i=0;i<path.size();++i) {
            c = path[i];
            cout << "p = " << p << " state = " << state << " i = " << i << " c =" << c  << endl;
            switch(state) {
                case NORMAL:
                    if (c == '.') {
                        state = DOT;
                    }
                    else if (c == '/') {
                        result[++p] = c; // first '/' should be kept
                        state = SLASH;
                    }
                    else {
                        result[++p] = c;
                    }
                    break;
                case SLASH:
                    if (c == '/') {
                        // omit it
                        continue;
                    }
                    else if (c == '.') {
                        state = DOT;
                    }
                    else {
                        result[++p] = c;
                        state = NORMAL;
                    }
                    break;
                case DOT:
                    if (c == '.') {
                        state = DOUBLEDOT;
                    }
                    else if (c == '/') {
                        // omit ./
                        state = SLASH;
                    }
                    else {
                        result[++p] = c;
                        state = NORMAL;
                    }
                    break;
                case DOUBLEDOT:
                    if (c == '/') {
                        // result is '/ab/' ('../' is not put into result)
                        if (p == 0) { 
                            // deal with'/../'
                            state = SLASH;
                            break;
                        }
                        --p; // to '/ab'
                        while(p > -1) {
                            if (result[p] == '/') break; // to '/'
                            --p;
                        }
                        state = SLASH; // back to up level dir
                    }
                    break;
                default:
                    cout << "invalid path!" << endl;
                    break;
            }
        }
        return string(result.begin(),result.begin()+p);
        
    }
};


int main()
{
  Solution s;
  string path("/a/./b/../../c/");
  string result = s.simplifyPath(path);
  cout << result << endl;
  return 0;
}
