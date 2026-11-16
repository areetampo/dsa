#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << ((n > m) ? n : m) << endl;
    }
}