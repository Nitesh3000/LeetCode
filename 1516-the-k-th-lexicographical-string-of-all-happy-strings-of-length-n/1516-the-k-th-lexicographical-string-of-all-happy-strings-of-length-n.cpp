class Solution {
private:
    bool happy(string str){
        for(int i = 0;i<str.size()-1;i++){
            if(str[i] == str[i+1]) return false;
        }
        return true;
    }
    void generateall(int n, vector<string>& res, string str = ""){
        for(char c:{'a','b','c'}){
            // str = str+c;
            if(str.size()>n){
                return;
            }
            if(str.size()==n-1){
                if(happy(str+c)){
                    res.push_back(str+c);
                }
            }
            generateall(n,res,str+c);
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> res;
        generateall(n,res);
        // cout<<res.size()<<endl;
        // res.sort(res.begin(),res.end());
        if(k>res.size()) return "";
        return res[k-1];
    }
};