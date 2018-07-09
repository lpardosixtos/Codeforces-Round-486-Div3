#include <bits/stdc++.h>

using namespace std;

bool isSubstr(string a, string b){
    bool itis=false;
    int sz1=a.size(), sz2=b.size();
    for(int i=0; i<=sz2-sz1; i++){
        bool aux=true;
        for(int j=0; j<sz1; j++){
            if(a[j]!=b[i+j]){
                aux=false;
                break;
            }
        }
        if(aux==true){
            itis=true;
            break;
        }
    }
    return itis;
}

int main(void){

    int n;
    cin >> n;
    vector< pair<int, string> > words(n);
    for(int i=0; i<n; i++){
        string aux;
        cin >> aux;
        pair<int, string> auxp(aux.size(), aux);
        words[i]=auxp;
    }
    sort(words.begin(), words.end());
    bool ind=true;
    for(int i=n-2; i>=0; i--){
        if(!(isSubstr( words[i].second, words[i+1].second))){
            cout << "NO\n";
            ind=false;
            break;
        }
    }
    if(ind==true){
        cout << "YES\n";
        for(int i=0; i<n; i++){
            cout << words[i].second << "\n";
        }
    }


    return 0;
}
