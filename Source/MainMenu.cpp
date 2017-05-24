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
//								Main Menu
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
MainMenu::MainMenu(sf::RenderWindow* window,HexStyle* s){
//Set Window Reference
	win = window;
//Set Resolution
	res=static_cast<sf::Vector2f>(win->getSize());
//Create GUI Elements
	//Set Style
	style = s;
	//HexLabels
	Title = new HexLabel(sf::Vector2f(250, 70), "InData", style);
	Sort = new HexLabel(sf::Vector2f(300, 50), "Sort Analysis", style);
	Tree = new HexLabel(sf::Vector2f(300, 50), "Tree Traversal", style);
	Exit = new HexLabel(sf::Vector2f(100, 50), "Exit", style);
	//Configure Data
	Title->getText()->setCharacterSize(48);
	lOrigin(Title->getText());
//Set Positions
	//Title
	Title->setPosition(res.x - Title->getSize().width - 20, 
		10 + Title->getSize().height / 2);
	//Sort
	Sort->setPosition(30, 
		Title->getHex()->getPosition().y+Title->getSize().height/2+Sort->getSize().height/2+10);
	//Tree Traversal
	Tree->setPosition(30,
		Sort->getHex()->getPosition().y + Sort->getSize().height / 2 + Sort->getSize().height / 2 + 10);
	//Exit
	Exit->setPosition(res.x - Exit->getSize().width - 20, 
		res.y-10 - Exit->getSize().height / 2);
}
//******************************************************************************
//								Destructor
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
MainMenu::~MainMenu() {
//Delete Menu
	//HexLabels
	delete Title;delete Sort;delete Tree;delete Exit;
}
//******************************************************************************
//******************************************************************************
//								Listen
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
short MainMenu::listen() {
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
		if(event.type== sf::Event::Closed)
			win->close();
	//ReSized Event
		else if (event.type == sf::Event::Resized) {
			resize(event.size.width, event.size.height);
		}
	//Mouse Buttons
		else if (event.type == sf::Event::MouseButtonPressed) {
		//Left Click
			if (event.mouseButton.button == sf::Mouse::Left) {
			//Sort Comparsion
				if (Sort->isIn(mPos)) {
					std::cout << "hey"; /*return SORT;*/ }
			//Tree Traversal
				if (Tree->isIn(mPos)) { return TREE; }
			//Quit
				if (Exit->isIn(mPos)) { win->close(); }
			}
		}
//Other Event



	}
//Out of Event Loop
	Sort->isIn(mPos);
	Tree->isIn(mPos);
	Exit->isIn(mPos);
	return MAIN;
}
//******************************************************************************
//******************************************************************************
//								Update
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void MainMenu::update() {
//Update the GUI Elements

}
//******************************************************************************
//******************************************************************************
//								Display
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void MainMenu::display() {
//Draw Elements to window
	win->clear();

	Title->draw(win);
	Sort->draw(win);
	Tree->draw(win);
	Exit->draw(win);

	win->display();
}
//******************************************************************************
//******************************************************************************
//								Resize
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void MainMenu::resize(int x,int y) {
//Cap the resize 
	res.x = x;
	res.y = y;
	sf::FloatRect visibleArea(0, 0,x, y);
	win->setView(sf::View(visibleArea));
//SetPositions
//Title
	Title->setPosition(res.x - Title->getSize().width - 20,
		10 + Title->getSize().height / 2);
	//Sort
	Sort->setPosition(30,
		Title->getHex()->getPosition().y + Title->getSize().height / 2 + Sort->getSize().height / 2 + 10);
	//Tree Traversal
	Tree->setPosition(30,
		Sort->getHex()->getPosition().y + Sort->getSize().height / 2 + Sort->getSize().height / 2 + 10);
	//Exit
	Exit->setPosition(res.x - Exit->getSize().width - 20,
		res.y - 10 - Exit->getSize().height / 2);


}