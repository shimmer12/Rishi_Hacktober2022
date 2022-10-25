#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> children(n);
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){
        cin >> children[i];
        mp[children[i]]++;
    }

    sort(children.begin(), children.end());
    int count = 0;
    for(auto grp: children){
        if(mp[grp] > 0){
            mp[grp]--;

            if(mp[4-grp] > 0) mp[4-grp]--;
            else if(mp[3-grp] > 0){
                mp[3-grp]--;
                if(mp[grp] > 0) mp[grp] -= 1;
            } 
            else if(mp[2-grp] > 0){
                mp[2-grp]--;
                if(mp[grp] > 0) mp[grp] -= 2;
            }
            else if(mp[1-grp] > 0){
                mp[1-grp]--;
                if(mp[grp] > 0) mp[grp] -= 3;
            } 
            count++;
        }
    }
    cout << count << endl;
    return 0;
}