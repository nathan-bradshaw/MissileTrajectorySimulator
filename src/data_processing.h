#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H

#include <vector>
#include <string>
#include "missile.h"

class DataProcessing {
public:
    // Function to calculate the horizontal distance traveled by the missile
    static double calculateHorizontalDistance(double initialVelocity, double launchAngle, double gravity);

    // Function to calculate the maximum height reached by the missile
    static double calculateMaximumHeight(double initialVelocity, double launchAngle, double gravity);

    // Function to calculate the time of flight of the missile
    static double calculateTimeOfFlight(double initialVelocity, double launchAngle, double gravity);
};

#endif // DATA_PROCESSING_H
