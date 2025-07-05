#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 2; i * i <= n; i++) { 
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i && n / i != 1)
                divisors.push_back(n / i);
        }
    }
    if (n != 1) divisors.push_back(n); 
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> results;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        vector<int> divisors = getDivisors(number);
        pair <int, int> result = {-1, -1};
        bool found = false;
        for (int j = 0; j < divisors.size() && !found ; j++) {
            for (int k = j + 1; k < divisors.size(); k++) {
                if (gcd(divisors[j] + divisors[k], number) == 1) {
                    result = {divisors[j], divisors[k]};
                    found = true;
                    break;
                }
            }
        }
        
        results.push_back(result);
    }

    for(int i = 0; i < results.size(); i++) {
        cout << results[i].first<< " ";
    }
    cout << endl;
    for(int i = 0; i < results.size(); i++) {
        cout << results[i].second << " ";
    }
}