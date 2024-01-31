# The Hangman Game

## Project Overview
The goal of this project is to develop a single-player Hangman game in the C programming language. In this game, the algorithm selects a random word(here, a famous website name) from a predefined list, and the player attempts to guess the word one letter at a time. The player has a limited number of incorrect chances before a hangman figure is fully drawn. The game will run in the console and provide an interactive and enjoyable user experience.


## Project Goals

1. **Educational Value:** Create a project that serves as a learning tool for C programming, including topics like user input handling, randomization, and text-based interface design.
2. **Entertainment:** Develop a fun and engaging Hangman game that players can enjoy and play repeatedly.
3. **User-Friendly Interface:** Design a user-friendly interface with clear instructions and prompts.

## Specifications

### 1. User Interface:
<ul>
    <li>Display the Hangman figure using ASCII art to represent the stages of the hangman's construction.</li>
    <li>Show the list of guessed letters to prevent repeated guesses.</li>
    <li>Show the number of incorrect guesses.</li>
</ul>

### 2. Game Logic
<ul>
    <li>Randomly select an encrypted word from a predefined list.</li>
    <li>Determine if the player has guessed the word correctly or if they have run out of guesses.</li>
</ul>

### 3. Website Names List
<ul>
    <li>Store the list of the websites after encrypting each name with a monoalphabetic cipher to prevent cheating.</li>
    <li>Allow the game to decrypt the name list only while in use, ensuring that it remains secure and tamper-proof.</li>
</ul>

### 4. Guess Time
<ul>
    <li>Display the time taken to guess the word at the end to maintain a sense of competition.</li>
</ul>

## How to Use

1. **Clone the Repository:**
   - Start by cloning the repository to your local machine using the following command:
     ```
     git clone <repository-url>
     ```

2. **Navigate to the Project Directory:**
   - Change into the project directory by running the command:
     ```
     cd <project-directory>
     ```

3. **Fetch the Required Files:**
   - If the `main.c` file is not directly visible in the project directory, navigate to the appropriate subdirectory where it is located.

4. **Compile the Code:**
   - Use the appropriate compiler command to compile the `main.c` file. For example, with GCC:
     ```
     gcc main.c -o main
     ```

5. **Execute the Compiled File:**
   - After successful compilation, execute the compiled file to run the program:
     ```
     ./main
     ```
 
## How to Play
<ul>
    <li> The user will be provided a Welcome Message along with the game rules. <br>
    <img src="assets/README Images/rules.png">
    <li> The user will be prompted as to weather they are ready to Start the game or not. They will be promted this question till they reply with a 'Y' or 'y'.
    <li> When the User enter 'Y' or 'y', Their timer will start.
    <li> They will be shown the Initial Hangman Body, Current Number of Mistake (initialized to 0), Incorrect guesses (initialized to "None") and the word to be guessed as underscores instead of it's letters.
    <img src="assets/README Images/prompt.png">
    <li> The user needs to type in a character that they think could be a part of that word.
    <li>The game continues till the user either guesses the word or exhausts their attempts.
    <li>If the user win they will be shown the following message.
    <img src="assets/README Images/win.png">
</ul>

## Conclusion
In conclusion, the Game aims to create an engaging and educational experience for users through the development of a single-player Hangman game in C programming. Through features like ASCII art for the hangman figure, encrypted website names, and a timer to maintain a competitive edge, The Hangman Game offers both enjoyment and learning opportunities for players.

## Updates
<ul>
    <li> Curl (web crawler)
    <li> accepting input -1 seprately
</ul>
