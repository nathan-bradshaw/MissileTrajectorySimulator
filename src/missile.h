#ifndef MISSILE_H
#define MISSILE_H

#include <string>
#include <vector>

class Missile {
private:
    std::string type;
    double initialVelocity;
    double launchAngle;
    double gravity;

public:
    Missile(int id, double initialVelocity, double launchAngle, double gravity); // Modify the constructor
    std::string getType() const;
    double getInitialVelocity() const;
    double getLaunchAngle() const;
    double getGravity() const;
    std::vector<std::pair<double, double>> calculateTrajectory(double timeToImpact) const;
};

#endif // MISSILE_H
