/*
Description
*/

//Simple and Fast MultiMedia Libraries

//System Libraries
#include <iostream>

//User Libraries
#include "AlgoritmBar.h"

//******************************************************************************
//******************************************************************************
//                            Algoritm Bar
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//                         Algoritm Bar
//Function- 
//Inputs
//      -->>
//Outputs
//      <<-- None
////////////////////////////////////////////////////////////////////////////////
AlgBar::AlgBar(sf::String t,sf::Font* f,sf::Vector2f a) {
//Create the Bar Elements
	//Percent
	percent = 0;
	//Hexagon Bar
	lBar = new HexBar(a.x, a.y);
	//Rectangles
	vBttn = new sf::RectangleShape(sf::Vector2f(100,50));
	//Text
	sName = new sf::Text(t, *f, 26);
	pTxt = new sf::Text("0%", *f, 26);
	//Font
	font = f;							//Uses Menu's Font
//Configure the Data
	//Hexagon Bar
	lBar->setOrigin(1);									//Loading Bar
	//Rectangle
	vBttn->setOutlineThickness(2);						//View Button
	vBttn->setOutlineColor(sf::Color::Cyan);
	vBttn->setFillColor(sf::Color(100, 100, 100, 255));
	lOrigin(vBttn);
	//Text
	sName->setColor(sf::Color::Cyan);					//Sort Name
	lOrigin(sName);
	pTxt->setColor(sf::Color::Cyan);					//Percentage Value
	cOrigin(pTxt);
}
//******************************************************************************
//                         Algoritm Bar (Destructor)
//Function- 
//Inputs
//      -->>
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
AlgBar::~AlgBar() {
//Free up Resources
	//Loading bar
	delete lBar;
	//Rectangles
	delete vBttn;
	//Texts
	delete sName; delete pTxt;
}
//******************************************************************************
//								SetPosition
//Function- 
//Inputs
//      -->>
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void AlgBar::setPosition(float x, float y) {
//Set Positions Based on Load Bar
	//Set LoadBar Position
	lBar->setPosition(x, y);
	//Set Title Position
	sName->setPosition(x,y-lBar->getWidth());
	//Set Rectangle Button
	vBttn->setPosition(x + lBar->getLength()+lBar->getHex()->getL()*2, y);
	//Set Percentage Value
	pTxt->setPosition(vBttn->getPosition().x+vBttn->getLocalBounds().width/2,
		vBttn->getPosition().y);
}
//******************************************************************************
//								Draw
//Function- 
//Inputs
//      -->>
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void AlgBar::draw(sf::RenderWindow* win) {
//Draw Elements to the Screen
	lBar->draw(win);
	win->draw(*vBttn);
	win->draw(*sName);
	win->draw(*pTxt);
}
//******************************************************************************
//								Update
//Function- 
//Inputs
//      -->>
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
void AlgBar::update() {
//Check if Load bar is Above 100%
	if (percent > 1)percent = 1;
//Update the Status of Load Bar and %
	lBar->update(percent);
	pTxt->setString(std::to_string(static_cast<int>(percent * 100))+"%");
	cOrigin(pTxt);
}