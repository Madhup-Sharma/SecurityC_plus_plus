#include <iostream> // main header file for c++
#include <fstream>  // fstream library allow us to work on files. -- filehandling
#include <sstream>  // It provides templates between string buffers and string objects
#include <string>   // Helps in using the  string inbuilt functions

using namespace std;

int main()
{
    int a, i = 0;

    string text, old, password1, password2, pass, name, password0, age, user, word, word1; // the variables we are going to use in the project

    // Making an array of strings

    string creds[2], cp[2];

    // Displaying the interface to the user (Non Abstracted View) 😎

    cout << "_____Security System_______";

    cout << "_____________________________" << endl
         << endl;
    cout << "|       1. Register         |" << endl;
    cout << "|       2. Login            |" << endl;
    cout << "|       3. Change Password  |" << endl;
    cout << "|_______4. End Program______|" << endl
         << endl;

    // The menu should be visible at least a time, so we will be using the do while loop for this --->>

    do
    {
        cout << endl;
        cout << "Enter your choice: " << endl;
        cin >> a;

        switch (a)
        {

            // case 1 is starting here ----- >>>>>

        case 1:
        {
            // Taking the data from the user
            cout << "____________________" << endl
                 << endl;
            cout << "|     REGISTER     |" << endl
                 << endl;
            cout << "|__________________|" << endl;
            cout << "Please Enter the Usernamme : " << endl;
            cin >> name;
            cout << "Enter the Password: " << endl;
            cin >> password0;
            cout << "Please enter your age: " << endl;
            cin >> age;

            // Now we have to store this data to some location for future authentication

            ofstream obj1;

            obj1.open("file.txt");

            if (obj1.is_open())
            {
                obj1 << name << '\n';
                obj1 << password0 << '\n';
                cout << "Registration Success !" << endl;
            }
            break;
        }

            // Case 2 is staring here ----- >>>>>

        case 2:
        {
            i = 0;

            cout << "_____________________________" << endl
                 << endl;
            cout << "|          LOGIN            |" << endl;
            cout << "|___________________________|" << endl
                 << endl;

            ifstream obj2;
            obj2.open("file.txt");

            cout << "Please Enter the Username : " << endl;
            cin >> user;

            cout << "Please Enter the Password : " << endl;

            cin >> pass;

            if (obj2.is_open())
            {
                // we must be using the end of file fucntion while fetching the detail from the file

                while (!obj2.eof())
                {
                    // this getline is helping in reading the file line by line also including the white spaces...
                    while (getline(obj2, text))
                    {
                        istringstream iss(text); // iss is simply an object of the istringstream class and it requires a constructor which is the text....

                        iss >> word;    // fetching the word from the file one by one 

                        creds[i] = word;
                        i++; // Array will look like this cred["username", "password"] -- Simple
                    }

                    if (user == creds[0] && pass == creds[1])
                    {
                        cout << "Login Successfull !" << endl;
                        cout << endl
                             << endl;

                        cout << " Details:  " << endl;

                        // Displaying details after the authentication
                        cout << "Username: " + name << endl;
                        cout << "Password: " + pass << endl;
                        cout << "Age: " + age << endl;
                    }

                    // Handling the edge case
                    else
                    {
                        cout << endl
                             << endl;
                        cout << "Incorrect Credentials" << endl;
                        cout << "|       1. Press 2 to Login     |" << endl;
                        cout << "|       2. Press 3 to change password     |" << endl;

                        break; // This break statement will make the program jump to the initial window
                    }
                }
            }

            break;
        }

        case 3:
        {
            i = 0;

            cout << "________Change Password__________" << endl;

            ifstream obj3;

            obj3.open("file.txt");

            cout << "Enter the Old Password" << endl;

            cin >> old;

            if (obj3.is_open())
            {

                while (obj3.eof())
                { // **** ERROR *** ?

                    while (getline(obj3, text))
                    {
                        istringstream iss(text);

                        iss >> word1;

                        cp[i] = word1; // new array to store the old pasword for comparison

                        i++;
                    }

                    if (old == cp[1])
                    { // Comparison happening here

                        obj3.close();
                        ofstream obj;
                        if (obj.is_open())
                        {

                            cout << "Enter your New Password: " << endl;
                            cin >> password1;

                            cout << "Enter your Password Again: " << endl;

                            cin >> password2;

                            if (password1 == password2)
                            {

                                // Overwriting the password here
                                obj << cp[0] << "\n";
                                obj << password1;
                                cout << "Password changed succesfully!" << endl;
                            }

                            else
                            {

                                obj << cp[0] << "\n";
                                obj << old;
                                cout << "Password does Not Match! " << endl;
                            }
                        }
                        else
                        {
                            cout << "Please Enter the Valid Password! " << endl;
                            break;
                        }
                    }
                }
            }

            break;
        }
        case 4:
        {
            cout << "____________Thankyou__________" << endl;
            break;
        }

        default:
            cout << "Enter the valid choice..." << endl; // If the user entered something other than 1,2,3,4
        }
    } while (a != 4);

    return 0;
}