#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <numeric>
#include <algorithm> 
#include<bits/stdc++.h> 

using namespace std;

int* stair;
int* brsteps;
int x, y;
long long int* caminosposibles;

long long int rodcuttingprob(int n, long long int* caminosposibles);
long long int rodcuttingprobaux(int n, long long int* caminosposibles);


int main() {
    x=100;
    y=5;
    int j=0;
    

    stair = new int[x];
    brsteps = new int[y];
    caminosposibles = new long long int[x];
    


    brsteps[0] = 1;
    brsteps[1] = 23;
    brsteps[2] = 45;
    brsteps[3] = 67;
    brsteps[4] = 89;
    stair[0]=1;
    for(int i=1;i<x;i++){
        stair[i]=i+1; 
    }
    /*for(int i=1;i<=x;i++){
        cout<<stair[i]<<" "; 
    }*/
    
    while(j<y){
        stair[brsteps[j]-1]=0;
        j++;
    }
    /*for(int i=0;i<x;i++){
        cout<<stair[i]<<" ";
    }*/
    long long int caminos= rodcuttingprob(0, caminosposibles);
    cout<<caminos<<" ";


}

long long int rodcuttingprob(int n, long long int* caminosposibles){
    for (int i=0; i<x;i++){
        caminosposibles[i]=-10;
    }
    caminosposibles[x-1]=1;

    return ((rodcuttingprobaux(0, caminosposibles)+rodcuttingprobaux(1, caminosposibles))%1000000007); // focus en que rodcuttingprobaux return caminos posibles osea el ultimo,
}

long long int rodcuttingprobaux(int n, long long int* caminosposibles){
    if (n == x){ //se pasa
        return 0;
    }
    if (caminosposibles[n]!= -10){
        return (caminosposibles[n]);
    }
    
    if (stair[n]==0){
        return 0;
    }
    caminosposibles[n] = ((rodcuttingprobaux(n+1, caminosposibles)+rodcuttingprobaux(n+2, caminosposibles))%1000000007);
    return (caminosposibles[n]);
}