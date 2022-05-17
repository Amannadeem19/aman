
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<cstdlib>
using namespace std;

class interface{
	public:
		virtual void signup()  = 0;
		virtual int login(const char[], const char[]) = 0;
		
};
class person: public interface{
	
	char name[20], dateOfBirth[20], sex[10];
	int yearOfJoin;

	protected: // as we compare the id through file we need id as protected or public //
		char id[10];	
			int Class;

	public:
	
		person(){
			
			name[20]= '\0';
			id[10] = '\0';
			dateOfBirth[20] = '\0';
			sex[10] = '\0';


		}
	virtual void setData()
	{
		
		
		cout << "Enter name: ";
		cin.getline(name,20);
		cout << endl;
		cout << "Enter ID: ";
		cin.getline(id,10);
		cout << endl;
		cout << "Enter Date of Birth: ";
		cin.getline(dateOfBirth,20);
		cout << endl;
		cout << "Enter Gender: ";
		cin.getline(sex,10);
		cout << endl;
		do{
			cout << "Enter Year of join: ";
			cin >> yearOfJoin;	
		}while(yearOfJoin < 0);
		cout << endl;
		do{
			cout  << "Enter Class : ";
			cin >> Class;
		}while(Class < 0);
		cout << endl;
	}
	virtual void showData()
	{
		cout << endl;
		
		cout << "\tName: " << setw(15) << "" <<name;
		cout << endl;
		
		cout << "\tID : " <<setw(15) << "" << id;
		cout << endl;
	
		
		cout << "\tDate of Birth: "<<setw(5) << "" << dateOfBirth;
		cout << endl;

		
		cout << "\tTeacher Gender: "<<setw(5) << "" << sex;
		cout << endl;

		
		cout << "\tYear of join: " <<setw(8) << ""<< yearOfJoin;
		cout << endl;
		
		cout  << "\tClass : "<<setw(15) << "" << Class;
		cout << endl;
		
	}
	
	void c1_table()
{
		system("Cls");
		cout<<"=========== Class 1 TIMETABLE ==========="<<endl;
		cout<<"=========== PERIODS :(MON-FRI) ========== \n1st : MATHS \n2nd : MATHS \n3rd : SCIENCE \n4th : SCIENCE \n5th : ISLAMIAT \n6th : PAKISTAN STUDIES \n7th : URDU \n8th : ENGLISH "<<endl;
}
void c2_table()
{
system("cls");
		cout<<"=========== Class 2 TIMETABLE ==========="<<endl;
		cout<<"=========== PERIODS :(MON-FRI) ========== \n1st : PAKISTAN STUDIES \n2nd : MATHS \n3rd : SCIENCE \n4th : ISLAMIAT \n5th : ISLAMIAT \n6th : URDU \n7th : URDU \n8th : ENGLISH "<<endl;
	}
	void c3_table()
	{
		system("cls");
		cout<<"=========== Class 3 TIMETABLE ==========="<<endl;
		cout<<"=========== PERIODS :(MON-FRI) ========== \n1st : PAKISTAN STUDIES \n2nd : PAKISTAN STUDIES \n3rd : MATHS \n4th : SCIENCE \n5th : SCIENCE \n6th : URDU \n7th : ENGLISH \n8th : ENGLISH "<<endl;
	}
	void c4_table()
	{
		system("cls");
		cout<<"=========== Class 4 TIMETABLE ==========="<<endl;
		cout<<"=========== PERIODS :(MON-FRI) ========== \n1st : ENGLISH \n2nd : ENGLISH \n3rd : URDU \n4th : MATHS \n5th : MATHS \n6th : ISLAMIAT \n7th : PAKISTAN STUDIES \n8th : PAKISTAN STUDIES "<<endl;
	}
	void c5_table()
	{
		system("cls");
		cout<<"=========== Class 5 TIMETABLE ==========="<<endl;
		cout<<"=========== PERIODS :(MON-FRI) ========== \n1st : SCIENCE \n2nd : PAKISTAN STUDIES \n3rd : PAKISTAN STUDIES \n4th : MATHS \n5th : ISLAMIAT \n6th : URDU \n7th : URDU \n8th : ENGLISH "<<endl;
	
	}
	
};




class teacher :  public person{
	int experience_level;
	public:
	float salary;
	static double total_salary;
	
	public:
		teacher()
		{
			salary = 0.0;
//			total_salary = 0.0;
			
		}
	void setData()
	{
		person::setData();
		
		do{
		
			cout << "Enter the experience level: ";
			cin >> experience_level;
		}while(experience_level < 0);
		cout << endl;
		do{
		
			cout << "Enter the salary: ";
			cin >> salary;
		}while(salary < 0);
	}
	
	void showData()
	{
		person::showData();		
		cout << "\tExperience: " <<setw(10) << ""<< experience_level << endl;
		
		cout << "\tMonthly Salary: "<<setw(5) << "" << salary << endl << endl;
		
	}
	
	int add_teacher();
	 void displayteacher_info();
	void search_teacher(char []);
	void edit_teacher(char []);
	void delete_teacher(char []);
	

 
	
	
};

double teacher::total_salary = 0.0;


int teacher:: add_teacher(){
	
		
		ofstream fout;
		fout.open("TeachersRecord.txt", ios::app);
		fout.write((char*)this, sizeof(*this));
		fout.close();
		
	}
	
	
void teacher::displayteacher_info()
	{
		ifstream fin;
		fin.open("TeachersRecord.txt", ios::in);
		if(!fin){
			cout << "File is not exist ";
			
		}
		else
		{
			fin.read((char*)this, sizeof(*this));

			while(!fin.eof())
			{
				showData();
				fin.read((char*)this, sizeof(*this));
			}
			fin.close();
		}

	}

void teacher::search_teacher(char *Id)
	{
		int count = 0;
		ifstream fin;
		fin.open("TeachersRecord.txt", ios::in);
		if(!fin){
			cout << "File is not exist ";
			
		}
		else
		{
			fin.read((char*)this, sizeof(*this));

			while(!fin.eof())
			{
				if(!strcmp(Id, this->id)){
					cout << "\t\t\t==========Record found============" << endl << endl;
					
					cout << "\t\t*********** Information of Teacher (" << Id << ")**********" << endl << endl;
							
					showData();
					count++;
				}
				fin.read((char*)this, sizeof(*this));
			}
			if(count==0){
				cout << endl << "Record is not found";
			}
			fin.close();
		}

	}

void teacher::edit_teacher(char *Id)
{
	
	ifstream fin;
	ofstream fout;	 // as fstream pointer is on the last position so we have to mmove the pointer on the first poistion //
	
	int loc;
		
	fin.open("TeachersRecord.txt", ios::in);

	if(!fin)
	{
		cout << "file does not exist." << endl;
	}
	else
	{
		fout.open("tempfile.txt", ios::out);
	
		fin.read((char *)this, sizeof(*this));
		
		while(!fin.eof())
		{
			if(strcmp(Id,this->id)){
			
				
				fout.write((char*)this, sizeof(*this));
			}
		
			fin.read((char*)this, sizeof(*this));
			
		}
		fin.close();
		fout.close();
		
	
		
		fout.open("tempfile.txt", ios::app);
		setData();
		fout.write((char*)this, sizeof(*this));
		fout.close();
		
		remove("TeachersRecord.txt");
		rename("tempfile.txt", "TeachersRecord.txt");
	}
	
}

void teacher::delete_teacher(char *Id)
{
	int c = 0;
	ifstream fin;
	ofstream fout;
	
	fin.open("TeachersRecord.txt", ios::in);
	if(!fin){
		cout << "\nFile is not exist.";
	}
	else{
		fout.open("tempfile.txt", ios::out);
		
		fin.read((char*)this, sizeof(*this));
		while(!fin.eof())
		{
			if(strcmp(Id, this->id))
			{
				c++;
				fout.write((char*)this, sizeof(*this));
			}
			fin.read((char *)this, sizeof(*this));
		}
		fin.close();
		fout.close();
		remove("TeachersRecord.txt");
		rename("tempfile.txt","TeachersRecord.txt");
	}
}
class student : public person{
	char phoneNo[20];
	char address[30];
	char month[20];
		
	public:
		float fees;
		static double total_fees;
	public:
	student()
	{
		fees = 0;
	}
	void setData()
	{
		person::setData();
		cin.ignore();
		
		cout << "Enter Phone number: ";
		 cin.getline(phoneNo, 20);
		 cout << endl;
		 cout << "Enter Address: ";
		 cin.getline(address, 30);
		 cout << endl;
	}
	void updateFees(float f)
	{
		fees = f;
	}
	void updateMonth(const char *str)
	{
		strcpy(month,str);
	}
	void setFees()
	{
		cout << "FEES: ";
		cin >> fees ;
		cout << endl;
		cin.ignore();
	}
	void setMonth()
	{
		cout << "Enter month: ";
		cin.getline(month, 20);
		
	}
	void showData()
	{
		cout << endl;
		
		person::showData();
		cout << "\tPhone Number: " <<setw(8) << ""<< phoneNo << endl;
		
		cout << "\tAddress: "<<setw(10) << "" << address << endl;
		
	}
	void showFees()const{
		
		cout << "\tFees: "<<setw(15) << "" << fees << endl;
		
	}
	void showMonth()const{
			
			cout << "\tMonth of Fees: "<<setw(10) << "" << month << endl << endl;
	}
	
	int add_student(const char[]);
	 void displayStudents(const char[]);
	void search_student(char [], const char[]);
	void edit_student(char [], const char[]);
	void delete_student(char [], const char[]);
	


};

double student::total_fees = 0.0;


int student::add_student(const char *str)
{
	ofstream fout;
	fout.open(str, ios::app);
	fout.write((char*)this, sizeof(*this));
	fout.close();
	
}

void student::displayStudents(const char *str)
{
	
		ifstream fin;
		fin.open(str, ios::in);
		if(!fin){
			cout << "File is not exist ";
			
		}
		else
		{
			fin.read((char*)this, sizeof(*this));

			while(!fin.eof())
			{
				showData();
				showFees();
				showMonth();
				fin.read((char*)this, sizeof(*this));
			}
			fin.close();
		}
	
}

void student::search_student(char *Id, const char *str)
	{
		int count = 0;
		ifstream fin;
		fin.open(str, ios::in);
		if(!fin){
			cout << "File is not exist ";
			
		}
		else
		{
			fin.read((char*)this, sizeof(*this));

			while(!fin.eof())
			{
				if(!strcmp(Id, this->id)){
					cout << "\t\t\t==========Record found============" << endl << endl;
					
					cout << "\t\t*********** Information of Student (" << Id << ")**********" << endl << endl;
							
					showData();
					showFees();
					showMonth();
					count++;
				}
				fin.read((char*)this, sizeof(*this));
			}
			if(count==0){
				cout << endl << "Record is not found";
			}
			fin.close();
		}

	}

void student::edit_student(char *Id, const char *str)
{
	
	ifstream fin;
	ofstream fout;	 // as fstream pointer is on the last position so we have to mmove the pointer on the first poistion //
	

		
	fin.open(str, ios::in);

	if(!fin)
	{
		cout << "file does not exist." << endl;
	}
	else
	{
		fout.open("tempfile.txt", ios::out);
	
		fin.read((char *)this, sizeof(*this));
		
		while(!fin.eof())
		{
			if(strcmp(Id,this->id)){
			
				
				fout.write((char*)this, sizeof(*this));
			}
		
			fin.read((char*)this, sizeof(*this));
			
		}
		fin.close();
		fout.close();
		
	
		
		fout.open("tempfile.txt", ios::app);
		setData();
		fout.write((char*)this, sizeof(*this));
		fout.close();
		
		remove(str);
		rename("tempfile.txt", str);
	}
	
	
	
}

void student::delete_student(char *Id, const char *str)
{
	int c = 0;
	ifstream fin;
	ofstream fout;
	
	fin.open(str, ios::in);
	if(!fin){
		cout << "\nFile is not exist.";
	}
	else{
		fout.open("tempfile.txt", ios::out);
		
		fin.read((char*)this, sizeof(*this));
		while(!fin.eof())
		{
			if(strcmp(Id, this->id))
			{
				c++;
				fout.write((char*)this, sizeof(*this));
			}
			fin.read((char *)this, sizeof(*this));
		}
		fin.close();
		fout.close();
		remove(str);
		rename("tempfile.txt",str);
		if(c!=0)
		{
			cout << "\n\t\t\t\t******Record deleted*************";
		}
	}
}
class admin : public teacher{
	char ann[50];
	char name_Announcer[50];
	char id[20];
	char password[20];
	public:
		void set_Announcement()
		{
			cout << "Announcer name with position: ";
			cin.getline(name_Announcer, 50);
			cout << endl;
			cout << "Add an announcement : ";
			cin.getline(ann, 50);
		}
		void add_Announcement()
		{
			ofstream fout;
			fout.open("Announcement.txt", ios::out);
			fout.write((char*)this, sizeof(*this));
			fout.close();
		}
		void file_announcement()
		{
			ifstream fin;
			fin.open("Announcement.txt", ios::in);
			if(!fin){
				cout << "File not exist.";
				
			}
			else{
				fin.read((char*)this, sizeof(*this));
				while(!fin.eof())
				{
					show_Announcement();
					
					fin.read((char*)this, sizeof(*this));
				}
				fin.close();
			}
		}
		void show_Announcement()
		{
			for(int i = 0; i < 120; i++)
			{
				cout << "*";
			}	
			cout << endl;
			cout << "\t\t\tATTENTION PLEASE! " << endl << endl;
			cout << "\t\t>>>" << ann << " <<<" << endl << endl << endl;
			cout << "\t\t Regards" << endl;
			cout << "\t\t ~" << name_Announcer;
			
			
			
			
		}
	void set()
    {
    	
        cout << "Enter ID: ";

        cin.getline(id,20);
        
        cout << endl;

        cout << "Enter Password : "; // minimum 8 characters //
        cin.getline(password, 20);

	}
 void signup(){
        ofstream fout;
        // open file and data enters //
        fout.open("LoginCredentials.txt", ios::app);


        fout.write((char*)this, sizeof(*this));

        fout.close();
        
    
    
    }
	int login(const char *Id, const char *ps){

        // read file and check the input data is valid or not //
        ifstream fin;
        int found;
        fin.open("LoginCredentials.txt", ios::in);
        if(!fin)
        {
        	cout << "file is not exist.";
		}
		else{
			
		
	        fin.read((char*)this, sizeof(*this));
	        while(!fin.eof())
	        {
	        
	                if(!strcmp(Id, this->id))
					{
							if(!strcmp(ps, this->password)){
								
								cout << "\n\t\t******You login Successfully.******* ";
								found = 1;
								break;
							
							}
							
					}
					else{
						
						cout << "\nIncorrect id or password";
						found = 0;
						break;
					}
						
	                fin.read((char*)this, sizeof(*this));
	        }
	        fin.close();
	    }
       return found; 
}  

	
	friend	double salary_given();
};

double salary_given()
{
	admin ad;
	ifstream fin;
		fin.open("TeachersRecord.txt", ios::in);
		if(!fin){
			cout << "File is not exist ";
			
		}
		else
		{
			fin.read((char*)&ad, sizeof(admin));

			while(!fin.eof())
			{
				ad.total_salary += ad.salary;
				fin.read((char*)&ad, sizeof(admin));
			}
			fin.close();
		}
		return ad.total_salary;

}

class attendee: public student{
		char c;
	public:
		
		
		void add_attendance(const char *str, int c, const char *att)
		{
			ifstream fin;
			ofstream fout;
			fin.open(str, ios::in);
			if(!fin){
				cout << "File is not exist ";
				
			}
			else
			{
				fout.open(att, ios::app);
				fin.read((char*)this, sizeof(*this));
	
				while(!fin.eof())
				{
					
					setAttendance(this->id);
					fout.write((char*)this, sizeof(*this));
					
					fin.read((char*)this, sizeof(*this));
				}
				fin.close();
				fout.close();
			}
		}
		void setAttendance(const char *id)
		{
		
			cout << this->id << "\t";
			cin >> c;
			
		}
		void showAttendance()
		{
			cout << "Id: " << this->id << "\t" << c << endl;
			
		}
		void show_attendance(const char *att)
		{
			ifstream fin;
			fin.open(att, ios::in);
			fin.seekg(0);
			if(!fin)
			{
				cout << "file not exist.";
				
			}
			else
			{
				fin.read((char*)this, sizeof(*this));
				while(!fin.eof())
				{
					showAttendance();
					fin.read((char*)this, sizeof(*this));
				}
				fin.close();
			}
		}
	void signup(){
		
	}
	int login(const char *, const char *)
	{
		
	}

		friend double total_fees_revenue(const char[]);
	
};

	


double total_fees_revenue(const char *str)
{
		attendee s;
	ifstream fin;
		fin.open(str, ios::in);
		if(!fin){
			cout << "File is not exist ";
			
		}
		else
		{
			fin.read((char*)&s, sizeof(attendee));

			while(!fin.eof())
			{
				s.total_fees += s.fees;
				fin.read((char*)&s, sizeof(attendee));
			}
			fin.close();
		}
		return s.total_fees;
		
}




class school {
	public:
			admin ad, al;
			attendee s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
//			teacher t;
//			students s;
		
	void Teacher()
	{
		int choose;
		cout << "Please select: ";
		cin >> choose;
		cin.ignore();
		if(choose == 1)
		{
			
			jump:
			char final;
			ad.setData();
			system("cls");
			cout << "You entered the following details.";
			ad.showData();
			cout << endl << endl;
			system("cls");
			cout << "Are you sure you want to store the details Y for yes N for no?";
			cin >> final;
			if(final == 'y' || final == 'Y')
			{
				ad.add_teacher();
				
				cout << "\n******Record is saved successfully.*******";
			}
			
			else
			Teacher();
			char jumping;
			cout << "\n\nDo you want to add one more teacher record? Y for Yes. ";
			cin >> 	jumping;
			cout << endl;
			cin.ignore();
			if(jumping == 'Y' || jumping == 'y')
				goto jump;
			else
			{
				cout << "Happy Record adding...";
					}		
		}
		else if(choose == 2)
		{
	
//			system("cls");
//			cout << "\t\t\tHere is the list of teachers" << endl << endl;
//			for(int i = 0; i < 120; i++)
//			{
//				cout << "-";
//			}
//			cout << endl;
//			ad.displayteacher_info();
		}
//		else if(choose == 3)
//		{
//			char iD[10];
//			
//			cout << "Enter the ID you want to find record : ";
//			cin.getline(iD,10);
//			
//			ad.search_teacher(iD);
//		}
		else if(choose == 4)
		{

			char ID[10];
			
			cout << "Enter the ID to update the record : ";
			cin.getline(ID,10);
			
			ad.edit_teacher(ID);
		}

		else if(choose == 5)
		{
			char ID[10];
			
			cout << "Enter the ID to delete the record : ";
			cin.getline(ID,10);
			ad.delete_teacher(ID);
		}
		
		else if(choose == 6)
		{
			system("cls");
			cout << "\t\t\t******************INFORMATION OF THE TOTAL SALARIES***************" << endl << endl << endl;
			for(int i = 0; i < 120; i++)
			{
				cout << "-";
			}	
			cout << endl;
			cout <<"\t\t\t\tTotal salaries of teachers : " << salary_given() << endl;
				for(int i = 0; i < 120; i++)
			{
				cout << "-";
			}
		}
		else if(choose == 7)
		{
			char ch;
			ad.set_Announcement();
			system("cls");
	
			cout << "\t\tAre you sure you want to set this announcement Y for YES: ";
			
			cin >> ch;
			
			if(ch == 'Y' || ch == 'y')
			{
					ad.add_Announcement();
					cout << endl;
					for(int i = 0; i < 120; i++)
					{
						cout << "*";
					}	
					cout << endl;
					cout << "\n\t\tThe Announcement is ready to show on the portal.";
					
			}
			
		}
		else if(choose == 8)
		{
			ad.file_announcement();
		}

		
		
	}
	void students()
	{
		int choose;
		cout << "Please select: ";
		cin >> choose;
		cin.ignore();
		if(choose == 1)
		{
			int noOfStudents;
			int clas;
			system("cls");
			cout << "Enter the class the student will add: ";
			cin >> clas;
			cout << endl;
			cout << "Enter how many students you want to add at a time: ";
			cin >> noOfStudents;
			cin.ignore();
			char str[20] = "Class1.txt";
			for(int i = 0; i < noOfStudents; i++)
			{
				s1.setData();
				s1.setFees();
				s1.setMonth();
				
				cout << "You entered the following details.";
				
				s1.showData();
				s1.showFees();
				s1.showMonth();
				char final;
				cout << endl << endl;
				cout << "Are you sure you want to store the details Y for yes N for no?";
				cin >> final;
				cin.ignore();
				if(final == 'y' || final == 'Y')
				{
					s1.add_student(str);
					
					cout << "\n******Record" << i+1 << " is saved successfully.*******";
				}
			
			}// loop ends //
		
			
		} // if ends //
		
		else if(choose == 2)
		{
			system("cls");
			char str[20] = "Class1.txt";
			cout << "\t\t\tHere is the list of students studied in this school" << endl << endl;
			for(int i = 0; i < 120; i++)
			{
				cout << "-";
			}
			cout << endl;
			s1.displayStudents(str);
		}	
		else if(choose == 3)
		{
			char str[20] = "Class1.txt";
			char iD[10];
			
			cout << "Enter the ID you want to find record : ";
			cin.getline(iD,10);
			
			s1.search_student(iD,str);
		}
		else if(choose == 4)
		{
			char str[20] = "Class1.txt";

			char ID[10];
			
			cout << "Enter the ID to update the record : ";
			cin.getline(ID,10);
			
			s1.edit_student(ID,str);
		}
		
		else if(choose == 5)
		{
			char str[20] = "Class1.txt";
			char ID[10];
			
			cout << "Enter the ID to delete the record : ";
			cin.getline(ID,10);
			s1.delete_student(ID, str);
		}
		else if(choose == 6)
		{
			char str[20] = "Class1.txt";
			system("cls");
			cout << "\t\t\t******************INFORMATION OF THE TOTAL SALARIES***************" << endl << endl << endl;
			for(int i = 0; i < 120; i++)
			{
				cout << "-";
			}
			cout << endl;
			cout <<"\t\t\t\tTotal salaries of teachers : " << total_fees_revenue(str) << endl;
				for(int i = 0; i < 120; i++)
			{
				cout << "-";
			}
		}
		else if(choose == 7)
		{
			int clas = 1;
			char str[20] = "Class1.txt";
			char att[20] = "Attendance1.txt";
			
			cout << "Add attendance: ";
			s1.add_attendance(str, clas,att);
//			s1.add_file(att);
			
		}
		else if(choose ==8)
		{
			char att[20] = "Attendance1.txt";
			s1.show_attendance(att);
		}
		else if(choose == 9)
		{
			
		}

	
	}

};

int main()
{   
	cout << endl << endl << endl; 
	for(int i = 0; i < 120; i++)
			{
				cout << "*";
			}
	

	cout << endl << "\t\t\t\tARMY PUBLIC SCHOOL MANAGEMENT SYSTEM" << endl << endl; 
	for(int i = 0; i < 120; i++)
			{
				cout << "*";
			}
	cout << endl << endl;
	cout << "\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "\t\t\t\t\t1. Administrator" << endl << endl;
	cout << "\t\t\t\t\t2. Teacher " << endl << endl;
	cout << "\t\t\t\t\t2. Student " << endl;
	cout << "\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	
	school sc;
	int choose;

	cin >> choose;
	
	fflush(stdin);
	if(choose == 1){
		system("cls");
//		sc.students();
//		sc.administrator();
	}
	else if(choose == 2)
	{
		sc.students();
	}

}
