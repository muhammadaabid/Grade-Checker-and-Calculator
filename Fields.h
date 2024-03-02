#include<string>

using namespace std;

class Fields {
	//fields and methods with private access modifier
	public:
		//declaring and initializing the arrays of Linked List
		int ID[30];
	    string FName[30];
	    string Subject[30];
	    int OMarks[30];
	    int TMarks[30];
	    string Grade[30];
	    int LINK[30] = {11, 8, 14, 6, 7, 13, 0, 2, 20, 3, 4, 5, 1, 22, 18, 29, 9, 19, 23, 26, 17, 16, 25, 28, 15, 24, 10, 29, 21, -1};
	    
	    //declaring and initializing the variables of Linked List
	    int START = -1;
	    int AVAIL = 12;
	    int NEW;
};