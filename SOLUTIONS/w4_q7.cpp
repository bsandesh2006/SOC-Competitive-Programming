#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> storage(t);
    int max_n = 0;
    for (int i = 0; i < t; i++) {
        cin >> storage[i];
        max_n = max(max_n, storage[i]);
    }

    vector<int> grundy(max_n + 1, 0);
    for (int i = 1; i <= max_n; i++) {
        set<int> reachable;
        for (int j = 1; j <= i / 2; j++) {
            int k = i - j;
            if (j != k) {
                reachable.insert(grundy[j] ^ grundy[k]);
            }
        }
        int mex = 0;
        while (reachable.count(mex)) {
            mex++;
        }
        grundy[i] = mex;
    }

    for (int i = 0; i < t; i++) {
        cout << (grundy[storage[i]] != 0 ? "first" : "second") << '\n';
    }
}
