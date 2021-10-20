#include <iostream>
#include <vector>
#include<string>

using namespace std;


template <typename T, typename K >
class MyHesh
{
private:
    struct s {
        T key;
        K value;
        s* next;
    };
    s* mass;
public:
    MyHesh() {
        for (int i = 0; i <= 255; i++) {
            mass = new s[256];          
            mass[i].key = NULL;
            mass[i].next = nullptr;
        }
    }
    void incert (T key, K value) {
        for (int i = 0; i<=255; i++) {
            if (mass[i].key == key) {
                s* t = new s; 
                s* m = &mass[i];
                t->key = key;
                t->value = value;
                t->next = nullptr;
                while (m->next != nullptr) {
                    m = m->next;
                }
                m->next = t;
                return;
            }
        }
        for (int i = 0; i <= 255; i++) {
            if (mass[i].key == NULL) {
                mass[i].key = key;
                mass[i].value = value;
                mass[i].next = nullptr;
                return;
            }
        }
    }
    void find(T key) {
        for (int i = 0; i <= 255; i++) {
            if (mass[i].key == key) {
                s m = mass[i];
                int i = 0;  
                cout << m.value << ' ';
                while (m.next != nullptr) {
                    m = *m.next;
                    cout << m.value << ' ';                  
                }    
                cout << endl;
                return;
            }          
        }
        cout << "NO" << endl;       
    }
    void change(T key, K newvalue) {
        for (int i = 0; i <= 255; i++) {
            if (mass[i].key == key) {
                s* m = &mass[i];
                deletehash(key);
                mass[i].key = key;
                mass[i].value = newvalue; 
                mass[i].next = nullptr;
                return;
            }
        }
        cout << "NO" << endl;
    }
    void deletehash(T key) {
        for (int i = 0; i <= 255; i++) {
            if (mass[i].key == key) {
                s ptr1 = mass[i]; 
                s* ptr2 = mass[i].next;
                if (ptr2 != nullptr) {
                    while (ptr2->next != nullptr) {
                        ptr2 = ptr2->next;
                        delete ptr1.next;
                        ptr1 = *ptr2;
                    }
                    delete ptr2;
                }
                mass[i].key = NULL;
                mass[i].value = "";
                mass[i].next = nullptr;
                break;
            }        
        }
    }
    ~MyHesh() {     
            delete[] mass;     
    }
};


int main()
{
    MyHesh<int, string> a;
    a.incert(1, "jfjfj");
    a.incert(1, "jfddd");
    a.incert(1, "ffff");
    a.find(1);
    a.change(1, "jjjjj");
    a.find(1);
    a.deletehash(1);
    a.find(1);
}