#include <bits/stdc++.h>
using namespace std;

int main(){
   int n;
    cin >> n;
    vector<long long>nums(n);
    for(long long i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    long long cost=0;
    for(int i=0;i<n;i++){
        cost += abs(nums[i]-nums[n/2]);
    }
    cout << cost;
}