//
// Created by manfred on 7/9/2016.
//

#include <iostream>
using namespace std;

int main(){
    char winner = 0;

    /* input */
    int unitT, unitA, K;
    cin >> unitT >> unitA >> K;

    /* represent the time A & T has spent */
    double currA = 0.5, currT = 0.0;
    int counter = 0;

    while(counter != K){
        if(currT + unitT < currA + unitA){
            currT += unitT;
            winner = 'T';
        }else if(currT + unitT > currA + unitA){
            currA += unitA;
            winner = 'A';
        }else{
            currA += unitA;
            currT += unitT;
            winner = 'B';
        }

        ++counter;
    }

    if(winner == 'T')
        cout << "Takahashi";
    else if(winner == 'A')
        cout << "Aoki";
    else
        cout << "Both";

    return 0;
}