
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

string fileLocation = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/Scrabble solver/Text Files/unigram_freq.txt";
const string letters = "bringbackthegold"; // cant do array because typing through all the ' would take too long during a game of scrabble
string piss = letters; // temp for searching
string balls = ""; // temp for current word to be tested

int main() {

  ifstream GetFile; 
  GetFile.open(fileLocation);
  while (!GetFile.is_open()) { // wait until open file
    cout << "File unable to open" << endl;
    _sleep(5000); // I know its depricated :(
    GetFile.open(fileLocation); 
  }

  while (getline(GetFile, balls)) { // whole file
  // for (int r = 0; r < 10000; r++) { // for testing so we dont use the whole file
  //   getline(GetFile, balls);

    balls = balls.substr(0, balls.find(',')); // use the word not the frequency
    
    piss = letters; // reset temp value

    for (int i = 0; i < balls.length(); i++) { // for every letter in word
      
      if (piss == "") { // out of usable letters
        break;
      }
      

      if (piss.find(balls.at(i)) != -1) { // iff ith letter of balls is in piss

        piss = piss.substr(0, piss.find(balls.at(i))) + piss.substr(piss.find(balls.at(i)) + 1, piss.length() - piss.find(balls.at(i))); // remove letter from temp


      } else { // letter missing
        break;
      }

      if (i == balls.length() - 1) {
        cout << "valid word: " << balls << endl;
      }
      
    }

  }

  GetFile.close();
  // cout << "we up" << endl;
}
