
# Maze Solver Game

## Description
The Maze Solver Game is a simple, console-based game implemented in C. The player navigates a randomly generated maze from the top-left corner (start) to the bottom-right corner (end) using keyboard inputs. It is designed to demonstrate basic concepts of C programming including loops, arrays, functions, structures, and user input handling.

## Features
- Randomly generated solvable maze
- Real-time keyboard input using W, A, S, D keys
- Console-based interface with a step counter
- Option to restart or exit the game
- Clean and modular code structure

## Controls
- **W**: Move Up
- **A**: Move Left
- **S**: Move Down
- **D**: Move Right
- **Q**: Quit the game

## How to Compile and Run
1. Open a terminal or command prompt.
2. Use a C compiler like GCC to compile the program:

   ```bash
   gcc -o maze_game maze_game.c
   ```

3. Run the compiled executable:

   ```bash
   ./maze_game  # On Linux/Mac
   maze_game.exe  # On Windows
   ```

> Note: This game uses Windows-specific headers (`<conio.h>` and `<windows.h>`). For compatibility with non-Windows systems, these parts need modification.

## Files
- `maze_game.c`: Main source code for the Maze Solver Game.
- `README.md`: This file, providing instructions and information about the game.

## Requirements
- GCC or any standard C compiler
- Windows OS (or adapt for Linux/macOS)
- Console terminal

## Future Improvements
- Add GUI using libraries like SDL or ncurses
- Implement save/load game feature
- Include different levels and maze sizes
- Add sound effects and scoring system

## License
This project is for educational purposes and is distributed under the MIT License.

## Author
Group Project - Maze Solver Game (4 Members)
- Member 1: Arnob Mallik Dhruba
 ID: 2512446642
- Member 2: Sumaya Islam Kotha
ID: 2511242642
- Member 3: Samrin Fatema
ID: 2513373042
- Member 4: S.M. Robiul Islam
ID: 2513924642
