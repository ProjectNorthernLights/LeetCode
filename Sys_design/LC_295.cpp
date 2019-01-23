class MedianFinder {
public:
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if( max_heap.empty() || max_heap.top() > num)
          max_heap.push(num);
      else
          min_heap.push(num);
      
        //perform rebalance if either heap size exceeds the other by 1
        if(max_heap.size() > min_heap.size() + 1)
        {
          min_heap.push(max_heap.top());
          max_heap.pop();
        }
        else if( min_heap.size() > max_heap.size() + 1)
        {
          max_heap.push(min_heap.top());
          min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size() == min_heap.size())
          return ((max_heap.top() + min_heap.top())/2.0);
        else if(max_heap.size() > min_heap.size())
          return max_heap.top();
        else
          return min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
