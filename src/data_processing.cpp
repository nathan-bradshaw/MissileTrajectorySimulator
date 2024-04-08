#include "data_processing.h"

#include <cmath>

// Function to calculate the horizontal distance traveled by the missile
double DataProcessing::calculateHorizontalDistance(double initialVelocity, double launchAngle, double gravity) {
    // Convert launch angle from degrees to radians
    double launchAngleRadians = launchAngle * M_PI / 180.0;
    
    // Calculate horizontal distance using the projectile motion formula
    double horizontalDistance = (initialVelocity * initialVelocity * sin(2 * launchAngleRadians)) / gravity;
    
    return horizontalDistance;
}

// Function to calculate the maximum height reached by the missile
double DataProcessing::calculateMaximumHeight(double initialVelocity, double launchAngle, double gravity) {
    // Convert launch angle from degrees to radians
    double launchAngleRadians = launchAngle * M_PI / 180.0;
    
    // Calculate maximum height using the projectile motion formula
    double maximumHeight = (initialVelocity * initialVelocity * sin(launchAngleRadians) * sin(launchAngleRadians)) / (2 * gravity);
    
    return maximumHeight;
}

// Function to calculate the time of flight of the missile
double DataProcessing::calculateTimeOfFlight(double initialVelocity, double launchAngle, double gravity) {
    // Convert launch angle from degrees to radians
    double launchAngleRadians = launchAngle * M_PI / 180.0;
    
    // Calculate time of flight using the projectile motion formula
    double timeOfFlight = (2 * initialVelocity * sin(launchAngleRadians)) / gravity;
    
    return timeOfFlight;
}
