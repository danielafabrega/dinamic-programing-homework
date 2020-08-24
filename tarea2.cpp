#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <numeric>
#include <algorithm> 
#include<bits/stdc++.h> 

using namespace std;

vector<int> stair;
vector<int> brsteps;
int x, y;
long* caminosposibles;

long rodcuttingprob(int n, long* caminosposibles);
long rodcuttingprobaux(int n, long* caminosposibles);


int main() {
    x=6;
    y=1;
    int j=0;
    stair.resize(x);
    brsteps.resize(y);
    iota (begin(stair), end(stair), 1);
    caminosposibles = new long[x];
    brsteps[0] = 3;
    //brsteps[0] = 23;
    //brsteps[0] = 45;
    //brsteps[0] = 67;
    //brsteps[0] = 89;
    for(int i:stair){
        cout<<stair[i]<<" ";
        
    }
    cout<<" "<<endl;
    while(j<y){
        stair[brsteps[j]-1]=0;
        j++;
    };
    long caminos= rodcuttingprob(0, caminosposibles);
    long mod= caminos%1000000007;
    cout<<mod<<" ";


}

long rodcuttingprob(int n, long* caminosposibles){
    
    for (int i=0; i<x;i++){
        caminosposibles[i]=-10;
    }
    caminosposibles[x-1]=1;

    return rodcuttingprobaux(0, caminosposibles)+rodcuttingprobaux(1, caminosposibles); // focus en que rodcuttingprobaux return caminos posibles osea el ultimo,
}

long rodcuttingprobaux(int n, long* caminosposibles){
    if (n == x){ //se pasa
        return 0;
    }
    if (caminosposibles[n]!= -10){
        return caminosposibles[n]%1000000007;
    }
    
    if (stair[n]==0){
        return 0;
    }
    caminosposibles[n] = rodcuttingprobaux(n+1, caminosposibles)+rodcuttingprobaux(n+2, caminosposibles);
    return caminosposibles[n]%1000000007;
}