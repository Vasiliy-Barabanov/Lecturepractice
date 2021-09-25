#include <iostream>
using namespace std;
class Image
{
	friend ostream& operator<<(std::ostream&, const Image&);
	friend bool operator ==(Image&, Image&);

private:
	int* img;
	int mx;
	int my;
public:
	Image(int tmx, int tmy) :mx(tmx), my(tmy) {
		img = new int[mx * my];
		for (int i = 0; i < my * mx; i++) {
			img[i] = 0;
		}
	}
	virtual ~Image() {
		delete[] img;
	}
	int get(int x, int y) {
		if (x >= mx || y >= my || x < 0 || y < 0)
			throw - 1;
		return img[y * my + x];
	}

	int set(int x, int y, int color) {
		if (x >= mx || y >= my || x < 0 || y < 0)
			throw -1;
		img[y * my + x] = color;
	}
};
ostream& operator<<(ostream& out, const Image& d1) {
	for (int i = 0; i < d1.my; i++) {
		for (int j = 0; j < d1.mx; j++)
			out << d1.img[i * d1.my + j] << ' ';
		out << endl;
	}
	return out;
}

bool operator ==(Image& arrInt, Image& arrInt2) {
	if (arrInt.mx != arrInt2.mx || arrInt.my != arrInt2.my)
		return false;
	for (int i = 0; i < arrInt.my * arrInt2.mx; i++) {
		if (arrInt.img[i] != arrInt2.img[i])
			return false;
	}		
	return true;
}

int main()
{
	Image d(7, 7);
	for (int i = 0; i <= 7; i++) {    // заполняем массив и проверяем работу try catch
		for (int j = 0; j < 7; j++) {
			try
			{
				d.set(i, j, (i + j) % 10);
			}
			catch (int a)
			{
				cerr << "error: out_of_range: can not set this possition" << endl;
			}
		}	
	}
	for (int i = -1; i <= 1; i++) {    // выводим некоторые элементы и проверяем работу try catch
		for (int j = 5; j <= 6; j++) {
			try
			{
				cout << "d[" << i + j << "," << i << "]: " << d.get(i, j + i) << endl;
			}
			catch (int a)
			{
				cerr << "error: out_of_range: can not get this possition" << endl;
			}
		}				
	}
	cout << d << endl;
	Image d1(7, 7);
	Image d2(7, 7);
	if (d1 == d2)
		cout << "Images are equal";
	else cout << "Images are not equal";
}
