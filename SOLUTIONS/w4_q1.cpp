#include <iostream>
using namespace std;

long long mod_pow(long long base, long long exponent, long long mod) {
    long long answer = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            answer = (answer * base) % mod;
        }
        base = (base * base) % mod;
        exponent = exponent / 2;
    }
    return answer;
}



int main(){
    long long n,a,b,c;
    cin >> n ;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        long long exponent = mod_pow(b, c, 1e9+6);
        long long result = mod_pow(a, exponent, 1e9+7);
        cout << result << endl;
    }
}