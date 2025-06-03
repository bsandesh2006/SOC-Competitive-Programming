#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    map<int, vector<int>> map_index;
    for (int i = 0; i < n; i++) {
        map_index[nums[i]].push_back(i + 1);  
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue; 

            int target = x - nums[i] - nums[j];

            if (map_index.find(target) != map_index.end()) {
                for (int index : map_index[target]) {
                    if (index != i + 1 && index != j + 1) {
                        cout << i + 1 << " " << j + 1 << " " << index << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}
