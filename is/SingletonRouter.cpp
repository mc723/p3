	/*
		Creates A Singleton Router
		@Author = Marcus
		
	*/

	#include <iostream>
	#include  "../ip/ac_tlm_mem/ac_tlm_mem.h"
	using namespace std;
	using user::ac_tlm_mem;
	class SingletonRouter
	{
	private:
	    static bool instance; //first, or not ?
	    static SingletonRouter *singleInstance; //router,itself
	    SingletonRouter()
	    {
		//private constructor
	    }
	public:
	    static SingletonRouter* getInstance();
	    void READ(); //my methods
	    void WRITE();
	    ~SingletonRouter() //default constructor
	    {
		instance = false; //start with no instance
		ac_tlm_mem mem("mem"); //my memory :)
		  
	    }
	};

	bool SingletonRouter::instance = false;
SingletonRouter* SingletonRouter::singleInstance = NULL;
SingletonRouter* SingletonRouter::getInstance()
{
    if(! instance) //if first
    {
        singleInstance = new SingletonRouter(); //new
        instance = true; //other router, no more!
        return singleInstance;
    }
    else
    {
        return singleInstance; //already exists
    }
}

void SingletonRouter::READ() //it will read mem
{
	cout << "READ" << endl;
}

void SingletonRouter::WRITE() // and write
{
	cout << "WRITE" << endl;
}

/*
int main() //just for testing
{
    SingletonRouter *sc1,*sc2;
    sc1 = SingletonRouter::getInstance();
    sc1->READ();
    sc2 = SingletonRouter::getInstance();
    sc2->WRITE();

    return 0;
}

*/
