#include <iostream>
#include <stack>
using namespace std;

int main() {
    int A[] = {5, 2, 7, 1, 6};
    int n = 5;
    int ans[5];
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= A[i % n]) {
            st.pop();
        }

        if (i < n) {
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
        }

        st.push(A[i % n]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
