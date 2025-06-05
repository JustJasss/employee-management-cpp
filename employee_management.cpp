#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

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
		name = newName;
	}
	void setCompany(const string& newCompany)
	{
		company = newCompany;
	}
	void setAge(const int newAge)
	{
		age = newAge;
	}
	void setID(const int newID)
	{
		id = newID;
	}

	string getName() const
	{
		return name;
	}
	string getCompany() const
	{
		return company;
	}
	int getAge() const
	{
		return age;
	}
	int getID() const
	{
		return id;
	}

	static Employee employeeCapture()
	{
		string name, company;
		int age, id;

		cout << "Create Employee info" << endl;

		do
		{
			cout << "Enter name: ";
			getline(cin, name);
			if (name.empty())
			{
				cout << "Name cannot be empty. Please try again." << endl;
			}
		} while (name.empty());

		do
		{
			cout << "Enter company: ";
			getline(cin, company);
			if (company.empty())
			{
				cout << "Company cannot be empty. Please try again." << endl;
			}
		} while (company.empty());

		cout << "Enter age: ";
		cin >> age;

		while (age <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid age input. Please enter a positive integer: " << endl;
			cin >> age;
		}

		cout << "Enter employee ID: ";
		cin >> id;

		while (id <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid ID input. Please enter a positive integer: " << endl;;
			cin >> id;
		}

		return Employee(name, company, age, id);
	}
};

void employeeDisplay(const Employee& employee1)
{
	cout << "Displaying employee info:" << endl;
	cout << employee1.getName() << endl << employee1.getCompany() << endl << employee1.getAge() << endl << employee1.getID() << endl;
	cout << endl;
}

void employeeEdit(Employee& employee1)
{

	int selectedOption = 0;
	bool returnToMainMenu = false;
	do
	{
		cout << "**Employee Editor**" << endl;
		cout << "Select option below:" << endl;
		cout << "1. Edit name." << endl;
		cout << "2. Edit company." << endl;
		cout << "3. Edit age." << endl;
		cout << "4. Edit ID" << endl;
		cout << "5. Return to main menu." << endl;

		cin >> selectedOption;

		while (selectedOption <= 0 || selectedOption > 5 || cin.fail())
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
			string name;

			cout << "*Edit name*" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			employee1.setName(name);
			cout << endl;
			break;
		}
		case 2:
		{
			string company;

			cout << "*Edit company*" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, company);
			employee1.setCompany(company);
			cout << endl;
			break;
		}
		case 3:
		{
			int age;
			cout << "*Edit age*" << endl;
			cin >> age;

			while (age <= 0 || cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid age input. Try again." << endl;
				break;
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			employee1.setAge(age);

			cout << endl;
			break;
		}
		case 4:
		{
			int id;
			cout << "*Edit ID*" << endl;
			cin >> id;

			while (id < 0 || cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid ID input. Try again:" << endl;
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			employee1.setID(id);

			cout << endl;
			break;
		}
		default:
		{
			returnToMainMenu = true;
			break;
		}
		}

	} while (!returnToMainMenu);
}

int main()
{
	vector<Employee> employees;

	int selectedOption = 0;
	bool exit = false;
	do
	{
		cout << "***Welcome to Employee Wizard***" << endl;
		cout << "Select from the options below:" << endl;
		cout << "1. Create new employee." << endl;
		cout << "2. Display employee info." << endl;
		cout << "3. Edit info." << endl;
		cout << "4. Exit." << endl;

		cin >> selectedOption;
		
		while (selectedOption <= 0 || selectedOption > 4 || cin.fail())
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
			employees.push_back(Employee::employeeCapture());
			cout << endl;
			break;
		}
		case 2:
		{
			cout << endl;
			for (size_t i = 0; i < employees.size(); i++)
			{
				cout << "Employee # " << i + 1 << ":" << endl;
				employeeDisplay(employees[i]);
			}
			break;
		}
		case 3:
		{
			int index = 0;
			cout << "Enter employee number: " << endl;
			cin >> index;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (index < 0 || cin.fail())
			{
				cout << "Invalid employee number. Try again." << endl;
				break;
			}

			if (index > 0 && index <= employees.size())
			{
				employeeEdit(employees[index - 1]);
			}
			else
			{
				cout << "Invalid employee number. Try again." << endl;
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