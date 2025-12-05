#include <iostream>
using namespace std;
// recursive function to solve Tower of Hanoi
// n: number of disks
// A: source peg
// C: destination peg
// B: auxiliary peg

void Hanoi(int n, char A, char C, char B) {
    if (n != 0) { // Base case: if there are no disks do nothing
           // Step 1: Move n-1 disks from Source (A) to Auxiliary (B) using Destination (C)
        Hanoi(n - 1, A, B, C);   // Déplacer n-1 de A → B en utilisant C
         // Step 2: Move the largest disk from Source (A) to Destination (C)
        cout << "Move(" << A << "," << C << ");" << endl; // Déplacer le dernier disque
         // Step 3: Move the n-1 disks from Auxiliary (B) to Destination (C) using Source (A)
        Hanoi(n - 1, B, C, A);   // Déplacer n-1 de B → C en utilisant A
    }
}

int main() {
    int n;
      // Ask the user how many disks to solve for
    cout << "Enter number of disks: ";
    cin >> n;
      // Call the recursive Hanoi function
    // This will print all the moves to solve the puzzle

    Hanoi(n, 'A', 'C', 'B'); // Respect exact des paramètres du cours

    return 0;
}
