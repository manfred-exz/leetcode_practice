//
// Created by manfred on 7/9/2016.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DiffPair{
public:
    char a, b;
    DiffPair(char _a, char _b){
       if(_a < _b){
           a = _a;
           b = _b;
       }else{
           a = _b;
           b = _a;
       }
    }

    bool operator!=(const DiffPair &rhs){
        return a != rhs.a || b != rhs.b;
    }


};

int main(){
    string S, T;

    cin >> S >> T;

    if(S.size() != T.size())
        return 0;

    DiffPair pair(0, 0);
    for (int i = 0; i < S.size(); ++i) {
        if(S[i] != T[i]){
            /* the first diff pair */
            if(pair.a == 0 && pair.b == 0){
                pair = {S[i], T[i]};
            }else{
                DiffPair tmpPair(S[i], T[i]);
                if(tmpPair != pair) {
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Possible" << endl;

    return 0;
}