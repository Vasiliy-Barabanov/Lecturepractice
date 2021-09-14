#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class FooString {
	char* buf;
	int size;
public:

	FooString(char* tbuf) {		 
	    int g = strlen(tbuf);
		this->size = g + 1;
		this->buf = new char[g+1];
		for (int i = 0; i <= g; i++) {
			buf[i] = tbuf[i];
		}
	}
	
	FooString(const FooString& other){ //конструктор копирования
		this->size = other.size;
		this->buf = new char[other.size];
		for (int i = 0; i < other.size; i++) {
			this->buf[i] = other.buf[i];
		}
	}

	void show() {
		for (int i = 0; buf[i] !='\0'; i++) {
			cout << buf[i];
		}
		cout << endl;
	}
	bool compare(FooString str) {
		int i = 0;
		while (buf[i] != '\0' || str.buf[i] != '\0') {

			if (buf[i] != str.buf[i]) {
				return false;
			}

			++i;
		}
		return true;
	}
	~FooString() {
		delete[] buf;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char atest[] = "dssd";
	char btest[] = "dssd";
	FooString hn(atest);
	FooString hd(btest);
	if (hn.compare(hd) == 0)
		cout << "TEST FAILD" << endl;
	else cout << "TEST COMPLETED SUCCSESSFULLY" << endl;
	char a1test[] = "dsd";
	char b1test[] = "dssd";
	FooString hn1(a1test);
	FooString hd1(b1test);
	if (hn1.compare(hd1) != 0)
		cout << "TEST FAILD" << endl;
	else cout << "TEST COMPLETED SUCCSESSFULLY" << endl;
	char a2test[] = "ds d";
	char b2test[] = "dssd";
	FooString hn2(a2test);
	FooString hd2(b2test);
	if (hn2.compare(hd2) != 0)
		cout << "TEST FAILD" << endl;
	else cout << "TEST COMPLETED SUCCSESSFULLY" << endl;

	char a[1000];
	char b[1000];
	cin.getline(a, 1000);
	cin.getline(b, 1000);
	FooString n(a);
	FooString d(b);
	n.show();
	d.show();
	cout << n.compare(d);
}