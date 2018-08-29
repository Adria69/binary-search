#include <iostream>
#include "tree.h"

using namespace std;

//-------------------------KONSTRUKTORY/DESTRUKTORY-------------------------
Node::Node(int key, Node *parent)
{
	this->key = key;
	this->parent = parent;
	left = NULL;
	right = NULL;
}

Node::~Node() {}

Tree::Tree(int number, Node* root)
{
	number_ = number;
	size_ = 0;
	root_ = root;
}

Tree::~Tree()
{
	T_deleteTree();
}

Tree::Tree(const Tree& other) //konstruktor kopiujacy
{
	this->number_ = other.number_;
	this->size_ = other.size_;
	this->root_ = other.root_->N_copyNodes(nullptr);
}

//-------------------------------------------------------------------------------------------------

void Node::N_showNode(int dot) //wyswietla wezly calego drzewa
{
	dot++;
	cout << key << endl;
	if (left)
	{
		for (int i = 0; i<dot; i++)
			cout << "|";
		cout << "lewy: ";
		left->N_showNode(dot);

	}
	if (right)
	{
		for (int i = 0; i<dot; i++)
			cout << "|";
		cout << "prawy ";
		right->N_showNode(dot);
	}
	if (!left && !right) return;
}

void Tree::T_showTree() //przekierowanie do wyswietlenia wezlow drzewa
{
	if (root_)
	{
		int dot = 0;
		root_->N_showNode(dot);
	}
	else
	{
		cout << "Drzewo puste" << endl;
		return;
	}
}

void Tree::T_addElement(int nr) //dodawanie do drzewa elementu o okreslonej wartosci
{
	Node *tempN, *currentN;

	if (!root_) //drzewo nie istnieje, dodajemy pierwszy element
	{
		tempN = new Node(nr);
		root_ = tempN;
		size_++;
		return;
	}

	currentN = root_;

	while (currentN)
	{
		if (currentN->key >= nr) //lewa strona poddrzewa
		{
			if (currentN->left != NULL)
				currentN = currentN->left;
			else
			{
				tempN = new Node(nr);
				tempN->parent = currentN;
				currentN->left = tempN;
				size_++;
				return;
			}
		} //prawa strona poddrzewa
		else
		{
			if (currentN->right)
				currentN = currentN->right;
			else
			{
				tempN = new Node(nr);
				tempN->parent = currentN;
				currentN->right = tempN;
				size_++;
				return;
			}
		}
	}
}

Node* Node::N_findElementNumber(int number) //zwraca element o okreslonej wartosci
{
	if (number == this->key)
		return this;
	else if (this->key >= number&&left)
		return left->N_findElementNumber(number);
	else if (this->key<number&&right)
		return right->N_findElementNumber(number);
	else return nullptr;
}

Node* Tree::T_findElementNumber(int number) //zwraca wezel lub przekierowuje do znalezienia elementu o okreslonej wartosci
{
	if (!root_) return nullptr;
	else return root_->N_findElementNumber(number);
}

Node* Node::N_findLeftMax() //znajduje najwiekszy element w lewym poddrzewie
{
	if (right)
	{
		return right->N_findLeftMax();
	}
	else return this;
}

void Tree::T_addElementIfNotPresent(Node* subtree) //funkcja sprawdzajaca czy element nie znajduje sie w drzewie (dodaje wezel, jesli nie nalezy)
{
	if (!this->T_belongToTree(subtree->key))
		this->T_addElement(subtree->key);
}

void Tree::T_addSubtree(Node *subtree) //funkcja dodajaca wezly, ktore nie wystepuja w drzewie, do ktorego dodajemy
{  //subtree - w tym przypadku wezel z poddrzewa
	this->T_addElementIfNotPresent(subtree);

	if (subtree->left)
		this->T_addSubtree(subtree->left);
	if (subtree->right)
		this->T_addSubtree(subtree->right);
}

void Tree::T_addTree(Tree& second) //funkcja wywolawcza dodawanie drzew
{
	this->T_addSubtree(second.root_);
}

void Tree::T_subtractElementIfPresent(Node* subtree) //funkcja sprawdzajaca czy element znajduje sie w drzewie (odejmuje wezel, jesli nalezy)
{
	if (this->T_belongToTree(subtree->key))
		this->T_deleteNode(subtree->key);
}

void Tree::T_subtractSubtree(Node *subtree) //funkcja odejmujaca wezly, ktore wystepuja w drzewie, od ktorego odejmujemy
{
	this->T_subtractElementIfPresent(subtree);

	if (subtree->left)
		this->T_subtractSubtree(subtree->left);
	if (subtree->right)
		this->T_subtractSubtree(subtree->right);
}

void Tree::T_subtractTree(Tree& second) //funkcja wywolujaca odejmowanie drzew
{
	return T_subtractSubtree(second.root_);
}

Node* Node::N_copyNodes(Node* parent) //funkcja kopiujaca wezly
{
	if (!this) return nullptr;

	Node *temp = new Node(this->key);

	temp->parent = parent;
	temp->left = this->left->N_copyNodes(temp);
	temp->right = this->right->N_copyNodes(temp);

	return temp;
}

int Tree::T_sizeTree() //zwraca ilosc wezlow w drzewie
{
	return size_;
}

bool Node::N_compareNodes(Node* second) //porownanie wezlow
{
	if (!this && !second)
		return true;
	else if (!this || !second)
		return false;

	return this->key == second->key && this->left->N_compareNodes(second->left) && this->right->N_compareNodes(second->right);
}

bool Tree::T_belongToTree(int value) //true - element nalezy, false - nie nalezy
{
	if (this->T_findElementNumber(value) != nullptr)
		return true;
	else return false;
}

//---------------------------------------------DELETE----------------------------------------------
int Node::N_deleteNodes() //usuwa wszystko od konkretnego wezla, na ktorym zostanie wykonany
{
	int deleted = 0; //zwraca ilosc usunietych wezlow
	if (left)
		deleted += left->N_deleteNodes();
	if (right)
		deleted += right->N_deleteNodes();
	delete this;
	deleted++;
	return deleted;
}

void Tree::T_deleteTree() //przekierowanie do usuniecia calego drzewa
{
	if (root_)
	{
		size_ -= root_->N_deleteNodes();
		root_ = nullptr;
	}
	else return;
}

void Tree::T_deleteSubtree(int nr) //usuniecie poddrzewa dla okreslonej wartosci
{
	Node *temp, *temppar;
	temp = T_findElementNumber(nr);
	temppar = temp->parent;

	if (temp->key <= temppar->key)
		temppar->left = nullptr;
	else
		temppar->right = nullptr;

	size_ -= temp->N_deleteNodes();
	delete temp;
}

void Tree::T_deleteNode(int nr) //funkcja usuwajaca wezel o podanej wartosci
{
	Node *temp, *temppar;
	temp = T_findElementNumber(nr);
	temppar = temp->parent;
	size_--;

	if (!temp) return;
	else if (!temp->left && !temp->right)
	{
		if (temp->key <= temppar->key)
			temppar->left = nullptr;
		else
			temppar->right = nullptr;
	}
	else if (temp->left && !temp->right)
	{
		if (temp->key <= temppar->key)
		{
			temppar->left = temp->left;
			temp->left->parent = temppar;
		}
		else
		{
			temppar->right = temp->left;
			temp->left->parent = temppar;
		}
	}
	else if (!temp->left&&temp->right)
	{
		if (temp->key <= temppar->key)
		{
			temppar->left = temp->right;
			temp->right->parent = temppar;
		}
		else
		{
			temppar->right = temp->right;
			temp->right->parent = temppar;
		}
	}
	else
	{
		Node *tempmax;
		tempmax = temp->left->N_findLeftMax();

		swap(temp->key, temp->left->N_findLeftMax()->key);

		tempmax->parent->right = nullptr;

		delete tempmax;
		return;
	}

	delete temp;
}

//--------------------------------------------OPERATORY--------------------------------------------
Node* Tree::operator[](int key) //operator pobierajacy element z drzewa
{
	return T_findElementNumber(key);
}

Tree Tree::operator+(Tree& tree) //operator dodajacy dwa drzewa
{
	Tree newTree(3);

	newTree.size_ = this->size_;
	newTree.root_ = this->root_->N_copyNodes(nullptr);

	if (tree.root_) newTree.T_addTree(tree);

	return newTree;
}

void Tree::operator+=(Tree& tree) //operator dodajacy drugie drzewo do drzewa, na ktorym zostanie wywolany operator
{
	if (!this->root_ && !tree.root_) return;
	//   else if(!this->root_&&tree.root_) this->T_addTree(tree);
	else if (this->root_ && !tree.root_) return;

	this->T_addTree(tree);
}

Tree Tree::operator-(Tree& tree) //operator odejmujacy dwa drzewa
{
	Tree newTree(3);

	newTree.size_ = this->size_;
	newTree.root_ = this->root_->N_copyNodes(nullptr);

	if (tree.root_) newTree.T_subtractTree(tree);

	return newTree;
}

void Tree::operator-=(Tree& tree) //operator odejmujacy drugie drzewo od drzewa, na ktorym zostanie wywolany operator
{
	if (!this->root_ && !tree.root_) return;
	else if (!this->root_&&tree.root_) return;
	else if (this->root_ && !tree.root_) return;

	this->T_subtractTree(tree);
}

Tree& Tree::operator=(const Tree& tree) //operator kopiujacy
{
	//  if(*this == tree) return;
	//   this->T_deleteTree();
	this->size_ = tree.size_;
	root_ = tree.root_->N_copyNodes(nullptr);
	return *this;
}

bool Tree::operator==(Tree& tree) //operator porownujacy
{
	if (this->size_ != tree.size_) return false;
	return this->root_->N_compareNodes(tree.root_);
}