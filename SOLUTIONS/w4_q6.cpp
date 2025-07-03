#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> x(n);
        for(int j = 0; j < n; ++j) {
            cin >> x[j];
        }
        int nim_sum = 0;
        for(int j = 0; j < n; ++j) {
            nim_sum ^= x[j];
        }
        if(nim_sum == 0) {
            cout << "second" << endl;
        } else {
            cout << "first" << endl;
        }
    }
}