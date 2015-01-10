#include <iostream>

using namespace std;

class A{
public:

	void print(){
		cout<<"A non-virtual print()"<<endl;
	}

	virtual void vprint(){
		cout<<"A virtual vprint()"<<endl;
	}
};


class B:public A{
public:
	void print(){
		cout<<"B non-virtual print()"<<endl;
	}
	/*
	virtual void vprint(){
		cout<<"B virtual vprint()"<<endl;
	}
	*/
};

class C: public B{
public:

	void print(){
		cout<<"C non-virtual print()"<<endl;
	}


	virtual void vprint(){
		cout<<"C virtual print()"<<endl;
	}
};

int main(){
	A *aptr = new B;
	//A is starting point to find the virtual func
	//B is the ending point to find, and nothing to do with C
	aptr->print();
	//because in B there is no virtual func defined
	//therefore even though the func in A is virtual, it could only call itself version
	//and will not go into C to find, even though C inherits B but new B limits the destination
	aptr->vprint();


	A *aaptr = new C;
	aaptr->vprint();
	//using scoping operator to 
	//limit the scope and statically call the base virtual version
	//rather than go down
	aaptr->A::vprint();

	//what's more , if A both inherits public B and C
	//it does not mean that B and C could share their functions afterwards
}
