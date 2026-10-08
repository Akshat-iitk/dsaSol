class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = -1 ;
        int num = 0 ;
        for(auto it : nums)
        {
            if(el==-1)
            {
                el = it ;
                num++ ;
            }
            else{
                if(it==el) {
                    num++ ;
                }
                else{
                    num--;
                    if(num==0) 
                    {
                        el = it ;
                        num++ ;
                    }
                }
            }
        }
        return el ;
    }
};