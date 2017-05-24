/*

*/

//Simple and Fast MultiMedia Libraries

//System Libraries
#include <iostream>

//User Libraries
#include "Menu.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
//								TreeTraversal
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//******************************************************************************
//								Constructor
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
TreeTrav::TreeTrav(sf::RenderWindow* window,HexStyle* s) {
//Set Style
	style = s;
//Render Window
	win = window;
//Set Resolution
	res = static_cast<sf::Vector2f>(win->getSize());
//Set Mode
	oType = -1;
//Create GUI Elements
	//HexLabel
	title = new HexLabel(sf::Vector2f(300, 50), "Tree Traversal", style);
	Back = new HexLabel(sf::Vector2f(100, 50), "Back", style);
	tree = new HexTree(s);
	//HexSelect
	mode = new HexSelect(50, "Choose Order", "Mode",style);
	//Hex Buttons
	trav = new HexButton(50, "Go", style);
	travNext = new HexButton(50, "Track", style);
	//Rectangle
	oBox = new sf::RectangleShape(sf::Vector2f(800, 80));
	//Text
	oTxt = new sf::Text("Order", *style->fBody, 48);
	order = new sf::Text(" ", *style->fBody, 30);
	//Thread
	thread = new sf::Thread(&TreeTrav::traverse, this);
	thread1 = new sf::Thread(&TreeTrav::traverseM, this);
//Configure Data
	//Rectangle
	oBox->setFillColor(sf::Color(200, 200, 200, 100));
	oBox->setOutlineColor(style->cOutline);
	oBox->setOutlineThickness(2);
	lOrigin(oBox);
	//Text
	oTxt->setColor(style->cText);
	lOrigin(oTxt);
	order->setColor(style->cText);
	tree->setPosition(500, 50);
//Place Objects on the Screen
	place();
}
//******************************************************************************
//								Destructor
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
TreeTrav::~TreeTrav() {
//Release Resources
	//HexLabel
	delete title;delete Back;
	//HexSelector
	delete mode;
	//Hex Buttons
	delete trav;delete travNext;
	//Hex Tree
	delete tree;
	//Rectangle
	delete oBox;
	//Text
	delete order; delete oTxt;
	//Thread
	thread->terminate();delete thread;
	thread1->terminate();delete thread1;
}
//******************************************************************************
//								Listen
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
short TreeTrav::listen() {
//Find Mouse Postion
	mPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*win));
//Check for Chnaged szie
	if (res.x != win->getSize().x || res.y != win->getSize().y) {
		res.x = win->getSize().x;
		res.y = win->getSize().y;
		resize(res.x, res.y);
	}
//Window Management
	//Poll Events
	while (win->pollEvent(event)) {
		//On Close
		if (event.type == sf::Event::Closed)
			win->close();
		//ReSized Event
		else if (event.type == sf::Event::Resized) {
			resize(event.size.width, event.size.height);
		}
		//Mouse Buttons
		else if (event.type == sf::Event::MouseButtonPressed) {
			//Left Click
			if (event.mouseButton.button == sf::Mouse::Left) {
			//Quit
				if (Back->isIn(mPos)) { return MAIN; }
			//If Traversing
				if (!traversing) {
					//Change Mode Left
					if (mode->isLeft(mPos)) {
						mode->spin(0, 1);
						if(oType>0)
							oType--;
						else oType = 2;
						setModeTxt();
						order->setString(" ");
					}
					//Change Mode Right
					else if (mode->isRight(mPos)) {
						mode->spin(1, 1);
						if (oType<2)
							oType++;
						else oType = 0;
						setModeTxt();
						order->setString(" ");
					}
					//Traverse All
					else if (trav->inside(mPos)) {
						thread->launch();
					}
					//Traverse Next
					else if (travNext->inside(mPos)) {
						thread1->launch();
					}
				}
			}

		}
		//Other Event
		Back->isIn(mPos);
		mode->isLeft(mPos);
		mode->isRight(mPos);
		trav->inside(mPos);
		travNext->inside(mPos);
	}
	//Out of Event Loop


	return TREE;
}
//******************************************************************************
//								Update
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::update() {
//Update Gui Elements
	mode->update();

}
//******************************************************************************
//								Display
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::display() {
//Clear the Window
	win->clear();
//Draw GUI Elements
	title->draw(win);
	Back->draw(win);
	tree->draw(win);
	mode->draw(win);
	trav->draw(win);
	travNext->draw(win);
	win->draw(*oBox);
	win->draw(*oTxt);
	win->draw(*order);
//Display the Elements Drawn
	win->display();
}
//******************************************************************************
//								Resize
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::resize(int x,int y) {
//Cap the resize 
	res.x = x;
	res.y = y;
//Set View
	sf::FloatRect visibleArea(0, 0, x, y);
	win->setView(sf::View(visibleArea));
//SetPositions
	place();
}
//******************************************************************************
//								Place
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::place() {
//Set Positions
	//Title
	title->setPosition(20 + title->getHex()->getL(),
		10 + title->getSize().height / 2);
	////Exit
	Back->setPosition(res.x - Back->getSize().width - 20,
		res.y - 10 - Back->getSize().height / 2);
	//Tree
	//tree->setPosition(500, 50);
	//HexSelector
	mode->setPosition(res.x - 250, 150);
	//Hex Button
	trav->SetPosition(res.x - 250 - trav->getL() * 2,  300);
	travNext->SetPosition(res.x - 250 + travNext->getL() * 2,  300);
	//Recatngle
	oBox->setPosition(50, res.y - oBox->getLocalBounds().height / 2 - 50);
	//Text
	oTxt->setPosition(oBox->getPosition().x, 
		oBox->getPosition().y - oBox->getLocalBounds().height / 2-oTxt->getLocalBounds().height/2-10);
	order->setPosition(50, res.y - oBox->getLocalBounds().height / 2 - 50);
}
//******************************************************************************
//								
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::traverse() {
//Prepare
	order->setString(" ");
	traversing = true;
	trav->setFillColor(style->cFaded);
	travNext->setFillColor(style->cFaded);
	mode->getHex()->setFillColor(style->cFaded);
	mode->getHex()->setOutlineColor(sf::Color(0, 255, 255, 100));
	tree->getRoot()->hex->setFillColor(style->cFaded);
	tree->getRoot()->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	//Reset String
	
//Traverse Tree
	switch (oType) {
	//Pre-Order
	case PRE:
		preOrder(tree->getRoot());
		break;
	case IN:
		inOrder(tree->getRoot());
		break;
	case POST:
		postOrder(tree->getRoot());
		break;
	}
//Reset
	traversing = false;
	trav->setFillColor(style->cFill);
	trav->setOutlineColor(sf::Color(0, 255, 255, 100));
	travNext->setFillColor(style->cFill);
	travNext->setOutlineColor(sf::Color(0, 255, 255, 100));
	mode->getHex()->setFillColor(style->cFill);
	mode->getHex()->setOutlineColor(style->cOutline);
	tree->getRoot()->hex->setFillColor(style->cFill);
	tree->getRoot()->hex->setOutlineColor(style->cOutline);
//Exit Thread
	thread->terminate();
}
//******************************************************************************
//							Traverse Movement
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::traverseM() {
	//Reset String
	order->setString(" ");
	traversing = true;
	//Set inactive
	trav->setFillColor(style->cFaded);
	travNext->setFillColor(style->cFaded);
	mode->getHex()->setFillColor(style->cFaded);
	mode->getHex()->setOutlineColor(sf::Color(0, 255, 255, 100));
	tree->getRoot()->hex->setFillColor(style->cFaded);
	tree->getRoot()->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	//Traverse Tree
	switch (oType) {
		//Pre-Order
	case PRE:
		preM(tree->getRoot());
		break;
	case IN:
		inM(tree->getRoot());
		break;
	case POST:
		postM(tree->getRoot());
		
		break;
	}
	//Reset
	traversing = false;
	trav->setFillColor(style->cFill);
	trav->setOutlineColor(sf::Color(0, 255, 255, 100));
	travNext->setFillColor(style->cFill);
	travNext->setOutlineColor(sf::Color(0, 255, 255, 100));
	mode->getHex()->setFillColor(style->cFill);
	mode->getHex()->setOutlineColor(style->cOutline);
	tree->getRoot()->hex->setFillColor(style->cFill);
	tree->getRoot()->hex->setOutlineColor(style->cOutline);
	//Exit Thread
	thread1->terminate();
}
//******************************************************************************
//								Pre Order
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::preOrder(HexNode* root) {
//Recursive Traverse
	if (root == NULL)
		return;
	//Access Root
	root->hex->setFillColor(style->cFill);
	root->hex->setOutlineColor(style->cOutline);
	root->hex->getText()->setColor(style->cText);
	order->setString(order->getString() + root->hex->getText()->getString()+" ");
	lOrigin(order);
	place();
	sf::sleep(sf::Time(sf::seconds(1.5)));
	root->hex->setFillColor(sf::Color(80, 80, 80, 100));
	root->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	root->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	//Left Child
	preOrder(root->left);
	preOrder(root->right);
}
//******************************************************************************
//								InOrder
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::inOrder(HexNode* root) {
	//Recursive Traverse
	if (root == NULL)
		return;
	//Left Child
	inOrder(root->left);
	//Access Root
	root->hex->setFillColor(style->cFill);
	root->hex->setOutlineColor(style->cOutline);
	root->hex->getText()->setColor(style->cText);
	order->setString(order->getString() + root->hex->getText()->getString() + " ");
	lOrigin(order);
	place();
	sf::sleep(sf::Time(sf::seconds(1.5)));
	root->hex->setFillColor(sf::Color(80, 80, 80, 100));
	root->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	root->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	//Right Child
	inOrder(root->right);
}
//******************************************************************************
//								PostOrder
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::postOrder(HexNode* root) {
	//Recursive Traverse
	if (root == NULL)
		return;
	//Left Child
	postOrder(root->left);
	//Right Child
	postOrder(root->right);
	//Access Root
	root->hex->setFillColor(style->cFill);
	root->hex->setOutlineColor(style->cOutline);
	root->hex->getText()->setColor(style->cText);
	order->setString(order->getString() + root->hex->getText()->getString() + " ");
	lOrigin(order);
	place();
	sf::sleep(sf::Time(sf::seconds(1.5)));
	root->hex->setFillColor(sf::Color(80, 80, 80, 100));
	root->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	root->hex->getText()->setColor(sf::Color(0, 255, 255, 120));

}
//******************************************************************************
//								
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::preM(HexNode* root) {
	//Recursive Traverse
	if (root == NULL)
		return;
	//Access Root
	root->hex->setFillColor(style->cFill);
	root->hex->setOutlineColor(style->cOutline);
	root->hex->getText()->setColor(style->cText);
	order->setString(order->getString() + root->hex->getText()->getString() + " ");
	lOrigin(order);
	place();
	sf::sleep(sf::Time(sf::seconds(1.5)));
	root->hex->setFillColor(sf::Color(80, 80, 80, 100));
	root->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	root->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	//Left Child
	preM(root->left);
	preM(root->right);
}
//******************************************************************************
//								
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::inM(HexNode* root) {
	//Recursive Traverse
	if (root == NULL)
		return;
	//Track Movement
	root->hex->setFillColor(style->cFill);
	root->hex->setOutlineColor(style->cOutline);
	root->hex->getText()->setColor(style->cText);
	sf::sleep(sf::Time(sf::seconds(1.0)));
	root->hex->setFillColor(sf::Color(80, 80, 80, 100));
	root->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	root->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	//Left Child
	inM(root->left);
	//Access Root
	root->hex->setFillColor(style->cFill);
	root->hex->setOutlineColor(style->cOutline);
	root->hex->getText()->setColor(style->cText);
	order->setString(order->getString() + root->hex->getText()->getString() + " ");
	lOrigin(order);
	place();
	sf::sleep(sf::Time(sf::seconds(1.5)));
	root->hex->setFillColor(sf::Color(80, 80, 80, 100));
	root->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	root->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	//Right Child
	inM(root->right);
}
//******************************************************************************
//								PostOrder Movement
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::postM(HexNode* root) {
	//Recursive Traverse
	if (root == NULL)
		return;
	//Track Movement
	root->hex->setFillColor(style->cFill);
	root->hex->setOutlineColor(style->cOutline);
	root->hex->getText()->setColor(style->cText);
	sf::sleep(sf::Time(sf::seconds(1.0)));
	root->hex->setFillColor(sf::Color(80, 80, 80, 100));
	root->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	root->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	//Left Child
	postM(root->left);
	//Right Child
	postM(root->right);
	//Access Root
	root->hex->setFillColor(style->cFill);
	root->hex->setOutlineColor(style->cOutline);
	root->hex->getText()->setColor(style->cText);
	order->setString(order->getString() + root->hex->getText()->getString() + " ");
	lOrigin(order);
	place();
	sf::sleep(sf::Time(sf::seconds(1.5)));
	root->hex->setFillColor(sf::Color(80, 80, 80, 100));
	root->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	root->hex->getText()->setColor(sf::Color(0, 255, 255, 120));

}
//******************************************************************************
//								
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void TreeTrav::setModeTxt() {
//Set Mode Txt
	switch (oType) {
	case PRE:
		mode->getText()->setString("Pre-Order");
		cOrigin(mode->getText());
		break;
	case IN:
		mode->getText()->setString("In-Order");
		cOrigin(mode->getText());
		break;
	case POST:
		mode->getText()->setString("Post-Order");
		cOrigin(mode->getText());
		break;
	}
	place();
}