#include<iostream>
#include<conio.h>
#include "Menu.h"

using namespace std;


/* THIS IS MENU CLASS
   IT HOLDS ALL THE METHODS AND FIELDS RELATED TO MAIN MENU
   */
class Menu {
	//fields and methods with private access modifier
	private:
		//decalring objects of the class of different operations
        Insertion INS;
        Searching SRCH;
        ViewAll VWALL;
        Delete DEL;
        
        //decalring variables
        int choice;
	
	
	
	//fields and methods with public access modifier
	public:    
		//method for main menu
 	    void setMainMenu() {
 	    	//clear the screen
		    system("CLS");
		    
		    //displaying the project banner on the top
		    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	    	cout<<"                                                 GRADE CHECKER AND CALCULATOR"<<endl;
		    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	    	
	    	//showing various options to perform operations
		    cout<<"Press 1 to Insert Data (grades will be calculated automatically)"<<endl;
		    cout<<"Press 2 to Search for any Record"<<endl;
		    cout<<"Press 3 to View All the Records"<<endl;
		    cout<<"Press 4 to Delete any Record"<<endl;
    		cout<<"Press 0 to Exit"<<endl<<endl;
		
	    	//getting an input for selecting a choice
	    	cin>>choice;
	    	
	    	//calling method to execute opeartion as per user choice
			setMenuConditions();   
    	}
    	
    	
    	
    	//method for setting menu conditions
    	void setMenuConditions() {
	    	/* SETTING UP THE CONDTIONS FOR SELECTING A CHOICE
		       THE SELECTED CHOICE WILL EXECUTE OPERATION RELATED CLASS AND METHOD */
    		
	    	//if user select Insert Data then this block of code will execute
    		if(choice == 1) {
    			//calling method to define the rules for grade calculation
    			INS.defineRules();
    			
	    		//if there is space then data can be inserted otherwise it go back to main menu
    			if (INS.checkSpace() == true) {
    				//calling methods from Insertion class to update avail, get information and update link array
    				INS.updateAVAIL();
    				INS.getInfo();
		        	INS.updateLINK();
			        
			        //asking to press any key to continue 
			        cout<<"\nPress any key to go back to Main Menu...";
		    	    getch();
		    	    
		    	    //calling method to set main menu back
		        	setMainMenu();
	    		}
		    		system("CLS");
		    		
		    		//ERROR message when there is insufficient space in array
			    	cout<<"You've Insufficient space in array. Please first delete any element from array."<<endl;
	    	    	cout<<"\nPress any key to continue...";
		        	getch();
	    	    	
	    		    //calling method to set main menu back
			    	setMainMenu();
		    }
		
	    	//if user select Search any Record then this block of code will execute
		    else if(choice == 2) {
		    	//calling method from Searching class to set searching menu
		    	SRCH.setSearchOptions();
		    	
		    	//asking to press any key to continue
	    	    cout<<"\nPress any key to back to main menu...";
		       	getch();
	    	   	
	    	    //calling method to set main menu back
		    	setMainMenu();
	    	}
	    	
		    //if user select View All the Records then this block of code will execute
		    else if(choice == 3) {
		    	//calling method from ViewAll class to view all the records
		    	VWALL.viewAllRecords();
		    	
		    	//asking to press any key to continue
	    	    cout<<"\n\nPress any key to back to main menu...";
		       	getch();
	    	   	
	    	    //calling method to set main menu back
		    	setMainMenu();
	    	}
	    	
		    //if user select Delete any Record then this block of code will execute
		    else if(choice == 4) {
		    	//calling method from Delete class to delete any record by providing ID
			    DEL.deleteRecord();
			    
			    //asking to press any key to continue
	    	    cout<<"\nPress any key to back to main menu...";
		       	getch();
	    	   	
	    	    //calling method to set main menu back
		    	setMainMenu();
	    	}
	    		
		    //if user select Exit then this block of code will execute
		    else if(choice == 0) {
		    	//calling exit method with parameter 0 (exit(0)) to terminate the program
			    exit(0);
	    	}
	    	
		    //if user doesn't select or select any other option then this block of code will run
		    else {
		    	//clear the screen
			    system("CLS");
			    
			    //displaying error message when you choose wrong choice which doesn't exist
		    	cout<<"ERROR! You have selected wrong choice. Please select again!";
		    	getch();
		    	
		    	//calling method to set main menu back
		    	setMainMenu();
	    	}
		}
};



//decalring object of Menu class
Menu MENU;

//main method
int main() {
	//calling method to set main menu
	MENU.setMainMenu();
	
	getch();
	return 0;
}