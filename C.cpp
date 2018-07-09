#include <bits/stdc++.h>

using namespace std;

int main(void){

    int k;
    cin >> k;
    vector<vector<long long int> > numbers(k);
    long long int sumarr[k];

    for(int i=0; i<k; i++){
        int aux;
        cin >> aux;
        long long int sum=0;
        for(int j=0; j<aux; j++){
            long long int aux2;
            cin >> aux2;
            numbers[i].push_back(aux2);
            sum+=aux2;
        }
        sumarr[i]=sum;
    }

    map<long long int, pair<int, int> > sums;
    int ind1=-1, ind2, num1, num2;
    pair<map<long long int, pair<int, int> >::iterator , bool> ret;

    for(int i=0; i<k; i++){
        for(int j=0; j<numbers[i].size(); j++){
            pair<int, int> auxp1(i, j);
            pair<long long int, pair<int, int> > auxp(sumarr[i]-numbers[i][j], auxp1);
            ret=sums.insert(auxp);
            if(ret.second==false && (ret.first->second).first!=i){
                ind1=(ret.first->second).first;
                ind2=i;
                num1=(ret.first->second).second;
                num2=j;
                break;
            }
        }
        if(ind1!=-1) break;
    }
    if(ind1==-1) cout << "NO\n";
    else{
        cout << "YES\n";
        cout << ind1+1 << " " << num1+1 << "\n";
        cout << ind2+1 << " "  << num2+1 << "\n";
    }

    return 0;
}
