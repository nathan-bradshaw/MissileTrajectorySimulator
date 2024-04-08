#include "missile.h"
#include <cmath>
#include <iostream>

Missile::Missile(int id, double initialVelocity, double launchAngle, double gravity)
    : type("Type" + std::to_string(id)), initialVelocity(initialVelocity), launchAngle(launchAngle), gravity(gravity) {}

std::string Missile::getType() const {
    return type;
}

double Missile::getInitialVelocity() const {
    return initialVelocity;
}

double Missile::getLaunchAngle() const {
    return launchAngle;
}

double Missile::getGravity() const {
    return gravity;
}

std::vector<std::pair<double, double>> Missile::calculateTrajectory(double timeToImpact) const {
    std::vector<std::pair<double, double>> trajectory;
    double g = gravity; // acceleration due to gravity in m/s^2

    // Calculate launch angle in radians
    double launchAngleRadians = launchAngle * M_PI / 180.0;

    // Calculate initial velocities using trigonometric functions
    double initialVelocityX = initialVelocity * sin(launchAngleRadians);
    double initialVelocityY = initialVelocity * cos(launchAngleRadians);

    double x = 0.0; // initial x position
    double y = 0.0; // initial y position
    double t = 0.0; // initial time
    double deltaT = 0.1; // time step for simulation

    while (t <= timeToImpact) {
        x = initialVelocityX * t;
        y = initialVelocityY * t - 0.5 * g * t * t;
        trajectory.push_back(std::make_pair(x, y));
        t += deltaT;
    }

    return trajectory;
}

