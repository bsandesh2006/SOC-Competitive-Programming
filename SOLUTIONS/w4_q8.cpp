#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MODm1 = MOD - 1;


ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp) {
        if (exp % 2) res = res * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}


ll mod_inv(ll x, ll mod) {
    return mod_pow(x, mod - 2, mod);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> a[i];
    }

    
    ll num_divisors = 1;
    for (int i = 1; i <= n; ++i) {
        num_divisors = num_divisors * (a[i] + 1) % MOD;
    }

    
    ll sum_of_divisors = 1;
    for (int i = 1; i <= n; ++i) {
        ll numerator = mod_pow(p[i], a[i] + 1, MOD) - 1;
        if (numerator < 0) numerator += MOD;
        ll denominator = mod_inv(p[i] - 1, MOD);
        ll term = numerator * denominator % MOD;
        sum_of_divisors = sum_of_divisors * term % MOD;
    }


    ll prod_of_divisors = 1;
    ll total_divisors = 1;

    for (int i = 1; i < n+1; i++) {
        ll base = mod_pow(p[i], a[i] * (a[i] + 1) / 2, MOD);
        prod_of_divisors = mod_pow(prod_of_divisors, a[i] + 1, MOD);
        prod_of_divisors = prod_of_divisors * mod_pow(base, total_divisors, MOD) % MOD;

        total_divisors = total_divisors * (a[i] + 1) % (MOD - 1);  
    }

    
    cout << num_divisors << " " << sum_of_divisors << " " << prod_of_divisors << "\n";

    return 0;
}
