#include "ui.h"
#include <iostream>
#include <limits> // For std::numeric_limits

void UI::showMainMenu() {
    std::cout << "=== Missile Trajectory Simulator ===" << std::endl;
    std::cout << "1. Start Simulation" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

UI::SimulationParameters UI::getUserInputForParameters() {
    SimulationParameters params;

    // Get initial velocity
    while (true) {
        std::cout << "Enter initial velocity (m/s): ";
        if (std::cin >> params.initialVelocity && params.initialVelocity > 0) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a positive number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Get launch angle
    while (true) {
        std::cout << "Enter launch angle (degrees): ";
        if (std::cin >> params.launchAngle && params.launchAngle >= 0 && params.launchAngle <= 90) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a number between 0 and 90." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Get gravitational acceleration
    while (true) {
        std::cout << "Enter gravitational acceleration (m/s^2): ";
        if (std::cin >> params.gravity && params.gravity > 0) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a positive number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Get time to impact
    while (true) {
        std::cout << "Enter time to impact (s): ";
        if (std::cin >> params.timeToImpact && params.timeToImpact > 0) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a positive number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return params;
}

void UI::displaySimulationParameters(const SimulationParameters& params) {
    std::cout << "=== Simulation Parameters ===" << std::endl;
    std::cout << "Initial Velocity: " << params.initialVelocity << " m/s" << std::endl;
    std::cout << "Launch Angle: " << params.launchAngle << " degrees" << std::endl;
    std::cout << "Gravitational Acceleration: " << params.gravity << " m/s^2" << std::endl;
    std::cout << "Time to Impact: " << params.timeToImpact << " s" << std::endl; // Display timeToImpact
}

void UI::displayGoodbyeMessage() {
    std::cout << "Exiting Missile Trajectory Simulator. Goodbye!" << std::endl;
}
