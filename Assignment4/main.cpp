/********************************************************************************/
/* PURPOSE: This program creates a small linked list using multiple classes     */
/* IMPLEMENTED BY: Octvaio Cea                                                  */
/* DATE: December 9, 2015                                                       */
/* USER INFORMATION: The user only runs the program.                            */
/* IMPLEMENTATION METHOD: This program uses multiple clases to create a small   */
/* liked list of families, it then uses functions located in the FamilyLL class */
/* to add husbands, wifes, and children to the linked list, it also uses 	*/
/* functions to remove children from the families, to remove wifes from the	*/ 
/* families and to remove husbands from the families. It uses the 		*/
/* processATransactionFile function to read a file and execute the comands in   */
/* the file. It finally uses the remaining functions (printAFamily), 		*/
/* (PrintAllFamilies) to list certain families in the linked list or to list 	*/
/* all the families in the linked list.                                         */
/********************************************************************************/

#include "familyLL.h"

int main()
{
	familyLL	USAFamilies;
	USAFamilies.ReadTransactionFile( );
	return 0;
} 
