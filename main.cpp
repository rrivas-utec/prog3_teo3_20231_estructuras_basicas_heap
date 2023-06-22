#include <iostream>
#include <deque>
#include "cola_prioritaria.h"

int main() {
    utec::priority_queue<int> pq1;
    vector vec = {20, 50, 10, 2, 60, 30};
    utec::priority_queue<int> pq2(vec);

    while(!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }

    return 0;
}
