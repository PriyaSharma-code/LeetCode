class Solution {
public:

    priority_queue<long long> small;

    priority_queue<long long,
                   vector<long long>,
                   greater<long long>> large;

    unordered_map<long long,int> delayed;

    int smallSize = 0;
    int largeSize = 0;

    void pruneSmall() {
        while (!small.empty()) {
            long long x = small.top();

            if (delayed.count(x) && delayed[x] > 0) {
                delayed[x]--;
                small.pop();
            }
            else
                break;
        }
    }

    void pruneLarge() {
        while (!large.empty()) {
            long long x = large.top();

            if (delayed.count(x) && delayed[x] > 0) {
                delayed[x]--;
                large.pop();
            }
            else
                break;
        }
    }

    void balance() {

        if (smallSize > largeSize + 1) {

            large.push(small.top());
            small.pop();

            smallSize--;
            largeSize++;

            pruneSmall();
        }

        else if (smallSize < largeSize) {

            small.push(large.top());
            large.pop();

            smallSize++;
            largeSize--;

            pruneLarge();
        }
    }

    void addNum(long long num) {

        if (small.empty() || num <= small.top()) {
            small.push(num);
            smallSize++;
        }
        else {
            large.push(num);
            largeSize++;
        }

        balance();
    }

    void removeNum(long long num) {

        delayed[num]++;

        if (num <= small.top()) {

            smallSize--;

            if (num == small.top())
                pruneSmall();
        }
        else {

            largeSize--;

            if (num == large.top())
                pruneLarge();
        }

        balance();
    }

    double getMedian(int k) {

        if (k % 2)
            return (double)small.top();

        return ((double)small.top() +
                (double)large.top()) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums,
                                       int k) {

        vector<double> ans;

        for (int i = 0; i < k; i++)
            addNum(nums[i]);

        ans.push_back(getMedian(k));

        for (int i = k; i < nums.size(); i++) {

            addNum(nums[i]);

            removeNum(nums[i - k]);

            ans.push_back(getMedian(k));
        }

        return ans;
    }
};