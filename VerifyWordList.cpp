// verifies the structure of the word list file

#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

string balls; // temporary storage for line of file
int piss = 0; // temporary counter value

string fileLocation = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/Scrabble solver/unigram_freq.txt";

int main() {
  // ofstream MyFile("C:/Users/paxto/OneDrive/Desktop/LocalProjects/cpp svg/filename.txt"); 
  
  ifstream GetFile; 
  GetFile.open(fileLocation);
  while (!GetFile.is_open()) { // wait until open file
    cout << "File unable to open" << endl;
    _sleep(5000);
    GetFile.open(fileLocation); 
  }




  
  
  while (getline(GetFile, balls)) { // whole file
  
    if (balls.substr(0, 2) != "//") { // if not a comment
      if (balls.find(',') == -1) { // if missing comma
        cout << "missing comma: " << balls << endl;
      } else {


        for (int i = 0; i < balls.length(); i++) { // count number of commas per line
          piss += (balls.at(i) == ',') ? 1 : 0; 
        }
        if (piss > 1) {
          cout << "multiple commas in a line: " << balls << endl;
        }
        piss = 0;
        
      }
      
      // cout << balls.substr(0, balls.) << endl;

    } else { // if comment
      cout << "Comment in file: " << balls << endl;
    }
    
  }

  GetFile.close();

  cout << endl << "End of reading";
}
