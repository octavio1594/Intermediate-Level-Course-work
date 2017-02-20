//*******************************************************************************
// PURPOSE: This program encrypts and decrypts a file using two methods, Rot	*
// Number and Cryptogram.					                *
// IMPLEMENTED BY: Octvaio Cea                                                  *
// DATE: September 23, 2015                                                     *
// USER INFORMATION: The user enters the name of the file to be encrypted 	*
// as well as the name of the files to be created.                              *
// IMPLEMENTATION METHOD: This program reads a file and it places it into a 	*
// vector. Then the program encrypts the vector using two methods of encryption,*
// Rot Number and Cryptogram. After that the program decrypts the encrypted 	*
// vectors using the same methods of ecryption, Rot Number and Cryptogram. 	*
// Finally the program sends the two decrypted vectors to a file created by the *
// user.       			                                                *
// OVERVIEW OF SUBPARTS: The program consists of the main function, the 	*
// getOriginalData function, the doEncRot function, the EncWordUsingRot 	*
// function, the doEncCrypto function, the EncWordUsingCrypto function, the	*
// doDecrptRot function, the DecWordUsingRot function, the doDecrptCrypto    	*
// function, the DecWordUsingCrypto function, the outToFile function, and the  	*
// printVector function.  	                                               	*
//*******************************************************************************
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
vector<string> getOriginalData();				//Step (1): Get original data and place it into vector			
vector<string> doEncrptRot(vector<string>& V, int RotNo);	//Step (2): Encript vector using Rot Number
string EncWordUsingRot(string word, int RotNo);			//Step (2b): Encript word using Rot Number
vector<string> doEncrptCrypto(vector<string>& V, string key);	//Step (3): Encript vector using Criptogram
string EncWordUsingCrypto(string word, string key);		//Step (3b): Encript word using Criptogram
vector<string> doDecrptRot(vector<string>& V, int RotNo);	//Step (4): Decript encripted vector using Rot Number
string DecWordUsingRot(string word, int RotNo);			//Step (4b): Decript encripted word using Rot Number
vector<string> doDecrptCrypto(vector<string>& V, string key);	//Step (5): Decript encripted vector using Criptogram
string DecWordUsingCrypto(string word, string key);		//Steps (5b): Decript encripted word using Criptogram
void outToFile(const vector<string>& V);			//Steps (6) and (7) Place decripted vector(s) into a file
void printVector(const vector<string>& V);			//Print vector(s) to the screen

int main()
{
	int RotNo, a, b, c;
	vector<string> V, EncVR, EncVC, DecVR, DecVC;
	
	V = getOriginalData();
	printVector(V);
	
	cout << "Enter a Rot Number to encript data and to place it into a file: ";
	cin >> RotNo;
	EncVR = doEncrptRot(V, RotNo);
	outToFile(EncVR);
	
	ifstream fin;
        string key;
	fin.open("cryptogram.txt");
	fin >> key;
	cout << "Press 1 to encript data using Cryptogram and to place it into a file: ";
	cin >> a;
	EncVC = doEncrptCrypto(V, key);
	outToFile(EncVC);
	
	cout << "Press 2 to decript encripted file using Rot number and place it into a file: ";
	cin >> b;
	DecVR = doDecrptRot(EncVR, RotNo);
	outToFile(DecVR);
	
	cout << "Press 3 to decript encripted file using Cryptogram and place it into a file: ";
	cin >> c;
	DecVC = doDecrptCrypto(EncVC, key);
	outToFile(DecVC);
	
	cout << "The files were created.";
	return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------
//*********************************************************************
// Definition of function printVector                                 *
// This function symply prints a vector to the screen.                *
//*********************************************************************
void printVector(const vector<string>& V)
{
	for(int i = 0; i < V.size(); i++)
	{
		cout << V[i] <<" ";
	}
	
	cout << endl << endl;
	
	return;
}
//----------------------------------------------------------------------------------------------------------------------------------
//*********************************************************************
// Definition of function getOriginalData                             *
// This function extracts data from a file and stores it in a vector. *
// Size is the number of elements in the vector.                      *
//*********************************************************************
vector<string> getOriginalData()  					   // Step (1): Get original data and place it into vector
{
        vector<string> V;
        ifstream fin;
        string fileName, word;
        cout << "What is the name of the file?: ";
        cin >> fileName;
        fin.open(fileName.data());
        while (fin >> word)
                V.push_back(word);

        return V;
}
//----------------------------------------------------------------------------------------------------------------------------------
//*********************************************************************
// Definition of function doEncRot                                    *
// This function encripts words using the EncWordUsingRot function and*
// places them into a new vector.                                     *
// Size is the number of encripted words in the vector.               *
//*********************************************************************
vector<string> doEncrptRot(vector<string>& V, int RotNo)		    // Step (2): Encript vector using Rot Number
{
        vector<string> EncV;
	string EncrptWord;
        for (int i = 0; i < V.size(); i++)
        {
                EncrptWord = EncWordUsingRot(V[i], RotNo);
                EncV.push_back(EncrptWord);
        }

        return EncV;
}
//*********************************************************************
// Definition of function EncWordUsingRot                             *
// This function encripts each word character by character using a    *
// Rotation number.                                                   *
//*********************************************************************
string EncWordUsingRot(string word, int RotNo)				     // Step (2a): Encript word using Rot Number
{
      RotNo = RotNo % 26;        
      string encWord = word;

      for(int i = 0; i < word.size(); i++)
  	{
    		unsigned x = word[i];
    		x = tolower(x);                      
    		if((x < 'a')||(x > 'z'))
    		{
      			encWord[i] = x;
    		}
    		else
    		{
      			x += RotNo;

     			 if(x > 'z')
      			{
      				x -= 26;
     			 }
      		encWord[i] = x;

   		 }	
  	}
  
	return encWord;
}       
//----------------------------------------------------------------------------------------------------------------------------------
//*********************************************************************
// Definition of function doEncCrypto                                 *
// This function encripts words using the EncWordUsingCrypto function *
// and places them into a new vector.                                 *
// Size is the number of encripted words in the vector.               *
//*********************************************************************
vector<string> doEncrptCrypto(vector<string>& V, string key)		     // Step (3): Encript vector using Criptogram
{
        vector<string> EncV;
        string EncrptWord;
        for (int i = 0; i < V.size(); i++)
        {
                EncrptWord = EncWordUsingCrypto(V[i], key);
                EncV.push_back(EncrptWord);
        }

        return EncV;
}
//*********************************************************************
// Definition of function EncWordUsingCrypt                           *
// This function encripts each word character by character using a    *
// Cryptogram in the form of a string.                                *
//*********************************************************************
string EncWordUsingCrypto(string word, string key)			     // Step (3b): Encript word using Criptogram
{
    string encWord = word;

    for (int i = 0; i < word.size(); i++)
    {
        unsigned char x = word[i];
	x = tolower(x);
	if ((x < 'a') || (x > 'z'))
        {
            encWord[i] = x;
        }
        else
        {
            int index = key.find(x, 0);
            encWord[i] = 'a' + index;
        }
    }
    return encWord;
}
//----------------------------------------------------------------------------------------------------------------------------------
//*********************************************************************
// Definition of function doDecrptRot                                 *
// This function decripts words using the DecWordUsingRot function    *
// and places them into a new vector.                                 *
// Size is the number of encripted words in the vector.               *
//*********************************************************************
vector<string> doDecrptRot(vector<string>& V, int RotNo)		     // Step (4): Decript encripted vector using Rot Number
{
        vector<string> DecVR;
        string DecWord;
        for (int i = 0; i < V.size(); i++)
        {
                DecWord = DecWordUsingRot(V[i], RotNo);
                DecVR.push_back(DecWord);
        }

        return DecVR;
}
//*********************************************************************
// Definition of function DecWordUsingRot                             *
// This function Decripts each word character by character using a    *
// Rotation number.                                                   *
//*********************************************************************
string DecWordUsingRot(string word, int RotNo)				     // Step (4b): Decript encripted word using Rot Number
{
 	 RotNo = RotNo%26;
  	string decWord = word;
  	for(int i = 0;i < word.size(); i++)
  	{
    		unsigned char x = word[i];
    		x -= RotNo;
    		if((x < 'a')||(x > 'z'))
     		 {
        		x += 26;
     		 }
      			decWord[i] = x;
    	}
  
 		 return decWord;
}
//----------------------------------------------------------------------------------------------------------------------------------
//*********************************************************************
// Definition of function doDecrptCrypto                              *
// This function decripts words using the DecWordUsingCrypto function *
// and places them into a new vector.                                 *
// Size is the number of encripted words in the vector.               *
//*********************************************************************
vector<string> doDecrptCrypto(vector<string>& V, string key)		     // Step (5): Decript encripted vector using Criptogram
{
        vector<string> DecVC;
        string DecWord;
        for (int i = 0; i < V.size(); i++)
        {
                DecWord = DecWordUsingCrypto(V[i], key);
                DecVC.push_back(DecWord);
        }

        return DecVC;
}
//*********************************************************************
// Definition of function DecWordUsingCrypto                          *
// This function Decripts each word character by character using a    *
// Cryptogram in the form of a string.                                *
//*********************************************************************
string DecWordUsingCrypto(string word, string key)			      // Step (5b): Decript encripted word using Criptogram
{
    string decWord = word;

    for (int i = 0;i < word.size(); i++)
    {
        unsigned char x = word[i];
        x = tolower(x);
        if((x < 'a')||(x > 'z'))
        {
            decWord[i] = x;
        }
        else
        {
            int index = x - 'a';
            decWord[i] = key[index];
        }
    }
    return decWord;
}
//----------------------------------------------------------------------------------------------------------------------------------
//*********************************************************************
// Definition of function outToFilre                                  *
// This function places the decripted vector passed as the parameter  *
// into a file.                                                       *
//*********************************************************************
void outToFile(const vector<string>& V)                                   // Steps (6) and (7): Placed decripted vectors into a file
{
        string fileName;
	ofstream fout;
	cout << "Enter desired name for file: ";
	cin >> fileName;
        fout.open(fileName.data());
        for (int i = 0; i < V.size(); i++)
        {
        fout << V[i] << "\t";
        }

        fout.close();
        return;
}

