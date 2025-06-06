# Employee Management System

A console-based C++ application for creating, viewing, editing, and removing employee records.  
Demonstrates clean architecture, robust input validation, and modern C++ best practices.

## 🎯 Project Overview

This project represents an evolution in my C++ journey, focusing on **clean, maintainable code**.  
Built as a second iteration of my [Library Management System](https://github.com/JustJasss/library-management-cpp) (a console-based book/magazine CRUD app).

## ✨ Key Features

### 🛡️ Robust Input Validation
- **String validation** (no empty names/companies)  
- **Integer validation** (age/ID must be positive)  
- **Error recovery** loops until valid input  

### 🎨 User Experience Focus
- **Auto-capitalization** for each word in name/company  
- **Unique ID enforcement** prevents data conflicts  
- **Intuitive menu system** with clear prompts and styling  
- **Professional error messages** guide user interaction  

### 🏗️ Modern C++ Architecture
- **Smart pointers** (`unique_ptr`) for automatic memory management  
- **Selective namespace usage** instead of `using namespace std;`  
- **Const-correctness** in function signatures  
- **RAII principles** for clean resource handling  

### 🔧 Clean Code Principles
- **Single Responsibility**: Each function does one job  
- **DRY (Don’t Repeat Yourself)**: Centralized validation helpers  
- **Separation of Concerns**: UI, logic, and data neatly separated  
- **Consistent naming** and formatting throughout  

## 🚀 Technical Highlights

Here are a few core declarations from [employee_management.cpp](./employee_management.cpp):

```cpp
// String validation
string getValidatedString(const string& prompt, const string& promptType);

// Integer validation
int getValidInteger(const string& prompt, const string& promptType);

// Unique ID lookup
int employeeIndexer(const vector<unique_ptr<Employee>>& employees, int id);

// Auto-capitalization helper
void autoCapitalise(string& str);

// Get a unique ID (re-prompts until valid)
int getUniqueEmployeeID(const vector<unique_ptr<Employee>>& employees);

// Main data structure
vector<unique_ptr<Employee>> employees;  // No manual delete needed
```

## 🛠️ Building and Running

### Prerequisites
- C++11-compatible compiler (GCC, Clang, MSVC)  
- CMake 3.10 or higher  

### Build with CMake

```bash
git clone https://github.com/JustJasss/employee-management-cpp.git
cd employee-management-cpp
mkdir build && cd build
cmake ..
make
./employee_management
```

### Direct Compilation (No CMake)

```bash
g++ -std=c++11 -Wall -Wextra employee_management.cpp -o employee_management
./employee_management
```

> **Windows (Visual Studio)**  
> ```bash
> mkdir build
> cd build
> cmake .. -G "Visual Studio 16 2019"
> cmake --build . --config Release
> .\Release\employee_management.exe
> ```

## 📋 Usage

Upon running, you’ll see:

```
*** Welcome to Employee Wizard ***
==================================
Select from the options below:
  1. Create new employee.
  2. Display all employee info.
  3. Edit info.
  4. Exit.
```

1. **Create new employee**  
   - Prompts for name, company, age, and ID (all validated).  
   - Auto-capitalizes name/company (e.g., “alice smith” → “Alice Smith”).  
   - If an ID is already taken, you only re-enter the ID.  

2. **Display all**  
   - Lists each employee’s details (Name, Company, Age, ID).  

3. **Edit info**  
   - Choose an employee by ID, then edit name, company, age, or ID.  
   - ID editing loops until a unique ID is provided.  

4. **Exit**  
   - Terminates the program gracefully.

### Sample Interaction
```
*** Welcome to Employee Wizard ***
==================================
Select from the options below:
1. Create new employee.
2. Display all employee info.
3. Edit info.
4. Exit.
1
Enter employee name: john doe
Enter employee company: tech solutions
Enter employee age: 28
Enter employee ID: 1001

Employee created:
-----------------
Name:    John Doe
Company: Tech Solutions
Age:     28
ID:      1001

2
Employee #1:
 Name:    John Doe
 Company: Tech Solutions
 Age:     28
 ID:      1001

4
Exiting…
```

## 🎓 Learning Outcomes

- Mastery of **modern C++ best practices** and memory management  
- Professional **input validation** and error handling  
- A clean, maintainable **code architecture**  
- **User-focused** console UI design  
- Familiarity with **CMake** build systems  

## 🔄 Evolution from Previous Projects

| Aspect               | Library System                           | Employee System                           |
|----------------------|-------------------------------------------|-------------------------------------------|
| **Memory Management**| Raw pointers with manual cleanup          | `unique_ptr` with RAII                   |
| **Input Validation** | Scattered and repetitive                  | Centralized helper functions              |
| **Code Organization**| Monolithic functions                      | Single-purpose, modular functions         |
| **User Experience**  | Basic prompts and error messages          | Auto-formatting, consistent UX            |
| **Namespace Usage**  | `using namespace std;`                    | Selective `std::` imports                 |

## 🚀 Future Enhancements

- File persistence (save/load employees to disk)  
- Split into multiple header files  
- Data export (CSV, JSON)  
- To be determined

## 🛡️ Code Quality

- Zero memory leaks through smart pointers  
- Exception safety with RAII and clean resource use  
- Thorough input sanitization prevents invalid data  
- Const-correctness ensures data integrity  
- Written to modern C++ (C++11 and beyond)

## 📞 Contact

**Jaskaran Debidin**  
- GitHub: [@JustJasss](https://github.com/JustJasss)  
- Portfolio: [Library Management System](https://github.com/JustJasss/library-management-cpp)  

---

*This project showcases professional C++ development practices suitable for production environments. Built with attention to code quality, user experience, and maintainability.*  
