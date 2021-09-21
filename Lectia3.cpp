
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Protocol
{
public:
	virtual void send(char* buf, int len) = 0;
};

class BinaryProtocol:public Protocol
{
public:
	void send(char* buf, int len) {
		for (int h = 0; h < len; h++) {
			int n = static_cast<int>(buf[h]);
			char d[8];
			int i = 7;
			for (int j = 1; j <= 8; j++) {
				if (n % 2 == 1) d[i] = '1';
				else d[i] = '0';
				i = i--;
				n = n / 2;
			}
			for (int j = 0; j < 8; j++) {
				cout << d[j];
			}
			cout << ' ';
		}		
	}
};

class HexProtocol :public Protocol
{
public:
	void send(char* buf, int len) {
		for (int h = 0; h < len; h++) {
			int n = static_cast<int>(buf[h]);
			char d[4];
			int i = 3;
			for (int j = 0; j < 2; j++) {
				if (n % 16 < 10) {
					d[i] = char(int('0') + n % 16);
				}
				else {
					switch (n % 16) {
					case 10:
						d[i] = 'A';
						break;
					case 11:
						d[i] = 'B';
						break;
					case 12:
						d[i] = 'C';
						break;
					case 13:
						d[i] = 'D';
						break;
					case 14:
						d[i] = 'E';
						break;
					case 15:
						d[i] = 'F';
						break;
					}
				}
				i = i--;
				n = n / 16;
			}
			d[0] = '0';
			d[1] = 'x';
			for (int j = 0; j < 4; j++) {
				cout << d[j];
			}
			cout << ' ';
		}
	}
};

void sendAll(Protocol** p, int number_of_protocols) {
	char g[200];
	cin >> g;	
	for (int i = 0; i < number_of_protocols; i++) {
		p[i]->send(g, strlen(g));
		cout << endl;
	}
}

void fileRead(string n) {
	string s;
	int k = 0;
	ifstream f;
	f.open(n);
	while (!f.eof()) {
		f >> s;
		k++;
	}
	f.close();
	f.open(n);
	Protocol** p = new Protocol * [k];
	int i = 0;
	while (!f.eof()) {
		f >> s;
		if (s == "HexProtocol") {
			p[i] = new HexProtocol;
		}		
		else p[i] = new BinaryProtocol;
		i++;
	}
	f.close();
	sendAll(p, k);
	delete[] p;
}

int main()
{
	HexProtocol a;
	char d[] = "ijklmn";
	a.send(d, 5);
	string filename;
	cout << endl;
	cin >> filename;
	fileRead(filename);
}