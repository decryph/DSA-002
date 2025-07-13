// You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.

// The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.

// Return the maximum number of matchings between players and trainers that satisfy these conditions.

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(),trainers.end());

        int a = players.size()-1;
        int b = trainers.size()-1;

        int matchings = 0;
        
        while(a>=0 && b>=0){
            if(players[a] <= trainers[b]) {
                a--; b--; matchings++;
                }
            else{
                a--;
            }
        }       
        return matchings;
    }
};
