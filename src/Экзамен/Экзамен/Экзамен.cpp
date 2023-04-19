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
	// добавление газеты
	void addNewspaper(string title, string owner, int pages) {
	
		for (int i = 0; i < num_papers; i++) {
			if (papers[i] == NULL) {
				//идёт сохранение указателей экземпляра газеты в массив 
				//перед этим ишется первый пустой элемент массива
				papers[i] = new Newspaper;
			    papers[i]->title = title;
				papers[i]->owner = owner;
				papers[i]->pages = pages;
				break;
			}
		}
	}
	//cj[hfytybt d afqlk
	void saveToFile(string filename) {
		ofstream fout(filename);
		for (int i = 0; i < num_papers; i++) {
			if (papers[i] != NULL) {
				fout << papers[i]->title << endl;
				fout << papers[i]->owner << endl;
				fout << papers[i]->pages << endl;
			}
		}
		// закрываем файл
		fout.close();
	}
};
int main() {
	
	return 0;
}