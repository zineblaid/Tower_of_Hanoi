#include <iostream>
#include <stack>
#include <chrono>
using namespace std;
using namespace std::chrono;
//pour représenter un mouvement d'un disque

struct Move {
    int disk;
    char from;
    char to;
};
//  résoudre le Tower of Hanoi itertive e
void hanoiIterative(int n) {
    stack<Move> moves;
    int totalMoves = (1 << n) - 1; // 2^n - 1
    char source = 'A', auxiliary = 'B', target = 'C';

    if (n % 2 == 0) swap(target, auxiliary);

    for (int i = 1; i <= totalMoves; i++) {
        int fromPeg = (i & i-1) % 3;
        int toPeg = ((i | i-1) + 1) % 3;
        cout << "Move " << i << ": from peg " << char('A'+fromPeg) << " to peg " << char('A'+toPeg) << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    auto start = high_resolution_clock::now();
    hanoiIterative(n);
    auto end = high_resolution_clock::now();
    //la durée en millisecondes
    
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    
    return 0;
}

    IterativeHanoi(n, 'A', 'B', 'C');  // S = 'A', A = 'B', D = 'C'

    return 0;
}

