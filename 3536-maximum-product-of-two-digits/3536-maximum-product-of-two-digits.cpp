class Solution {
public:
    int maxProduct(int n) {
        int maxDig =0;
        int secMaxDig =0;

        while(n>0){
            int r = n%10;
            if(maxDig <r){
                secMaxDig = maxDig;
                maxDig =r;
            } else if (secMaxDig < r){
                secMaxDig =r;
            }
            n /= 10;
        }
        return maxDig * secMaxDig;
    }
};