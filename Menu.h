#include<iostream>
#include<conio.h>
#include<iomanip>
#include <random>
#include "Fields.h"

using namespace std;


//declaring object of Fields class
Fields FLD;





/* THIS IS INSERTION CLASS
   IT HOLDS ALL THE METHODS AND FIELDS RELATED TO INSERTION OPEARTION
   */
class Insertion {
	//fields and methods with public access modifier
	public:
		//boolean flag to check whether there is free space available or not in Linked List
		bool isSpace;
		//if there is no space then it returns false otherwise it returns true 
		bool checkSpace() {
			if(FLD.AVAIL == -1)
				isSpace = false;
			else
				isSpace = true;
			
			//returning isSpace value
			return(isSpace);
		}
		
		
		
		//method for updating AVAIL
	    void updateAVAIL() {
	    	//updating value of NEW
	    	FLD.NEW = FLD.AVAIL;
	    	//updating value of AVAIL
	    	FLD.AVAIL = FLD.LINK[FLD.AVAIL];
		}
		
		
		
		//method for getting user information from user
	    void getInfo() {
	    	//clear the screen
	    	system("CLS");
	    	
			//displaying the insertion screen banner on the top
        	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	        cout<<"                                                      INSERT DATA"<<endl;
	        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
		    
			//these are required fields to insert data
			cout<<"Enter your Full Name: ";
		    cin>>FLD.FName[FLD.NEW];
		    cout<<"Course/Subject: ";
		    cin>>FLD.Subject[FLD.NEW];
		    cout<<"Enter your obtained marks: ";
		    cin>>FLD.OMarks[FLD.NEW];
		    cout<<"Enter total marks of subject: ";
		    cin>>FLD.TMarks[FLD.NEW];
		    
		    //calling method calculateGrade to calculate the Grades
		    calculateGrade();
	    }
	    
	    
	    //method for calculating the percentage of obtained marks
	    float calculatePercen() {
	    	return((FLD.OMarks[FLD.NEW]*100)/FLD.TMarks[FLD.NEW]);
		}
	    
	    
	    //method for calculating grade
	    void calculateGrade() {
	    	//conditons for checking that entered marks are right or wrong
	    	if(FLD.OMarks[FLD.NEW]<=FLD.TMarks[FLD.NEW] && FLD.OMarks[FLD.NEW]>0) {
	    		
	    		//storing percentage in a variable
		    	float Percen = calculatePercen();
		    	
	    		/* SETTING UP THE CONDITIONS FOR ALL GRADES
	    		   */
	    	   
		    	//if percentage is greater than 90, then grade is A+
		    	if(Percen>90) {
	    			FLD.Grade[FLD.NEW] = "A+";
				}
				
				//if percentage is in between 83 & 90, then grade is A
				else if(Percen>=83 && Percen<=90) {
					FLD.Grade[FLD.NEW] = "A";
				}
				
				//if percentage is in between 83 & 90, then grade is B+
				else if(Percen>=75 && Percen<=82) {
					FLD.Grade[FLD.NEW] = "B+";
				}
				
				//if percentage is in between 83 & 90, then grade is B
				else if(Percen>=65 && Percen<=74) {
					FLD.Grade[FLD.NEW] = "B";
				}
				
				//if percentage is in between 83 & 90, then grade is C+
				else if(Percen>=60 && Percen<=64) {
					FLD.Grade[FLD.NEW] = "C+";
				}
				
				//if percentage is in between 83 & 90, then grade is C
				else if(Percen>=50 && Percen<=59) {
					FLD.Grade[FLD.NEW] = "C";
				}
				
				//if percentage is less than 50, then grade is F (FAIL)
				else if(Percen<50) {
					FLD.Grade[FLD.NEW] = "F";
				}
			}
			else {
				//clear the screen
	    	    system("CLS");
				
		    	//ERROR message when there is insufficient space in array
			   	cout<<"You've entered wrong marks (Obtained Marks are greater than Total Marks!)"<<endl;
			    
    			//asking to press any key to continue
    	    	cout<<"\nPress any key to enter data again...";
		    	getch();
		    	
		    	//calling getInfo method to get information for insertion again
		    	getInfo();
			}	
		}
		
		
		
		//method for updating LINK
		void updateLINK() {
			//initiallizing variable LAST as START
			int LAST = FLD.START;
			
			//setting LINK of last node to NULL
			FLD.LINK[FLD.NEW] = -1;
			
			//setting condtions for insertion at first or in-between node
			if(LAST == -1) {
				FLD.START = FLD.NEW;
			}
			else {
				//while loop for traversing the filled portion of array to find last node
			    while(FLD.LINK[LAST] != -1) {
				    LAST = FLD.LINK[LAST];
			    }
			    //updating LINK of old last node
			    FLD.LINK[LAST] = FLD.NEW;
			}
			
			//assigning ID to the record
			FLD.ID[FLD.NEW] = genRandNum();
		}
		
		
		
		//method for generating random number
		int genRandNum() {
			/* Create a random number generator
			   */
			   
			// Initialize a random seed
    		random_device rd;
    		
    		// Mersenne Twister pseudo-random generator
    		mt19937 generator(rd());
		    
    		// Define the range of random numbers (1 to 30)
    		uniform_int_distribution<int> distribution(1, 30);
		    
    		// Generate a random number
    		int random_number = distribution(generator);
    		
    		//returning random number
    		return(random_number);
		}
	    
	    
	    
	    //method for defining rules for calculating grades
	    void defineRules() {
	    	//clear the screen
	    	system("CLS");
	    	
	    	//displaying the rules for caculating grades screen banner on the top
        	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	        cout<<"                                          RULES FOR CALCULATING GRADES"<<endl;
	        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	    	
			//rules for calculating grades
			cout<<"A+ is on above 90%."<<endl;
	    	cout<<"A is on 83% - 90%."<<endl;
	    	cout<<"B+ is on 75% - 82%."<<endl;
	    	cout<<"B is on 65% - 74%."<<endl;
	    	cout<<"C+ is on 60% - 64%."<<endl;
	    	cout<<"C is on 50% - 59%."<<endl;
	    	cout<<"FAIL is on below 50%."<<endl;
	    	
	    	//asking to press any key to continue
	    	cout<<"\nPress any key to continue...";
	    	getch();
		}
};





/* THIS IS SEARCHING CLASS
   IT HOLDS ALL THE METHODS AND FIELDS RELATED TO SEARCHING OPERATION
   */
class Searching {
	//fields and methods with private access modifier
	private:
		//decalring variable choice
        int choice;
	
	
	
	//fields and methods with public access modifier
	public:	
		//method for setting searching options
    	void setSearchOptions() {
    		//clear the screen
	 	    system("CLS");
	 	    
		    //displaying the searching screen banner on the top
    	    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        	cout<<"                                                      SEARCH DATA"<<endl;
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	 	    
    	   	//showing various options to perform operations
    	   	cout<<"Press 1 to Search by ID."<<endl;
	        cout<<"Press 2 to Search by Full Name."<<endl;
		    cout<<"Press 3 to Search by Subject/Course."<<endl;
    	    cout<<"Press 4 to Search by Grade."<<endl<<endl;
    	    
    	    //getting an input for selecting a choice
	    	cin>>choice;
	    	
	    	//calling method to execute opeartion of search as per user choice
	    	setSearchConditions();
	    }
	    
	    
	    
	    //method for setting search conditions
    	void setSearchConditions() {
	    	/* SETTING UP THE CONDTIONS FOR SELECTING A CHOICE
		       THE SELECTED CHOICE WILL EXECUTE OPERATION RELATED CLASS AND METHOD */
    		
	    	//if user selects Search by ID then this block of code will execute
    		if(choice == 1) {
    			//calling method for searching by ID
    			searchByID();
    		}
    		
    		//if user selects Search by Full Name then this block of code will execute
    		else if(choice == 2) {
    			//calling method for searching by Full Name
    			searchByFName();
    		}
		
	    	//if user selects Search by Subject/Course then this block of code will execute
		    else if(choice == 3) {
		    	//calling method for searching by Subject/Course
		    	searchBySubject();
	    	}
	    	
		    //if user selects Search by Grade then this block of code will execute
		    else if(choice == 4) {
		    	//calling method for searching by Grade
			    searchByGrade();
	    	}
	    	
		    //if user doesn't select or select any other option then this block of code will run
		    else {
		    	//clear the screen
			    system("CLS");
			    
			    //displaying error message when you choose wrong choice which doesn't exist
		    	cout<<"ERROR! You have selected wrong choice. Please select again!";
		    	getch();
		    	
		    	//calling method to set searching options again
		    	setSearchOptions();
	    	}
		}
		
		
		
		//method for search by ID
		void searchByID() {
			//declaring variable ID and initiallizing variable PTR as START
			int ID;
			int PTR = FLD.START;
			
			//clear the screen
			system("CLS");
			
			//displaying the search data by ID screen banner on the top
    	    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        	cout<<"                                                   SEARCH DATA BY ID"<<endl;
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
		    
		    //getting ID to search the record
			cout<<"Enter ID to search the record: ";
			cin>>ID;
			
			//calling method to set header of searched data by ID
			showSearchedRecord();
			
			//while loop for traversing whole linked list to search data about specific ID
			while(PTR != -1) {
				//setting condtions for identifying searching ID
				if(FLD.ID[PTR] == ID) {
					//displaying the found data
					cout<<left<<setw(8)<<FLD.ID[PTR]<<left<<setw(22)<<FLD.FName[PTR]<<left<<setw(27)<<FLD.Subject[PTR]<<left<<setw(27)<<FLD.OMarks[PTR]<<left<<setw(24)<<FLD.TMarks[PTR]<<left<<setw(5)<<FLD.Grade[PTR]<<endl;
			        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
			        
			        //break statement to terminate the loop
					break;
				}
				
				//updating value of PTR at each itteration
				PTR = FLD.LINK[PTR];
			}
			
			//this if block will execute only when ID doesn't found
			if(FLD.ID[PTR] != ID) {
				cout<<"\n\nThe ID "<<ID<<" doesn't found!";
			}
		}
		
		
		
		//method for search by full name
		void searchByFName() {
			//declaring variable FName and initiallizing variable PTR as START
			string FName;
			int PTR = FLD.START;
			
			//boolean flag to track whether cout has been executed
            bool coutExecuted = false;
			
			//clear the screen
			system("CLS");
			
			//displaying the search data by full name screen banner on the top
    	    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        	cout<<"                                                SEARCH DATA BY FULL NAME"<<endl;
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
		    
		    //getting ID to search the record
			cout<<"Enter Full Name to search the record: ";
			cin>>FName;
			
			//calling method to set header of searched data by full name
			showSearchedRecord();
			
			//while loop for traversing whole linked list to search data about specific Full Name
			while(PTR != -1) {
				//setting condtions for identifying searching full name
				if(FLD.FName[PTR] == FName) {
					//displaying the found data
					cout<<left<<setw(8)<<FLD.ID[PTR]<<left<<setw(22)<<FLD.FName[PTR]<<left<<setw(27)<<FLD.Subject[PTR]<<left<<setw(27)<<FLD.OMarks[PTR]<<left<<setw(24)<<FLD.TMarks[PTR]<<left<<setw(5)<<FLD.Grade[PTR]<<endl;
			        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
			        
			        //making codeExecuted as true as one time or more time cout has been executed
			        coutExecuted = true;
				}
				
				//updating value of PTR at each itteration
				PTR = FLD.LINK[PTR];
			}
			
			//this if block will execute only when full name doesn't found
			if(coutExecuted == false) {
				cout<<"\n\nThe Full Name "<<FName<<" doesn't found!";
			}
		}
		
		
		
		//method for search by subject
		void searchBySubject() {
			//declaring variable Student and initiallizing variable PTR as START
			string Subject;
			int PTR = FLD.START;
			
			//boolean flag to track whether cout has been executed
            bool coutExecuted = false;
			
			//clear the screen
			system("CLS");
			
			//displaying the search data by subject screen banner on the top
    	    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        	cout<<"                                                  SEARCH DATA BY SUBJECT/COURSE"<<endl;
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
		    
		    //getting ID to search the record
			cout<<"Enter Subject/Course to search the record: ";
			cin>>Subject;
			
			//calling method to set header of searched data by subject/course
			showSearchedRecord();
			
			//while loop for traversing whole linked list to search data about specific Subject/Course
			while(PTR != -1) {
				//setting condtions for identifying searching subject/course
				if(FLD.Subject[PTR] == Subject) {
					//displaying the found data
					cout<<left<<setw(8)<<FLD.ID[PTR]<<left<<setw(22)<<FLD.FName[PTR]<<left<<setw(27)<<FLD.Subject[PTR]<<left<<setw(27)<<FLD.OMarks[PTR]<<left<<setw(24)<<FLD.TMarks[PTR]<<left<<setw(5)<<FLD.Grade[PTR]<<endl;
			        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
			        
			        //making codeExecuted as true as one time or more time cout has been executed
					coutExecuted = true;
				}
				
				//updating value of PTR at each itteration
				PTR = FLD.LINK[PTR];
			}
			
			//this if block will execute only when subject/course doesn't found
			if(coutExecuted == false) {
				cout<<"\n\nThe Subject/Course "<<Subject<<" doesn't found!";
			}
		}
		
		
		
		//method for search by grade
		void searchByGrade() {
			//declaring variable Grade and initiallizing variable PTR as START
			string Grade;
			int PTR = FLD.START;
			
			//boolean flag to track whether cout has been executed
            bool coutExecuted = false;
			
			//clear the screen
			system("CLS");
			
			//displaying the search data by grade screen banner on the top
    	    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        	cout<<"                                                  SEARCH DATA BY GRADE"<<endl;
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
		    
		    //getting ID to search the record
			cout<<"Enter Grade to search the record: ";
			cin>>Grade;
			
			//calling method to set header of searched data by grade
			showSearchedRecord();
			
			//while loop for traversing whole linked list to search data about specific Grade
			while(PTR != -1) {
				//setting condtions for identifying searching grade
				if(FLD.Grade[PTR] == Grade) {
					//displaying the found data
					cout<<left<<setw(8)<<FLD.ID[PTR]<<left<<setw(22)<<FLD.FName[PTR]<<left<<setw(27)<<FLD.Subject[PTR]<<left<<setw(27)<<FLD.OMarks[PTR]<<left<<setw(24)<<FLD.TMarks[PTR]<<left<<setw(5)<<FLD.Grade[PTR]<<endl;
			        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
			        
					//making codeExecuted as true as one time or more time cout has been executed
					coutExecuted = true;
				}
				
				//updating value of PTR at each itteration
				PTR = FLD.LINK[PTR];
			}
			
			//this if block will execute only when grade doesn't found
			if(coutExecuted == false) {
				cout<<"\n\nThe Grade "<<Grade<<" doesn't found!";
			}
		}
		
		
		
		//method for showing searched record
		void showSearchedRecord() {
			//clear the screen
			system("CLS");
			
	    	//displaying the view all records banner on the top
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	        cout<<"                                                     SEARCHED RECORD"<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
            
		    //displaying header row for all type of searches (search by ID, Full Name, Subject or Grade)
		    cout<<left<<setw(8)<<"ID"<<left<<setw(22)<<"Full Name"<<left<<setw(27)<<"Subject/Course"<<left<<setw(27)<<"Obtained Marks"<<left<<setw(24)<<"Total Marks"<<left<<setw(5)<<"Grade"<<endl;
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
		}
};





/* THIS IS VIEW ALL CLASS
   IT HOLDS ALL THE METHODS AND FIELDS RELATED TO VIEW ALL OPERATION
   */
class ViewAll {
	//fields and methods with private access modifier
	private:
		//decalring variable PTR
		int PTR;
	
	
	
	//fields and methods with public access modifier
	public:    
		//method for showing all records
 	    void viewAllRecords() {
 	    	//clear the screen
		    system("CLS");
		    
		    //displaying the view all records banner on the top
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	    	cout<<"                                                    VIEW ALL RECORDS"<<endl;
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
		    
		    //displaying header row for all type of searches (search by ID, Full Name, Subject or Grade)
		    cout<<left<<setw(8)<<"ID"<<left<<setw(22)<<"Full Name"<<left<<setw(27)<<"Subject/Course"<<left<<setw(27)<<"Obtained Marks"<<left<<setw(24)<<"Total Marks"<<left<<setw(5)<<"Grade"<<endl;
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
			
			//calling method for traversing the data
			traverseData();  
    	}
    	
    	
    	//method for traversing whole data
    	void traverseData() {
    		//setting  PTR as START
    		PTR = FLD.START;
    		
    		//while loop for traversing the whole array to display all the records/data
    		while(PTR != -1) {
    			//calling method to show all the records
    			showRecord();
    			
    			//updating value of PTR at each itteration
    			PTR = FLD.LINK[PTR];
			}
		}
		
		
		//method for displaying records
		void showRecord() {
			//cout statement to display each record at each iteration
			cout<<left<<setw(8)<<FLD.ID[PTR]<<left<<setw(22)<<FLD.FName[PTR]<<left<<setw(27)<<FLD.Subject[PTR]<<left<<setw(27)<<FLD.OMarks[PTR]<<left<<setw(24)<<FLD.TMarks[PTR]<<left<<setw(5)<<FLD.Grade[PTR]<<endl;
			cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
		}
};





/* THIS IS DELETE CLASS
   IT HOLDS ALL THE METHODS AND FIELDS RELATED TO DELETE OPERATION
   */
class Delete {
	//fields and methods with private access modifier
	private:
		//decalring variable ID and PTR
		int ID;
		int PTR;
	
	
	
	//fields and methods with public access modifier
	public:
		//method for deleteing a record
	    void deleteRecord() {
	    	//clear the screen
	    	system("CLS");
	    	
		    //displaying the view all records banner on the top
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	        cout<<"                                                      DELETE RECORD"<<endl;
		    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
		    
		    
		    //getting ID from user to delete the record of that ID
		    cout<<"Enter ID to delete the record: ";
		    cin>>ID;
		    
		    //calling method of retrieving and deleting ID (first retrieve and then delete)
		    deleteID();
	    }
	    
	    
	    //method for retrieving and deleting provided ID
	    void deleteID() {
	    	//initiallizing PTR as START and LOCP (Location of Previous Node) as PTR
	    	int PTR = FLD.START;
	    	int LOCP = PTR;
	    	
			//traversing whole data through a while loop for getting provided ID
			while(PTR != -1) {
				//setting codition for matching IDs
				if(ID == FLD.ID[PTR]) {
					//setting conditions for first or in-between node (LOCP == PTR => First Node)
					if(LOCP == PTR) {
						//deleting the first node
						FLD.START = FLD.LINK[PTR];
						
						//updating the avail list
						FLD.LINK[PTR] = FLD.AVAIL;
						FLD.AVAIL = PTR;
						
						//displaying message "The Record has been successfully deleted!"
		                cout<<"\n\nThe Record has been successfully deleted!";
		                
		                //break statement to terminate the loop
						break;
					}
					    FLD.LINK[LOCP] = FLD.LINK[PTR];
					    
					    //updating the avail list
						FLD.LINK[PTR] = FLD.AVAIL;
						FLD.AVAIL = PTR;
						
						//displaying message "The Record has been successfully deleted!"
		                cout<<"\n\nThe Record has been successfully deleted!";
		                
		                //break statement to terminate the loop
					    break;
					}	
				}
				
				//updating value of LOCP (Location of Previous Node) at each itteration
				LOCP = PTR;
				
				//updating value of PTR at each itteration
				PTR = FLD.LINK[PTR];
			
			//this if block will execute only when ID doesn't found
			if(FLD.ID[PTR] != ID) {
				cout<<"\n\nThe ID "<<ID<<" doesn't found!";
			}
		}
};