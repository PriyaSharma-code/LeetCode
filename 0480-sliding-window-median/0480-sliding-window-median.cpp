class Solution {
    multiset<int> lo, hi; // lo = lower half, hi = upper half

    void addNum(int num) {
        lo.insert(num);
        // Push max of lo into hi to maintain ordering
        hi.insert(*lo.rbegin());
        lo.erase(lo.find(*lo.rbegin()));
        // Rebalance sizes: lo should be >= hi in size
        if (lo.size() < hi.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    }

    void removeNum(int num, int k) {
        // Remove from whichever half it belongs to
        if (lo.find(num) != lo.end() && 
            (hi.empty() || num <= *hi.begin())) {
            lo.erase(lo.find(num));
        } else {
            hi.erase(hi.find(num));
        }
        // Rebalance after removal
        if (lo.size() < hi.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        } else if (lo.size() > hi.size() + 1) {
            hi.insert(*lo.rbegin());
            lo.erase(lo.find(*lo.rbegin()));
        }
    }

    double getMedian(int k) {
        if (k % 2 == 1) return (double)*lo.rbegin();
        return ((double)*lo.rbegin() + (double)*hi.begin()) / 2.0;
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            addNum(nums[i]);

            if ((int)(lo.size() + hi.size()) == k) {
                result.push_back(getMedian(k));
                // Remove the element leaving the window
                removeNum(nums[i - k + 1], k);
            }
        }
        return result;
    }
};
