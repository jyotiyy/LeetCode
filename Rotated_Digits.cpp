class Solution {
public:
    bool isgood(int n){
        set<int> nums;
        while(n > 0){
            int d = n%10;
            if(d == 3 || d == 4 || d == 7) return false;
            if(d == 2 || d == 5){
                nums.insert(1);
            }
            if(d == 6 || d == 9){
                nums.insert(2);
            }
            n/=10;
        }
        return (nums.size() > 0) ;
    }
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(isgood(i)) cnt++;
        }
        return cnt;
         

    }
};
