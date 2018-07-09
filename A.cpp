#include <bits/stdc++.h>

using namespace std;

int scores[101][2];

int main(void){

    int n,k;
    cin >> n >> k;
    int cont=0;
    for(int i=0; i<n; i++){
        int aux;
        cin >> aux;
        if(scores[aux][0]==0){
            scores[aux][0]++;
            scores[aux][1]=i+1;
            cont++;
        }
    }
    if(cont<k) cout << "NO\n";
    else{
        cout << "YES\n";
        cont=0;
        int ind=1;
        while(scores[ind][0]==0) ind++;
        cout << scores[ind][1];
        cont++;
        ind++;
        while(cont<k){
            while(scores[ind][0]==0) ind++;
            cout << " " << scores[ind][1];
            cont++;
            ind++;
        }
        cout <<"\n";
    }





    return 0;
}
