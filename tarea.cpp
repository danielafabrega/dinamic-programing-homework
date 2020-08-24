#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <numeric>
#include <algorithm> 
#include<bits/stdc++.h> 

using namespace std;

//variables globales
vector<int> stair;
vector<int> brsteps;
int x, y;
int q = -10;

//funciones
//int Naruto(int stair_step);
int rodcuttingprob(int strair_step, int n);
int rodcuttingprobaux(int caminosposibles[], int strair_step, int n);


int main(){
    int p, j;
    j=0;
    //cout<<"cantidad escalones: "<<endl;
    //cin>>x;
    //cout<<"cantidad de escalones rotos"<<endl;
    //cin>>y;
    x=4;
    y=0;
    stair.resize(x);
    brsteps.resize(y);

    iota (begin(stair), end(stair), 1);
    /*for (int i = 0; i<y;i++){
        cout<<"escalones: "<<endl;
        cin>>p;
        brsteps[i]=p;
    }*/
    //ordena el vector de escalones rotos brsteps
    //sort(brsteps.begin(), brsteps.end());

    //retorna 0 si hay dos escalones rotos seguidos
   /* for(int i=0; i<y-1;i++){
        if(brsteps[i]==(brsteps[i+1]-1)){
            cout<<"0";
            return 0;
        }
    }*/
    //dejar 0 los escalones rotos en el arreglo de escalones
    /*
    while(j<y){
        stair[brsteps[j]-1]=0;
        j++;
    }*/

    /*for(int i:stair){
        cout<<i<<" ";
    }*/

    //int total = Naruto(1)+Naruto(2);
    int n=x;
    int total = rodcuttingprob(0,n);
    cout<<"\n"<<total;
   
    return 0;
}

//El equipo le pide ayuda a Naruto, que con su jutsu clones de sombra los ayudará a encontrar todas las rutas posibles
/*int Naruto(int stair_step){
    if (stair_step == x){
        return 1;
    }
    if(stair[stair_step-1] == 0 || stair_step == x+1){
        return 0;
    }
    return(Naruto(stair_step+1)+Naruto(stair_step+2));
}*/

//Naruto era muy lento y agotó su chakra antes de conseguir un buen resultado y hasta el día de hoy sigue buscando el mejor resultado para 10000 escalones :(

int rodcuttingprob(int strair_step, int n){
    int caminosposibles[x];
    for (int i=0; i<=x;i++){
        caminosposibles[i]=-10;
    }
    return rodcuttingprobaux(caminosposibles, strair_step, n);
}

int rodcuttingprobaux(int caminosposibles[], int strair_step, int n){

    int aux;
    // que buscamos:??? cantidad de caminos 
    //[1,2,3,4,5]
    //[-1,-1,-1,-1,-1] // arreglo global de cantidad de caminos para ir de a b2
    if (caminosposibles[n]>=0){
        return caminosposibles[n];
    }
    if (n==0){
        q=0;
    }
    else if(q==-10){
        for(int i=0;i<=n;i++){
            aux = strair_step + rodcuttingprobaux(caminosposibles, strair_step+1, n-i);
            if(q<aux){
                q = aux;
            }
        }
    }
    caminosposibles[n] = q;
    return q;
}