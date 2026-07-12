class MedianFinder {
public:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    MedianFinder() {   

    }
    
    void addNum(int num) {
        maxHeap.push(num);
        int min_s = minHeap.size();
        int max_s = maxHeap.size();

        if (abs(min_s - max_s) > 1) {
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            return;
        }

        if (minHeap.size() && maxHeap.size() && maxHeap.top() > minHeap.top()) {
            int temp = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(temp);
        }

        // if(minHeap.size() && (maxHeap.size() > minHeap.size()) && (maxHeap.top() > minHeap.top())) {
        //     minHeap.push(maxHeap.top());
        //     maxHeap.pop();
        // }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            double res = (maxHeap.top() + minHeap.top()) / 2.0;
            return res;
        }

        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        return minHeap.top();
    }
};
