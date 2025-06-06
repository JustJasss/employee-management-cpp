#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

//using namespace std;

using std::cout;
using std::string;
using std::vector;
using std::cin;
using std::endl;
using std::unique_ptr;
using std::numeric_limits;
using std::streamsize;

class Employee;

string getValidatedString(const string& prompt, const string& promptType);
int getValidInteger(const string& prompt, const string& promptType);
int employeeIndexer(const vector<unique_ptr<Employee>>& employees, int id);
int getUniqueEmployeeID(const vector<unique_ptr<Employee>>& employees);
void autoCapitalise(string& str);

class Employee
{
private:
	string name;
	string company;
	int age, id;
public:
	Employee() : name(""), company(""), age(0), id(0) {}
	Employee(const string& newName, const string& newCompany, const int newAge, const int newID) : name(newName), company(newCompany), age(newAge), id(newID) {}

	void setName(const string& newName)
	{
		name	= newName;
	}
	void setCompany(const string& newCompany)
	{
		company = newCompany;
	}
	void setAge(const int newAge)
	{
		age		= newAge;
	}
	void setID(const int newID)
	{
		id		= newID;
	}

	string getName()	const
	{
		return	name;
	}
	string getCompany() const
	{
		return	company;
	}
	int	getAge()		const
	{
		return	age;
	}
	int getID()			const
	{
		return	id;
	}

	static Employee employeeCapture()
	{
		string name, company;
		int age, id;

		cout << "* Create Employee info *" << endl;

		name = getValidatedString("Enter employee name: ", "Name");
		autoCapitalise(name);

		company = getValidatedString("Enter employee company: ", "Company");
		autoCapitalise(company);

		age = getValidInteger("Enter employee age: ", "age");
		id = getValidInteger("Enter employee ID: ", "ID");

		return Employee(name, company, age, id);
	}
};

int employeeIndexer(const vector<unique_ptr<Employee>>& employees, int id)
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getID() == id)
		{											//static_cast for explicit conversion of data types.
			return static_cast<int>(i);				//Here static_cast converts from size_t data type (larger unsigned int) to regular (sized/signed) int.
		}
	}
	return -1;
}

string getValidatedString(const string &prompt, const string& promptType)
{
	string input;
	do
	{
		cout << prompt;
		getline(cin, input);

		if (input.empty())
		{
			cout << promptType << " cannot be empty. Please try again." << endl;
		}
	} while (input.empty());
	return input;
}

int getValidInteger(const string &prompt, const string &promptType)
{
	int input;

	cout << prompt;
	cin >> input;

	while (input <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Invalid " << promptType << " input. Try again." << endl;
		cin >> input;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}

void autoCapitalise(string &str)
{
	bool newWord = true;												//Starts off as a new word

	for (size_t i = 0; i < str.length(); i++)							//iterates over length of string
	{
		if (std::isspace(static_cast<unsigned char>(str[i])))			//if space is found in i-index
		{
			newWord = true;												//indicates it is a new word
		}
		else if (newWord)												//if it is indeed a new word
		{
			str[i] = std::toupper(static_cast<unsigned char>(str[i]));	//it capitalises the specific character (after the space) with index i
			newWord = false;											//thus it is no longer a new word
		}
		else
			str[i] = std::tolower(static_cast<unsigned char>(str[i]));	//and if it is not a new word it goes to lowercase
	}
}

int getUniqueEmployeeID(const vector<unique_ptr<Employee>>& employees)
{
	int id;
	while (true)
	{
		id = getValidInteger("Enter a different employee ID: ", "ID");
		if (employeeIndexer(employees, id) == -1)
		{
			return id;
		}
		cout << "That ID is already in use. Try again." << endl;
	}
}

void displayMenu(int menu)
{
	switch (menu)
	{
		case 1:
		{
			cout << "*** Welcome to Employee Wizard ***"<< endl;
			cout << "=================================="<< endl;
			cout << "Select from the options below:"	<< endl;
			cout << "1. Create new employee."			<< endl;
			cout << "2. Display all employee info."		<< endl;
			cout << "3. Edit info."						<< endl;
			cout << "4. Exit."							<< endl;
			break;
		}
		case 2:
		{
			cout << endl;
			cout << "** Employee Editor **"				<< endl;
			cout << "====================="				<< endl;
			cout << "Select option below:"				<< endl;
			cout << "1. Edit name."						<< endl;
			cout << "2. Edit company."					<< endl;
			cout << "3. Edit age."						<< endl;
			cout << "4. Edit ID"						<< endl;
			cout << "5. Remove employee"				<< endl;
			cout << "6. Return to main menu."			<< endl;
			break;
		}
	}
}

void employeeDisplay(const unique_ptr<Employee>& employee)  
{  
    //cout << "Displaying all employee info:" << endl;
	//cout << endl;
    cout << "Name:		" << employee->getName()	<< endl;  
    cout << "Company:	" << employee->getCompany() << endl;  
    cout << "Age:		" << employee->getAge()		<< endl;  
    cout << "ID:		" << employee->getID()		<< endl;  
	//cout << endl;
}

void employeeDisplayALL(const vector<unique_ptr<Employee>>& employees)
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		cout << endl;
		cout << "Employee # " << i + 1 << ":" << endl;
		employeeDisplay(employees[i]);
	}
}

void employeeEdit(vector<unique_ptr<Employee>>& employees, int index)
{
	unique_ptr<Employee>& employee = employees[index];
	bool returnToMainMenu = false;

	do
	{
		displayMenu(2);

		int selectedOption = 0;
		cin >> selectedOption;

		while (selectedOption <= 0 || selectedOption > 6 || cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid selection input. Please enter a positive integer corresponding to the options: " << endl;
			cin >> selectedOption;
		}

		switch (selectedOption)
		{
			case 1: 
			{
				string name = getValidatedString("* Edit name *", "name");
				autoCapitalise(name);

				employee->setName(name);


				break;
			}
			case 2: //edit company
			{
				string company = getValidatedString("* Edit company *", "company");
				autoCapitalise(company);

				employee->setCompany(company);
				break;
			}
			case 3: //edit age
			{
				int age = getValidInteger("* Edit age *", "age");
				employee->setAge(age);
				break;
			}
			case 4: //edit id
			{
				int id = getValidInteger("* Edit ID *", "ID");

				if (id == employee->getID())
				{
					cout << "ID remains unchanged (Still " << employee->getID() << endl;
					break;
				}

				if(employeeIndexer(employees, id) == -1)
				{
					cout << "ID already exists." << endl;
					break;
				}

				//if (employeeIndexer(employees, id) == -1)						I tried to implement something similar to this in the class but no dice.
				//{
				//	employee->setID(id);
				//}
				//else
				//{
				//	cout << "ID already exists." << endl;
				//}
				cout << endl;
				break;
			}
			case 5:
			{
				char confirmation = NULL;

				cout << "Are you sure you would like to remove Employee " << employee->getName();
				cout << "? (y/n) ";
				cin >> confirmation;

				confirmation = std::tolower(static_cast<char>(confirmation));	//Was told that static_cast is good practice when dealing with stuff from <cctype>>.
																				//user can input in either upper or lowercase with tolower.
				if (confirmation == 'y' && !cin.fail())
				{
					employees.erase(employees.begin() + index);					//simple erase with smart pointers. Legacy pointers require both .erase and .delete iirc.

					cout << "Employee removed successfully." << endl;

					returnToMainMenu = true;
					break;
				}
				else if (cin.fail())											//if cin fails i.e. the user inputs a integer instead of a char
				{
					cout << "Invalid input. (User did not choose options 'y' or 'n')." << endl;
					break;
				}
				else
				{
					cout << "Employee removal cancelled." << endl;
					break;
				}
			}
			default:
			{
				returnToMainMenu = true;
				break;
			}
		}

	} while (!returnToMainMenu);
}

//bool employeeRemoval(vector<unique_ptr<Employee>>& employees, int id)
//{
//	int index = employeeIndexer(employees, id);
//	if (index != -1)
//	{
//		employees.erase(employees.begin() + index);
//		return true;
//	}
//	return false;
//}

int main()
{
	vector<unique_ptr<Employee>> employees;

	int selectedOption = 0;
	bool exit = false;
	do
	{
		displayMenu(1);
		cin >> selectedOption;
		
		while (selectedOption <= 0 || selectedOption > 4 || cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid selection input. Please enter a positive integer corresponding to the options: " << endl;
			cin >> selectedOption;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (selectedOption)
		{
			case 1: //add employee
			{
				Employee newEmployee = Employee::employeeCapture();				//creates new object for a new employee and places info gathered from employeeCaptured() there.

				if (employeeIndexer(employees, newEmployee.getID()) != -1)		//if employeeIndexer returns -1 it means that the ID doesn't exist (yet), if it doesn't then the ID exists.
				{
					cout << "An employee with that ID already exists." << endl;		
					int newID = getUniqueEmployeeID(employees);					//if the ID does already exist on the database, user can create a new ID. getUniqueEmployeeID() will ensure user inputs unique ID.
					newEmployee.setID(newID);									//once user inputs unique ID, getUniqueEmployeeID() will return the unique ID which will be placed in newEmployee object.
				}

				employees.push_back(std::make_unique<Employee>(newEmployee));	//once that rigamarole is completed it will be pushed to the stack/vector where all employee info is stored.
				cout << endl;
				cout << "Employee created: " << endl;
				cout << "-----------------" << endl;
                employeeDisplay(std::make_unique<Employee>(newEmployee));
				cout << endl;													//initially tried to do something similar INSIDE the class but obviously that was a bad idea.
				break;
			}
			case 2: //display all employees
			{
				employeeDisplayALL(employees);									//displays all employee info as the name suggests.
				cout << endl;
				break;
			}
			case 3: //edit info
			{
				int id, index = 0;

				cout << "Enter employee ID: " << endl;
				cin >> id;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				index = employeeIndexer(employees, id);							//Searches for user based on ID for the purpose of editing their info.
				if (index != -1)
				{
					employeeEdit(employees, index);
				}
				else
				{
					cout << "Employee not found." << endl;
				}

				cout << endl;
				break;
			}
			case 4:
			{
				exit = true;
				break;
			}
		}
	} while (!exit);

	return 0;
}