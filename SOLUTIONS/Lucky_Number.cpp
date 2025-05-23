#include "bits/stdc++.h"
#include <string>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t ;
    for(int i=0;i<t;i++){
        int l,r;
        cin >> l >> r;
        int lucky_num=l;
        int lucky_num_diff=0;
        for(int i=l;i<=r;i++){
            vector<int> temp_arr;
            int j=i;
            int max_digit=0;
            int min_digit=9;

            while(j>0){
                int digit=j%10;
                min_digit=min(min_digit,digit);
                max_digit=max(max_digit,digit);
                j /=10;
            }
            int temp_lucky_num_diff=max_digit-min_digit;

            if(temp_lucky_num_diff>lucky_num_diff){
                lucky_num_diff=temp_lucky_num_diff;
                lucky_num=i;
            }

            if(lucky_num_diff==9){
                break;
            }
        }
        cout << lucky_num << "\n";

    }
}