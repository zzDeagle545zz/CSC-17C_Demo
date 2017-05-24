/*
* File:   Menu.h
* Author: zzDeagle545zz(Christopher Garcia)
* Version V1 Created on May 24, 2017.
*
* Function: Creates Classes to handle Menu opitions.
*	Each Class is a SubMenu the the "Engine" could
*	cycle through.
*/

//Guard Block
#ifndef MENU_H
#define MENU_H

//Simple and Fast MultiMedia Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//User Libraries
#include "Utilities.h"
#include "MenuStates.h"
#include "HexGUI.h"
#include "AlgoritmBar.h"
#include "Sorts.h"
#include "HexTree.h"

//******************************************************************************
//******************************************************************************
//                                   Menu
//  
////////////////////////////////////////////////////////////////////////////////
class Menu {
private:

protected:
//Utility Members
	//Frame Time
	FTIME T;
	//Render Window Reference
	sf::RenderWindow* win;
	//Window Event
	sf::Event event;
	//Mouse Position
	sf::Vector2f mPos;
	//Resolution
	sf::Vector2f res;
public:
	Menu();									//Constructor
	virtual ~Menu();						//Destructor
	virtual void display()=0;					//Displays all the GUI
	virtual void resize(int, int) = 0;			//handles the resize event
	virtual short listen()=0;					//Handles User Input
	virtual void update()=0;					//Update the screen;
};
//******************************************************************************
//******************************************************************************
//								Main Menu
//  
////////////////////////////////////////////////////////////////////////////////
class MainMenu :public Menu {
private:
//Utility Members

//GUI Elements
	//Style
	HexStyle* style;						//Menu Style
	//Menu Labels
	HexLabel* Title;						//Title
	HexLabel* Sort;							//Sort Comparison Demo
	HexLabel* Tree;							//Tree Traversal Dem
	HexLabel* Exit;							//Exits the Program
protected:

public:
	MainMenu(sf::RenderWindow*,HexStyle*);		//Constructor
	~MainMenu();								//Destructor
//Menu handling Functions
	short listen();							//Handles user Input
	void update();							//Update the screen
	void display();							//Displays the Elements
	void resize(int, int);
};
//******************************************************************************
//******************************************************************************
//								Sort Comparison
//  
////////////////////////////////////////////////////////////////////////////////
//class SortComp :public Menu {
//private:
////Data Members
//	//Primatives
//	bool show;
//	//Sort Data
//	SortData* data;
//	//Hex Bars
//	AlgBar* sSort;					//Selection Sort
//	AlgBar* bSort;					//Bubble Sort
//	AlgBar* maSort;					//Mark Sort
//	AlgBar* meSort;					//Merge Sort
//	AlgBar* qSort;					//Quick Sort
//	AlgBar* hSort;					//Heap Sort
//	//Style
//	HexStyle* style;				//Hex Style
//protected:
//
//public:
//	SortComp(sf::RenderWindow*,HexStyle*);		//Constructor
//	~SortComp();								//Destructor
////Menu handling Functions
//	short listen();							//Handles user Input
//	void update();							//Update the screen
//	void display();							//Displays the Elements
//	void resize(int, int){}
//};
//******************************************************************************
//******************************************************************************
//								Tree Traversval
//  
////////////////////////////////////////////////////////////////////////////////
class TreeTrav :public Menu {
private:
//Functional Members
	//Enumerator
	enum odr {PRE,IN,POST};				//Order type Enumeration
	//Booleans
	bool traversing;					//Whether the tree is being Traversed
	//Shorts
	int oType;							//Order Type
	//Threads
	sf::Thread* thread;					//Order Thread
	sf::Thread* thread1;				//Movement Thread
//GUI Elements
	//Style
	HexStyle* style;					//Menu Style
	//HexLabels
	HexLabel* title;					//Menu Title
	HexLabel* Back;						//Exits the Program
	//HexTree
	HexTree* tree;						//Tree of Hexagons
	//Hex Selector
	HexSelect* mode;					//Mode of Traversal Order
	//Hex Buttons
	HexButton* trav;					//Traverse Tree
	HexButton* travNext;				//Traverse Movement
	//Rectangle
	sf::RectangleShape* oBox;			//Order Box
	//Text
	sf::Text* order;
	sf::Text* oTxt;			
protected:
//Utility Functions
	void setModeTxt();
public:
//Constructor
	TreeTrav(sf::RenderWindow*,HexStyle*);	//Sets Window Reference/Style
//Destructor
	~TreeTrav();								
//Menu handling Functions
	short listen();							//Handles user Input
	void update();							//Update the screen
	void display();							//Displays the Elements
	void resize(int, int);					//Handles User Input
	void place();							//Places all Elements to the Screen
//Functional Members
	void traverse();				//Traverses tree based of Order
	void traverseM();				//Traverses tree and tracks movement
	//Traversal Functions
	void preOrder(HexNode*);		//Pre-Order Traversal
	void inOrder(HexNode*);			//In-Order Traversal
	void postOrder(HexNode*);		//Post-Order Traversal
	//Traversal Tracking Functions
	void preM(HexNode*);			//Track Pre-Order Traversal
	void inM(HexNode*);				//Track In-Order Traversal
	void postM(HexNode*);			//Track Post-Order Traversal
};

#endif	//MENU_H
