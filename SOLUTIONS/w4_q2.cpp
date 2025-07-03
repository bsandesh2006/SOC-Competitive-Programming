#include <iostream>
using namespace std;
typedef long long ll;
const long long mod = 1e9 + 7;
const long long inv2 = (mod + 1) / 2;
int main() {
    long long n;
    cin >> n;
    ll answer = 0;
    ll j=0;
    for(ll i=1;i<=n;i=j){
        ll q=n/i;
        j=n/q + 1;
        ll sumofrangewithvalueq = ((((j-i)%mod)*((j+i-1)%mod))% mod * inv2) % mod; 
        answer = (answer + (q%mod * sumofrangewithvalueq) % mod) % mod;
    }
    cout << answer << endl;
}
