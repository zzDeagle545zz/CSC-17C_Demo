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
//								 HexSelect
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//******************************************************************************
//						HexSelect(Hex Size,Label,Style)
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
HexSelect::HexSelect(int sLgth, sf::String s1,sf::String s2, HexStyle* s) {
//
	spinning = false;
//Create GUI Elements
	//Style
	style = s;
	//Font
	font = style->fBody;
	//HexButton
	hex = new HexButton(sLgth, s2, style);
	//Triangles
	lTri = new sf::ConvexShape(3);
	rTri = new sf::ConvexShape(3);
	//Text
	descrip = new sf::Text(s1, *font,style->chBody);
//Set Point Data for Triangles
	//Left Triangle
	lTri->setPoint(0, sf::Vector2f(0, 0));
	lTri->setPoint(1, sf::Vector2f(0-.5f*sLgth*SQ3*.7f, .5f*sLgth*.7f));
	lTri->setPoint(2, sf::Vector2f(0, sLgth*.7f));
	lTri->setOrigin(sf::Vector2f(0, .5f*sLgth*.7f));
	//Right Triangle
	rTri->setPoint(0, sf::Vector2f(0, 0));
	rTri->setPoint(1, sf::Vector2f(0 + .5f*sLgth*SQ3*.7f, .5f*sLgth*.7f));
	rTri->setPoint(2, sf::Vector2f(0,sLgth*.7f));
	rTri->setOrigin(sf::Vector2f(0, .5f*sLgth*.7f));
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
HexSelect::~HexSelect() {
//Release Resources
	//HexButton
	delete hex;
	//Triagnles
	delete lTri;delete rTri;
	//Text
	delete descrip;
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
void HexSelect::setPosition(float x, float y) {
//Set the Hex Button
	//HexButton
	hex->SetPosition(x, y);
	//Triangles
	lTri->setPosition(x-hex->getL()-20,y);
	rTri->setPosition(x + hex->getL() + 20, y);
	//Text
	descrip->setPosition(x, y -hex->getL()- 10 - descrip->getLocalBounds().height / 2);
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
void HexSelect::configure(HexStyle* style) {
//Configure Data
	//Triangles
	lTri->setFillColor(style->cFill);				//Left
	lTri->setOutlineColor(style->cOutline);
	lTri->setOutlineThickness(style->oThick);
	rTri->setFillColor(style->cFill);				//Right
	rTri->setOutlineColor(style->cOutline);
	rTri->setOutlineThickness(style->oThick);
	//Font
	font = style->fBody;
	//Text
	descrip->setCharacterSize(style->chBody);
	descrip->setColor(style->cText);
	cOrigin(descrip);
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
void HexSelect::draw(sf::RenderWindow* win) {
//Draw GUI Item to screen
	hex->draw(win);
	win->draw(*lTri);
	win->draw(*rTri);
	win->draw(*descrip);
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
void HexSelect::update() {
//Spin the Hex Button if necessary
	if (spinning) {
	//Left Spin
		if (left) {
			if (hex->getRotation() > rotate) {
				hex->rotate(-240 * T.fTime);
			} else {
				hex->setRotation(rotate);
				left = false;
				hex->setRotation(0);
				rotate = 0;
				spinning = false;
			}
		}
	//Right Spin
		else if (right) {
			if (hex->getRotation() < rotate) {
				hex->rotate(240 * T.fTime);
			}
			else {
				hex->setRotation(rotate);
				left = false;
				rotate = 0;
				hex->setRotation(0);
				spinning = false;
			}
		}
	}
}
//******************************************************************************
//******************************************************************************
//								IsLeft
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
bool HexSelect::isLeft(sf::Vector2f xy) {
//Check if Mouse is in Left Triangle
	if (lTri->getGlobalBounds().contains(xy)) {
		lTri->setOutlineColor(style->cHover);
		return true;
	}
	else {
		lTri->setOutlineColor(style->cOutline);
		return false;
	}
}
//******************************************************************************
//******************************************************************************
//								IsRight
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
bool HexSelect::isRight(sf::Vector2f xy) {
	//Check if Mouse is in Left Triangle
	if (rTri->getGlobalBounds().contains(xy)) {
		rTri->setOutlineColor(style->cHover);
		return true;
	}
	else {
		rTri->setOutlineColor(style->cOutline);
		return false;
	}//////CHANGE
}
//******************************************************************************
//******************************************************************************
//								Spin
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void HexSelect::spin(int dir,int spins) {
//Spins left on Zero, Right on 1
	if (spinning)
		return;
//Rotate left or right
	switch (dir) {
	//Left
	case LEFT:
		left = true;right = false;
		rotate = spins* 60;
		hex->setRotation(rotate+60);
		spinning = true;
		break;
	//Right
	case RIGHT:
		right = true;left = false;
		rotate = spins * 60;
		spinning = true;
		break;
	}
}