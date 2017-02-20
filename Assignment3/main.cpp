/********************************************************************************/
/* PURPOSE: This program creates a small university using multiple classes      */                                                     
/* IMPLEMENTED BY: Octvaio Cea                                                  */
/* DATE: November 17, 2015                                                      */
/* USER INFORMATION: The user only runs the program.		                */
/* IMPLEMENTATION METHOD: This program uses multiple clases to create a small   */
/* university it then uses functions located in the university class to add     */
/* add students, faculties, departments and courses to the university, it also  */
/* uses functions to enrroll students in courses, assign faculties to courses,  */
/* courses to departments, and faculties to students. It finally uses remaining */
/* functions to list all departments, courses, students, and faculties in the   */
/* screen. 								        */                                                    
/********************************************************************************/
#include "University.h"

int main() 
{
	University csusm;
	csusm.ProcessTransactionFile("TransactionFile.txt");
}

