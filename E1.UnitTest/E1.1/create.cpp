#include "asciiart.h"

using namespace std;

int main() {
  ASCII primero("movies.txt");

  cout << primero.makeCompress() << endl;
  //cout << primero.length << endl;

  return 0;
}
