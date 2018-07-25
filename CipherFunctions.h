#pragma once
#ifndef CIPHERFUNCTIONS_H
#define CIPHERFUNCTIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
using namespace std;

class CipherFunctions {

public:
	// to generate the key
	string KeyGenerator(string OriginalText, string keyword);

	// to get the text from the file input
	string GetMessage();

	// to encrypt the text
	string EncryptText(string OriginalText, string PassedKeyValue);

	// to decrypt the text
	string DecryptText(string EncryptedText, string PassedKeyValue);

private:
	string space = " !.,-_=+\"'*[]{}|()&^%@~`:;$—#0123456789";	// this is used to omit the non-alpha characters
	string EncryptedText; // to store the encrypted text
	string DecryptedText; // to store the decrypted text
};

#endif