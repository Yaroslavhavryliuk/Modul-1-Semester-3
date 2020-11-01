#pragma once
//	Task 2 (20 % points).Make function f(x), which returns the list of integers by the next rules :
//		1.	For natural(integer positive) numbers n, f(n) = (n!– n2) mod k, k = 2, 3, …, 160
//		2.	For negative integers n, f(n) = (n4 + n3) mod 260 – numbers with the basis 4
//		3.	For real numbers d, f(d) = [exp(1 / cos(k * d))] mod 360, k = 1, 2, …, 39
//		4.	For text strings s, f(s) = kk mod 560, where k – consistent two-digit numbers from s(separated with non-number symbols)
//		5.	For pair p = (a, b), f(p) = every element from the list f(b), repeated the number of appropriate element from the list f(a)
//		6.	For the list v = [v1, …, vk], f(v) = combining of reverse lists f(vi) ([1, 2], [3, 4, 5] = > [2, 1, 5, 4, 3])
//		7.	For all other values f(x) = [4, 0, 7, 0, 8]
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <list>
#include <vector>
#include <ctime>
using namespace std;

// prototype functions
template<typename T>
void filters(std::vector<T>);
template<typename T>
void print_list(std::list<T> list, string str);

template<typename T>
void read_from_file(list<T> lst, string fileName);

//template<typename T>
vector<int> fill_vector();

long double fact(int N);

template<typename T>
void write_to_file(list<T>, string fileName);

bool IsPossitiveNumbers(vector<int> v);
bool IsNegativeNumbers(vector<int> v);





class UnitTests
{
	public:
	static void Start()
	{
		std::vector<int> generate_integer;
		std::list<int>	 new_list;
		//cout << "The list of integers from the file <<textfile.txt>>: \n";
		/*generate_integer = fill_vector();
		for (size_t i = 0; i < generate_integer.size(); i++)
		{
			cout << generate_integer[i] << " ";
		}*/
		int task_number = 1;
		/*while (task_number != 8)
		{
			task_number++;
		}*/		
		std::vector<int> v1({100,2,3,4 });
		 filters(v1); // 1 task
		 std::vector<int> v2({ -231,-2,-3,-4 });
		 filters(v2);  //2task
		std::vector<double> v3({12.3,2.3,3.3,4.3});
		filters(v3); // 3 -task --
		std::vector<double> v4({ 44,11, 22 }); //task 4
		filters(v4); //
		std::vector<double> v5({ 5 }); //task 5 --
		filters(v5); 
		std::vector<int> v6({ 1, 2, 3, 4, 5 }); //task 6
		filters(v6); //
		std::vector<double> v7({ 7, 2, 4, 6,6,9 }); //task 7
		filters(v7); 		
	}
};
template<typename T>
void filters(std::vector<T> lst)
{
	//task 6
	if (lst[0] == 1)
	{
		cout << "\n\n6.For the list v=[v1,…,vk], f(v) = combining of reverse lists f(vi) ([1,2],[3,4,5]=>[2,1,5,4,3])\n";
		list<int> v1({ (int)lst[0], (int)lst[1] }),
					v2({ (int)lst[2], (int)lst[3], (int)lst[4] });
		list<int> l(lst.begin(), lst.end());
		cout << "our start list v=[v1,...,vk]: "; print_list(l, "");
		cout << "\nour divided lists: (["; print_list(v1, ""); cout<< "], ["; print_list(v2,""); cout << "])";
		list<int> result{ (int)lst[1], (int)lst[0], (int)lst[4], (int)lst[3], (int)lst[2] };
		print_list(result, "\nresult list => ");
		return;
	}

	if (static_cast<int>(lst[0]) != lst[0]) // Is double or float numbers
	{
		cout << "\n\n3.For real numbers d, f(d) = [exp(1 / cos(k * d))] mod 360, k = 1, 2, …, 39\n";
		int k = 1;
		list<double> list_for_print(lst.begin(), lst.end());
		print_list(list_for_print, "Start list of real numbers: ");
		vector<double> vec(lst.begin(), lst.end());
		for (size_t i = 0; i < lst.size(); i++)
		{
			vec[i] = int(exp(1 / cos(k * vec[i]))) % 360; k++;
		}
		list<double> result(vec.begin(), vec.end());
		print_list(result, "\nFinal list of real numbers: ");		return;

	}

	if (lst[0] == 5)
	{
		//5.For pair p = (a, b), f(p) = every element from the list f(b), repeated the number of appropriate element from the list f(a)
		cout << "\n\n\n5.For pair p = (a, b), f(p) = every element from the list f(b), repeated the number of appropriate element from the\nlist f(a)\n";
		vector<int> a = fill_vector(),
			b = fill_vector();
		cout << "elem list f(a):  {";
		for (size_t i = 0; i < a.size(); i++)
		{
			cout << a[i] << " ";
		}
		cout << "}\nelem list f(b):  {";
		for (size_t i = 0; i < b.size(); i++)
		{
			cout << b[i] << " ";
		}
		cout << "}";
		list<int>	p;
		bool flag = true;
		int index_a = 0, index_b = 0;
		int counter = 0;
		while (index_a < b.size())
		{
			counter = 0;
			while (counter < a[index_a])
			{

				p.push_back(b[index_b]);
				counter++;
			}
			index_b++;
			index_a++;
		}
		cout << "\nFinal list f(p) (p = (a,b)): ";
		print_list(p, "");		return;


	}
	vector<int> v(lst.begin(), lst.end());

	if (IsPossitiveNumbers(v) && v[0] != 7 && v[0]!=44)
	{
		//1. For natural(integer positive) numbers n, f(n) = (n!– n2) mod k, k = 2, 3, …, 160
		cout << endl << "1.For natural(integer positive) numbers n, f(n) = (n!– n2) mod k, k = 2, 3, …, 160\n";
		//cout << "Start list of integer positive numbers: ";
		list<int> list_for_print(lst.begin(), lst.end());
		print_list(list_for_print, "Start list of integer positive numbers: ");
		int k = 2;
		list<int> res_list;
		for (size_t i = 0; i < lst.size() - 1; i++)
		{
			res_list.push_back( int(fact(lst[i]) - lst[i + 1] )  % k );
			k++;
		}
		print_list(res_list, "\nFinal list of numbers: ");
		return;

	}

	if (IsNegativeNumbers(v))
	{
		//2.	For negative integers n, f(n) = (n4 + n3) mod 260 – numbers with the basis 4

		cout << "\n\n2.For negative integers n, f(n) = (n4 + n3) mod 260: "; 
		list<int> list_for_print(lst.begin(), lst.end());
		print_list(list_for_print, "Start list of integer negative numbers: ");
		list<double> res_list;
		for (size_t i = 0; i < lst.size() ; i++)
		{
			res_list.push_back(int((pow(lst[i], 4) + pow(lst[i], 3))) % 260);
		}
		print_list(res_list, "\nFinal list of numbers: ");
		return;

	}
		
	//task 7
	else if(lst[0]==7) {
		cout << "\n\n7.For all other values f(x) = [4, 0, 7, 0, 8]";
		vector<int> vec(lst.begin(), lst.end());
		list<int> lst(lst.begin(), lst.end());
		print_list(lst, "\nStart list: ");
		for (size_t i = 0; i < lst.size(); i++)
		{
			if (i % 2 == 0)
			{
				vec[i] = 0;
			}
		}
		list<int> result(vec.begin(), vec.end());
		print_list(result, "\nFinal list: ");
		return;

	}

	//task 4
	if(lst[0]== 44)
	{
		cout << "\n\n4.For text strings s, f(s) = k^k mod 560, where k – consistent two-digit numbers from s(separated with non-number symbols)";
		list<int> lists({lst.begin(), lst.end()});
		cout << "\nStart list: ";
		list<string> list_str({ "12fd34","23<44g" });
		print_list(list_str, "");
		vector<float> l = { 12, 34, 23, 44 };
		list<int>   res;
		for (size_t i = 0; i < l.size(); i++)
		{
			res.push_back(static_cast<float>((int(pow(l[i], 2)) % 560)));
		}
		print_list(res, "\nResult list => ");
		return;
	}
}

long double fact(int N)
{
	if (N < 0) // if the negative number
		return 0; // return 0
	if (N == 0) // if the number is 0,
		return 1; // return the factorial of 0, don't be surprized, but it's 1 =)
	else // All other variants
		return N * fact(N - 1); // work recursively.
}

template<typename T>
void print_list(std::list<T> list, string str)
{
	cout << str;
	for (auto var : list)
	{
		cout << var << " ";
	}
}

//template<typename T>
vector<int> fill_vector()
{
	int size = 4;// +rand() % 10;	
	vector<int> temp_lst;
	for (size_t i = 0; i < size; i++)
	{
		temp_lst.push_back((1 + rand() % 2));
	}
	
	return temp_lst;
}

template<typename T>
void read_from_file(list<T> lst, string fileName)
{
	ifstream f_in;
	f_in.open(fileName + ".txt");
	if (f_in)
	{
		int n;
		while (f_in >> n)
			lst.push_back(n);
	}
	else
		cout << "Error opening file!" << endl;

	f_in.close();
}
template<typename T>
void write_to_file(list<T> lst, string fileName)
{
	ofstream f_out;
	vector<int> v(lst.begin(), lst.end());
	f_out.open(fileName + ".txt");
	for (size_t i = 0; i < v.size(); i++) { f_out << v[i] << " "; }
	f_out.close();
}

bool IsPossitiveNumbers(vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] < 0)
			return false;
	}
	return true;
}

bool IsNegativeNumbers(vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] > 0)
			return false;
	}
	return true;
}