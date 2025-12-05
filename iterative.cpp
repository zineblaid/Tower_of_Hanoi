#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//  pour  print the moves
void printMove(char from, char to) {
    cout << "Move(" << from << "," << to << ");" << endl;
}

// pour  move a disk from one peg stack to another
void moveDisk(vector<int>& fromStack, vector<int>& toStack, char fromPeg, char toPeg) {
    if (fromStack.empty()) {
        // si  fromStack is empty on fait  pop from toStack to fromStack
        int disk = toStack.back();
        toStack.pop_back();
        fromStack.push_back(disk);
        printMove(toPeg, fromPeg);
    }
    else if (toStack.empty()) {
        // si toStack is empt on fait  pop from fromStack to toStack
        int disk = fromStack.back();
        fromStack.pop_back();
        toStack.push_back(disk);
        printMove(fromPeg, toPeg);
    }
    else if (fromStack.back() < toStack.back()) {
        int disk = fromStack.back();
        fromStack.pop_back();
        toStack.push_back(disk);
        printMove(fromPeg, toPeg);
    }
    else {
        int disk = toStack.back();
        toStack.pop_back();
        fromStack.push_back(disk);
        printMove(toPeg, fromPeg);
    }
}

// fonction iterative tower of hanoi
void IterativeHanoi(int n, char S, char A, char D) {
    int totalMoves = pow(2, n) - 1;  // Total number of moves

    //si le nombre de disk est pair swap auxiliary et  destination pegs
    if (n % 2 == 0) {
        char temp = D;
        D = A;
        A = temp;
    }

    // intilization pile stack 
    vector<int> S_stack, A_stack, D_stack;
    for (int i = n; i >= 1; i--) S_stack.push_back(i);  // Source peg has all disks initially

    // loop through all moves
    for (int moveNumber = 1; moveNumber <= totalMoves; moveNumber++) {
        if (moveNumber % 3 == 1) {
            moveDisk(S_stack, D_stack, S, D);  // move between Source and Destination
        }
        else if (moveNumber % 3 == 2) {
            moveDisk(S_stack, A_stack, S, A);  // move between Source and Auxiliary
        }
        else {
            moveDisk(A_stack, D_stack, A, D);  // mve between Auxiliary and Destination
        }
    }
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    IterativeHanoi(n, 'A', 'B', 'C');  // S = 'A', A = 'B', D = 'C'

    return 0;
}

