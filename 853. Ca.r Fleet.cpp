// There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

// You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

// A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

// A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

// If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

// Return the number of car fleets that will arrive at the destination.

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);

        for(int i=0; i<n;i++){
            cars[i].first = position[i];
            cars[i].second = (double)(target - position[i])/speed[i];
        }
        sort(cars.begin(), cars.end(), [] (const pair<int, double> & a, const pair<int, double>& b){
            return a.first > b.first;
        });

        int cnt =0;
        double prev =0;

        for(const auto& car: cars){
            if (car.second > prev){
                cnt++;
                prev = car.second;
            }
        }
        return cnt;
    }
};
