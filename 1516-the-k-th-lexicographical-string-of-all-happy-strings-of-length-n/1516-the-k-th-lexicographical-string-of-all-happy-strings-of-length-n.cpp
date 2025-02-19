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
            if(str.size() == n){
                if(happy(str)){
                    res.push_back(str);
                    
                }
                return;
            }
            generateall(n,res,str+c);
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> res;
        generateall(n,res);
        if(k>res.size()) return "";
        return res[k-1];
    }
};