 #include <bits/stdc++.h>
 using namespace std;
 
void twoSum(vector<int>& nums, int target) {
        map<int,int> M;
        int second_index=0;
        for(int j = 0 ; j < nums.size() ; j++){
            int first_index=j;
            int key = target - nums[j];

            if(M.find(key) != M.end()){
                second_index=M[key];
                cout<< (second_index+1) <<" "<< (first_index+1);
                return;
            }
            M[nums[j]]=j;
        }
        cout << "IMPOSSIBLE";
        
}

int main(){
    int n,target;
    cin >> n >> target;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    twoSum(nums,target);
}