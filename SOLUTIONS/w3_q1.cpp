#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> tasks(n);

    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end());

    long long totalTime = 0;
    long long totalReward = 0;

    for (int i = 0; i < n; i++) {
        totalTime += tasks[i].first;
        totalReward += tasks[i].second - totalTime;
    }

    cout << totalReward << endl;

    return 0;
}
