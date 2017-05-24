/*
* File:   HexTree.h
* Author: zzDeagle545zz(Christopher Garcia)
* Version V1 Created on May 24, 2017.
*
* Function: To Create a Demo Tree Data Structure out of 
*	HexButtons
*/

//Guard Block
#ifndef HEXTREE_H
#define HEXTREE_H

//Simple and Fast MultiMedia Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//System Library

//User Libraries
#include "HexGUI.h"

//******************************************************************************
//******************************************************************************
//                              Hex Node
//  
////////////////////////////////////////////////////////////////////////////////
struct HexNode{
//Data 
	HexButton* hex;
//Child References
	HexNode* left;
	HexNode* right;
};
//******************************************************************************
//******************************************************************************
//                              Hex Tree
//  
////////////////////////////////////////////////////////////////////////////////
class HexTree {
private:
//Functional Members
	int place;
//GUI Elements
	//Root Node
	HexNode* root;
	//Nodes
	HexNode* n1;
	HexNode* n2;
	HexNode* n3;
	HexNode* n4;
	HexNode* n5;
	HexNode* n6;
	HexNode* n7;
	HexNode* n8;
	HexNode* n9;
	//Links
	HexButton* links;
protected:
//Utility Functions
	void setTree(HexNode*);					//Sets Position of Hex Tree
public:
//Constructors
	HexTree(HexStyle*);						//Creates the Tree with the Style
//Destructor
	~HexTree();
//Management Functions
	void setPosition(float,float);			//Sets postion of the Root Node 
	void draw(sf::RenderWindow*);
//Accessor Functions
	HexNode* getRoot() { return root; }
};

#endif //HEXTREE_H