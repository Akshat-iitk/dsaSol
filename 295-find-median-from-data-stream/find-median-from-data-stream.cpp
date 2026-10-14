class MedianFinder {
public:
vector<int>arr ;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(arr.size()==0 || num>=arr.back())
        arr.push_back(num) ;
        else
        {
            int ind = lower_bound(arr.begin(),arr.end(),num)-arr.begin() ;
            arr.insert(arr.begin()+ind,num) ;
        }
    }
    
    double findMedian() {
        // sort(arr.begin(),arr.end()) ;
        int n = arr.size() ;
        if(n%2==1) return arr[n/2] ;
        else {
          return  (double)((arr[n/2]+arr[n/2-1])/2.0) ;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */