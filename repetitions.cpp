#include <iostream>
#include <string>
using namespace std;

int main(){
    string DNA;
    cin >> DNA;
    int count=1;
    int max_count=1;
    for(int i=0; i< DNA.length();i++){
        if(DNA[i] == DNA[i+1]){
            count++;
        }
        if(DNA[i]!= DNA[i+1]){
            if(max_count < count){
                max_count=count;
            }
            count = 1;
        }
    }
    cout << max_count;
}