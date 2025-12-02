#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void hanoiRecursive(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    hanoiRecursive(n - 1, source, auxiliary, target);
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    hanoiRecursive(n - 1, auxiliary, target, source);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    auto start = high_resolution_clock::now();
    hanoiRecursive(n, 'A', 'C', 'B');
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    
    return 0;
}

