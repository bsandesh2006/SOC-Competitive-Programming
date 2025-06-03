#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int k;
    cin >> k;
    deque<int> dq;
    vector<int> maxArr;
    for(int i=0;i<k;i++){
        while(dq.size()>0 && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i=k;i<n;i++){
        maxArr.push_back(nums[dq.front()]);
        while(dq.size() >0 && dq.front()<=i-k){
            dq.pop_front();
        }
        while(dq.size()>0 && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    maxArr.push_back(nums[dq.front()]);

    for(int i=0;i<maxArr.size();i++){
        cout << maxArr[i]<<" ";
    }

}