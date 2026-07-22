class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;

        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;

        unordered_set<string> corners;

        for (auto &r : rectangles) {
            int x1 = r[0], y1 = r[1];
            int x2 = r[2], y2 = r[3];

            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            area += 1LL * (x2 - x1) * (y2 - y1);

            vector<string> pts = {
                to_string(x1) + " " + to_string(y1),
                to_string(x1) + " " + to_string(y2),
                to_string(x2) + " " + to_string(y1),
                to_string(x2) + " " + to_string(y2)
            };

            for (auto &p : pts) {
                if (corners.count(p))
                    corners.erase(p);
                else
                    corners.insert(p);
            }
        }

        long long expectedArea = 1LL * (maxX - minX) * (maxY - minY);

        if (area != expectedArea)
            return false;

        if (corners.size() != 4)
            return false;

        if (!corners.count(to_string(minX) + " " + to_string(minY)))
            return false;
        if (!corners.count(to_string(minX) + " " + to_string(maxY)))
            return false;
        if (!corners.count(to_string(maxX) + " " + to_string(minY)))
            return false;
        if (!corners.count(to_string(maxX) + " " + to_string(maxY)))
            return false;

        return true;
    }
};