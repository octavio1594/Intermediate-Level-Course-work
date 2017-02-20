/********************************************************************************/
/* PURPOSE: This program creates a dictionary that has 26 files named A.txt,    */
/* B.txt, C.txt,....,Z.txt.                                                     */
/* IMPLEMENTED BY: Octvaio Cea                                                  */
/* DATE: October 26, 2015                                                       */
/* USER INFORMATION: The user only enters the transaction file.                 */
/* IMPLEMENTATION METHOD: The program uses the AddAword function to add a word  */
/* to the dictionary, it uses the DeleteAWord function to delete a word form the*/
/* dictionary, it uses the SearchAWord function to look fo a word in the dictio-*/
/* nary, it uses the PrintAFileInDict function to print a certain file to the   */
/* screen, it uses the SpellChecking function to to detect misspelled words in a*/
/* file, it uses the InsertWordsIntoDict function to insert words into the 	*/
/* dictionary, it uses the ProcessTransactionFile function to proccess words and*/ 
/* files, and finally it uses the lowerWord function to lowercase all words put */
/* into the dictionary.								*/
/********************************************************************************/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<fstream>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Dictionary
{
	private:
		const 	int	maxWordsInDict;
		const	int 	maxWordsPerFile;
		const	int 	alphabetLetters;
			int	totalWordsInDict;
			int	numOfWordsInFile[26];
		static	bool 	failure;
		static	bool 	success;
	
	public:
		Dictionary();
		Dictionary(int dictMaxWords, int fileMaxWords);
		bool AddAWord(string word);
		bool DeleteAWord(string word);
		bool SearchForWord(string word);
		bool PrintAFileInDict(string filename);
		bool SpellChecking(string fileName);
		bool InsertWordsIntoDict(string fileName);
		bool AddWordToFile(string word);
		void ProcessTransactionFile();		
		void DeleteWordInFile(vector<string> V, string word, string fileName);
		string LowerWord(string word);	
};

#endif
