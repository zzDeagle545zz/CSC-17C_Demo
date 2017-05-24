/*
Description
*/

//Simple and Fast MultiMedia Libraries

//System Libraries
#include <iostream>

//User Libraries
#include "HexTree.h"


//******************************************************************************
//******************************************************************************
//								 HexTree
//  
////////////////////////////////////////////////////////////////////////////////
//******************************************************************************
//******************************************************************************
//								HexTree()
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
HexTree::HexTree(HexStyle* style) {
//Initalize Place
	place = 0;
//Create the Root Node
	//Create the Nodes
	root = new HexNode;
	n1 = new HexNode;
	n2 = new HexNode;
	n3 = new HexNode;
	n4 = new HexNode;
	n5 = new HexNode;
	n6 = new HexNode;
	n7 = new HexNode;
	n8 = new HexNode;
	n9 = new HexNode;
	//Create the Buttons
	root->hex = new HexButton(40, "R", style);
	n1->hex = new HexButton(40, "A", style);
	n2->hex = new HexButton(40, "B", style);
	n3->hex = new HexButton(40, "C", style);
	n4->hex = new HexButton(40, "D", style);
	n5->hex = new HexButton(40, "E", style);
	n6->hex = new HexButton(40, "F", style);
	n7->hex = new HexButton(40, "G", style);
	n8->hex = new HexButton(40, "H", style);
	n9->hex = new HexButton(40, "I", style);
	//Create Links
	links = new HexButton[9];
	for (int c = 0;c < 9;c++)
		links[c].configure(style);
	//Link Tree
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->left = NULL;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	n4->left = NULL;
	n4->right = NULL;
	n5->left = n8;
	n5->right = n9;
	n6->left = NULL;
	n6->right = NULL;
	n7->left = NULL;
	n7->right = NULL;
	n8->left = NULL;
	n8->right = NULL;
	n9->left = NULL;
	n9->right = NULL;
	//Confiure Data
	n1->hex->setFillColor(sf::Color(80, 80, 80, 100));
	n1->hex->setOutlineColor(sf::Color(0,255,255, 100));
	n1->hex->getText()->setColor(sf::Color(0,255,255,120));
	n2->hex->setFillColor(sf::Color(80, 80, 80, 100));
	n2->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	n2->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	n3->hex->setFillColor(sf::Color(80, 80, 80, 100));
	n3->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	n3->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	n4->hex->setFillColor(sf::Color(80, 80, 80, 100));
	n4->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	n4->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	n5->hex->setFillColor(sf::Color(80, 80, 80, 100));
	n5->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	n5->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	n6->hex->setFillColor(sf::Color(80, 80, 80, 100));
	n6->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	n6->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	n7->hex->setFillColor(sf::Color(80, 80, 80, 100));
	n7->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	n7->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	n8->hex->setFillColor(sf::Color(80, 80, 80, 100));
	n8->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	n8->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
	n9->hex->setFillColor(sf::Color(80, 80, 80, 100));
	n9->hex->setOutlineColor(sf::Color(0, 255, 255, 100));
	n9->hex->getText()->setColor(sf::Color(0, 255, 255, 120));
}
//******************************************************************************
//******************************************************************************
//								HexTree()
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
HexTree::~HexTree() {
//Delete Items
	//Hexagon Buttons
	delete root->hex;delete n1->hex;delete n2->hex;delete n3->hex;delete n4->hex;
	delete n5->hex;delete n6->hex;delete n7->hex;delete n8->hex;delete n9->hex;
	delete[] links;
	//Hex Nodes
	delete root;delete n1;delete n2;delete n3;delete n4;delete n5;delete n6;
	delete n7;delete n8;delete n9;
}
//******************************************************************************
//******************************************************************************
//								setPosition
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void HexTree::setPosition(float x,float y) {
//Set the Root Node
	root->hex->SetPosition(x, y);
	setTree(root);
}
//******************************************************************************
//******************************************************************************
//								Set Tree
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void HexTree::setTree(HexNode* node) {
//Check for Leaves of tree
	if (node->left == NULL&&node->right == NULL)
		return;
//Quick Calc
	int L = node->hex->getL();
//Set left Nodes
	if (node->left != NULL) {
		node->left->hex->SetPosition(node->hex->getPosition().x - 3 * L,
			node->hex->getPosition().y + L * 3);
		links[place].setPosition(node->hex->getPosition().x - 3 * L /2,
			node->hex->getPosition().y + L * 3 /2);
		place++;
	}
//Set Right Node
	if (node->right != NULL) {
		node->right->hex->SetPosition(node->hex->getPosition().x + 3 * L,
			node->hex->getPosition().y + L * 3);
		links[place].setPosition(node->hex->getPosition().x + 3 * L/2,
			node->hex->getPosition().y + L * 3/2 );
		place++;
	}
	if (node->left != NULL)setTree(node->left);
	if (node->right != NULL)setTree(node->right);
}
//******************************************************************************
//******************************************************************************
//								draw
//Function- 
//Inputs
//      
//Outputs
//      
////////////////////////////////////////////////////////////////////////////////
void HexTree::draw(sf::RenderWindow* win) {
//Draw Elements to Screen
	root->hex->draw(win);
	n1->hex->draw(win);
	n2->hex->draw(win);
	n3->hex->draw(win);
	n4->hex->draw(win);
	n5->hex->draw(win);
	n6->hex->draw(win);
	n7->hex->draw(win);
	n8->hex->draw(win);
	n9->hex->draw(win);
	for (int c = 0;c < 9;c++)
		links[c].draw(win);
}