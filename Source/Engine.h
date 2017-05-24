/*
* File:   Engine.h
* Author: zzDeagle545zz(Christopher Garcia)
* Version V1 Created on May 24, 2017.
*
* Function: To Create a class to handle moving through a Menu.
*/

//Guard Block
#ifndef ENGINE_H
#define ENGINE_H

//Simple and Fast MultiMedia Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//User Libraries
#include "Menu.h"

//******************************************************************************
//******************************************************************************
//                                Game Class
//  
////////////////////////////////////////////////////////////////////////////////
class Engine {
private:
//Utility Members
	//Render Window Reference
	sf::RenderWindow* win;		//Render Window
	//Current State
	short cState;	
	//Time Between Frames
	FTIME T;
//GUI Elements
	//Style of Menu
	HexStyle style;
	//Character Fonts
	sf::Font* bFont;
	sf::Font* tFont;
protected:

public:
//Menus
	MainMenu* Main;					//Main Menu
//	SortComp* Sort;					//Sort Comparison Analysis
	TreeTrav* Tree;					//Tree Traversal Demonstration
//Member Functions
	Engine(sf::RenderWindow*);		//Constructor
	~Engine();						//Destructor
//Functional Members
	void run();						//Runs Menu
};

#endif //ENGINE_H