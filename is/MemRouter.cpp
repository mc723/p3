//implements a memory router to a mips processor
#include<iostream>
#include  "ac_tlm_port.H"
using namespace std;

class MemRouter{
private:

	//ac_tlm_port DM_port("DM_port", 5242880U);
	//ac_tlm_port DM_port ("DM_port",5242880U);
public:
        //ac_tlm_port DM_port("DM_port",5242880U);
	ac_tlm_port DM_port; //("DM_port", 5242880U);
	MemRouter(); //constructor
        ~MemRouter(); //destructor
};


MemRouter::MemRouter():DM_port("DM_port",5242880U)
{
	
	//DM_port(tlm)
	//DM_port("DM_port",5242880U);
	//DM_port=new ac_tlm_port("DM_port",5242880U);
	cout<<"just construct"<<endl;
}

MemRouter::~MemRouter()
{
	cout<<"just destruct"<<endl;
}

/*
int main( )
{
	MemRouter m;
	return 0;
}
*/
