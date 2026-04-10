#include <iostream>
#include <deque>
using namespace std;

void slidingWindowMax(int arr[], int n, int k) {
    deque<int> dq;

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < n; i++) {
        cout << arr[dq.front()] << " ";

        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }
    cout << arr[dq.front()];
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = 8;
    int k = 3;

    slidingWindowMax(arr, n, k);

    return 0;
}
