#include <iostream>
#include <cstdlib>

#include "functions.h"

using namespace std;

void clear()
{
	system("cls"); //windows
				   //   system("clear"); //linux
} //CLEAR

void menu()
{
	int choice;

	while (1)
	{
		cout << endl << "TESTY" << endl;
		cout << "Wybierz, ktory test wykonac:" << endl;
		cout << "[1] - Stworzenie drzewa." << endl;
		cout << "[2] - Dodawanie elementow do drzewa." << endl;
		cout << "[3] - Usuniecie calego drzewa." << endl;
		cout << "[4] - Usuniecie poddrzewa w zaleznosci od wartosci wezla." << endl;
		cout << "[5] - Usuniecie wezla o konkretnej wartosci." << endl;
		cout << "[6] - Pobranie elementu o podanej wartosci." << endl;
		cout << "[7] - Dodawanie dwoch drzew do siebie." << endl;
		cout << "[8] - Odjecie dwoch drzew od siebie." << endl;
		cout << "[9] - Kopiowanie drzewa." << endl;
		cout << "[10] - Sprawdzenie wielkosci drzewa." << endl;
		cout << "[11] - Porownanie drzew." << endl;
		cout << "[12] - Sprawdzenie czy dana wartosc nalezy do drzewa." << endl;
		cout << "[0] - Zakoncz." << endl;

		cout << "Wybieram: ";
		cin >> choice;
		cout << endl;

		clear();

		switch (choice)
		{
		case 0:
			return;
		case 1:
			testAddTree();
			break;
		case 2:
			testAdd();
			break;
		case 3:
			testDeleteTree();
			break;
		case 4:
			testDeleteSubtree();
			break;
		case 5:
			testDeleteNode();
			break;
		case 6:
			testTakeElement();
			break;
		case 7:
			testSumTree();
			break;
		case 8:
			testSubtractTree();
			break;
		case 9:
			testCopyTree();
			break;
		case 10:
			testSizeTree();
			break;
		case 11:
			testCompareTree();
			break;
		case 12:
			testBelongToTree();
			break;
		default:
			cout << "Zly wybor" << endl;
			break;
		}
	}
}

void testAddTree() //1
{
	Tree tree1(1);
	cout << "Zostanie stworzone drzewo nr 1 o osmiu elementach" << endl << "12, 8, 15, 1, 2, 20, 19, 0:" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(8);
	tree1.T_addElement(15);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(20);
	tree1.T_addElement(19);
	tree1.T_addElement(0);

	tree1.T_showTree();
}

void testAdd() //2
{
	Tree tree1(1);
	cout << "Zostanie stworzone drzewo nr 1 o szesciu elementach" << endl << "12, 15, 1, 2, 20, 0:" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(15);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(20);
	tree1.T_addElement(0);

	tree1.T_showTree();

	cout << endl << "Do drzewa nr 1 dodajemy czterokrotnie po jednym elemencie." << endl;
	cout << endl << "1: ";
	cout << "Dodano element " << 19 << endl << endl;
	tree1.T_addElement(19);
	tree1.T_showTree();
	cout << endl << "2: ";
	cout << "Dodano element " << 5 << endl << endl;
	tree1.T_addElement(5);
	tree1.T_showTree();
	cout << endl << "3: ";
	cout << "Dodano element " << 13 << endl << endl;
	tree1.T_addElement(13);
	tree1.T_showTree();
	cout << endl << "4: ";
	cout << "Dodano element " << 50 << endl << endl;
	tree1.T_addElement(50);

	tree1.T_showTree();
}

void testDeleteTree() //3
{
	Tree tree1(1);
	cout << "Zostanie stworzone drzewo nr 1 o osmiu elementach" << endl << "12, 8, 15, 1, 2, 20, 19, 0:" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(8);
	tree1.T_addElement(15);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(20);
	tree1.T_addElement(19);
	tree1.T_addElement(0);

	tree1.T_showTree();

	cout << endl << "Usuwamy drzewo." << endl << endl;
	tree1.T_deleteTree();

	tree1.T_showTree();
}

void testDeleteSubtree() //4
{
	Tree tree1(1);
	cout << "Zostanie stworzone drzewo nr 1 o trzynastu elementach" << endl << "12, 20, 6, 3, 19, 9, 18, 5, 21, 1, 2, 0, 4:" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(20);
	tree1.T_addElement(6);
	tree1.T_addElement(3);
	tree1.T_addElement(19);
	tree1.T_addElement(9);
	tree1.T_addElement(18);
	tree1.T_addElement(5);
	tree1.T_addElement(21);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(0);
	tree1.T_addElement(4);

	tree1.T_showTree();

	cout << endl << "Sprawdzamy wielkosc drzewa" << endl;
	cout << "Wielkosc: " << tree1.T_sizeTree() << endl;

	cout << endl << "Usuwamy poddrzewo wezla o wartosci 3 wraz z podanym wezlem" << endl;

	tree1.T_deleteSubtree(3);

	tree1.T_showTree();

	cout << endl << "Sprawdzamy wielkosc drzewa" << endl;
	cout << "Wielkosc: " << tree1.T_sizeTree() << endl;
}
//-----usuwanie wezla

void testDeleteNode() //5
{
	Tree tree1(1), tree2(2), tree3(3);
	cout << "Zostanie stworzone drzewo nr 1 o trzynastu elementach" << endl << "12, 8, 15, 1, 2, 20, 19, 0, 10, 40, 56, 52, 60:" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(8);
	tree1.T_addElement(15);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(20);
	tree1.T_addElement(19);
	tree1.T_addElement(0);
	tree1.T_addElement(10);
	tree1.T_addElement(40);
	tree1.T_addElement(56);
	tree1.T_addElement(52);
	tree1.T_addElement(60);

	tree1.T_showTree();

	cout << endl << "Sprawdzamy wielkosc drzewa" << endl;
	cout << "Wielkosc: " << tree1.T_sizeTree() << endl;

	cout << endl << "Usuwamy wezel o wartosci 60 (przypadek, gdzie usuwany wezel nie ma synow)" << endl << endl;
	tree1.T_deleteNode(60);

	tree1.T_showTree();

	cout << endl << "Sprawdzamy wielkosc drzewa" << endl;
	cout << "Wielkosc: " << tree1.T_sizeTree() << endl;

	cout << endl << "Usuwamy wezel o wartosci 56 (przypadek, gdzie usuwany wezel ma jednego syna)" << endl << endl;
	tree1.T_deleteNode(56);

	tree1.T_showTree();

	cout << endl << "Sprawdzamy wielkosc drzewa" << endl;
	cout << "Wielkosc: " << tree1.T_sizeTree() << endl;

	cout << endl << "Usuwamy wezel o wartosci 8 (przypadek, gdzie usuwany wezel ma dwoch synow)" << endl << endl;
	tree1.T_deleteNode(8);

	tree1.T_showTree();

	cout << endl << "Sprawdzamy wielkosc drzewa" << endl;
	cout << "Wielkosc: " << tree1.T_sizeTree() << endl;
}

void testTakeElement() //6
{
	int value[2] = { 15, 12 };
	Tree tree1(1);
	cout << "Zostanie stworzone drzewo nr 1 o osmiu elementach" << endl << "12, 8, 15, 1, 2, 20, 19, 0" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(8);
	tree1.T_addElement(15);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(20);
	tree1.T_addElement(19);
	tree1.T_addElement(0);

	tree1.T_showTree();

	/*
	cout<<endl<<"Uzycie funkcji:"<<endl;
	for(int i=0; i<2; i++)
	{
	if(tree1.T_findElementNumber(value[i]))
	{
	cout<<endl<<endl<<"Wartosc: "<<tree1.T_findElementNumber(value[i])->key;
	if(tree1.T_findElementNumber(value[i])->left)
	cout<<endl<<"Lewy: "<<tree1.T_findElementNumber(value[i])->left->key;
	if(tree1.T_findElementNumber(value[i])->right)
	cout<<endl<<"Prawy: "<<tree1.T_findElementNumber(value[i])->right->key;
	}
	}
	*/

	cout << endl << "Wezly:";
	for (int i = 0; i<2; i++)
	{
		if (tree1[value[i]])
		{
			cout << endl << endl << "Wartosc: " << tree1[value[i]]->key;
			if (tree1[value[i]]->parent)
				cout << endl << "Rodzic: " << tree1[value[i]]->parent->key;
			if (tree1[value[i]]->left)
				cout << endl << "Lewy: " << tree1[value[i]]->left->key;
			if (tree1[value[i]]->right)
				cout << endl << "Prawy: " << tree1[value[i]]->right->key;
		}
	}
	cout << endl;

}

void testSumTree() //7
{
	Tree tree1(1), tree2(2);

	cout << "Zostanie stworzone drzewo nr 1 o osmiu elementach" << endl << "12, 8, 15, 1, 2, 20, 19, 0:" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(8);
	tree1.T_addElement(15);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(20);
	tree1.T_addElement(19);
	tree1.T_addElement(0);

	tree1.T_showTree();

	cout << endl << endl << "Zostanie stworzone drzewo nr 2 o szesciu elementach" << endl << "52, 10, 56, 60, 25, 0:" << endl << endl;
	tree2.T_addElement(52);
	tree2.T_addElement(10);
	tree2.T_addElement(56);
	tree2.T_addElement(60);
	tree2.T_addElement(25);
	tree2.T_addElement(0);

	tree2.T_showTree();

	cout << endl << "Dodajemy do drzewa nr 1 drzewo nr 2 wczesniej tworzac drzewo nr 3 (operator +)" << endl << endl;
	Tree tree3 = tree1 + tree2;
	tree3.T_showTree();
	cout << endl;

	cout << endl << "Dodajemy do drzewa nr 1 drzewo nr 2 (operator +=)" << endl << endl;
	tree1 += tree2;
	tree1.T_showTree();
}

void testSubtractTree() //8
{
	Tree tree1(1), tree2(2);

	cout << "Zostanie stworzone drzewo nr 1 o osmiu elementach" << endl << "12, 8, 15, 1, 2, 20, 19, 0:" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(8);
	tree1.T_addElement(15);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(20);
	tree1.T_addElement(19);
	tree1.T_addElement(0);

	tree1.T_showTree();

	cout << endl << endl << "Zostanie stworzone drzewo nr 2 o szesciu elementach" << endl << "52, 8, 56, 20, 25, 0:" << endl << endl;
	tree2.T_addElement(52);
	tree2.T_addElement(15); //8
	tree2.T_addElement(56);
	tree2.T_addElement(20);
	tree2.T_addElement(25);
	tree2.T_addElement(0);

	tree2.T_showTree();

	cout << endl << "Odejmujemy od drzewa nr 1 drzewo nr 2 wczesniej tworzac drzewo nr 3 (operator -)" << endl << endl;
	Tree tree3 = tree1 - tree2;
	tree3.T_showTree();
	cout << endl;

	cout << endl << "Odejmujemy od drzewa nr 1 drzewo nr 2 (operator -=)" << endl << endl;
	tree1 -= tree2;
	tree1.T_showTree();


}

void testCopyTree() //9
{
	Tree tree1(1);
	cout << "Zostanie stworzone drzewo nr 1 o osmiu elementach" << endl << "12, 8, 15, 1, 2, 20, 19, 0:" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(8);
	tree1.T_addElement(15);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(20);
	tree1.T_addElement(19);
	tree1.T_addElement(0);

	tree1.T_showTree();
	cout << endl << "Rozmiar: " << tree1.T_sizeTree() << endl;

	cout << endl << "Kopiujemy drzewo nr 1 do drzewa nr 2" << endl << endl;
	Tree tree2(2);
	tree2 = tree1;
	tree2.T_showTree();
	cout << endl << "Rozmiar: " << tree2.T_sizeTree() << endl;
}

void testSizeTree() //10
{
	Tree tree1(1), tree2(2);
	cout << "Zostanie stworzone drzewo nr 1 o osmiu elementach" << endl << "12, 8, 15, 1, 2, 20, 19, 0:" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(8);
	tree1.T_addElement(15);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(20);
	tree1.T_addElement(19);
	tree1.T_addElement(0);

	tree1.T_showTree();

	cout << endl << "Sprawdzamy wielkosc drzewa" << endl;
	cout << "Wielkosc: " << tree1.T_sizeTree() << endl;

	cout << endl << endl << "Zostanie stworzone drzewo nr 2 o szesciu elementach" << endl << "52, 10, 56, 60, 25, 0:" << endl << endl;
	tree2.T_addElement(52);
	tree2.T_addElement(10);
	tree2.T_addElement(56);
	tree2.T_addElement(60);
	tree2.T_addElement(25);
	tree2.T_addElement(0);

	tree2.T_showTree();

	cout << endl << "Sprawdzamy wielkosc drzewa" << endl;
	cout << "Wielkosc: " << tree2.T_sizeTree() << endl;
}

void testCompareTree() //11
{
	Tree tree1(1), tree2(2), tree3(3);
	cout << "Zostanie stworzone drzewo nr 1 o szesciu elementach" << endl << "12, 15, 1, 2, 20, 0:" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(15);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(20);
	tree1.T_addElement(0);

	tree1.T_showTree();

	cout << endl << endl << "Zostanie stworzone drzewo nr 2 o szesciu elementach" << endl << "52, 10, 56, 60, 25, 0:" << endl << endl;
	tree2.T_addElement(52);
	tree2.T_addElement(10);
	tree2.T_addElement(56);
	tree2.T_addElement(60);
	tree2.T_addElement(25);
	tree2.T_addElement(0);

	tree2.T_showTree();

	cout << endl << "Porownujemy drzewa nr 1 i nr 2" << endl;
	if (tree1 == tree2)
		cout << "Drzewa sa takie same" << endl;
	else cout << "Drzewa sa rozne" << endl;

	cout << endl << "Kopiujemy drzewo nr 2 do drzewa nr 3" << endl << endl;
	tree3 = tree2;
	tree3.T_showTree();

	cout << endl << "Porownujemy drzewa nr 2 i nr 3" << endl;
	if (tree2 == tree3)
		cout << "Drzewa sa takie same" << endl;
	else cout << "Drzewa sa rozne" << endl;
}

void testBelongToTree() //12
{
	int value[2] = { 15, 33 };
	Tree tree1(1);
	cout << "Zostanie stworzone drzewo nr 1 o osmiu elementach" << endl << "12, 8, 15, 1, 2, 20, 19, 0:" << endl << endl;
	tree1.T_addElement(12);
	tree1.T_addElement(8);
	tree1.T_addElement(15);
	tree1.T_addElement(1);
	tree1.T_addElement(2);
	tree1.T_addElement(20);
	tree1.T_addElement(19);
	tree1.T_addElement(0);

	tree1.T_showTree();

	cout << endl;

	for (int i = 0; i<2; i++)
	{
		if (tree1.T_belongToTree(value[i]))
			cout << "Element " << value[i] << " znajduje sie juz w drzewie" << endl;
		else
			cout << "Element " << value[i] << " nie znajduje sie w drzewie" << endl;
	}
}