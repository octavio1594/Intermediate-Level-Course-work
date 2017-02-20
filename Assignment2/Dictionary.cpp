#include "Dictionary.h"

bool Dictionary::failure = false; 
bool Dictionary::success = true; 

// This routine sets the following values to the following attributes

Dictionary::Dictionary():maxWordsInDict(10000),maxWordsPerFile(100),alphabetLetters(26)
{
	totalWordsInDict = 0;
  
	for(int i = 0; i < alphabetLetters; i++)
	{
      		numOfWordsInFile[i] = 0;	// Sets all the files in the dictionary (A-Z)to 0 words. 
    	}
}

//---------------------------------------------------------------------------------------------------------------------

// This routine sets the following values to the following attributes

Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords), 
											 alphabetLetters(26)
{  
  	totalWordsInDict = 0;

  	for(int i = 0; i < alphabetLetters; i++)
    	{
      		numOfWordsInFile[i] = 0;	 // Sets all the files in the dictionary (A-Z)to 0 words.
    	}
}

//---------------------------------------------------------------------------------------------------------------------

// This routine tries to add the word that is passed to the function to the dictionary.

bool Dictionary::AddAWord(string word)
{
	string wrd;
	
  	if(totalWordsInDict >= maxWordsInDict)
  		{
			cout << "Dictionary is full" << endl;
			return failure;
		}
  
  	char ch = word[0];	// Character ch = the first character of the word passed to the function.
  	ch = toupper(ch);	
  	int index = ch - 'A';	// the Index belongs to a particular file (A is 0, B is 1, C is 2,.....Z is 25).
 
  	if(numOfWordsInFile[index]>= maxWordsPerFile)
   		{
			cout << "File is full." <<endl;
			return failure;
		}

  	wrd = LowerWord(word);

	bool found = SearchForWord(wrd);
  
	if(found == failure)
    	{
      		AddWordToFile(wrd);
      			return success;
    	}
	
}

//---------------------------------------------------------------------------------------------------------------------

// This routine opens the appropriate file, (If the first letter of the word is A, it should be in A.txt, or if the 
// first letter of the word starts with B it should be in B.txt, and so on) and tries to add the word that is passed 
// to this function into that file. 

bool Dictionary::AddWordToFile(string word)
{
  	char ch = word[0];	 // Character ch = the first character of the word passed to the function.
  	ch = toupper(ch);
  	string fileName = "?.txt";	
	fileName[0] = ch;	// The first character of the file name gets replaced with ch.
	int index = ch - 'A';	   // the Index belongs to a particular file (A is 0, B is 1, C is 2,.....Z is 25).
	ofstream fout;

  	fout.open(fileName.data(), ios::app);
  	
		if(!fout)
    		{
			cout << "Could not open file to add a word" << endl;
			return failure;
		}

   	fout << word << endl;                     
  
	numOfWordsInFile[index]++;
 	totalWordsInDict++;
  
	return success;
	
	fout.close();
}

//---------------------------------------------------------------------------------------------------------------------

// This routine opens the appropriate file where the word that you are looking for might be kept. (If the first letter
// of the word is A, it should be in A.txt, or if the first letter of the word starts with B it should be in B.txt, and
// so on. Then it places all the words into a vector.

bool Dictionary::DeleteAWord(string word)
{
	char ch = word[0];	// Character ch = the first character of the word passed to the function.
  	ch = toupper(ch);
  	string fileName = "?.txt";
	string wrd;
     	fileName[0] = ch;	// The first character of the file name gets replaced with ch.
  	int index = ch - 'A';	   // the Index belongs to a particular file (A is 0, B is 1, C is 2,.....Z is 25).
  	vector<string> V;
	ifstream fin;
  
  	fin.open(fileName.data());
   
  	if(!fin) 
    		{
			cout << "Could not open the file '" << fileName << "' to delete a word from the dictionary. "
			<< endl;
			return failure;   
		}

	bool found = SearchForWord(word);
  	
	if(found == success)
    	{
    		while (fin >> wrd)
		{
			 V.push_back(wrd);
		}
		
		DeleteWordInFile(V, word, fileName);
		
		totalWordsInDict--;
        	numOfWordsInFile[index]--;
	
		return success;
	}
      
      	if(found == failure)
		{
			cout << endl << "The word to be deleted '" << word << "' is not in the dictionary."<< endl;
			return failure;
		}
	fin.close();
}

//---------------------------------------------------------------------------------------------------------------------

// This routine looks for the word in the vector. If the word is in the vector, it should be deleted and then the
// modified vector should be inserted back into the appropriate file.

void Dictionary::DeleteWordInFile(vector<string> V, string word, string fileName)
{
	ofstream fout;
	fout.open(fileName.data());

	for (int i = 0; i < V.size(); i++)
	{
		if (V[i] == word)	
			V.erase(V.begin() + i);
	}

	for (int i = 0; i < V.size(); i++)
        {
               fout << (V[i]) << endl;
        }
	
	fout.close();
}

//---------------------------------------------------------------------------------------------------------------------

// This routine opens the appropriate file to search for the word that you are looking for. (If the first letter of the
// word is A, it should be in A.txt, or if the first letter of the word starts with B it should be in B.txt, and so on.
// If the word cannot be found in the appropriate file.

bool Dictionary::SearchForWord(string word)
{
 	char ch = word[0];	// Character ch = the first character of the word passed to the function.
  	ch = toupper(ch);
  	string fileName = "?.txt";	// The first character of the file name gets replaced with ch.
  	string wrd;
	fileName[0] = ch;
  	ifstream fin;
  
  	fin.open(fileName.data());
	
  	while(fin >> wrd)
    	{
      		if(wrd == word)
			return success;
			
	}
	
		if (wrd != word)
                        return failure;
                        

	
	fin.close();
}

//---------------------------------------------------------------------------------------------------------------------

// This routine opens the file fileName, read the words one by one and print them on the screen.

bool Dictionary::PrintAFileInDict(string fileName)
{   
  	string word;
  	ifstream fin;
  	vector<string> V;

  	fin.open(fileName.data());
  	
	if(!fin)
    		{
			cout << "Could not open file '" << fileName << "' to print." << endl;
			return failure;
		}

  	cout << endl << "The words in the '" << fileName << "' file are:" << endl;

	int count = 0;	

	while(fin >> word)
    	{
		cout << word << ", ";
		count++;
	
		if (count % 5 == 0)
			cout << endl;
	}
	
	cout << endl;
	
 	return success;

	fin.close();
}

//---------------------------------------------------------------------------------------------------------------------

// This routine opens the file fileName, read the words one by one and does the spell checking of the words. Every word
// is searched and those that are not in the dictionary are reported on the screen.

bool Dictionary::SpellChecking(string fileName)
{
  	ifstream fin;
  	string word;
	string wrd;
	
	fin.open(fileName.data());
  
	if(!fin)
    		{
			cout << "Could not open file to perform spell check." << endl;
			return failure;
		}

  	else
		{
			cout << endl;

			while( fin >> word)
			{
				wrd = LowerWord(word);
				
				bool found = SearchForWord(wrd);
			
				if(found == failure)
					cout << "The word '" << word << "' in the file '" << fileName 
					<< "' is misspelled." << endl;
			}
	
			return success;
		}

	fin.close();
}
    
//---------------------------------------------------------------------------------------------------------------------

// This routine opens the file fileName, read the words one by one and try to insert them into the dictionary. 

bool Dictionary::InsertWordsIntoDict(string fileName)
{
	ifstream fin;
	fin.open(fileName.data());
	string word;

	if (!fin)
		{
			cout << "Could not open file to insert words into dictionary.";
			return failure;
		}

	while (fin >> word)
	{
		AddAWord(word);
	}
		
		return success;
	

	fin.close();
}

//---------------------------------------------------------------------------------------------------------------------

// In this routine, you need to ask the user to enter a transaction file. A transaction file has two information per
// line. The first information is a command telling the programmer what to do. The second information is the data
// associated with the command. 

void Dictionary::ProcessTransactionFile()
{
	string fileName;
	
	cout << "Please enter the name of the transaction file: " << endl;
	cin >> fileName;
	
	ifstream fin;
	string word;
	string comand;

	fin.open(fileName.data());
	
	if (!fin)
		cout << "Could not open file, file might not exist." << endl;
	
	
			while (fin >> comand)
			{	
				if (comand == "InsertF")
                                {
                                        fin >> word;
                                        InsertWordsIntoDict(word);
                                }

				if (comand == "AddW")
                                {
                                	fin >> word;
                                	AddAWord(word);
                                }

                                if (comand == "SpellCheck")
                                {
                                        fin >> word;
                                        SpellChecking(word);
                                }

				if (comand == "DeleteW")
                                {
                                        fin >> word;
                                        DeleteAWord(word);
                                }

				if (comand == "SearchW")
                                {
                                        fin >> word;;
                                        SearchForWord(word);
                                }
				
				if (comand == "PrintF")
                                {
                                        fin >> word;
                                        PrintAFileInDict(word);
                                }

			}

	fin.close();
}

//---------------------------------------------------------------------------------------------------------------------

// This routine lower cases the word passed to the function character by character. It returns the word in lower case
// characters.

string Dictionary::LowerWord(string word)
{
	string wrd = word;
	
	for (int i = 0; i < word.size(); i++)
        {
        	wrd[i] = tolower(word[i]);
        }
	
	return wrd;
}
