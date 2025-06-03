#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t ;
    for(int i=0;i<t;i++){
        long long  n,k;
        cin >> n;
        cin >> k;
        if(n%2==0){
            cout << "YES" << "\n";
        }else{
            if(k%2==0){
                cout << "NO" << "\n";
            }else{
                cout << "YES" << "\n";
            }
        }
    }
}
