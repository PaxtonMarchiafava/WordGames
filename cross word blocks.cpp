// Generates ways to reconfigure signs made of blocks so they can say different things

#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

string ReadFileLocation = "Path/Text Files/unigram_freq.txt";
string PutFileLocation = "Path/Text Files/Valid_words.txt";

const string letters = "givethanks"; // cant do array because typing through all the ' would take too long during a game of scrabble. spacebar is a wild
string remainingLetters = ""; // temp for ???
string remainingLetters2 = ""; // temp for ???
string word = ""; // temp for current word to be tested
string word2 = ""; // temp for current word to be tested


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

  ifstream GetFile2; // file to read from second lol
  GetFile2.open(ReadFileLocation);
  while (!GetFile2.is_open()) { // wait until open file
    cout << "Get File 2 unable to open" << endl;
    _sleep(5000);
    GetFile2.open(ReadFileLocation); 
  }

  ofstream PutFile; // file to put to
  PutFile.open(PutFileLocation); // creates file I dont think I need to wait for that
  while (!PutFile.is_open()) { // wait until open file
    cout << "Put File unable to open" << endl;
    _sleep(5000);
    PutFile.open(PutFileLocation); 
  }


  while (getline(GetFile, word)) { // whole file
    while (word.at(0) == '/') { // push past comments
      getline(GetFile, word);   
    }

    word = word.substr(0, word.find(','));
    remainingLetters = isValid(word, letters);


    if (remainingLetters != "!") {

      cout << word << endl;

      while (getline(GetFile2, word2)) { // check file again

        while (word2.at(0) == '/') { // push past comments
          getline(GetFile2, word2);
        }
        word2 = word2.substr(0, word2.find(',')); // format to just word
        

        remainingLetters2 = isValid(word2, remainingLetters + word.at(word.length() - 1)); // check valid
        
        if (remainingLetters2 != "!" && word2.find(word.at(word.length() - 1)) != -1) { // if word2 valid and word2 contains final letter of word
          PutFile << "." << remainingLetters2.length() << " " << word << " " << word2 << endl;// the . with number of remaining letters is so it is easy to CTRL + F through the giant files this code generates. I may change the code to sort by remaining letters in the future.

        }
      }

      GetFile2.close();
      GetFile2.open(ReadFileLocation);
      // GetFile2.seekg(0); // Not sure why I cent just do this

    }
  }

  GetFile.close();
  GetFile2.close();
  PutFile.close();
  cout << "we up" << endl;

}
