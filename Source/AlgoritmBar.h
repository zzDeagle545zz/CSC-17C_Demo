/*
* File:   Algorithmbar.h
* Author: zzDeagle545zz(Christopher Garcia)
* Version V1 Created on May 24, 2017.
*
* Function: To Create a Class to Display Speed of an Algorithm
*	For Comparative  Purposes.
*/

//Guard Block
#ifndef ALGORITMBAR_H
#define ALGORITMBAR_H

//Simple and Fast MultiMedia Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//System Library
#include <string>

//User Libraries
#include "Utilities.h"


//******************************************************************************
//******************************************************************************
//                              Algoritm Bar
//  
////////////////////////////////////////////////////////////////////////////////
class AlgBar {
private:
//Functional Members
	//Primatives
	float percent;						//Completeion Precent <=1
//GUI Elements
	//Loading Bar
	HexBar* lBar;						//Loading Bar
	//Retangles
	sf::RectangleShape*	vBttn;			//View Button
	//Texts
	sf::Text* sName;					//Sort Name
	sf::Text* pTxt;						//Percentage Text
	//Font
	sf::Font* font;						//Text Font
protected:

public:
	AlgBar(sf::String,sf::Font*,sf::Vector2f);	//Constructor
	~AlgBar();									//Destructor
//Management Functions
	void setPosition(float,float);				//Sets the positions of all the Items
//Display Functions
	void draw(sf::RenderWindow*);				//Draws Elements to Screen
	void update();								//Updates the Loading Bar
	void addPercent(float f) { if(percent<1)percent += f; }
//Accessor Functions
	float getPercent() { return percent; }
//Manipulation Functions
	void setPercent(float f) { percent = f; }
};

#endif //ALGORITMBAR_H