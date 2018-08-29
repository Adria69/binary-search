#ifndef drzewo
#define drzewo

#include <string>

struct Node
{
	int key;
	Node *parent, *left, *right;

	Node(int key, Node *parent = nullptr);
	~Node();

private:
	void N_showNode(int dot); //wyswietla wezly calego drzewa
	int N_deleteNodes(); //usuwa wszystko od konkretnego wezla, na ktorym zostanie wykonany
	Node* N_findElementNumber(int key); //zwraca element o okreslonej wartosci
	Node* N_findLeftMax(); //znajduje najwiekszy element w lewym poddrzewie
	Node* N_copyNodes(Node* parent); //funkcja kopiujaca wezly
	bool N_compareNodes(Node* second); //porownanie wezlow

	friend class Tree;
};

class Tree
{
	int number_;
	int size_;
	Node *root_;

public:
	Tree(int number, Node* root_ = NULL);
	~Tree();
	Tree(const Tree& other); //konstruktor kopiujacy

	void T_showTree(); //przekierowanie do wyswietlenia wezlow drzewa
	void T_addElement(int nr); //dodawanie do drzewa elementu o okreslonej wartosci
	void T_deleteTree(); //przekierowanie do usuniecia calego drzewa
	void T_deleteSubtree(int nr); //usuniecie poddrzewa dla okreslonej wartosci
	void T_deleteNode(int nr); //funkcja usuwajaca wezel o podanej wartosci
	Node* T_findElementNumber(int key); //zwraca wezel lub przekierowuje do znalezienia elementu o okreslonej wartosci
	void T_addElementIfNotPresent(Node* subtree); //funkcja sprawdzajaca czy element nie znajduje sie w drzewie (dodaje wezel, jesli nie nalezy)
	void T_addSubtree(Node *subtree); //funkcja dodajaca wezly, ktore nie wystepuja w drzewie, do ktorego dodajemy
	void T_addTree(Tree& second); //funkcja wywolawcza dodawanie drzew
	void T_subtractElementIfPresent(Node* subtree); //funkcja sprawdzajaca czy element znajduje sie w drzewie (odejmuje wezel, jesli nalezy)
	void T_subtractSubtree(Node *subtree); //funkcja odejmujaca wezly, ktore wystepuja w drzewie, od ktorego odejmujemy
	void T_subtractTree(Tree& second); //funkcja wywolujaca odejmowanie drzew
	int T_sizeTree(); //funkcja zwracajaca rozmiar drzewa
	bool T_belongToTree(int value); //true - element nalezy, false - nie nalezy

	Node* operator[](int key); //operator pobierajacy element z drzewa
	Tree operator+(Tree& tree); //operator dodajacy dwa drzewa
	void operator+=(Tree& tree); //operator dodajacy drugie drzewo do drzewa, na ktorym zostanie wywolany operator
	Tree operator-(Tree& tree); //operator odejmujacy dwa drzewa
	void operator-=(Tree& tree); //operator odejmujacy drugie drzewo od drzewa, na ktorym zostanie wywolany operator
	Tree& operator=(const Tree& tree); //operator kopiujacy
	bool operator==(Tree& tree); //operator porownujacy

};

#endif