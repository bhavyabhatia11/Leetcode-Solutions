class MedianFinder {
public:
    
    priority_queue<int> first;
    priority_queue<int, vector<int>, greater<int>> second;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(first.empty()){
            second.push(num);
        }
        else if(second.empty()){
            first.push(num);
        }
        else{
            if(first.top() > num){
                first.push(num);
            }
            else{
                second.push(num);
            }
        }


        while( abs( (int)first.size() - (int)second.size() ) > 1) {
            // rebalance
            if(first.size() > second.size()){
                second.push(first.top());
                first.pop();
            }
            else{
                first.push(second.top());
                second.pop();
            }
            
        }
    }
    
    double findMedian() {
        if(first.size() == second.size()){
            return (double)(first.top() + second.top()) / 2.0;
        }
        return first.size() > second.size() ? first.top() : second.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */