#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include "CipherFunctions.h"
using namespace std;

string CipherFunctions::KeyGenerator(string OriginalText, string keyword)
{
	/*
									How this function works:
		The function is taking the key and making sure that it is the same size as the text.
		Moreover, it is assigning a character value from the key to each character in the string "OriginalText".
	*/

	for (int i = 0; i < OriginalText.size(); i++) {
		keyword.push_back((toupper(keyword[i])));
	}

	return keyword;
}
string CipherFunctions::GetMessage()
{
	/*
		The code below is used to read in a text file and to make it uppercase.
		The file must be in the same folder as the project files
	*/

	string TextFile; // this will store the lines of text from the input file
	string UpperCaseTextFile; // this will be used to store and convert the text to uppercase

	fstream InputFile;
	InputFile.open("example.txt");

	if (!InputFile.eof())
	{
		getline(InputFile, TextFile);
	}

	// the for-loop is for converting the text to uppercase
	for (int i = 0; i < TextFile.size(); i++)
	{
		UpperCaseTextFile.push_back(toupper(TextFile[i]));
	}

	return UpperCaseTextFile;
}
string CipherFunctions::EncryptText(string OriginalText, string PassedKeyValue)
{
	/*	
									How this function works:
		The outer for-loop will go through each character in the string "OriginalText".
	
		The inner for-loop and the if-statement will make sure to not encrypt non-alpha characters
	
		The inner for-loop will compare the current character from the string "OriginalText" with the string "space".
		This will make sure to omit non-alpha characters and only encrypt the alpha characters.
	
		The other if-statements is for encrypting and converting to ASCII.
	*/

	int x = 0;

	for (int i = 0; i < OriginalText.size(); i++)
	{
		for (int j = 0; j < space.size(); j++)
		{
			if (OriginalText[i] == space[j])
			{
				EncryptedText.push_back(space[j]);
				break;
			}
		}

		if (isupper(OriginalText[i]))
		{
			x = ((((OriginalText[i] - 65) + (PassedKeyValue[i] - 65)) % 26) + 65);
			EncryptedText.push_back(x);
		}
	}

	return EncryptedText;
}
string CipherFunctions::DecryptText(string EncryptedText, string PassedKeyValue)
{
	/*
									How this function works:
		The outer for-loop will go through each character in the string "EncryptedText"
		and decrypt as necessary.
	
		The inner for-loop and the if-statement will compare the current character from the string "EncryptedText" with the string "space". 
		This will make sure to "push_back" the non-alpha characters into the "DecryptedText".
	
		The other if-statement is for decrypting and converting to ASCII.
	*/

	int x = 0;

	for (int i = 0; i < EncryptedText.size(); i++)
	{
		for (int j = 0; j < space.size(); j++)
		{
			if (EncryptedText[i] == space[j])
			{
				DecryptedText.push_back(space[j]);
				break;
			}
		}

		if (isupper(EncryptedText[i]))
		{
			x = ((((EncryptedText[i] + 'A') - (PassedKeyValue[i] - 'A')) % 26) + 'A');
			DecryptedText.push_back(x);
		}
	}

	return DecryptedText;
}