## Missile Trajectory Simulator

This program simulates the trajectory of missiles based on user-provided parameters such as initial velocity, launch angle, gravitational acceleration, and time to impact. It calculates various parameters related to the missile's trajectory and provides a visualization of the trajectory using ASCII art.

### Source Files

- **data_processing.h/cpp**: Contains functions to perform data processing related to missile trajectory calculations.
- **missile.h/cpp**: Defines the Missile class and its methods for representing individual missiles.
- **ui.h/cpp**: Handles user interface functions, including displaying menus and obtaining user input.
- **visualization.h/cpp**: Implements functions for visualizing the missile trajectory using ASCII art.
- **main.cpp**: Entry point of the program where user interactions and simulations are managed.

### Functionality

- **Data Processing**: Calculates horizontal distance, maximum height, and time of flight based on input parameters.
- **Missile Class**: Represents individual missiles and calculates their trajectories.
- **User Interface**: Guides users through simulation setup and displays simulation parameters.
- **Visualization**: Provides an animated ASCII art representation of the missile trajectory.

### Building Instructions

This project uses CMake for building. Follow these steps to build the project:

1. Ensure CMake (version 3.10 or higher) is installed on your system.
2. Navigate to the project directory in the terminal.
3. Create a build directory: `mkdir build && cd build`.
4. Generate build files: `cmake ..`.
5. Build the project: `cmake --build .`.

### Usage

After building the project, you can run the executable generated. Follow the on-screen instructions to set up simulations, choose options from the main menu, and visualize missile trajectories.

### Author

This Missile Trajectory Simulator is authored by Nathan Bradshaw.

For any inquiries or issues, please contact the author.
