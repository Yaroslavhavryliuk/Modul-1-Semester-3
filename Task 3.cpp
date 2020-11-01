#include <iostream>
using namespace std;
#include <list>
#include<string>
//Task 3 (20 % points + bonus).We have a virtual basic class  Base, and three subclasses Alpha, Beta, Gamma.Every object of class Base has number 
//number N(unique for every subclass, starts from 1 for the first object of the subclass, increases by 1 for every next object),
//and nested list of objects of class Base.Destructors make changes in global variable S : destructor Base S : = 2S - N + 18, destructor Alpha 
//S : = S - N + 18, дdestructor Beta S : = S + N, destructor Gamma S : = S + 3N.
//1.	Realise that classes, create and delete the number of objects, print the value of S.
//2.	Realise the function, which will take the list of objects and predict the value of global variable after deleting of objects.
//3     For the number of objects  M(which includes independent and nested objects) to sort out all the combinations of objects, and print the value of S for every one. Let M < 7.
//
int S = rand() % 100;
class Base {
public:
	virtual string getList() = 0;
	int N;
	~Base()
	{
		S = 2 * S - N + 18;
	}
};

class Alpha : Base
{
public:
	virtual string getList()
	{
		return "any str";
	}
	int N;
	Alpha();
	~Alpha();
	static int counter;
	list<Alpha> inner_list;

private:

};

Alpha::Alpha()
{

}

Alpha::~Alpha()
{
	S = S - N + 18;
}

class Beta :Base
{
public:
	virtual string getList()
	{
		return "base";
	}
	int N;
	static int counter;
	Beta() { S = S + N; }
	~Beta() {}
	list<Beta> inner_list;


private:

};

class Gamma : Base
{
public:
	virtual string getList()
	{
		return "Gamma";
		counter++;
	}
	int N;
	int counter = 0;
	Gamma() { S = S + 3 * N; }
	~Gamma() {}
	list<Gamma> inner_list;
private:

};

void create_any_object()
{
	Alpha first_obj;
	list<Alpha> list_alphas();
	list<Beta>  beta_obj;
	list<Gamma> gamma_object;
}

int main()
{
	cout << "condition before making changes: " << S << endl;
	create_any_object();
	create_any_object();
	create_any_object();
	cout << "\ncondition after making changes" << S;
}