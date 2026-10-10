class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size() ;
        int mx = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            mx = max(mx,abs(nums1[i]-nums2[i])) ;
        }
        vector<int> feq(mx+1,0) ;
        for(int i = 0 ; i < n ;i++)
        {
            feq[abs(nums1[i]-nums2[i])]++ ;
        }
        int num = k1+k2 ;
        long long ans = 0 ;
        for(int i = mx ; i>0 ; i--)
        {
            if(num>=feq[i])
            {
                feq[i-1]+=feq[i] ;
                num-=feq[i] ;
                feq[i] = 0 ;
            }
            else{
                feq[i]-=num ;
                feq[i - 1] += num;
                num = 0 ;
                break ;
            }
        }
        for(int i = 0 ; i <=mx ; i++)
        {
            if(feq[i]!=0)
            {
                ans+=(feq[i]*1ll*i*1ll*i) ;
            }
        }
        return ans ;
    }
};