class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        st.push(n);
        n--;
        int i = 0;
        while(n>0){
            int topEl = st.top();
            
            switch(i%4){
                
                case(0): st.pop(); st.push(topEl * n); break;
                case(1): st.pop(); st.push(topEl / n); break;
                case(2): st.push(n); break;
                case(3): st.push(-n); break;
            }
            i++;
            n--; 
        }
        int ans = 0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};