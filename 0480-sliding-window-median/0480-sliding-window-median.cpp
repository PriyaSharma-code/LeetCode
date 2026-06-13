#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class MedianFinder
{
    // Max-heap stores the smaller half of the numbers (left side)
    priority_queue<int> maxHeap;
    
    // Min-heap stores the larger half of the numbers (right side)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Tracks numbers that should be deleted but are still sitting inside the heaps
    unordered_map<int, int> pendingDeletions;
    
    // Number of valid, active elements inside each half
    int leftHeapActiveCount = 0;
    int rightHeapActiveCount = 0;
    int windowSize;

    // Cleans up invalidated elements from the top of the max-heap
    void purgeInvalidElementsFromLeft(priority_queue<int> &maxHeap)
    {
        while (!maxHeap.empty() && pendingDeletions[maxHeap.top()])
        {
            pendingDeletions[maxHeap.top()]--;
            maxHeap.pop();
        }
    }

    // Cleans up invalidated elements from the top of the min-heap
    void purgeInvalidElementsFromRight(priority_queue<int, vector<int>, greater<int>> &minHeap)
    {
        while (!minHeap.empty() && pendingDeletions[minHeap.top()])
        {
            pendingDeletions[minHeap.top()]--;
            minHeap.pop();
        }
    }

    // Rebalances the size of the two halves to maintain median properties
    void balanceHeaps(int imbalance)
    {
        // Left side has too many elements
        if (imbalance > 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            leftHeapActiveCount--;
            rightHeapActiveCount++;
        }
        // Right side has more elements than the left side
        else if (imbalance < 0)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            leftHeapActiveCount++;
            rightHeapActiveCount--;
        }
        
        // Ensure the tops of both heaps represent valid active elements
        purgeInvalidElementsFromLeft(maxHeap);
        purgeInvalidElementsFromRight(minHeap);
    }

public:
    MedianFinder(int k)
    {
        while (!maxHeap.empty()) maxHeap.pop();
        while (!minHeap.empty()) minHeap.pop();
        pendingDeletions.clear();
        leftHeapActiveCount = rightHeapActiveCount = 0;
        this->windowSize = k;
    }

    void add(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top()) 
        {
            maxHeap.push(num);
            leftHeapActiveCount++;
        }
        else 
        {
            minHeap.push(num);
            rightHeapActiveCount++;
        }
        balanceHeaps(leftHeapActiveCount - rightHeapActiveCount);
    }

    void remove(int num)
    {
        pendingDeletions[num]++;
        
        // Decrement our tracking count depending on which half the number belongs to
        if (!maxHeap.empty() && num <= maxHeap.top()) 
        {
            leftHeapActiveCount--;
        }
        else 
        {
            rightHeapActiveCount--;
        }
        balanceHeaps(leftHeapActiveCount - rightHeapActiveCount);
    }

    double getMedian()
    {
        purgeInvalidElementsFromLeft(maxHeap);
        purgeInvalidElementsFromRight(minHeap);
        
        if (windowSize % 2 == 1) 
        {
            return maxHeap.top();
        }
        else 
        {
            return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
        }
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        MedianFinder medianTracker(k);
        vector<double> result;
        
        for (int i = 0; i < nums.size(); i++)
        {
            medianTracker.add(nums[i]);
            
            // Once the window reaches size k, start recording medians and sliding
            if (i >= k - 1)
            {
                result.push_back(medianTracker.getMedian());
                
                // Remove the element that is falling out of the back of the window
                int elementToRemove = nums[i - k + 1];
                medianTracker.remove(elementToRemove);
            }
        }
        return result;
    }
};