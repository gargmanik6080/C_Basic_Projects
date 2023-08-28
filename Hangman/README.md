# The Hangman Game

## Project Overview
The goal of this project is to develop a single-player Hangman game in the C programming language. In this game, the algorithm selects a random word(here, a famous Website) from a predefined list, and the player attempts to guess the word one letter at a time. The player has a limited number of incorrect guesses before a hangman figure is fully drawn. The game will run in the console and provide an interactive and enjoyable user experience.


## Project Goals

1. Educational Value: Create a project that serves as a learning tool for C programming, including topics like user input handling, randomization, and text-based interface design.
2. Entertainment: Develop a fun and engaging Hangman game that players can enjoy and play repeatedly.
3. User-Friendly Interface: Design a user-friendly interface with clear instructions and prompts.

## Specifications

### 1. User Interface:
<ul>
    <li>Display the Hangman figure using ASCII art to represent the stages of the hangman's construction.</li>
    <li>Display the Hangman figure using ASCII art to represent the stages of the hangman's construction </li>
    <li>Show the list of guessed letters to prevent repeated guesses</li>
</ul>

### 2. Game Logic
<ul>
    <li>Randomly select an encrypted word from a predefined list</li>
    <li>Determine if the player has guessed the word correctly or if they have run out of guesses.</li>
</ul>

### 3. Website Names List
<ul>
    <li>Store the list of the websites after encrypting each name with a monoalphabetic cipher to prevent cheating</li>
    <li>Allow the game to decrypt the name list only while in use, ensuring that it remains secure and tamper-proof.</li>
</ul>

### 4. Top Scores
<ul>
    <li>Store the score top 10 player on the basis of Total Time Taken to guess the word. </li>
    <li>Display the leaderboard at the end of each game to show the player's ranking.</li>
</ul>

## How to Play
<li>The user will be provided a Welcome Message along with the game rules. <br>
<img src="rules.png">
<li>The user will be prompted as to weather they are ready to Start the game or not. They will be promted this question till they reply with a 'Y' or 'y'.
<li>When the User enter 'Y' or 'y', Their timer will start.
<li> They will be shown the Initial Hangman Body and the word to be guessed as underscores instead of it's letters.