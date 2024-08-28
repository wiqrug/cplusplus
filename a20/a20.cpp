/*
Να δημιουργηθεί κλάση η οποία θα παριστά τον χάρτη ενός
λαβύρινθου που καταλαμβάνει ορθογώνιο χώρο Μ Χ Ν θέσεων. Ο χαρακτήρας “”*”
παριστά τοίχους και ο χαρακτήρας “ “ διαδρόμους. Τα αντικείμενα της κλάσης θα
αρχικοποιούνται με δεδομένα που θα διαβάζονται από αρχείο κειμένου το οποίο θα
περιέχει μόνο τις γραμμές του χάρτη. Η κλάση θα παρέχει τη ακόλουθη
λειτουργικότητα:
Τύπωμα χάρτη σε κανάλι.
Τροποποίηση θέσης του χάρτη.
Αποθήκευση χάρτη σε αρχείο κειμένου
Εύρεση τυχαίας θέσης στον λαβύρινθο η οποία αποτελεί μέρος διαδρόμου.
Δημιουργία συμμετρικού χάρτη (κατακόρυφη συμμετρία)
Η αναφορά λαθών που προκύπτουν κατά τη λειτουργία του διαβάσματος από αρχείο
θα πραγματοποιείται με χρήση εξαιρέσεων.
 */




#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cstdlib>  // Για τη χρήση της rand()
#include <ctime>    // Για την αρχικοποίηση της rand()

class Maze {
private:
    std::vector<std::string> map;
    int rows, cols;

public:
    Maze(const std::string& filename);
    void printMap(std::ostream& os) const;
    void modifyPosition(int x, int y, char value);
    void saveToFile(const std::string& filename) const;
    std::pair<int, int> findRandomPathPosition() const;
    void createSymmetricMaze();

private:
    bool isValidPosition(int x, int y) const;
};

Maze::Maze(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (cols == 0) {
            cols = line.length(); // Ορίζει τον αριθμό των στηλών
        }
        map.push_back(line);
    }
    rows = map.size(); // Ορίζει τον αριθμό των γραμμών
    file.close();
}

void Maze::printMap(std::ostream& os) const {
    for (const auto& line : map) {
        os << line << std::endl;
    }
}

void Maze::modifyPosition(int x, int y, char value) {
    if (!isValidPosition(x, y)) {
        throw std::out_of_range("Invalid position in the maze.");
    }
    map[x][y] = value;
}

void Maze::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    for (const auto& line : map) {
        file << line << std::endl;
    }
    file.close();
}

std::pair<int, int> Maze::findRandomPathPosition() const {
    std::srand(std::time(0)); // Αρχικοποίηση της rand με το χρόνο

    while (true) {
        int x = std::rand() % rows;
        int y = std::rand() % cols;

        if (map[x][y] == ' ') {
            return {x, y};
        }
    }
}

void Maze::createSymmetricMaze() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols / 2; ++j) {
            map[i][cols - j - 1] = map[i][j];
        }
    }
}

bool Maze::isValidPosition(int x, int y) const {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

int main() {
    try {
        Maze maze("maze.txt");

        std::cout << "Original Maze:" << std::endl;
        maze.printMap(std::cout);

        maze.modifyPosition(2, 3, '*');
        maze.saveToFile("modified_maze.txt");

        auto randomPosition = maze.findRandomPathPosition();
        std::cout << "Random path position: (" << randomPosition.first << ", " << randomPosition.second << ")" << std::endl;

        maze.createSymmetricMaze();
        std::cout << "Symmetric Maze:" << std::endl;
        maze.printMap(std::cout);

        maze.saveToFile("symmetric_maze.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
