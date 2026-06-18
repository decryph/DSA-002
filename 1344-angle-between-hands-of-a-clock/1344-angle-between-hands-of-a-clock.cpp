class Solution {
public:
    double angleClock(int hour, int minutes) {
        double totalhour = double(hour)+ double(minutes)/60;

        double anglehour = totalhour*30;
        double anglemin = minutes *6;

        double ans = abs(anglemin - anglehour);
        if(ans>180){
            return 360-ans;
        }
        return ans;
    }
};