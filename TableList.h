
#include "Table.h"
#include "List.h"
#include <string>
#include <iostream>
#include <iomanip>

class TableList : public Table {
private:
	List* entries;
	static const int SIZE = 120001;
public:
	TableList();
	~TableList();
	void add(const std::string& key);
	int del(const std::string& key);
	int get(const std::string& key);
	void print() const;
	bool is_empty() const;
	bool is_full() const;
};

TableList::TableList() {
    entries = new List[SIZE];
}

TableList::~TableList() {
    delete[] entries;
}

void TableList::add(const std::string& item) {

    counter = 1;
    entries->add(item, counter);
}

int TableList::del(const std::string& item) {
    counter = 1;
    return entries->del(item, counter);
}

void TableList::print() const {
    if (is_empty()) {
        std::cout << "В таблице нет элементов" << std::endl;
        return;
    }
    std::cout <<
        std::setw(30) << std::left << "WORD" <<
        std::setw(30) << std::left << "AMOUNT" << std::endl;

    for (int i = 0; i < SIZE; i++)
        if (!entries[i].is_empty())
            entries[i].print();
}

int TableList::get(const std::string& item) {
    int res;
    counter = 1;
    res = entries->get(item, counter);
    return res;
}

bool TableList::is_empty() const {
    for (int i = 0; i < SIZE; i++)
        if (!entries[i].is_empty())
            return false;
    return true;
}

bool TableList::is_full() const {
    Link* tmp;
    tmp = new Link;
    return tmp == nullptr;
}
