#include <iostream>
using namespace std;

void Hanoi(int n, char A, char C, char B) {
    if (n != 0) {
        Hanoi(n - 1, A, B, C);   // Déplacer n-1 de A → B en utilisant C
        cout << "Move(" << A << "," << C << ");" << endl; // Déplacer le dernier disque
        Hanoi(n - 1, B, C, A);   // Déplacer n-1 de B → C en utilisant A
    }
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    Hanoi(n, 'A', 'C', 'B'); // Respect exact des paramètres du cours

    return 0;
}
