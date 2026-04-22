
// map words to a set of "Blocks" to create decorations with the highest number of word combinations

#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;

string lowerString (string s) {
  string news = "";
  for (int i = 0; i < s.length(); i++) {
    news += tolower(s[i]);
  }
  return news;
}

// string fileLocation = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/WordGames/TextFiles/ChristmasWords.txt";
string fileLocation = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/WordGames/TextFiles/JustWords.txt";
string AllWords = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/WordGames/TextFiles/unigram_freq.txt";
string PutFileLocation = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/WordGames/TextFiles/WordMaxxingBlocks_Output.txt";
string WordsWeCantSpell = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/WordGames/TextFiles/WordMaxxingBlocks_WordsWeCantSpell.txt";


int main() {
  

  vector<vector<char>> Blocks;
  uint8_t MaxLettersPerBlock = 5;
  vector<bool> UsedBlocks;
  string balls = "";
  
  ifstream GetFile;
  GetFile.open(fileLocation);
  while (!GetFile.is_open()) { // wait until open file
    cout << "File unable to open" << endl;
    _sleep(5000);
    GetFile.open(fileLocation);
  }
  
  while (getline(GetFile, balls)) { // whole file
    if (balls.substr(0, 2) == "//") { // if a comment
      continue;
    }
    balls = lowerString(balls);
  
    for (int i = 0; i < balls.length(); i++) {

      char currentChar = balls[i];
      bool charFound = false;

      for (int j  = 0; j < Blocks.size(); j++) { // for each block
        for (int k = 0; k < Blocks[j].size(); k++) { // for each letter on the block
          if (Blocks[j][k] == currentChar && UsedBlocks[j] == false) {
            charFound = true;
            UsedBlocks[j] = true;
            break;
          }
        }
        if (charFound) { break; };
      }
      
      if (!charFound) {
        for (int j = 0; j < Blocks.size(); j++) { // find empty block
          if (Blocks[j].size() < MaxLettersPerBlock && UsedBlocks[j] == false) {
            Blocks[j].push_back(currentChar);
            UsedBlocks[j] = true;
            charFound = true;
            break;
          }
        }
      }
      
      if (!charFound) {
        vector<char> temp; // place new block in vector
        temp.push_back(currentChar);
        Blocks.push_back(temp);
        UsedBlocks.push_back
        (true);
      } 
    }

    for (int i = 0; i < UsedBlocks.size(); i++) {
      UsedBlocks[i] = false;
    }
    

  }

  GetFile.close();
  
  for (const auto& bigNode : Blocks) { // print blocks
    for (const auto& littleNode : bigNode) {
      cout << littleNode << " ";
    }
    cout << endl;
  }



  cout << "Blocks Needed: " << Blocks.size() << endl; // Found required blocks, print them to console



  // Now find all word that the blocks can spell


  ifstream AllWordStream;
  AllWordStream.open(AllWords);
  while (!AllWordStream.is_open()) { // wait until open file
    cout << "File unable to open" << endl;
    _sleep(5000);
    AllWordStream.open(AllWords);
  }

  ofstream PutFile; // file to put to
  PutFile.open(PutFileLocation); // creates file I dont think I need to wait for that
  while (!PutFile.is_open()) { // wait until open file
    cout << "Put File unable to open" << endl;
    _sleep(5000);
    GetFile.open(PutFileLocation); 
  }

  ofstream NotAble; // file to put to
  NotAble.open(WordsWeCantSpell); // creates file I dont think I need to wait for that
  while (!NotAble.is_open()) { // wait until open file
    cout << "Put File unable to open" << endl;
    _sleep(5000);
    NotAble.open(WordsWeCantSpell); 
  }

  bool NoBlock = false;
  int WordCount = 0;
  while (getline(AllWordStream, balls)) {
    NoBlock = false;
    if (balls.substr(0, 2) == "//") { // if a comment
      continue;
    }
    balls = lowerString(balls.substr(0, balls.find(','))); // lowercase + pre freq

    for (int i = 0; i < balls.length(); i++) { // for letters in balls
      for (int j = 0; j < Blocks.size(); j++) { // for blocks in Blocks
        if (!UsedBlocks[j] && (count(Blocks[j].begin(), Blocks[j].end(), balls[i]) > 0)) { // letter here
          UsedBlocks[j] = true;
          break;
        }
        if (j == (Blocks.size() - 1)) {
          NoBlock = true;
        }
        
      }
      if (NoBlock) {
        break;
      }

    }

    if (!NoBlock) {
      PutFile << balls << endl;
      WordCount++;
    } else {
      NotAble << balls << endl;
    }
    for (int i = 0; i < UsedBlocks.size(); i++) {
      UsedBlocks[i] = false;
    }
  }

  cout << "Words Found: " << WordCount << endl;
}

