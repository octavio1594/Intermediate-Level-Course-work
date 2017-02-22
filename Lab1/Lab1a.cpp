#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void ProcessARow(int, int, int, int&, int&, double&);

int main()
{
        int score1, score2, score3;
        int student;
        int line = 0;
	int M;
	int Mi;
	double A;

        ifstream fin;
        fin.open("scores.txt");

        if(!fin)
          cout << "The input file does not exist" << endl;
        else
        {
                fin >> student >> score1 >> score2 >> score3;

                cout << "Std-Id   A1   A2   A3   Min   Max   Average" << endl;
                cout << "-------------------------------------------" << endl;

                while(fin)
                {
                        line++;
	
			ProcessARow(score1, score2, score3, M, Mi, A);
                      
			cout << student << setw(5) << score1 << setw(5) << score2 << setw(5) << score3 << setw(5) << M << setw(6) << Mi << setw(7) << fixed << setprecision (1) << A << endl;
 
                        fin >> student >> score1 >> score2 >> score3;
                }

        fin.close();

        }

        return 0;
}
	
  	
	void ProcessARow(int s1, int s2, int s3, int& Max, int& Min, double& Avrg)
	{

                	
			if (s1 > s2)
                	Max = s1;

                	else
                	Max = s2;

                	if (s3 > Max)
                	Max = s3;
        	

                	
			if (s1 < s2)
                	Min = s1;
		 	else
                	Min = s2;

                	if (s3 < Min)
                	Min = s3;
			

        		
                	Avrg = (s1 + s2 + s3)/3;
			
        		return;
	}
