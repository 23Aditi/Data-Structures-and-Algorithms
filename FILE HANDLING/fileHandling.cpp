/*Department maintains student’s database.  The file contains roll number, name, division and address. Write a program to create a sequential file to store and maintain student data. 
It should allow the user to
a)	Create a student database
b)	Add a information of student
c)	Delete information of student
d)	Search and Display information of particular student. 
	i.	If record of student does not exist an appropriate message is displayed.
	ii.	 If student record is found it should display the student details.
e)	Display Record of All students in tabular from
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Student{
	string rollNo;
	string name;
	string div;
	string address;
	/*Student(string rollNo,string name, string div,string address){
		this->rollNo = rollNo;
		this->name = name;
		this->div = div;
		this->address=address;
	}*/
};

void createStudentDatabase(){
	ofstream file("students.txt",ios::trunc);
	if(file.is_open()){
		cout << "\033[33m Student database created successfully !"<<"\033[0m"<<endl;
		file.close();
	}
	else{
		cout << "\033[31m Error : Unable to create the database." <<endl;
	}
}


void addStudent(){
	ofstream file("students.txt",ios::app);
	if(!file){
		cerr <<"\033[33m \t Error opening file for writing !" <<"\033[0m"<<endl;
		return;
	}
	Student s;
	cout << "Enter Roll No : ";
	getline(cin,s.rollNo);
	cout << "Enter Name : ";
	getline(cin,s.name);
	cout << "Enter Division : ";
	getline(cin,s.div);
	cout << "Enter Address : ";
	getline(cin,s.address);
	
	file << s.rollNo << "||" << s.name << "||" << s.div << "||" << s.address<<"\n";
	file.close();
	//cout << "\033[34m \t Student Record added successfully !! " << "\033[0m"<<endl;
}

void add(int n){
	for(int i = 0; i < n ; i++){
		addStudent();
	}
	cout << "\033[34m \t Student Records added successfully !! " << "\033[0m"<<endl;
}

void display(){
	ifstream file("students.txt",ios::in);
	if(!file){
		cerr << "\033[31m \t Error Opening the File !" << "\033[0m"<<endl;
		return;
	}
	cout << left << setw(15) << "Roll No" << setw(20) << "Name" <<
	setw(15) << "Division" << setw(30) << "Address" << endl;
	cout << string(80,'-') <<endl;
	string line;
	while(getline(file,line)){
	// Extract fields using '||' as the delimiter
	size_t pos1 = line.find("||");
	size_t pos2 = line.find("||",pos1+2);
	size_t pos3 = line.find("||",pos2+2);
	
	string rollNo = line.substr(0,pos1);
	string name = line.substr(pos1+2,pos2-pos1-2);
	string div = line.substr(pos2+2,pos3-pos2-2);
	string address = line.substr(pos3+2);

	cout << left << setw(15) << rollNo << setw(20) << name << setw(15) << div
	<< setw(30) << address << endl;
	}
	file.close();
}

void search(string key){
	ifstream file("students.txt",ios::in);
	if(!file){
		cerr<< "Error in opening file" <<endl; return;
	}
	string line;
	while(getline(file,line)){
		size_t pos1 = line.find("||");
		string rollNo = line.substr(0,pos1);
		if(line.find(key) != string :: npos){
			cout << line << endl;
			cout << "Record Found Successfully !" << endl;
			return;
		}
	}
	cout << "record not found !"<<endl;
	file.close();
}


void deletekey(string key){
	fstream file("students.txt",ios::in |ios::out);
	if(!file){
		cerr<< "Error in opening file" <<endl; return;
	}
	vector<string> lines;
	string line;
	while(getline(file,line)){
		size_t pos1 = line.find("||");
		string rollNo = line.substr(0,pos1);
		if(line.find(key) != string :: npos){
			continue;
		}else{
			lines.push_back(line);
		}
	}
	file.close();
	ofstream outfile("students.txt",ios::trunc);
	for(auto line : lines){
		outfile << line << "\n";
	}
	outfile.close();

}

int main(){
	//createStudentDatabase();
	//addStudent();
	add(4);
	display();
	search("4");
	deletekey("4");
	display();
	return 0;
}

/*		OUTPUT

F:\ADITI_2nd_YEAR\PRACTICLE END SEM 2024 2025>file
Enter Roll No : 1
Enter Name : 1
Enter Division : 1
Enter Address : 1
Enter Roll No : 2
Enter Name : 2
Enter Division : 2
Enter Address : 2
Enter Roll No : 3
Enter Name : 3
Enter Division : 3
Enter Address : 3
Enter Roll No : 4
Enter Name : 4
Enter Division : 4
Enter Address : 4
         Student Records added successfully !!
Roll No        Name                Division       Address
--------------------------------------------------------------------------------
1              1                   1              1
2              2                   2              2
3              3                   3              3
4              4                   4              4
4||4||4||4
Record Found Successfully !
Roll No        Name                Division       Address
--------------------------------------------------------------------------------
1              1                   1              1
2              2                   2              2
3              3                   3              3

F:\ADITI_2nd_YEAR\PRACTICLE END SEM 2024 2025>

*/


























