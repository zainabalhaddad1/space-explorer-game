// main.c
#include <stdio.h>   // For standard input/output operations
#include <stdlib.h>  // For general utilities like random number generation
#include <time.h>    // For time-related functions, used for random seed
#include "game.h"    // Including the header file "game.h"

// A simple variable to represent the game difficulty (example)
int gameDifficulty = 1;

// Q1: Explanation of the player location update function
void updatePlayerLocation(SpaceExplorer *game, int newX, int newY) {
    printf("Attempting to move the player to (%d, %d)\n", newX, newY);
    // First, we check if the new location is within the game grid boundaries
    if (newX >= 0 && newX < game->gridWidth && newY >= 0 && newY < game->gridHeight) {
        game->playerPos.x = newX; // If within bounds, update the player's x-coordinate
        game->playerPos.y = newY; // And update the player's y-coordinate
        printf("Player is now at (%d, %d)\n", game->playerPos.x, game->playerPos.y);
    } else {
        printf("Whoops! The player tried to move outside the grid! Current location: (%d, %d)\n", game->playerPos.x, game->playerPos.y);
        // Here, we could implement other actions like preventing movement or displaying an error message
    }
}

// Q9: Explanation of the game initialization function
SpaceExplorer initializeGame(int width, int height) {
    SpaceExplorer game; // Create a new "notebook" to store the game's state
    game.gridWidth = width;   // Record the entered width of the grid
    game.gridHeight = height; // And record the entered height of the grid
    game.playerPos.x = width / 2;  // Initially place the player in the middle of the grid horizontally
    game.playerPos.y = height / 2; // And in the middle vertically
    printf("Game started! Grid: %d x %d, Player location: (%d, %d)\n",
           game.gridWidth, game.gridHeight, game.playerPos.x, game.playerPos.y);
    return game; // Return this "notebook" so we know the game's state
}

// Q3: Explanation of the function to check win/lose conditions
void checkGameConditions(const SpaceExplorer *game) {
    // Simple example: we could say the player wins if they reach a certain location (still need to define that location)
    // And loses if they collide with an asteroid (still need to add asteroids)
    // This check usually happens frequently in the game after any movement or change
    printf("Currently checking win/lose conditions (this function is not fully implemented in this simple example).\n");
    // In the full game, this would involve checks like:
    // - Has the player reached the target location? (Win)
    // - Has the player collided with an asteroid? (Lose)
    // - Has the time run out? (Could be a loss or a draw)
}

// Q5: Explanation of the function to create and move asteroids (simple example)
Position generateAsteroid(int gridWidth, int gridHeight) {
    Position asteroid; // Create a new "location" for the asteroid
    asteroid.x = rand() % gridWidth; // Give the asteroid a random horizontal position
    asteroid.y = 0;                  // And make it start from the top
    printf("New asteroid spawned at (%d, %d)\n", asteroid.x, asteroid.y);
    return asteroid; // Return the "location" of this asteroid
}

void moveAsteroid(Position *asteroid) {
    asteroid->y++; // Move the asteroid down by one step
    printf("Asteroid moved to (%d, %d)\n", asteroid->x, asteroid->y);
    // In the full game, the asteroid could move left, right, faster, or slower
}

// Q6: Explanation of the function to change game difficulty (simple example)
void setDifficulty(int difficultyLevel) {
    gameDifficulty = difficultyLevel; // Record the difficulty level chosen by the player
    printf("Game difficulty changed to: %d\n", gameDifficulty);
    // Here, we could implement other actions based on the difficulty, such as:
    // - Making asteroids faster or slower
    // - Increasing or decreasing the number of asteroids
    // - Making player movement faster or slower
    // - Adding items to help or hinder the player
}

// Q7: Explanation of the function to handle files (simple example)
void performFileOperations() {
    printf("The game (in the full version) could perform file-related operations like:\n");
    printf("- Saving the game so the player can continue later (in a file named, for example, savegame.dat or savegame.txt).\n");
    printf("- Recording high scores so people can see who the best is (in a file named, for example, highscores.txt).\n");
    printf("- Reading game settings configured by the player (in a file named, for example, config.ini or settings.json).\n");
    // In this simple example, this function doesn't actually do anything with files.
}

// Q10: Explanation of the function to display the game grid on the screen (simple example)
void renderGrid(const SpaceExplorer *game) {
    printf("\n--- Game Grid ---\n");
    // Loop through each position in the grid, row by row
    for (int y = 0; y < game->gridHeight; y++) {
        for (int x = 0; x < game->gridWidth; x++) {
            // If this position contains the player, draw a "P"
            if (x == game->playerPos.x && y == game->playerPos.y) {
                printf("P ");
            } else {
                printf(". "); // If the position is empty, draw a dot
            }
        }
        printf("\n"); // Move to the next line after finishing a row
    }
    printf("-------------------\n");
}

// Q8: Explanation of how we organized our code in a structured way
// We divided the code into small functions, each performing a specific task in the game,
// such as a function to move the player, a function to create an asteroid, a function to display the screen, and so on.
// We also used "Position" and "SpaceExplorer" to organize game information.
// This approach makes the code easier to read and modify, and if we want to change something in the game,
// we can directly go to the function that handles that specific task instead of searching through a large, monolithic code.

int main() {
    srand(time(NULL)); // This is to make the random numbers different each time the game is run

    SpaceExplorer game = initializeGame(10, 8); // Start the game with a grid of 10 units wide and 8 units high

    setDifficulty(2); // Set the game difficulty (level 2 as an example)

    renderGrid(&game); // Display the initial game grid

    // Attempt to move the player
    updatePlayerLocation(&game, 5, 4);
    renderGrid(&game); // Display the grid after the move

    updatePlayerLocation(&game, 12, 5); // Attempt to move outside the grid
    renderGrid(&game); // Display the grid again

    Position asteroid1 = generateAsteroid(game.gridWidth, game.gridHeight); // Create a new asteroid
    moveAsteroid(&asteroid1); // Move the asteroid

    checkGameConditions(&game); // Check for win/lose conditions (still not fully implemented)

    performFileOperations(); // Perform any file-related operations (currently doesn't do anything real)

    printf("\nGame Over.\n");

    return 0;
}