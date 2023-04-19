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
	void addNewspaper() {
		string title;
		string owner;
		int pages;
		int buf;
		cout << "Введите количество записей" << endl;
		cin >> buf;
		num_papers = buf;
		if (buf == NULL)
		{
			cout << "размер вводится положительной не дробной цифрой";
			
		}
		else {


			for (int i = 0; i <= buf; i++)
			{
				for (int i = 0; i < num_papers; i++) {
					if (papers[i] == NULL) {
						//идёт сохранение указателей экземпляра газеты в массив 
						//перед этим ишется первый пустой элемент массива
						cout << "Введите название газеты" << endl;
						cin >> title;
						cout << "Введите название компании" << endl;
						cin >> owner;
						cout << "Введите количество страниц" << endl;
						cin >> pages;
						papers[i] = new Newspaper;
						papers[i]->title = title;
						papers[i]->owner = owner;
						papers[i]->pages = pages;
						break;
					}
					cout << "Запись успешно добавлена в массив" << endl;
				}
				
			}
			cout << "Запись успешно добавлена";
		}
	}
	// просто сортировка
	void sortNewspapers() {
		for (int i = 0; i < num_papers - 1; i++) {
			for (int j = i + 1; j < num_papers; j++) {
				if (papers[i]->pages > papers[j]->pages)
				{
					Newspaper* temp = papers[i];
					papers[i] = papers[j];
					papers[j] = temp;
				}
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
	setlocale(LC_ALL, "Russian");
	PostBox postbox(5);
	postbox.addNewspaper();
	postbox.saveToFile("newspapers.txt");
	return 0;
}