#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;


const string letters = "airplane"; // cant do array because typing through all the ' would take too long during a game of scrabble. spacebar is a wild
string piss = ""; // temp for ???
string balls = ""; // temp for current word to be tested


string ReadFileLocation = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/Scrabble solver/Text Files/unigram_freq.txt";
string PutFileLocation = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/Scrabble solver/Text Files/" + letters + "_Valid_words.txt";

// returns unused letters
string isValid (string TestWord, string AvailableLetters) {
  
  for (int i = 0; i < TestWord.length(); i++) { // for every letter in word

    if (AvailableLetters == "") { // out of usable letters
      // cout << "out of letters" << endl;
      break;
    }
    

    if (AvailableLetters.find(TestWord.at(i)) != -1) { // if ! missing letter
      
      AvailableLetters = AvailableLetters.substr(0, AvailableLetters.find(TestWord.at(i))) + AvailableLetters.substr(AvailableLetters.find(TestWord.at(i)) + 1, AvailableLetters.length() - AvailableLetters.find(TestWord.at(i))); // remove letter from temp

    } else { // letter missing

      if (AvailableLetters.find(' ') != -1) { // wild letter
        AvailableLetters = AvailableLetters.substr(0, AvailableLetters.find(' ')) + AvailableLetters.substr(AvailableLetters.find(' ') + 1, AvailableLetters.length() - AvailableLetters.find(' ')); // remove letter from temp
        // cout << "Wild used" << endl;

      } else {
        // cout << "letter missing" << endl;
        break;
      }
    }

    if (i == TestWord.length() - 1) {
      return AvailableLetters;
    }

  }
  return "!"; // not admissible
}


int main() {


 
  ifstream GetFile; // file to read from
  GetFile.open(ReadFileLocation);
  while (!GetFile.is_open()) { // wait until open file
    cout << "Get File unable to open" << endl;
    _sleep(5000);
    GetFile.open(ReadFileLocation); 
  }


  ofstream PutFile; // file to put to
  PutFile.open(PutFileLocation); // creates file I dont think I need to wait for that
  while (!PutFile.is_open()) { // wait until open file
    cout << "Put File unable to open" << endl;
    _sleep(5000);
    GetFile.open(PutFileLocation); 
  }

  cout << "files open. generating list" << endl;
  while (getline(GetFile, balls)) { // whole file
  // for (int r = 0; r < 10000; r++) {
  //   getline(GetFile, balls);

    while (balls.at(0) == '/'){ // skip comments
      getline(GetFile, balls);   
    }
    


    balls = balls.substr(0, balls.find(','));
    piss = isValid(balls, letters);

    // cout << balls.length() << " " << balls << endl;

    if (piss != "!") {
      
      PutFile << balls.length() << " " << balls << endl;
      
    }


  }

  cout << endl << endl << endl << endl << "List Generated" << endl;

  GetFile.close();
  PutFile.close();
}
