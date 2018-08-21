#include <iostream>
#include <string>

using namespace std;

#define LENGTH 300

int read_file(char texto[LENGTH])
{
	FILE *file;
	if ((file = fopen("encriptado.txt","r")) == NULL) {
		return 1;
  }
  fscanf(file, "%s", texto);
  cout << texto << endl;
  fclose(file);
  return 0;
}

int main(int argc, char const *argv[]) {
  char texto[LENGTH], ch;
  int key = 3;

  read_file(texto);

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
