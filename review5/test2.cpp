#include <iostream>
#include <pthread.h>
#include <unistd.h>
using std::cout;
using std::endl;

class Student
{
public:
    Student();
    ~Student();
    void print();
    void *operator new(size_t n);
    void *operator new[](size_t n);
    void operator delete(void *n);
    void operator delete[](void *n);

private:
    int _id;
    char *name;
};

Student::Student()
{
    cout << "Student" << endl;
}

Student::~Student()
{
    cout << "~Student()" << endl;
}

void *Student::operator new(size_t n)
{
    cout << "overload new() " << endl;
    void *ret = (Student *)malloc(n);
    return ret;
}

void *Student::operator new[](size_t n)
{
    cout << "overload new[]()" << endl;
    void *ret = (Student *)malloc(n);
    return ret;
}

void Student::operator delete(void *del)
{
    cout << "overload delete" << endl;
    if (del)
    {
        free(del);
        del = NULL;
    }
}

void Student::operator delete[](void *del)
{
    cout << "overload delete[]" << endl;
    if (del)
    {
        free(del);
        del = NULL;
    }
}

int main()
{
    // Student *s = new Student[3]();
    // delete[] s;

    Student *s2 = new Student();
    delete s2;

    return 0;
}
