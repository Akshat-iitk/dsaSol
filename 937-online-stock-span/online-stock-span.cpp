class StockSpanner {
public:
stack<pair<int,int>>st ;
int flag = 1 ;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first<=price)
        {
            st.pop() ;
        }
        int ans = 0 ;
        if(st.empty()) ans = flag ;
        else ans = flag - st.top().second ;
        st.push({price,flag}) ;
        flag++ ;
        return ans ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */