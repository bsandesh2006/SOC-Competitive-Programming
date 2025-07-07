#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp) {
        if (exp % 2) res = res * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}


int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        ll sum = 0, min_sum = 0;
        for(ll i = 0; i < n; i++){
            sum += a[i];
            min_sum = min(min_sum, sum);
        }

        ll sum_1 = 0 ;
        ll non_negative_count = 0;
        ll ans = 0;

        if(min_sum == 0){
            ans = mod_pow(2,n, MOD);
        }else if(min_sum != 0){

            for(ll i = 0; i < n; i++){
                sum_1 += a[i];
                if(sum_1 == min_sum){
                    ans = ( ans + mod_pow(2, non_negative_count +(n-i-1), MOD) ) % MOD ;
                }
                if(sum_1 >= 0){
                    non_negative_count++;
                }
            }
        }
            cout << ans << endl;

    }

}