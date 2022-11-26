#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Page {
 public:
  std::string name;
  size_t num;
  int type;  // NORMAL = 0, WIN = 1, LOSE = 2
  bool ref;
  std::vector<std::string> navigation;
  std::vector<size_t> nextPage;
  std::vector<std::string> contents;

  // constructor
  Page() :
      num(0),
      type(0),
      ref(false),
      navigation(std::vector<std::string>()),
      nextPage(std::vector<size_t>()),
      contents(std::vector<std::string>()) {}

  void readPageContent(std::string directoryName) {
    std::string path = directoryName + "/" + name;
    std::ifstream inputFile;
    inputFile.open(path.c_str());
    if (inputFile.fail()) {
      std::cerr << "Can't open file: " << name << std::endl;
      exit(EXIT_FAILURE);
    }
    std::string line;
    while (!inputFile.eof()) {
      std::getline(inputFile, line);
      contents.push_back(line);
    }
  }

  void printPage() {
    std::vector<std::string>::const_iterator it = contents.begin();
    while (it != contents.end()) {
      std::cout << *it << std::endl;
      it++;
    }
    if (type == 0) {
      std::cout << "What would you like to do?" << std::endl;
      std::cout << std::endl;
      for (int i = 0; i < (int)navigation.size(); i++) {
        std::cout << " " << i + 1 << ". " << navigation[i] << std::endl;
      }
    }
    else if (type == 1) {
      std::cout << "Congratulations! You have won. Hooray!" << std::endl;
    }
    else {
      std::cout << "Sorry, you have lost. Better luck next time!" << std::endl;
    }
  }
};
