#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include "CipherFunctions.h"
using namespace std;

int main() {

	string GetTextFile; // used for input file
	string keyword = "key"; // this is the key to use to encrypt


	// created an object of class "CipherFunction" in order to use its functions
	CipherFunctions cipherObject;

	// calling the function to get the textfile
	GetTextFile = cipherObject.GetMessage();

	// generating the key
	string PassedKeyValue = cipherObject.KeyGenerator(GetTextFile, keyword);

	// calling the function to encrypt
	string TheENCRYPTEDtext = cipherObject.EncryptText(GetTextFile, PassedKeyValue);
	cout << "Encrypted Text:\n" << TheENCRYPTEDtext << endl << endl;

	// calling the function to decrypt
	string DecryptText = cipherObject.DecryptText(TheENCRYPTEDtext, PassedKeyValue);
	cout << "Decrypted Text:\n" << DecryptText << endl << endl;

	system("pause");
	return 0;
}