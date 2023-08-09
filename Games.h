#ifndef GAMES_H
#define GAMES_H

#include <iostream>
#include <string>
#include <vector>

class Game {
public:
    // Constructor
    Game();

    // Function to start the trivia game
    bool startTriviaGame();

private:
    struct TriviaQuestion {
        std::string question;
        std::string options[4];
        char correctOption;
    };

    // Private member variables
    std::vector<TriviaQuestion> questions;
    int numCorrectAnswers;

    // Private member functions
    void loadQuestionsFromFile(const std::string& fileName);
    void askQuestion(const TriviaQuestion& question);
};

#endif