#include <iostream>
#include <queue>
#include <vector>

using coordinate_t = float;
using distance_t = float;
using point_t = std::vector<float>;

std::vector<point_t> points;

distance_t calc_dis(const point_t& a, const point_t& b) {
    distance_t dis = 0;
    for (int i = 0; i < a.size(); ++i) {
        dis += static_cast<distance_t>(a[i] - b[i]) * (a[i] - b[i]);
    }
    return dis;
}

void search(const point_t& target, std::vector<int>& result, int k) {
    std::priority_queue<std::pair<distance_t, int>> pq;
    for (int i = 0; i < points.size(); ++i) {
        pq.emplace(calc_dis(target, points[i]), i + 1);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    for (int i = 0; i < k; ++i) {
        result[i] = pq.top().second;
        pq.pop();
    }
}

void solve() {
    int n, d, q, k;
    std::cin >> n >> d >> q >> k;

    for (int i = 0; i < n; ++i) {
        auto& point = points.emplace_back();
        point.resize(d);
        for (int j = 0; j < d; ++j) {
            std::cin >> point[j];
        }
    }

    point_t target;
    std::vector<int> result;
    target.resize(d);
    result.resize(k);
    for (int i = 0, s; i < q; ++i) {
        for (int j = 0; j < d; ++j) {
            std::cin >> target[j];
        }
        search(target, result, k);
        for (int j = 0; j < k; ++j) {
            std::cout << result[j] << " \n"[j + 1 == k];
        }
    }
}

int main() {
    solve();
    return 0;
}