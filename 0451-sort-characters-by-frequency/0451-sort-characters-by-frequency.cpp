class Solution {
private:
    static bool comparator(const pair<int,char>& a,
                           const pair<int,char>& b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }

public:
    string frequencySort(string s) {
        pair<int,char> freq[256];

        for (int i = 0; i < 256; i++) {
            freq[i] = {0, char(i)};
        }

        for (unsigned char ch : s) {
            freq[ch].first++;
        }

        sort(freq, freq + 256, comparator);

        string ans = "";

        for (int i = 0; i < 256; i++) {
            while (freq[i].first--) {
                ans.push_back(freq[i].second);
            }
        }

        return ans;
    }
};
