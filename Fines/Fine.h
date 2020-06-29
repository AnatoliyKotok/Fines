#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;
class Fine
{
public:
	void setName(const string& name);
	const string& GetName();
	void setDate(const string& date);
	const string& GetDate();
	void setSum(float& sum);
	float GetSum();
	Fine(const string name, const string data, float sum) {
		setName(name);
		setDate(data);
		setSum(sum);
	}
	void print() {
		cout << "\tName->" << name << "\n";
		cout << "\tDate->" << date << "\n";
		cout << "\tSum->" << sum << "\n";
	}
private:
	string name;
	string date;
	float sum;
};
class CarNode {
public:
	CarNode() = default;
	bool isEmpty()const;
	void AddNode(int number,Fine* fine);
	void print()const;
	void printByNumber(int number);
	void deleteByNumber(int number);
private:
	struct Node {
		int number;
		list<Fine*>fines;
		void show() {
			for (auto el : fines) {
				el->print();
			}
		}
		Node* right;
		Node* left;
		Node* parent;

	};
	Node* root = nullptr;
	void printHelper(Node* p)const;
    auto fineNode(Node* node, int d);
};

