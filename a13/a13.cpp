#include <iostream>
#include <string>
#include <cstring>
#include <termios.h>
#include <unistd.h>
#include <algorithm>

class TerminalHandler {
public:
    TerminalHandler() {
        // Save the current terminal settings
        tcgetattr(STDIN_FILENO, &old_tio);
        new_tio = old_tio;

        // Disable canonical mode and echoing
        new_tio.c_lflag &= (~ICANON & ~ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    }

    ~TerminalHandler() {
        // Restore the original terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    }

    // Read a single character without requiring Enter and without echoing it to the screen
    char readChar() const {
        char ch;
        ch = getchar();
        return ch;
    }

    // Clear the screen
    void clearScreen() const {
        std::cout << "\033[2J\033[1;1H";  // ANSI escape code to clear screen and move cursor to top-left
    }

    // Print the first N characters of a C-string at a specific position (row, col)
    void printAtPosition(const char* str, int n, int row, int col) const {
        std::cout << "\033[" << row << ";" << col << "H";  // Move cursor to (row, col)
        std::cout.write(str, n);  // Print the first N characters
        std::cout.flush();  // Ensure the output is displayed
    }

private:
    struct termios old_tio, new_tio;
};

void scrollMessage(const char* message) {
    const int displayWidth = 8;
    const int msgLength = std::strlen(message);

    if (msgLength < 20) {
        std::cerr << "Message must be at least 20 characters long." << std::endl;
        return;
    }

    TerminalHandler terminal;
    int offset = 0;

    while (true) {
        terminal.clearScreen();
        
        // Calculate how many characters to print
        int charsToPrint = std::min(displayWidth, msgLength - offset);
        terminal.printAtPosition(message + offset, charsToPrint, 5, 10);

        // Scroll
        offset++;
        if (offset >= msgLength) {
            offset = 0;  // Restart from the beginning of the message
        }

        // Delay to slow down the scrolling
        usleep(200000);  // Sleep for 200ms

        // Check for ESC key press
        if (terminal.readChar() == 27) {  // 27 is the ASCII code for ESC
            break;
        }
    }
}

int main() {
    const char* message = "This is a message that will scroll across the screen!";
    scrollMessage(message);
    return 0;
}
