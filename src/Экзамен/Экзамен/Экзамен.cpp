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
};
int main() {
	
	return 0;
}