#include <iostream>
#include <string>

using namespace std;

#define LENGTH 300

int main(int argc, char const *argv[]) {
  char texto[LENGTH] = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ", ch;
  int key = 3;

  for(int i = 0; texto[i] != '\0'; ++i){
    ch = texto[i];
    if(ch >= 'a' && ch <= 'z'){
      ch = ch - key;
      if(ch < 'a'){
        ch = ch + 'z' - 'a' + 1;
      }
      texto[i] = ch;
    }
    else if(ch >= 'A' && ch <= 'Z'){
      ch = ch - key;
      if(ch > 'a'){
        ch = ch + 'Z' - 'A' + 1;
      }
      texto[i] = ch;
    }
  }
	
  cout << endl << texto << endl;
  return 0;
}
