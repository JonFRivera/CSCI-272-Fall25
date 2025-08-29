#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool wordCheck(string word) {

  if (cin.fail() || word.length() != 4) {
    cin.clear();
    cin.ignore(TMP_MAX, '\n');
    cout << "Incorrect. Please enter four letter word." << endl;
  } else {
    return true;
  }

  return false;

}

string userRequest() {

  string word {};

do {

  cout << "Please guess four-letter word: ";
  cin >> word;
  
} while (!wordCheck(word));

  return word;
  
}

int mainOperation(vector<string> &database) {

  int numberOfGuesses {0};

  [[maybe_unused]] vector<string>::iterator wordDatabaseIt;

  do {
    string userWord = userRequest();

    for (auto wordDatabaseIt = database.begin(); wordDatabaseIt != database.end(); ) {
      if (*wordDatabaseIt == userWord) {
        wordDatabaseIt = database.erase(wordDatabaseIt);
      } else {
        wordDatabaseIt++;
      }
    }

    numberOfGuesses++;

    if (numberOfGuesses != 4) {
      for (auto word : database) {
        cout << word << endl;
      }
    }

  } while (numberOfGuesses != 4);

  database.shrink_to_fit();
  return 0;
}

int main() {

  vector<string> wordDatabase = {"WORD", "TRUE", "USER", "MAIN"};

  mainOperation(wordDatabase);
  
  
  if (wordDatabase.size() == 0) {
    cout << "All Words Have Been Found!" << endl;
  } else {
    cout << "Final Words Remaining: " << endl;
    for (auto word : wordDatabase) {
      cout << word << endl;
    }
  }
  
  return 0;
  
}