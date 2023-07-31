#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        // Student(string str1, string str2, int identi, vector<int> &scores){
        Student(string str1, string str2, int identi,vector<int> &scores) : Person(str1, str2, identi){
        // This last line was an epic discovery for me!!
        // Subclass in C++ https://www.codesdope.com/cpp-subclass/
            testScores=scores;
            // testScores.assign(scores.begin(), scores.end());
        }

        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate(){
            int x=0;
            for (int i=0; i<testScores.size(); i++){           
                x+=testScores[i];
            }
            x=x/testScores.size();
            if (x>=90 && x<=100)
                return 'O';
            else if (x>=80 && x<90)
                return 'E';
            else if (x>=70 && x<80)
                return 'A';
            else if (x>=55 && x<70)
                return 'P';
            else if (x>=40 && x<55)
                return 'D';
            else //if (x<40)
                return 'T';
// Another way of doing the if-else :
            // return ( total > 89 ? 'O' : 
            //     total > 79 ? 'E' : 
            //     total > 69 ? 'A' : 
            //     total > 54 ? 'P' :
            //     total > 39 ? 'D' : 'T' );
        }
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}