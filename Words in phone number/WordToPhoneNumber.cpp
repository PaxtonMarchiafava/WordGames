// converts a word to what the asociated phone number would be. will intake any length of string

#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

string word = "";

void makeASCIIchart () {
  for (int i = 0; i <= 127; i++) {
    cout << i << " " << char(i) << endl;
  }
}

// makes string lowecase
void getLow (string* lower) {
  for (int i = 0; i < (*lower).length(); i++) {
    if ((*lower).at(i) <= 'Z') {
      (*lower).at(i) += 32;
    }
  }
}

string wordToNumber (string wrd) {

  string wordNum = "";
  for (int i = 0; i < wrd.length(); i++) { // build 
    switch (wrd.at(i)) {
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
      cout << word.at(i) << " is not a letter" << endl;
      break;
    }
  }

  return wordNum;

}

int main () {
  // makeASCIIchart();
  cout << "Enter a word to get the asociated phone number" << endl;
  cin >> word;
  getLow(&word);
  cout << endl << wordToNumber(word);
}