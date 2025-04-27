class Solution {
private:
    struct Point {
        int dist2 = 0;
        int idx = -1;

        bool operator<(const Point& second) const {
            return this->dist2 < second.dist2;
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<Point> p;
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];
            p.emplace_back(x * x + y * y, i);
        }

        nth_element(begin(p), begin(p) + (k - 1), end(p));

        vector<std::vector<int>> result;
        for (int i = 0; i < k; ++i) {
            int idx = p[i].idx;
            result.push_back(move(points[idx]));
        }

        return result;
    }
};