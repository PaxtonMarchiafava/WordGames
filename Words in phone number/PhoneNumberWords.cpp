// finds the words that fit within your phone number. too bad people are forgetting that there are letters asociated with numbers.
// for example: the phone number:
// 5556663297
// 555MONDAYS
// or
// 3278426863
// EARTHBOUND
// also should work on different length phone numbers like numbers from france

#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

string Number = "2262689249";
string pisser = "";
int position = 0;

string ReadFileLocation = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/WordGames/Text Files/unigram_freq.txt";
string PutFileLocation = "C:/Users/paxto/OneDrive/Desktop/LocalProjects/WordGames/Text Files/" + Number + "_Valid_Mnemonic.txt";

 // returns index of occurance of word in num
int inside (string num, string word) {

  if (word.length() > num.length()) {
    return -1;
  }
  
  string wordNum = "";
  for (int i = 0; i < word.length(); i++) { // build 
    switch (word.at(i)) {
    case 'a':
      wordNum += '2';
      break;
    case 'b':
      wordNum += '2';
      break;
    case 'c':
      wordNum += '2';
      break;

    case 'd':
      wordNum += '3';
      break;
    case 'e':
      wordNum += '3';
      break;
    case 'f':
      wordNum += '3';
      break;

    case 'g':
      wordNum += '4';
      break;
    case 'h':
      wordNum += '4';
      break;
    case 'i':
      wordNum += '4';
      break;

    case 'j':
      wordNum += '5';
      break;
    case 'k':
      wordNum += '5';
      break;
    case 'l':
      wordNum += '5';
      break;

    case 'm':
      wordNum += '6';
      break;
    case 'n':
      wordNum += '6';
      break;
    case 'o':
      wordNum += '6';
      break;

    case 'p':
      wordNum += '7';
      break;
    case 'q':
      wordNum += '7';
      break;
    case 'r':
      wordNum += '7';
      break;
    case 's':
      wordNum += '7';
      break;

    case 't':
      wordNum += '8';
      break;
    case 'u':
      wordNum += '8';
      break;
    case 'v':
      wordNum += '8';
      break;

    case 'w':
      wordNum += '9';
      break;
    case 'x':
      wordNum += '9';
      break;
    case 'y':
      wordNum += '9';
      break;
    case 'z':
      wordNum += '9';
      break;
    
    default:
      cout << word.at(i) << " is not a letter";
      break;
    }
  }

  for (int i = 0; i <= num.length() - wordNum.length(); i++) { // inefficient way of doing things
    // cout << wordNum << " " << num.substr(i, wordNum.length()) << endl;
    if (wordNum == num.substr(i, wordNum.length())) {
      return i;
    }
  }
  return -1;
  
}

int main () {
 
  ifstream GetFile; // file to read from
  GetFile.open(ReadFileLocation);
  while (!GetFile.is_open()) { // wait until open file
    cout << "Get File unable to open" << endl;
    _sleep(5000);
    GetFile.open(ReadFileLocation); 
  }


  ofstream PutFile; // file to put to
  PutFile.open(PutFileLocation); // creates file
  while (!PutFile.is_open()) { // wait until open file
    cout << "Put File unable to open" << endl;
    _sleep(5000);
    GetFile.open(PutFileLocation); 
  }

  cout << "files open. generating list" << endl;

  while (getline(GetFile, pisser)) { // whole file

    while (pisser.at(0) == '/'){ // skip comments
      getline(GetFile, pisser);   
    }
    pisser = pisser.substr(0, pisser.find(','));

    position = inside(Number, pisser);
    if (position > -1) {
      cout << Number.substr(0,position) << pisser << Number.substr(position + pisser.length()) << endl;
      PutFile << "." << Number.substr(position + pisser.length()).length() << " " << pisser.length() << " ";
      PutFile << Number.substr(0,position) << pisser << Number.substr(position + pisser.length()) << endl;
    }
  }

  GetFile.close();
  PutFile.close();

}
