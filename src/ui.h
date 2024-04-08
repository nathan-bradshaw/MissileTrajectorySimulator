#ifndef UI_H
#define UI_H

#include <string>

class UI {
public:
    // Define SimulationParameters struct
    struct SimulationParameters {
        double initialVelocity;
        double launchAngle;
        double gravity;
        double timeToImpact; // Add timeToImpact member
    };

    static void showMainMenu();
    static SimulationParameters getUserInputForParameters();
    static void displaySimulationParameters(const SimulationParameters& params);
    static void displayGoodbyeMessage();
};

#endif // UI_H
