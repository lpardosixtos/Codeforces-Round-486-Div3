#include <bits/stdc++.h>

using namespace std;


int maxi;
int globmax;
int globpot;
int maxind;
map<int, int> coords;
void fillDp(int n){
    int pot=1;
    int locmax=1;
    int locpot=1;
    map<int, int>::iterator it;
    while(n+pot<=maxi){
        it=coords.find(n+pot);
        if(it!=coords.end()){
            it=coords.find(n+2*pot);
            if(it!=coords.end()){
                globmax=3;
                maxind=n;
                globpot=pot;
                break;
            }
            locmax=2;
            locpot=pot;
        }
        pot=pot<<1;
    }
    if(locmax>globmax){
        globmax=locmax;
        maxind=n;
        globpot=locpot;
    }
}


bool isPower(long long int n){
    if(n&(n-1)==0) return true;
    return false;
}

int main(void){

    int n;
    cin >> n;
    maxi=-1000000000;
    globmax=1;
    for(int i=0; i<n; i++){
        int aux;
        cin >> aux;
        pair<int, int> auxp(aux, i);
        coords.insert(auxp);
        maxi=max(aux, maxi);
    }
    map<int, int>::iterator it=coords.end();
    it--;
    while(it!=coords.begin()){
        fillDp(it->first);
        if(globmax==3) break;
        it--;
    }
    if(globmax!=3) fillDp(it->first);

    cout << globmax << "\n";
    if(globmax==1) cout << maxi << "\n";
    else{
        if(globmax==2) cout << maxind <<" " <<  maxind+globpot << "\n";
        else cout<< maxind << " "  << maxind+globpot << " " << maxind+2*globpot << "\n";
    }


    return 0;
}
