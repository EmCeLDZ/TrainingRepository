# TrainingRepository

This is a simple project in Unreal Engine version 4.27 that showcases basic usage of C++ and Blueprints, as well as GitHub repository management.

## Getting Started

To get started with this project, simply clone this repository to your local machine.

### Prerequisites

Make sure you have Unreal Engine version 4.27 installed on your machine.

### Installing

1. Clone this repository to your local machine.
2. Open the project in Unreal Engine.

## Built With

* Windows Platform

* Unreal Engine 4.27

## What will you find in the project?

The character blueprint class has been reparented to a custom C++ class (EmCe_Character.cpp). This class contains simple functions that trigger animation for rolling, Niagara particle effects, and sound when the left mouse button is pressed. It also displays information on the screen about the pressed button.

The project features a sample C++ component, (EmCe_HealthComponent). This component allows us to define health, maximum health, and regeneration rates. The component regenerates health if it falls below the maximum health and deactivates itself after reaching full charge. A basic "TakeDamage" function has been added to this component to allow damage to be inflicted and to test the system. Currently, this function is triggered by the "K" input in the character's Blueprint.

The project also includes a sample Day/Night Plugin written in C++. It creates a button in the editor that enables the modification of lighting and post-processing effects when clicked (EmCe_DayNightPlugin). The plugin checks whether lighting and post-processing effects are added to the map, displaying a relevant message if they are missing.

In addition, the project has undergone cosmetic changes. The loading screen appearance, the icon for the built game, and the plugin icon have been updated to ensure a more cohesive and distinctive look compared to others. Essential project information such as the project description, author details, and the designated map to be included in the project have also been revised.

## Authors

* EmCeLDZ

## License 

* The project is covered by the MIT license. More information can be found in the LICENSE.md file.

## Acknowledgments

* Thanks to anyone whose code was used.
