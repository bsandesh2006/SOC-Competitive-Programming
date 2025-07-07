#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool solve(ll a){
    bool res = true;
    vector<ll> digits;
    while(a > 0 ){
        digits.push_back(a % 10);
        a = a / 10;
    }
    reverse(digits.begin(), digits.end());

    ll length = digits.size();
    if(length == 1){
        res = false;
    }
    if(digits[0] != 1){
        res = false;
    }
    for(ll i=1; i<length-1; i++){
        if(digits[i] == 0){
            res = false;
            break;
        }
    }
    if(digits[length-1] == 9){
        res = false;
    } 

    return res;
}

int main(){
    ll n;
    cin >> n;
    for(ll i=0; i<n; i++){
        ll a;
        cin >> a;
        //cout << "checking" <<" " <<  a << " ";
        bool isTrue = solve(a);   
        if(isTrue){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}