#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Newspaper {
	string title;
	string owner;
	int pages;
};

class PostBox {
private:
	Newspaper** papers;
	int num_papers;
public:
	// конструктор
	PostBox(int size) {
		num_papers = size;

		//выделение памяти
		papers = new Newspaper * [num_papers];

		//инициализация
		for (int i = 0; i < num_papers; i++) {
			papers[i] = NULL;
		}
	}

	// деструктор
	~PostBox() {
		
		for (int i = 0; i < num_papers; i++) {
			if (papers[i] != NULL) {
				delete papers[i];
			}
		}

		//освобождение памяти
		delete[] papers;
	}

};
int main() {
	
	return 0;
}