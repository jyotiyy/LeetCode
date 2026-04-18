#include<bits/stdc++.h>

using namespace std;

int upper_bound(vector<int> arr,int t){
    int st = 0;
    int end = arr.size()-1;
    int ans = 0;
    
    while(st <= end){
        int mid = st + (end-st)/2;
        if(arr[mid] > t){
            ans = arr[mid];
            end = mid-1;
        }else{
            st = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6};
    int target = 5;
    
    int ans = upper_bound(arr,target);
    cout << ans << "\n";
}
