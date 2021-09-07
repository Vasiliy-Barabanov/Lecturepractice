#include <iostream>
#include <Windows.h> 
#include "strutil.h"

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char strTest0[8] = "asaboba";
	char aTest0[6] = "aboba";	
	if (srtConteins(aTest0, strTest0) != 2)
		cout << "TEST FAILD" << endl;
	else cout << "TEST COMPLETED SUCCSESSFULLY" << endl;

	char strTest1[1000] = "string";
	char aTest1[500] = "ing";
	if (srtConteins(aTest1, strTest1) != 3)
		cout << "TEST FAILD" << endl;
	else cout << "TEST COMPLETED SUCCSESSFULLY" << endl;

	char strTest2[1000] = "striiing";
	char aTest2[500] = "ing";
	if (srtConteins(aTest2, strTest2) != 5)
		cout << "TEST FAILD" << endl;
	else cout << "TEST COMPLETED SUCCSESSFULLY" << endl;

	char strTest3[1000] = "asdfghj";
	char aTest3[500] = "cv";
	if (srtConteins(aTest3, strTest3) == -1)
		cout << "TEST COMPLETED SUCCSESSFULLY" << endl;
	else cout << "TEST FAILD" << endl;

	char str[1000];
	char a[500];

	cout << "введите строку в которой будете искать (str): " << endl;
	cin.getline(str, 1000);
	cout << "введите строку которую булете искать (a): " << endl;
	cin.getline(a, 500);
	cout << srtConteins(a, str) + 1;
}
