#include <iostream>

class B1{
    public:
        virtual void vf(){
            std::cout << "B1::VF" << std::endl;
        }
        void f(){
            std::cout << "B1::F" << std::endl;
        }
        virtual void pvf() = 0;// ezt muszáj felülírni azoknak az osztályoknak akik ebből az osztályból származnak
};

struct D1 : B1{ 
    void vf() override {
            std::cout << "D1::VF" << std::endl;
    }
    void f(){
            std::cout << "D1::F" << std::endl; 
    }
};


struct D2 : D1 {
    virtual void pvf() override {
        std::cout << "D2::PVF" << std::endl;
    }
};

class B2 {
    public:
        virtual void pvf() const = 0;
};

struct D21 : B2 {
    std::string str = "string";
     virtual void pvf() const override {
        std::cout << str << std::endl;
    }
};

struct D22 : B2 {
    int num = 22;
     virtual void pvf() const override {
        std::cout << num << std::endl;
    }
};


void f(const B2& b2){
    b2.pvf();
}

int main()
{
    
    /*std::cout << "B1 functions:" << std::endl;

    B1 b1;
    b1.vf();
    b1.f();

    std::cout << "D1 functions:" << std::endl;

    D1 d1;
    d1.vf();
    d1.f();
    //4 .feladat: Nem az ős fugvényét hívja meg, hanem a sajátját

    std::cout << "B1 ref functions:" << std::endl;

    B1& bref {d1};
	bref.vf();
	bref.f();*/

    std::cout << "D2 functions:" << std::endl;

    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    std::cout << "B2 functions:" << std::endl;

    D21 d21;
    D22 d22;
    f(d21);
    f(d22);
	

	return 0;
}