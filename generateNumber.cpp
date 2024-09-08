#include <iostream>
#include <random>
#include <ctime>
using namespace std;



int main() {
    // Create a random number generator and seed it with the current time
    std::random_device rd;     // Obtain a random seed
    std::mt19937 gen(rd());    // Mersenne Twister engine, seeded with random device

    // Define the range [1, 40]
    std::uniform_int_distribution<> distr(1, 40);  // Inclusive range

    // Generate a random number between 1 and 40
    int randomNumber = distr(gen);

    std::cout << "Random number between 1 and 40: " << randomNumber << std::endl;

    return 0;
}
