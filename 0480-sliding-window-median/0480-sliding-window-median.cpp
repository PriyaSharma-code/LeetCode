class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans;
        for (int i = 0; i < k-1; i++)
            addNumber(i, 0, nums);
        for (int i = k-1; i < n; i++) {
            addNumber(i, i-k+1, nums);
            ans.push_back(calc(k, i-k+1));
            removeNumber(i-k+1, i-k+1, nums);
        }
        return ans;
    }

private:
    priority_queue<pair<int, int>> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    int minHeapSize = 0;
    int maxHeapSize = 0;

    void cleanMaxHeap(int l) {
        while (!maxHeap.empty()) {
            if (maxHeap.top().second >= l)
                break;
            maxHeap.pop();
        }
        return;
    }

    void cleanMinHeap(int l) {
        while (!minHeap.empty()) {
            if (minHeap.top().second >= l)
                break;
            minHeap.pop();
        }
        return;
    }

    void adjustHeaps(int l) {
        cleanMaxHeap(l);
        cleanMinHeap(l);
        if (maxHeapSize == minHeapSize+1) {
            if (!maxHeap.empty()) {
                pair<int, int> t = maxHeap.top();
                maxHeap.pop();
                maxHeapSize--;
                minHeap.push(t);
                minHeapSize++;
            }
        }
        if (maxHeapSize == minHeapSize-2) {
            if (!minHeap.empty()) {
                pair<int, int> t = minHeap.top();
                minHeap.pop();
                minHeapSize--;
                maxHeap.push(t);
                maxHeapSize++;
            }
        }

        if (maxHeapSize > 0) {
            pair<int, int> maxHeapTop = maxHeap.top();
            pair<int, int> minHeapTop = minHeap.top();
            if (maxHeapTop > minHeapTop) {
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(minHeapTop);
                minHeap.push(maxHeapTop);
            }
        }
    }

    void addNumber(int ind, int l, vector<int> &nums) {
        minHeap.push({nums[ind], ind});
        minHeapSize++;
        adjustHeaps(l);
        // test("add");
    }

    void removeNumber(int ind, int l, vector<int> &nums) {
        cleanMinHeap(l);
        pair<int, int> t = minHeap.top();
        pair<int, int> cur = {nums[ind], ind};

        if (cur >= t) {
            minHeapSize--;
        } else {
            maxHeapSize--;
        }
        adjustHeaps(l+1);
        // test("remove");
    }

    double calc(int k, int l) {
        cleanMaxHeap(l);
        cleanMinHeap(l);
        // test("calc");
        if (k&1)
            return (double) (minHeap.top().first);
        return (double) ((long long) minHeap.top().first + (long long) maxHeap.top().first)/2.0;
    }

};