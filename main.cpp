#include <iostream>
// #include <string>
#include "MyString.h"

using namespace std;

int main()
{
    // string s = "abhishek";
    // cout << s;
    MyString s("Abhishek Kumar");
    cout << s << endl;

    MyString t = "Ritesh";
    cout << t << endl;

    cout << "T length : " << t.size() << endl;

    cout << s[2] << endl;

    s += t;

    cout << "s+t =" << s << endl;

    t.append("b");
    cout << t << endl;

    cout << "Find res " << s.find("b") << endl;

    s.erase(1, 17);
    cout << s << endl;
    return 0;
}