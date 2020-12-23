# PayrollManagementSystem
Object Oriented Programming in C++

# Project Summary
The payroll management system project in C++ is a console application with the use of Objected-Oriented Programming. The project included multiple classes and sub-classes with many features. Users could perform the program project functions, such as handling adding new employee record, delete, modify employee record, display and list employee record, and allow user to print the salary slip for a particular employee. 
This project was finished by Kai-yu Chiang, Paramit Ray, and Jialin Li. We worked on the project and reviewed the code to make sure the functions, algorithm, data structure and test file run successfully. If we have more time for the project, we could continue to complete the following goals to make this project more complete.

# Project features and functions
1. Class
There are two classes using in the program, Employee and Menu. Menu Class included two public function, main_menu and edit_menu. Employee class function include adding new employee, display employee information, read record in data, delete record in data, list all employee, modify employee information, edit employee salary slip, and print employee salary slip.
2. Menu
Main Menu function let user to choose which function want to use. It included (1) Add new employee (2) display one employee (3) list employee (4) print salary slip (5) edit menu. Edit menu included (6) delete employee information (7) modify employee information. Once user finished the function, it will return to the menu page until used exit out of the program.
3. New Employee
If user want to add new employee information into data, the program will ask user to input information included, code, name, number, address, date join in the company, designation, grade, basic salary, house, convenes. After entering those information, program will call “ADD” function. It opened the “test.csv” file and write those data in csv format.
4. Display Employee
If user want to look for particular employee information, they can use Display Emp function to get the data information. Program will ask you to enter the employee code, and search the employee code in “test.csv” file. Once the program got the employee code, it will display the information from that employee. And if the employee code is not exist, it will show “Not found!” and return to the main menu.
5. List Employee
For this function, it will ask you how many employee you want to list in the screen. Once user enter the number of employee, it will open “test.csv” file, and list down the name and code from data. If it got problem reading the file, it will pop up “Not found!” and return to main menu.
6. Salary slip
For salary ship, there are four function included. For the first part of the function, user have to enter the employee information that want to know and print. Second part of the function is calculate the total salary. Based on the data and information user enter, it will calculate the total amount in the salary slip. Third part of the function is fetch employee information from “test.csv”. It will only fetch the information that salary slip needed. And last part of the function is printing the result of salary slip. It will display the salary slip what user looking for.
7. Edit menu – delete, modify
In the edit menu, there are two function user could choose, delete employee information or modify employee information. For delete function, it will ask user which employee code information want to delete. And the program will open “test.csv” file and write into “temp.csv” file, only skip the employee code user enter. At the end, it will copy the “temp.csv” back to “test.csv” and delete “temp.csv” file.
For modify employee function, the program will call delete function for the employee code user want to modify, and enter the information want to change for that employee code. It’s the combination for adding new employee and delete employee information.

# Project follow up and improvement
If we could have more time to improve the project, there are the following parts that we could try to complete. First, limit the length of the string and number that the user could enter, and ensure that when the user enters the number where the string should be entered could pop up a warning line and remind user to re-enter the correct data format. When there is no problem for the data entered by the user, we could make sure less error and bugs generated when the data sorted and calculated later.
Second, the user interface improvement. The data presented at the project are very intuitive. If the collated data can be presented in a more structured way, it will have a better experience for users and developers.
Third, improve functionality. In addition to allowing users to generate specific salary slips, if the data of multiple employees can be generated at a time, or classified according to a specific grade group, or the data of certain specific members can be filtered when searching, the entire Salary management system will be more complete.
Finally, algorithm update. The current algorithm is suitable for the situation where the amount of data is small, and the program is aimed at the improvement of a single employee data. However, if the amount of data is large, the calculation speed and time will become inefficient. If the algorithm can be updated for huge data, we could improve the efficiency of the entire system.
