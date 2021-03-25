#include <iostream>
#include "std_lib_facilities.h"

struct Person {
public: 
    Person(){
        first_name = "";
        second_name = "";
        age = 0;
    }
    Person(string fn,string sn, int aa){
        minAge = 0;
        maxAge = 150;
        
        if(aa < maxAge && aa > minAge){
            if(nameOk(fn, sn)){
            first_name = fn;
            second_name = sn;
            age = aa;
            }else{
                error("A név nem tartalmazhat speciális karaktereket!");
            }
        }else{
            error("Nem jó kor! (min: 1, max:149)");
        }
        
    }

    string getName() const{
        return first_name + " " + second_name;
    }

    int getAge() const{
        return age;
    }
    friend ostream& operator<<(ostream& os, const Person& p){
        return os << "Person name: " << p.getName() << " , person age: " << p.getAge() <<endl;
    }

    friend istream& operator>>(istream& is, Person& p){
        string first_name;
        string second_name;
        int age; 
        cin >> first_name >> second_name >> age;
        Person newPerson(first_name, second_name, age);
        p = newPerson;
        return is;
    }
private:
    string first_name;
    string second_name;
    int age;
    int minAge;
    int maxAge;
    char specChars[14] = {';' , ':', '"', '\'', '[', ']', '*', '&', '^', '%', '$', '#', '@', '!'};
    
    bool nameOk(string fn, string sn){
                
        for(int i = 0; i < (sizeof(specChars)/sizeof(*specChars)); i++){
            if(fn.find(specChars[i])  != std::string::npos){
                return false;
            }
            if(sn.find(specChars[i])  != std::string::npos){
                return false;
            }
        }
        return true;
    }


};



int main()
{
    
    vector<Person> people;
    while(cin){
        Person newPerson;
        cin >> newPerson;
        cout << newPerson;
        people.push_back(newPerson);
    }
	return 0;
}