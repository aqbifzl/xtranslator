#include "XTranslator/xtranslator.h"
#include "lingva-api/include/lingva.hpp"

using std::string, std::cout, std::cerr, std::exception;

void showHelp() {
  cout << "Usage: xtranslator [text_source] [source] [target]\n\n"
       << "Parameters:\n"
       << "  text_source  - The name of the selection from the X server "
          "(like PRIMARY or CLIPBOARD)\n"
       << "  source       - The source language code\n"
       << "  target       - The target language code\n";
  exit(1); x
}

int main(int argc, char **argv) {
  if (argc != 4)
    showHelp();

  string textSource = argv[1];
  string tSource = argv[2];
  string tTarget = argv[3];

  XTranslator client(textSource);
  lingvaClient translator(tSource, tTarget);

  try {
    string result = client.getSelectionData();
    cout << translator.translate(result);
    return 0;
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
  }
}