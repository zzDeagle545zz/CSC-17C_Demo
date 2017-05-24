/*
* File:   Button.h
* Author: zzDeagle545zz(Christopher Garcia)
* Version V1 Created on May 24, 2017.
*
* Function: Creat a Rectangle Button with Descriptor
*/

//Guard Block
#ifndef BUTTON_H
#define BUTTON_H

//Simple and Fast MultiMedia Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//User Libraries
#include "Utilities.h"

//******************************************************************************
//******************************************************************************
//								 Button
//  
////////////////////////////////////////////////////////////////////////////////
class Button :public sf::RectangleShape {
private:
	//Text
	sf::Text bString;
protected:

public:
//Constructor/Destructor
	Button(sf::Vector2f,sf::String);
	~Button();
//Management Functions
	void setPosition(float, float);
//Acsessor Functions
	sf::Text* getText() { return &bString; }
//Manipulation Functions
	void setTOc() { cOrigin(&bString); }	//Sets Origin of Text, Center
	void setTOl() { lOrigin(&bString); }	//Sets Origin of Text, Left
	void setTOr() { rOrigin(&bString); }	//Sets Origin of Text, Right
};

#endif //BUTTON_H