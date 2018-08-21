#include "cesar.h"

int main()
{
    string text="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int s = 3;
    cout << "Text : " << text;
    cout << "\nShift: " << s;
    cout << "\nCipher: " << encrypt(text, s) << endl;

    return 0;
}
