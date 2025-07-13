class Solution {
public:
    int bulbSwitch(int n) {
        int a=0, b=1;
        if( n ==0) return 0;
        else if (n<=3) return b;

        while(a<n){
            a += 2* b+1;
            if(a<n) {b++;}
        }
        return b;
    }
};

//or simply return sqrt(n);
