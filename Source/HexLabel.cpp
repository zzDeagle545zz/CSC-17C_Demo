/*
Description
*/

//Simple and Fast MultiMedia Libraries

//System Libraries
#include <iostream>

//User Libraries
#include "HexGUI.h"


//******************************************************************************
//******************************************************************************
//                            HexLabel
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//******************************************************************************
//					 HexLabel(Size Vector, Hex Style)
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
HexLabel::HexLabel(sf::Vector2f xy,sf::String s1,HexStyle* s) {
//Create GUI Elements
	//Style
	style = s;
	//Font
	font = style->fBody;
	//Hexagon
	hex = new HexButton(SQ3*xy.y/4);				//Emblem
	//Rectangle
	uLine = new sf::RectangleShape(sf::Vector2f(xy.x,2));			//Underline
	hitBox = new sf::RectangleShape(sf::Vector2f(xy.x +hex->getL()*2, xy.y));
	//Text
	label = new sf::Text(s1, *font,style->chBody);
//Confgiure Data
	configure(style);
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
HexLabel::~HexLabel() {
//Reallocate Resources
	//HexButton
	delete hex;
	//Rectangles
	delete uLine;delete hitBox;
	//Text
	delete label;
}
//******************************************************************************
//******************************************************************************
//								SetPosition
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void HexLabel::setPosition(float x,float y) {
//SetPosition of the Elements
	//HexButton
	hex->setPosition(x, y);
	//Rectangles
	uLine->setPosition(x + hex->getL(), y + .5f*SQ3*hex->getL());
	hitBox->setPosition(x - hex->getL(), y);
	//Text
	label->setPosition(x + hex->getL()+10, y);
}
//******************************************************************************
//******************************************************************************
//									Draw
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void HexLabel::draw(sf::RenderWindow* win) {
//Draw Elements
	win->draw(*hex);
	win->draw(*uLine);
	win->draw(*label);
}
//******************************************************************************
//******************************************************************************
//								Configure
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void HexLabel::configure(HexStyle* style) {
//Configure
	//HexButtons
	hex->setFillColor(style->cFill);
	hex->setOutlineColor(style->cOutline);
	hex->setOutlineThickness(style->oThick);
	//Rectangles
	uLine->setFillColor(style->cFill);				//Underline
	uLine->setOutlineColor(style->cFill);
	uLine->setOutlineThickness(style->oThick);
	lOrigin(uLine);
	hitBox->setFillColor(sf::Color(0, 255, 0, 100));	//HitBox
	lOrigin(hitBox);
	//Font
	font = style->fBody;
	//Text
	label->setCharacterSize(style->chBody);
	label->setColor(style->cText);
	lOrigin(label);
}
//******************************************************************************
//								Is In
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
bool HexLabel::isIn(sf::Vector2f xy) {
//Check the Hit box
	if (hitBox->getGlobalBounds().contains(xy)) {
		label->setColor(style->cHover);
		hex->setOutlineColor(style->cHover);
		uLine->setOutlineColor(style->cHover);
		uLine->setFillColor(style->cHover);
		return true;
	}
	else {
		label->setColor(style->cText);
		hex->setOutlineColor(style->cOutline);
		uLine->setOutlineColor(style->cFill);
		uLine->setFillColor(style->cFill);
		return false;
	}
}