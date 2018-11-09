#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define MAX_RLEN 50
//#include "gtest/gtest.h"

using namespace std;

class ASCII {
   public:
     string raw;
     int length;
     ASCII( const char *filename );  // This is the constructor
     string makeCompress();
     string deCompress();
};

// Member functions definitions including constructor
ASCII::ASCII( const char *filename ) {
  ifstream myReadFile;
  myReadFile.open(filename);
  char ch;
  if (myReadFile.is_open()) {
    while (myReadFile >> ch)
    //std::cout << ch << '\n';
    raw += ch;
  }
  myReadFile.close();
  //cout<<raw;
  length = raw.length();
  //cout << "lenght: " << length << endl;
}

string ASCII::makeCompress() {
    char c = ' ';
    int num = 0;
    string result;
    string::const_iterator it = raw.begin();
    for(; it != raw.end(); ++it)
    {
        if(*it!=c)
        {
            if(num!=0)
            {
                stringstream ss;
                ss << num;
                string num_s(ss.str());
                result += num_s;
            }

            c = *it;
            result.push_back(c);

            num = 1;
        }
        else
        {
            num++;
        }
    }

    stringstream ss;
    ss << num;
    string num_s(ss.str());
    result += num_s;

    return result;
}
