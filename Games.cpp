#include "Games.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <iostream>
using namespace std;

Game::Game() {
    numCorrectAnswers = 0;
    loadQuestionsFromFile("QuestionBank.txt");
}

void Game::loadQuestionsFromFile(const std::string& fileName) {
    std::ifstream inFile(fileName);

    if (!inFile.is_open()) {
        std::cout << "Failed to open " << fileName << std::endl;
        return;
    }

    TriviaQuestion question;
    std::string line;

    while (std::getline(inFile, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }

        if (line[0] == 'Q') {
            question.question = line.substr(3);
        } else if (line[0] == 'a') {
            question.options[0] = line.substr(4);
        } else if (line[0] == 'b') {
            question.options[1] = line.substr(4);
        } else if (line[0] == 'c') {
            question.options[2] = line.substr(4);
        } else if (line[0] == 'd') {
            question.options[3] = line.substr(4);
        } else if (line[0] == 'A') {
            question.correctOption = line[8];
            questions.push_back(question);
        }
    }
    inFile.close();
}

void Game::askQuestion(const TriviaQuestion& question) {
    cout << "Q: " << question.question << endl;

    char optionLetter = 'a';
    for (int i = 0; i < 4; ++i) {
        cout << optionLetter << ") " << question.options[i] << endl;
        optionLetter++;
    }

    cout << "Answer (a, b, c, or d): ";
    char userAnswer;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    cin >> userAnswer;

    userAnswer = tolower(userAnswer); // Convert the answer to lowercase for case-insensitive comparison

    if (userAnswer == question.correctOption) {
        cout << "Correct!" << endl;
        numCorrectAnswers++;
    } else {
        cout << "Incorrect!" << endl;
    }

    cout << endl;
}


bool Game::startTriviaGame() {
    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Shuffle the questions to get random order
    std::shuffle(questions.begin(), questions.end(), gen);

    numCorrectAnswers = 0;
    for (int i = 0; i < 5; ++i) {
        askQuestion(questions[i]);
    }

    std::cout << "You answered " << numCorrectAnswers << " out of 5 questions correctly." << std::endl;

    // Return true if the player answered at least 3 questions correctly, else return false
    return numCorrectAnswers >= 3;
}