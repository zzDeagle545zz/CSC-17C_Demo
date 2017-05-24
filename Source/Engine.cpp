/*
	Game Contianer which holds all the items of the Game
	-Including Menus and the game itself
	-Handles the user input
	-Handles Graphics
*/

//Simple and Fast MultiMedia Libraries

//System Libraries
#include <iostream>

//User Libraries
#include "Engine.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
//								Menu Engine
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
Engine::Engine(sf::RenderWindow* win) {
//Create Fonts
	tFont = new sf::Font;
	bFont = new sf::Font;
//Load Fonts 
	try {
	//Title Font
		if (!tFont->loadFromFile("Resources/Fonts/BBrick-R.otf"))
					throw "Could not load Title Font.";
		//Title Font
		if (!bFont->loadFromFile("Resources/Fonts/Xolonium-R.otf"))
			throw "Could not load Body Font.";
		} catch (char msg[]) { std::cout << msg << std::endl; }
//Configure Style
	style.cFill = sf::Color(80, 80, 80, 255);
	style.cText = sf::Color::Cyan;
	style.cOutline = sf::Color::Cyan;
	style.cHover = sf::Color(0, 139, 139, 255);
	style.cFaded = sf::Color(80, 80, 80, 100);
	style.fTitle = tFont;
	style.fBody = bFont;
	style.chBody = 30;
	style.chTitle = 48;
	style.oThick = 2;
//Create Menus
	//Main Menu
	Main = new MainMenu(win,&style);
	//Sort = new SortComp(win,&style);
	Tree = new TreeTrav(win, &style);

//Set Current State
	cState = MAIN;
}
//******************************************************************************
//******************************************************************************
//								Destructor
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
Engine::~Engine() {
//Release Resources
	delete Main;
//	delete Sort;

	delete tFont;delete bFont;
}
//******************************************************************************
//******************************************************************************
//									Run
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void Engine::run() {
//Decide what Menu needs to be Ran
	switch(cState){
//Main Menu
	case MAIN:		//Main Menu
		Main->update();
		Main->display();
		cState = Main->listen();
		break;
//Sort Comparison
	/*case SORT:
		Sort->update();
		Sort->display();
		cState = Sort->listen();
		break;*/
//Tree Traversal
	case TREE:
		Tree->update();
		Tree->display();
		cState = Tree->listen();
		break;
	}

}