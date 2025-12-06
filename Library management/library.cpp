#include <iostream>
#include <vector>
using namespace std;

struct data
{
    string bookname;
    string authorname;
    string id;
    string bookadd;
    string booktype;
};
struct information
{
    string username;
    string userid;
    string branch;
    int year;
};

vector<information> USER;
vector<data> show;

class admin
{
public:
    string Username;
    string userid;
    string branch;
    int year;
};

class User : public admin
{
public:
    void Creataccount()
    {
        cout << "Set the user id and password  " << endl;
        cout << "enter user name :-";
        cin >> Username;
        cout << "Set the user ID :- ";
        cin >> userid;
        cout << "Enter the your branch :-";
        cin >> branch;
        cout << "Enter the year:- ";
        cin >> year;

        information inf;

        inf.username = Username;
        inf.userid = userid;
        inf.branch = branch;
        inf.year = year;
        USER.push_back(inf);
    }
    void UserDetails()
    {
        int i = 0;
        cout << " s.no. " << "name" << "\t\t" << "ID" << "\t\t" << "Branch" << "\t\t" << "year" << endl;
        for (vector<information>::iterator f1 = USER.begin(); f1 != USER.end(); ++f1)
        {
            cout << " " << i + 1 << " "
                 << f1->username << "\t\t"
                 << f1->userid << "\t\t"
                 << f1->branch << "\t\t"
                 << f1->year << endl;
            i + 1;
        }
    }
};

class library
{
public:
    string bookName;
    string bookAuthor;
    string id;
    string userId;

public:
    void SetData();
    void Display();
};

void library::SetData()
{
    cout << endl;
    cout << "Enter the book name :- ";
    cin >> bookName;
    cout << "Enter the author name :- ";
    cin >> bookAuthor;
    cout << "Enter the book id :- ";
    cin >> id;
}

class Book : public library
{
public:
    string book_adition;
    void set_edition()
    {
        SetData();
        cout << "Enter the book edition :- ";
        cin >> book_adition;
    }
};

class Book1 : public Book, public User
{
public:
    string Booktype;
    void Display();
    void set_type()
    {
        set_edition();
        cout << "Enter book type :- ";
        cin >> Booktype;

        // Correct push_back
        data d;
        d.bookname = bookName;
        d.authorname = bookAuthor;
        d.id = id;
        d.bookadd = book_adition;
        d.booktype = Booktype;
        show.push_back(d);
    }
};

void Book1::Display()
{
    cout << endl;
    int i = 0;
    cout << "S.No.       Book Name     Author Name           Book Id         Book Edition          Type" << endl;

    for (vector<data>::iterator it = show.begin(); it != show.end(); ++it)
    {
        cout << " " << i + 1 << ".          "
             << it->bookname << "         "
             << it->authorname << "               "
             << it->id << "              "
             << it->bookadd << "             "
             << it->booktype << endl;
        i++;
    }
}

class Issue : public Book1
{
public:
    string bname;
    string PhoneNumber;
    int issueday, returnday;
    Issue()
    {
        cout << "--------- Welcome To Library --------- " << endl;
    }
    void issuebook()
    { 
        int press;
        cout << "Choose your year :-";
        cin >> year;
        cout << "Book subject :- ";
        cin >> bname;
        cout << "kindly enter book name :- ";
        cin >> bname;
        cout << "Which author you prefer :-";
        cin >> bookAuthor;
        cout << "Are you want to issue book press 1 or it's just for reading press 2. :-";
        cin >> press;
        if (press == 1)
        {
            cout << "for issuing again enter your id :-";
            cin >> userid;
            cout << "enter your phone number :-";
            cin >> PhoneNumber;
            cout << "Enter the issue date (in number) :-";
            cin >> issueday;

            cout << "\nBook Name       Author Name           Book Id          Book Edition          Type" << endl;

            for (vector<data>::iterator it = show.begin(); it != show.end(); ++it)
            {
                if (it->bookname == bname)
                {
                    cout << it->bookname << "            "
                         << it->authorname << "                "
                         << it->id << "               "
                         << it->bookadd << "            "
                         << it->booktype << endl;
                }
            }
        }
    }

    void calculatefine()
    {
        int allowedDays = 14;
        int days = returnday - issueday;

        if (days > allowedDays)
        {
            int lateday = days - allowedDays;
            int fine = lateday * 2;
            cout << "Book returned late by " << lateday << " days." << endl;
            cout << "Fine amount: Rs " << fine << endl;
        }
        else
        {
            cout << "Book returned on time. No fine." << endl;
        }
    }

    void returnbook()
    {
        string k;
        cout << "Enter the user id :- ";
        cin >> k;
        for (vector<information>::iterator f1 = USER.begin(); f1 != USER.end(); ++f1)
        {
            if (f1->userid == k)
            {
                cout << "Enter return day (as number) :- ";
                cin >> returnday;
                calculatefine();
            }
        }
    }
};

int main()
{
    int ch;
    Issue i1;
    do
    {
        cout << endl;
        cout << "Enter your choice\n";
        cout << "0. Exit\n";
        cout << "1. Admin block \n";
        cout << "2. creat account \n";
        cout << "3. Student block \n";
        // cout << "4. issue book \n";
        // cout << "5. Return a book (fine calculation)\n";
        cout << "Your choice: ";
        cin >> ch;
        cout << endl;
        string username, password;

        switch (ch)
        {
        case 1:
            cout << "enter username :-";
            cin >> username;
            cout << "enter password :-";
            cin >> password;
            if (username == "Admin@123" && password == "1234")
            {
                char c;
                while (c != 'D')
                {
                    cout << "enter you choice's\n"
                         << "A. Add new book\n"
                         << "B. Display All Book's\n"
                         << "C. User Detail's\n"
                         << "D. exit " << endl;
                    cout << "Enter the your choice :-";
                    cin >> c;
                    switch (c)
                    {
                    case 'A':
                        i1.set_type();
                        cout << "\n--- Thank you for entering your book details ---" << endl;
                        break;

                    case 'B':
                        cout << endl;
                        i1.Display();
                        cout << "\n--- Your Book info is displayed on the screen ---" << endl;
                        break;
                    case 'C':
                        cout << endl;
                        cout << "all user details are :- " << endl;
                        i1.UserDetails();
                        break;
                    default:
                        cout << "invailid character " << endl;
                    }
                }
            }
            else
                cout << "wrong user name and  password !!" << endl;

            break;

        case 2:
            cout << endl;
            i1.Creataccount();
            cout << "account creat success " << endl;
            break;
        case 3:
            char i;
            while (i != 'd')
            {   string  k;
                cout << "a. Display All Book's\n"
                     << "b. Issue Book \n"
                     << "c. Return Book's \n"
                     << "d. Exit " << endl;
                cout << "Enter the your choice :-";
                cin >> i;
                switch (i)
                {
                case 'a':
                    i1.Display();
                    cout << "\n--- Your Book info is displayed on the screen ---" << endl;
                    break;

                case 'b': cout<<endl;
                    cout << "Enter the user id :- ";
                    cin >> k;
                    for (vector<information>::iterator f1 = USER.begin(); f1 != USER.end(); ++f1)
                    {
                        if (f1->userid == k)
                        {
                            i1.issuebook();
                            cout << "\n--- Your book is issued ---" << endl;
                            cout << "--- Thank you for using our services ---" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Wrong Id " << endl;
                        }
                    }
                    break;
                case 'c':
                    i1.returnbook();
                    cout << endl;
                    break;

                case 'd':
                    cout << "Exting!!" << endl;
                default:
                    cout << "invailid no." << endl;
                }
            }
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid number, try again!" << endl;
        }
    } while (ch != 0);

    return 0;
}