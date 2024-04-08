#include "data_processing.h" // Include data processing functions
#include "ui.h"
#include "missile.h"
#include "visualization.h"
#include <iostream>
#include <limits> // For std::numeric_limits

int main() {
    int choice;

    do {
        // Show the main menu
        UI::showMainMenu();

        // Get user choice
        while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
            std::cout << "Invalid input. Please enter 1 or 2: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: {
                // Get the number of missiles
                int numMissiles;
                std::cout << "Enter the number of missiles: ";
                while (!(std::cin >> numMissiles) || numMissiles <= 0) {
                    std::cout << "Invalid input. Please enter a positive integer: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                std::vector<Missile> missiles; // Vector to hold missiles
                for (int i = 0; i < numMissiles; ++i) {
                    std::cout << "\nMissile " << (i + 1) << " parameters:" << std::endl;

                    // Get user input for missile parameters
                    UI::SimulationParameters missileParams = UI::getUserInputForParameters();

                    // Create missile with individual parameters
                    Missile missile(i + 1, missileParams.initialVelocity, missileParams.launchAngle, missileParams.gravity);
                    missiles.push_back(missile); // Add missile to vector

                    // Calculate and display trajectory for this missile
                    std::vector<std::pair<double, double>> trajectory = missile.calculateTrajectory(missileParams.timeToImpact); // Calculate trajectory
                    visualizeTrajectory(trajectory); // Visualize trajectory
                    UI::displaySimulationParameters(missileParams);

                    // Calculate additional parameters using data processing functions
                    std::cout << "\nAdditional Parameters:" << std::endl;
                    std::cout << "Horizontal Distance: " << DataProcessing::calculateHorizontalDistance(missileParams.initialVelocity, missileParams.launchAngle, missileParams.gravity) << " m" << std::endl;
                    std::cout << "Maximum Height: " << DataProcessing::calculateMaximumHeight(missileParams.initialVelocity, missileParams.launchAngle, missileParams.gravity) << " m" << std::endl;
                    std::cout << "Time of Flight: " << DataProcessing::calculateTimeOfFlight(missileParams.initialVelocity, missileParams.launchAngle, missileParams.gravity) << " s" << std::endl;

                    std::cout << std::endl;
                }
                break;
            }
            case 2: {
                // Exit the program
                UI::displayGoodbyeMessage();
                break;
            }
        }
    } while (choice != 2);

    return 0;
}
