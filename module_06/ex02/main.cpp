#include <iostream>
#include <ctime>

class Base                         { public: virtual ~Base( void ) {} };
class A:    public Base            {};
class B:    public Base            {};
class C:    public Base            {};

Base        *generate(void);
void        identify(Base* p);
void        identify(Base& p);

//-------------------------------------------------------------------------------------------

int main()
{
    Base *newBase = generate();
    identify(newBase);
    identify(*newBase);
    
    return 0;
}


Base        *generate(void)
{
    srand (static_cast<unsigned int>(time(NULL)));
    int randomNumber = rand() % 3;

    if (randomNumber == 0)
    {
        std::cout << "Creating an instance of A class!" << std::endl;
        return new A();
    }
    else if (randomNumber == 1)
    {
        std::cout << "Creating an instance of B class!" << std::endl;
        return new B();
    } 
    else
    {
        std::cout << "Creating an instance of C class!" << std::endl;
        return new C();
    } 
}
    

void        identify(Base *p)
{
    std::cout << std::endl << "Trying to indentify the class from the POINTER to a parent..." << std::endl;

    {
        A *ptr = dynamic_cast<A *>(p);
        if (ptr)
            std::cout << "It's A class!" << std::endl;
    }
    {
        B *ptr = dynamic_cast<B *>(p);
        if (ptr)
            std::cout << "It's B class!" << std::endl;
    }
    {
        C *ptr = dynamic_cast<C *>(p);
        if (ptr)
            std::cout << "It's C class!" << std::endl;
    }

    std::cout << std::endl;
    
}

void        identify(Base & p)
{
    std::cout << std::endl << "Trying to indentify the class from the REFERENCE to a parent..." << std::endl;

    try
    {
        A & ref = dynamic_cast<A &>(p);
        static_cast<void>(ref);
        std::cout << "It's A class!" << std::endl;
    }
    catch(const std::bad_cast& e) {}

    try
    {
        B & ref = dynamic_cast<B &>(p);
        static_cast<void>(ref);
        std::cout << "It's B class!" << std::endl;
    }
    catch(const std::bad_cast& e) {}
    
    try
    {
        C & ref = dynamic_cast<C &>(p);
        static_cast<void>(ref);
        std::cout << "It's C class!" << std::endl;
    }
    catch(const std::bad_cast& e) {}
    
    std::cout << std::endl;
    
}
