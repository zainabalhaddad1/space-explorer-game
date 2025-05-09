// game.h
#ifndef GAME_H
#define GAME_H

// Here we define a structure named "Position" which will consist of two integers (x and y)
typedef struct {
    int x; // The horizontal position of something
    int y; // The vertical position of something
} Position;

// Here we define a structure named "SpaceExplorer" which will represent the overall state of the game
typedef struct {
    Position playerPos; // The player's location
    int gridWidth;    // The width of the game grid
    int gridHeight;   // The height of the game grid
    // We could add information about asteroids, points, or anything else in the game here
} SpaceExplorer;

// Here we declare a function named "updatePlayerLocation" which will take game information and a new location for the player
void updatePlayerLocation(SpaceExplorer *game, int newX, int newY);

// Here we declare a function named "initializeGame" which will start the game and give it grid dimensions
SpaceExplorer initializeGame(int width, int height);

// Here we declare a function named "checkGameConditions" which will see who won and who lost
void checkGameConditions(const SpaceExplorer *game);

// Here we declare a function named "generateAsteroid" which will create a new asteroid (simple example)
Position generateAsteroid(int gridWidth, int gridHeight);

// Here we declare a function named "moveAsteroid" which will move the asteroid (simple example)
void moveAsteroid(Position *asteroid);

// Here we declare a function named "setDifficulty" which will change the game difficulty (simple example)
void setDifficulty(int difficultyLevel);

// Here we declare a function (dummy in this example) that will perform file-related operations
void performFileOperations();

// Here we declare a function (dummy in this example) that will draw the game's appearance on the screen
void renderGrid(const SpaceExplorer *game);

#endif // GAME_H