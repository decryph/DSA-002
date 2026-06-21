class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
     sort(begin(costs), end(costs));

     int cnt =0;

     for(int &cost : costs){
        if(cost>coins){
            return cnt;
        } else{
            cnt++;
            coins -= cost;
        }
     }   
     return cnt;
    }
};