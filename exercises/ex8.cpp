#include <vector>
#include <queue>
#include <algorithm>

int lastBallWeight(const std::vector<int>& weights) {
  std::priority_queue<int> pq(weights.begin(), weights.end());

  while (pq.size() > 1) {
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();

    if (x != y) {
      pq.push(x-y);
    }
  } 

  return pq.empty() ? 0 : pq.top();
}
