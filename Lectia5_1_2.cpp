#include <iostream>
using namespace std;
template<typename T>
class Image
{
	friend ostream& operator<<(ostream& out, const Image<T>& d1) {
		for (int i = 0; i < d1.my; i++) {
			for (int j = 0; j < d1.mx; j++)
				out << d1.img[i * d1.my + j] << ' ';
			out << endl;
		}
		return out;
	}
	friend bool operator ==(Image<T>& arrInt, Image<T>& arrInt2) {
		if (arrInt.mx != arrInt2.mx || arrInt.my != arrInt2.my)
			return false;
		for (int i = 0; i < arrInt.my * arrInt2.mx; i++) {
			if (arrInt.img[i] != arrInt2.img[i])
				return false;
		}
		return true;
	}

private:
	T* img;
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
			throw - 1;
		img[y * my + x] = color;
	}
};

template <typename DataType>
class List final {
private:
	struct Node {
		Node* next;
		DataType data;
	} *head;
public:
	List(int d) {
		head = new Node(nullptr, d);
	}
	List(List&& newNode) {
		head = new Node(nullptr, 0);
		while (newNode->next != nullptr) {
			head->data = newNode->data;
			head->next = newNode->data;
		}
	}

	// move contructor;
	~List() {
		delete[] head;
	}
	void InsertNode(Node* newNode, int position) {
		Node* g = head;
		int i = 0;
		while (g->next != nullptr && i != position) {
			g = g->next;
			i++;
		}
		Node* m = g;
		if (g->next != nullptr) {
			m->next = newNode;
			g = g->next;
			newNode->next = g->next;
			delete g;
		}
		else {
			m->next = newNode;
		}
	}
	void RemoveNode(int position) {
		Node* g = head;
		int i = 0;
		while (g->next != nullptr && i != position) {
			g = g->next;
			i++;
		}
		Node* m = g;
		if (g->next != nullptr) {
			m->next = g->next->next;
			m->data = g->next->next->data;
			g = g->next;
			delete g;
		}
		else {
			m->next = nullptr;
		}
	}
	DataType& GetElement(size_t position) {
		Node* g = head;
		int i = 0;
		while (g->next != nullptr && i != position) {
			i++;
			g = g->next;
		}
		return g->data;
	}
	void PrintList() {
		Node* g = head;
		while (g->next != nullptr) {
			cout << g->data << ' ';
			g = g->next;
		}
	}
};

int main()
{
	Image<int> d(7, 7);
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
	Image<int> d1(7, 7);
	Image<int> d2(7, 7);
	if (d1 == d2)
		cout << "Images are equal";
	else cout << "Images are not equal";
}
