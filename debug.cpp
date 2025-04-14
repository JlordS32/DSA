#include <iostream>
#include <list>
#include <queue>
#include <vector>

int main()
{
    std::vector<int> weights {45, 98, 21, 111, 32};
    std::priority_queue<int> pq(weights.begin(), weights.end());

    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        if (x != y)
        {
            pq.push(x - y);
        }
    }

    std::cout << (pq.empty() ? 0 : pq.top()) << std::endl;
    return 0;
}
