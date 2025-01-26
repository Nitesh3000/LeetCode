class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char ch:tasks){
            freq[ch-'A']++;
        }
        sort(freq.begin(),freq.end());
        int maxfq=freq[25]-1;
        int idleslot=maxfq*n;
        for(int i=24;i>=0;i--){
            idleslot-=min(freq[i],maxfq);
        }
        return idleslot>0? idleslot+tasks.size() :tasks.size();
    }
};