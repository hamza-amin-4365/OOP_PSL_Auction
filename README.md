# PSL Auction System

## Overview

The PSL Auction System is a C++ application designed to facilitate an auction for cricket players in the Pakistan Super League (PSL). It allows team managers to log in, view players from different categories, and place bids on players. The system also provides an administrative interface for managing teams and players.

## Features

- **User Authentication**: Login for team managers and admin.
- **Player Management**: Admin can add, delete, and manage players.
- **Bidding System**: Team managers can bid on players from various categories (Batsmen, Bowlers, All-Rounders).
- **Data Persistence**: Player and team information is stored in text files.

## Inheritance and Polymorphism

The Project tries to help us practice with Diamond problems as such where the All-Rounder Class is derived from both the Batsmen and Bowler classes which are already derived from a Parent Class, Players.
![player structure](https://github.com/hamza-amin-4365/cs-112-project/assets/131896316/df4f3db8-45dd-475d-9467-ae81bbd8c57e)

## Bidding Process 

The bidding process included past topics we learnt such as rand() functions to generate a 6 figure random bid made by another Cricket Team. Furthermore, it also used polymorphism and file handling to display the Players available to bid on. 

![bidding proc](https://github.com/hamza-amin-4365/cs-112-project/assets/131896316/cb9d516d-41cc-41f5-87a1-9b6fb10f7aeb)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/hamza-amin-4365/OOP_PSL_Auction.git
   ```

2. Navigate to the project directory:
   ```bash
   cd OOP_PSL_Auction
   ```

3. Open the solution file in Visual Studio: `Project3.sln`.

4. Build the project and run the `main.cpp` file.

## Usage

### Admin Functions
- **Add Team**: Admin can add a new team with a name and budget.
- **Delete Team**: Admin can delete an existing team.
- **Add Player**: Admin can add players to the auction system.

### Team Manager Functions
- **Login**: Managers can log in using their credentials.
- **Bidding**: Managers can bid on players during the auction.

### Player Categories
- Batsmen
- Bowlers
- All-Rounders

Each player type has its own dedicated file for managing player data.

## Contributing

Contributions are welcome! Please fork this repository and submit a pull request for any improvements or bug fixes.


## Contact

For any inquiries, please contact Hamza Amin at [mh4070685@gmail.com](mailto:mh4070685@gmail.com).

## Acknowledgments

- This project was developed as part of a coursework assignment for Object-Oriented Programming.
