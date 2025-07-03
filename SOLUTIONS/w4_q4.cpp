#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp) {
        if (exp % 2) result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

int main(){
    ll n,m;
    cin >> n >> m;

    ll num_product, den_product, inv_den_product, answer;
    num_product = 1;
    den_product = 1;
    for(ll i=1;i<n;i++){
        num_product = (num_product * (m + i )) % mod;
        den_product = (den_product * i) % mod;
    }
    inv_den_product = mod_pow(den_product, mod - 2, mod);

    answer = (num_product * inv_den_product) % mod;
    cout << answer << endl;
}