#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> songs(n);
    for(int i = 0; i < n; i++){
        cin >> songs[i];
    }

    set<int> heard_songs; 
    int l=0;
    int r=0;
    int max_count=0;
    while(l < n && r < n){
        while(r<n && !heard_songs.count(songs[r])) {
            heard_songs.insert(songs[r]);
            max_count=max(max_count,r-l+1);
            r++;
        }
        while(r<n && heard_songs.count(songs[r])){
            heard_songs.erase(songs[l]);
            l++;
        }
    }

    cout << max_count << "\n";
    return 0;
}
