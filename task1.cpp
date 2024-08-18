//This CGPA CALCULATOR program:
//Calculates the student's overall course grade.
//Computes the CGPA from the exam results.
//Displays individual grades of each course.
//Calculates total credits and total grade points achieved.
//Determines the GPA for the semester.

#include <iostream>
using namespace std;

class CGPA{
protected:
int numcourses;//num of courses
int credits[10];//takes in credit hours
float grades[10];//takes in grade points
int totalcredits=0;//displays total credits earned
float totalgrade=0.0;//displays total grade points earned
float cgpa=0;//displays GPA
float calcgpa=0.0;

public:
void input(){
    cout<<"Enter the number of courses you took this semester: ";
    cin>>numcourses;

    for(int i=1;i<numcourses+1;i++){
    cout<<"Enter the credit hour(s) for course "<<i<<": ";
    cin>>credits[i];

    cout<<"Enter the grade points for the course "<<i<<": ";
    cin>>grades[i];

    totalcredits+=credits[i];
    totalgrade+=grades[i];

    calcgpa+=grades[i]*credits[i];
    }
}

void displaycgpa(){
cout<<"TOTAL CREDIT HOURS: "<<totalcredits<<endl;
cout<<"TOTAL GRADE POINTS: "<<totalgrade<<endl;

cgpa=calcgpa/totalcredits;
cout<<"CGPA: "<<cgpa<<endl;
}
};


int main(){
    CGPA cgpa;
    char choice;
    cout<<"WELCOME TO THE CGPA CALCULATOR"<<endl;
    cgpa.input();
    cgpa.displaycgpa();
    

do{
    cout<<"Do you want to calculate GPA for another semester?(Y/N): ";
    cin>>choice;

if (choice=='Y' || choice=='y'){
cgpa.input();
cgpa.displaycgpa();
}

else{
    cout<<"EXITING CGPA CALCULATOR..."<<endl;
}
}while (choice=='Y' || choice=='y');

return 0;
}
