#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

#define N 5
#define SUB 5

class Person
{
protected:
    char name[30];
    char branch[10];

public:
    Person()
    {
        strcpy(name, "NA");
        strcpy(branch, "NA");
    }

    Person(char n[], char b[])
    {
        strcpy(name, n);
        strcpy(branch, b);
    }
};

class Student : public Person
{
    int roll;
    int marks[SUB];
    int total;
    float per;
    char grade;
    static int count;

public:
    Student()
    {
        roll = 0;
        total = 0;
        per = 0;
        grade = 'F';
        for (int i = 0; i < SUB; i++)
        {
            marks[i] = 0;
        }
    }

    Student(int r, char n[], char b[]) : Person(n, b)
    {
        roll = r;
        total = 0;
        per = 0;
        grade = 'F';
        for (int i = 0; i < SUB; i++)
        {
            marks[i] = 0;
        }
    }

    ~Student()
    {
    }

    void getdata();
    void calculate();
    void putdata();
    void writeToFile(ofstream &fout);
    int readFromFile(ifstream &fin);

    int operator>(Student s)
    {
        if (per > s.per)
            return 1;
        else
            return 0;
    }

    int getRoll()
    {
        return roll;
    }

    float getPer()
    {
        return per;
    }

    char getGrade()
    {
        return grade;
    }

    char *getName()
    {
        return name;
    }

    static int getCount()
    {
        return count;
    }
};

int Student::count = 0;

void Student::getdata()
{
    cout << "Enter roll number: ";
    cin >> roll;
    cout << "Enter name (no spaces): ";
    cin >> name;
    cout << "Enter branch: ";
    cin >> branch;

    for (int i = 0; i < SUB; i++)
    {
        cout << "Enter marks of subject " << i + 1 << ": ";
        cin >> marks[i];
        while (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Wrong marks, enter again (0 to 100): ";
            cin >> marks[i];
        }
    }
    count++;
    calculate();
}

void Student::calculate()
{
    int fail = 0;
    total = 0;

    for (int i = 0; i < SUB; i++)
    {
        total = total + marks[i];
        if (marks[i] < 40)
        {
            fail = 1;
        }
    }

    per = (float)total / SUB;

    if (fail == 1)
        grade = 'F';
    else if (per >= 75)
        grade = 'A';
    else if (per >= 60)
        grade = 'B';
    else if (per >= 50)
        grade = 'C';
    else if (per >= 40)
        grade = 'D';
    else
        grade = 'F';
}

void Student::putdata()
{
    cout << left << setw(8) << roll;
    cout << setw(15) << name;
    cout << setw(8) << branch;
    cout << right << setw(8) << total;
    cout << setw(10) << fixed << setprecision(2) << per;
    cout << setw(8) << grade << endl;
}

void Student::writeToFile(ofstream &fout)
{
    fout << roll << " " << name << " " << branch << " ";
    for (int i = 0; i < SUB; i++)
    {
        fout << marks[i] << " ";
    }
    fout << endl;
}

int Student::readFromFile(ifstream &fin)
{
    fin >> roll >> name >> branch;
    for (int i = 0; i < SUB; i++)
    {
        fin >> marks[i];
    }

    if (fin.fail())
        return 0;

    calculate();
    return 1;
}

void printHeader()
{
    cout << left << setw(8) << "Roll";
    cout << setw(15) << "Name";
    cout << setw(8) << "Branch";
    cout << right << setw(8) << "Total";
    cout << setw(10) << "Percent";
    cout << setw(8) << "Grade" << endl;
    cout << "------------------------------------------------------------" << endl;
}

void sortStudents(Student s[], int n)
{
    Student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j + 1] > s[j])
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void searchStudent()
{
    int r;
    int flag = 0;
    char nm[] = "NA";
    char br[] = "NA";
    Student temp;
    Student found(0, nm, br);

    cout << "Enter roll number to search: ";
    cin >> r;

    ifstream fin("result.txt");
    if (!fin)
    {
        cout << "File not opened" << endl;
        return;
    }

    while (temp.readFromFile(fin))
    {
        if (temp.getRoll() == r)
        {
            flag = 1;
            found = temp;
            break;
        }
    }
    fin.close();

    if (flag == 1)
    {
        cout << endl;
        printHeader();
        found.putdata();
    }
    else
    {
        cout << "Roll number " << r << " not found" << endl;
    }
}

int main()
{
    Student s[N];
    Student r[N];
    int i, n = 0;
    int a = 0, b = 0, c = 0, d = 0, f = 0;
    char choice;

    cout << "***** STUDENT GRADING SYSTEM *****" << endl;

    for (i = 0; i < N; i++)
    {
        cout << endl << "Student " << i + 1 << endl;
        s[i].getdata();
    }

    ofstream fout("result.txt");
    if (!fout)
    {
        cout << "File not created" << endl;
        return 0;
    }
    for (i = 0; i < N; i++)
    {
        s[i].writeToFile(fout);
    }
    fout.close();
    cout << endl << "Data saved in result.txt" << endl;

    ifstream fin("result.txt");
    if (!fin)
    {
        cout << "File not opened" << endl;
        return 0;
    }
    while (n < N && r[n].readFromFile(fin))
    {
        n++;
    }
    fin.close();

    sortStudents(r, n);

    cout << endl << "***** RESULT SHEET *****" << endl;
    printHeader();
    for (i = 0; i < n; i++)
    {
        r[i].putdata();
    }

    for (i = 0; i < n; i++)
    {
        if (r[i].getGrade() == 'A')
            a++;
        else if (r[i].getGrade() == 'B')
            b++;
        else if (r[i].getGrade() == 'C')
            c++;
        else if (r[i].getGrade() == 'D')
            d++;
        else
            f++;
    }

    cout << endl << "Topper: " << r[0].getName() << " with ";
    cout << fixed << setprecision(2) << r[0].getPer() << "%" << endl;
    cout << "A = " << a << "  B = " << b << "  C = " << c;
    cout << "  D = " << d << "  F = " << f << endl;
    cout << "Total students: " << Student::getCount() << endl;

    do
    {
        cout << endl;
        searchStudent();
        cout << endl << "Search again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you" << endl;
    return 0;
}
