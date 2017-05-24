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
//								 HexButton
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//******************************************************************************
//								HexButton()
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
HexButton::HexButton() {
//Declare Variables
	size = 10;
	text = new sf::Text();
//Creates the Hexagon Shape
	this->setPointCount(6);
	//Set Points of the Hexagon
	this->setPoint(0, sf::Vector2f		//Point 1
		(this->getOrigin().x - .5f*size, this->getOrigin().y - SQ3/2* size));
	this->setPoint(1, sf::Vector2f		//Point 2
		(this->getOrigin().x + .5f*size, this->getOrigin().y - SQ3 / 2 * size));
	this->setPoint(2, sf::Vector2f		//Point 3
		(this->getOrigin().x + size, this->getOrigin().y));
	this->setPoint(3, sf::Vector2f		//Point 4
		(this->getOrigin().x + .5f*size, this->getOrigin().y + SQ3 / 2 * size));
	this->setPoint(4, sf::Vector2f		//Point 5
		(this->getOrigin().x - .5f*size, this->getOrigin().y + SQ3 / 2 * size));
	this->setPoint(5, sf::Vector2f		//Point 6
		(this->getOrigin().x - size, this->getOrigin().y));
	//Set the Origin
	this->setOrigin(this->getPoint(5).x + size, getPoint(0).y + size*SQ3 / 2);

}
//******************************************************************************
//******************************************************************************
//								HexButton(int)
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
HexButton::HexButton(int sLgth) {
//Set Radial Length
	size = sLgth;
//Create Hexagon
	this->setPointCount(6);
//Set Points of the Hexagon
	this->setPoint(0, sf::Vector2f		//Point 1
		(this->getOrigin().x - .5f*size, this->getOrigin().y - SQ3 / 2 * size));
	this->setPoint(1, sf::Vector2f		//Point 2
		(this->getOrigin().x + .5f*size, this->getOrigin().y - SQ3 / 2 * size));
	this->setPoint(2, sf::Vector2f		//Point 3
		(this->getOrigin().x + size, this->getOrigin().y));
	this->setPoint(3, sf::Vector2f		//Point 4
		(this->getOrigin().x + .5f*size, this->getOrigin().y + SQ3 / 2 * size));
	this->setPoint(4, sf::Vector2f		//Point 5
		(this->getOrigin().x - .5f*size, this->getOrigin().y + SQ3 / 2 * size));
	this->setPoint(5, sf::Vector2f		//Point 6
		(this->getOrigin().x - size, this->getOrigin().y));
//Set the Origin
	this->setOrigin(this->getPoint(5).x + size, getPoint(0).y + size*SQ3 / 2);
}
//******************************************************************************
//******************************************************************************
//						HexButton(int,string,HexStyle*)
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
HexButton::HexButton(int sLgth, sf::String s1, HexStyle* s) {
//Set Radial Length
	size = sLgth;
//Set Style
	style = s;
//Set Font Refenece
	font = style->fBody;
//Create Text
	text = new sf::Text(s1, *font, style->chBody);
//Create Hexagon+
	this->setPointCount(6);
	//Set Points of the Hexagon
	this->setPoint(0, sf::Vector2f		//Point 1
		(this->getOrigin().x - .5f*size, this->getOrigin().y - SQ3 / 2 * size));
	this->setPoint(1, sf::Vector2f		//Point 2
		(this->getOrigin().x + .5f*size, this->getOrigin().y - SQ3 / 2 * size));
	this->setPoint(2, sf::Vector2f		//Point 3
		(this->getOrigin().x + size, this->getOrigin().y));
	this->setPoint(3, sf::Vector2f		//Point 4
		(this->getOrigin().x + .5f*size, this->getOrigin().y + SQ3 / 2 * size));
	this->setPoint(4, sf::Vector2f		//Point 5
		(this->getOrigin().x - .5f*size, this->getOrigin().y + SQ3 / 2 * size));
	this->setPoint(5, sf::Vector2f		//Point 6
		(this->getOrigin().x - size, this->getOrigin().y));
	//Set the Origin
	this->setOrigin(this->getPoint(5).x + size, getPoint(0).y + size*SQ3 / 2);
//Configure Data
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
HexButton::~HexButton() {
//Delete Text
	delete text;
}
//******************************************************************************
//******************************************************************************
//									Inside
//Function- Check to see if a X,Y Cordinate is in a shape
//Inputs
//      -->> Vector with X,Y cordinates
//Outputs
//      <<--
////////////////////////////////////////////////////////////////////////////////
bool HexButton::inside(sf::Vector2f cord) {
	//Check point in entire Float Rect
	if (!this->getGlobalBounds().contains(cord)) {
		this->setOutlineColor(style->cOutline);
		return false;
	}
	//Check Top left Triangle
	else if ((cord.y < -SQ3*(cord.x - (this->getPosition().x -
		(this->size*this->getScale().x))) + this->getPosition().y)) {
		this->setOutlineColor(style->cOutline);
		return false;
	}
	//Check Top Right Triangle
	else if ((cord.y < SQ3*(cord.x - (this->getPosition().x +
		(this->size*this->getScale().x))) + this->getPosition().y)) {
		this->setOutlineColor(style->cOutline);
		return false;
	}
	//Check Bot left Triangle
	else if ((cord.y > -SQ3*(cord.x - (this->getPosition().x +
		(this->size*this->getScale().x))) + this->getPosition().y)) {
		this->setOutlineColor(style->cOutline);
	return false;
	}
	//Check Top Right Triangle
	else if ((cord.y > SQ3*(cord.x - (this->getPosition().x -
		(this->size*this->getScale().x))) + this->getPosition().y)) {
		this->setOutlineColor(style->cOutline);
		return false;
	}
	//Its in!
	else {
		this->setOutlineColor(style->cHover);
		return true;
	}
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
void HexButton::SetPosition(float x, float y) {
//Set Postion of Hexagon
	this->setPosition(x, y);
//Set Position of Text
	text->setPosition(x, y);
}
//******************************************************************************
//******************************************************************************
//								Draw
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void HexButton::draw(sf::RenderWindow* win) {
//Draw Elements to the Screen
	win->draw(*this);
	win->draw(*text);
}
//******************************************************************************
//******************************************************************************
//									Configure
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void HexButton::configure(HexStyle* style) {
//Set GUI Attriubutes to Hex Style
	//Font
	font = style->fBody;
	//Colors
	this->setFillColor(style->cFill);
	this->setOutlineColor(style->cOutline);
	text->setColor(style->cText);
	//Values
	this->setOutlineThickness(style->oThick);
	text->setCharacterSize(style->chBody);
	//Text Configure
	text->setFont(*font);
	cOrigin(text);
}