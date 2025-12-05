#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread; 

struct Disk {
    sf::RectangleShape shape;
};

struct Peg {
    vector<Disk> disks;
};

// fonction pour dessiner les tours et les disques
void drawPegsAndDisks(sf::RenderWindow &window, Peg pegs[3]) {
    window.clear(sf::Color::White);

    // dessiner les tours
    for (int i = 0; i < 3; i++) {
        sf::RectangleShape peg(sf::Vector2f(10, 200));
        peg.setFillColor(sf::Color::Black);
        peg.setPosition(150 + i * 150, 100);
        window.draw(peg);
    }

    // dessiner les disques
    for (int i = 0; i < 3; i++) {
        int y = 300; // cordonnée verticale de base.
        for (auto &disk : pegs[i].disks) {
            disk.shape.setPosition(150 + i * 150 - disk.shape.getSize().x / 2, y - disk.shape.getSize().y);
            window.draw(disk.shape);
            y -= disk.shape.getSize().y;
        }
    }

    window.display();
    sleep_for(milliseconds(500)); // délai pour voir l'animation
}

// fonction pour déplacer un disque d'une tour à une autre
void moveDisk(Peg pegs[3], int from, int to, sf::RenderWindow &window) {
    if (pegs[from].disks.empty()) return;
    Disk d = pegs[from].disks.back();
    pegs[from].disks.pop_back();
    pegs[to].disks.push_back(d);
    drawPegsAndDisks(window, pegs);
}

// algo récursif
void hanoiRecursive(int n, int from, int to, int aux, Peg pegs[3], sf::RenderWindow &window) {
    if (n == 0) return;
    hanoiRecursive(n - 1, from, aux, to, pegs, window);
    moveDisk(pegs, from, to, window);
    hanoiRecursive(n - 1, aux, to, from, pegs, window);
}

// algorithme itératif
void hanoiIterative(int n, Peg pegs[3], sf::RenderWindow &window) {
    stack<tuple<int,int,int>> s;
    s.push({n,0,2}); // déplacer n disks de la tour 0 à la tour 2
    int aux = 1;

    while(!s.empty()) {
        auto [disks, from, to] = s.top();
        s.pop();
        if (disks == 1) {
            moveDisk(pegs, from, to, window);
        } else {
            s.push({disks-1, aux, to});
            s.push({1, from, to});
            s.push({disks-1, from, aux});
        }
    }
}

int main() {
    int n;
    cout << "Enter number of disks (3-6 recommended): ";
    cin >> n;

    int mode;
    cout << "Choose mode: 1-Recursive, 2-Iterative: ";
    cin >> mode;

    sf::RenderWindow window(sf::VideoMode(600, 400), "Tower of Hanoi");

    Peg pegs[3];
    // Initialiser les disques sur la première tour
    for (int i = n; i >= 1; i--) {
        Disk d;
        d.shape.setSize(sf::Vector2f(20*i, 20));
        d.shape.setFillColor(sf::Color::Red);
        pegs[0].disks.push_back(d);
    }

    drawPegsAndDisks(window, pegs);

    auto start = high_resolution_clock::now();

    if (mode == 1)
        hanoiRecursive(n, 0, 2, 1, pegs, window);
    else
        hanoiIterative(n, pegs, window);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " ms" << endl;

    // Garder la fenêtre ouverte
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
    }

    return 0;
}
