#include<iostream>
#include<string>

using namespace std;

class dayType //daytype class definition
{
    private:
	string* current_day;//data member is pointer as it is dynamically allocated.
    string week_days[7];// array for days of week.
    
    void initialize_days_of_week()//Function initializing days of week.
    	{
    	week_days[0] = "Sun";// Sun for 'Sunday'.
		week_days[1] = "Mon";// Mon for 'Monday'.
		week_days[2] = "Tue";// Tue for 'Tuesday'.
		week_days[3] = "Wed";// Wed for 'Wednesday'.
		week_days[4] = "Thu";// Thu for 'Thursday'.
		week_days[5] = "Fri";// Fri for 'Friday'.
		week_days[6] = "Sat";// Sat for 'Saturday'.
		}
		
    public:
    dayType() //default constructor to set current day to Sunday.
	{
        current_day = new string("Sun");//dynamically allocating current day to Sun.
        initialize_days_of_week();//calling member function for initializing days of week.
    }

    dayType(const string& day)//Parametrized constructor to set current day to the value of parameter. 
	{
        current_day = new string(day);
        initialize_days_of_week();//calling member function for initializing days of week.
    }

    dayType(const dayType& obj) //copy constructor to copy the data of one object to another there is deep copy. 
	{
        current_day = new string(*(obj.current_day));
        initialize_days_of_week();//calling member function for initializing days of week.
    }

    ~dayType() //destructor is called when dynamically allocated current day pointer is deleted.
	{
        delete current_day;
    }

    void Set_Day(const string& set_day) //Set_Day function will set the current day to the day provided by user through parameter.
	{
        *current_day = set_day;//assign value of parameter to current day
    }

    void Print_day() const// Print Function is kept constant because it is read only function and display the current day.
	 {
        cout << "Current Day is: " << *current_day << endl;
    }

    string Get_Day() const //Getter function are usually constant and it will return current day.
	{
        return *current_day;
    }

    string Previous_Day() const //Function will return Previous day on the basis of current day 
	{
        for(int i = 0;i < 7;i++) //Loop iterates through no of week days
		{
            if (week_days[i]==*current_day) //this statement will match current day with week day and find it's index. 
			{
                if (i == 0)//if index is 0 then previous day will be at index 6.
				{
                    return week_days[6]; // Return Sunday if the current day is Monday
                } 
				else 
				{
                    return week_days[i - 1]; // Return the previous day
                }
                break;
            }
            
        }
        return "Invalid Day";//if current day will not match to the array of week 
    }

    string Next_Day() const //Function will return Next day on the basis of current day
	{
        for (int i = 0;i < 7;i++) 
		{
            if (week_days[i]== *current_day)
			 {
                if (i == 6) //if index is 6 then next day will be at index 0.
				{
                    return week_days[0]; // Return Sunday if the current day is Saturday
                } 
				else
				{
                    return week_days[i + 1]; // Return the next day
                }
                break;
            }
        }
        return "Invalid Day!";
    }

    string add_Days(int num) const //Add days function will add number of days to the current day.
	{
        for (int i = 0;i<7;i++) 
		{
            if (week_days[i] ==*current_day)//this statement will match current day with week day and find it's index.
			{
                int newIndex = (i + num) % 7; //the variable calculate the new index.
                return week_days[newIndex]; // return the new day.
            }
        }
        return "Invalid Day!";
    }
};
   //Fnction to dynamically allocate the object of class.
 dayType *dynamically_allocating(const string& default_day)//function will accept the string which represent the default day
    {
    	return new dayType(default_day);//return obj dynamically allocated.
	}
    	

int main() {
    char choice;
    int num;
    string new_day;
    
    dayType *d1 = dynamically_allocating("Sun");//declaring object of class and calling dynamically allocating function.

    do //Loop for menu driven program.
	{
        cout << "***Menu Program***\n";
        cout << "Press [a] to Set the day: \n";
        cout << "Press [b] to Print the day: \n";
        cout << "Press [c] to Return the day: \n";
        cout << "Press [d] to Return the next day: \n";
        cout << "Press [e] to Return the Previous day: \n";
        cout << "Press [f] to Calculate and return the day by adding certain days to the current day.: \n";
        cout << "Press [g] to Exit: \n";
        cin >> choice;// Prompt user to enter choice.

        switch (choice) {
            case 'a':
                cout <<"Enter 'Sun' for Sunday\n'Mon' for Monday\n'Tue' for Tuesday\n'Wed' for Wednesday\n'Thu' for Thursday\n'Fri' for Friday\n'Sat' for Saturday \n";//prompt user to enter new day to set
                cin.ignore(); // Ignore newline character left in the buffer
                getline(cin, new_day);
                
                if(new_day =="Sun"||new_day == "Mon"||new_day =="Tue"||new_day=="Wed" || new_day =="Thu"|| new_day=="Fri"||new_day=="Sat")
                {
                	d1->Set_Day(new_day);//calling Set Day function.
				}
                else
                {
                	cout<<"Enter correct abbreviation!"<<endl;
				}
                
                break;

            case 'b':
                d1->Print_day();//Calling Print day function.
                break;

            case 'c':
                cout << "Current day " << d1->Get_Day() << endl;//returning current day. 
                break;

            case 'd':
                cout << "Next Day " << d1->Next_Day() << endl;//calling next day fun which will return next day.
                break;

            case 'e':
                cout << "Previous Day " << d1->Previous_Day() << endl;//calling Previous day fun which will return previous day.
                break;

            case 'f':
                cout<<"Enter number you want to add: ";//Prompt user to enter number of days they want to add. 
                cin >> num;
                cout << "Day is " << d1->add_Days(num) << endl;//calling add days function.
                break;

            case 'g':
                cout << "Exiting program!\n";//exit program
                break;

            default:
                cout << "Invalid Input!" << endl;
                break;
        }
    } while (choice != 'g');//loop will iterate until user enter (g).

    delete d1;
    return 0;
}
