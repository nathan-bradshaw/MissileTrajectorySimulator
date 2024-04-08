#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h> // For usleep function

// Function to clear the screen
void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape sequence to clear screen
}

// Function to visualize the missile trajectory with animation
void visualizeTrajectory(const std::vector<std::pair<double, double>>& trajectory) {
    // Define grid size
    const int gridWidth = 100;
    const int gridHeight = 30;

    // Create a grid to represent the trajectory
    std::vector<std::vector<char>> grid(gridHeight, std::vector<char>(gridWidth, ' '));

    // Get maximum y-coordinate to scale the trajectory
    double maxY = 0.0;
    for (const auto& point : trajectory) {
        if (point.second > maxY) {
            maxY = point.second;
        }
    }

    // Animate the trajectory
    for (double t = 0.0; t <= trajectory.back().first; t += 0.1) { // Increment time by 0.1 seconds
        // Clear the screen
        clearScreen();

        // Clear the grid
        for (auto& row : grid) {
            std::fill(row.begin(), row.end(), ' ');
        }

        // Plot the trajectory at current time
        for (const auto& point : trajectory) {
            if (point.first <= t) {
                int x = static_cast<int>((point.first / trajectory.back().first) * (gridWidth - 1));
                int y = static_cast<int>((maxY - point.second) / maxY * (gridHeight - 1)); // Flip y-coordinate
                if (x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
                    grid[y][x] = '*';
                }
            }
        }

        std::cout << "\033[1;32m";
        // Render the grid
        for (int i = 0; i < gridHeight; ++i) {
            for (int j = 0; j < gridWidth; ++j) {
                std::cout << grid[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << "\033[0m";

        // Delay to control animation speed
        usleep(500);
    }
}
