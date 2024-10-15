
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

string ReadFileLocation = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/Scrabble solver/Text Files/unigram_freq.txt";
string PutFileLocation = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/Scrabble solver/Text Files/Valid_words.txt";

const string letters = "givethanksla"; // cant do array because typing through all the ' would take too long during a game of scrabble. spacebar is a wild
string piss = letters; // temp for searching
string balls = ""; // temp for current word to be tested

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


  while (getline(GetFile, balls)) { // whole file

    balls = balls.substr(0, balls.find(','));

    piss = letters; // reset temp value

    for (int i = 0; i < balls.length(); i++) { // for every letter in word
      
      if (piss == "") { // out of usable letters
        // cout << "out of letters" << endl;

        break;
      }
      

      if (piss.find(balls.at(i)) != -1) { // iff ith letter of balls is in piss

        piss = piss.substr(0, piss.find(balls.at(i))) + piss.substr(piss.find(balls.at(i)) + 1, piss.length() - piss.find(balls.at(i))); // remove letter from temp


      } else { // letter missing
        // cout << "letter missing" << endl;
        break;
      }

      if (i == balls.length() - 1) {
        cout << "valid word: " << balls << endl;
        PutFile << balls.length() << " " << balls << endl;
      }
      
    }

  }

  // cout << "we up" << endl;

  GetFile.close();
  PutFile.close();
}
