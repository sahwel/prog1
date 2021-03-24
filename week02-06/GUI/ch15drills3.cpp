#include <iostream>
#include "std_lib_facilities.h"

struct Person {
public: 
    person(string nn, int aa){
        name = nn;
        age = aa;
    }

    string getName(){
        return name;
    }

    int getAge(){
        return age;
    }

private:
    string name;
    int age;

    
};

int main()
{
    Person goofy = new Person("Goofy", 63);
    cout << goofy.getName() << endl;

	return 0;
}