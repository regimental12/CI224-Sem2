/*
 * Inventory.cpp
 *
 *  Created on: 27 Apr 2015
 *      Author: George
 */

#include "Inventory.h"

Inventory::Inventory()
	:dirtCount(0),
	 stoneCount(0)
{
	// TODO Auto-generated constructor stub

}

Inventory::~Inventory() {
	// TODO Auto-generated destructor stub
}

int Inventory::getBlockCount(GLuint type)
{
	switch (type)
	{
	case 1:
		return dirtCount;
		break;
	case 2:
		return stoneCount;
		break;
	default:
		return 0;
	}
}

void Inventory::incBlockCount(GLuint type)
{
	switch (type)
	{
	case 1:
		dirtCount++;
		break;
	case 2:
		stoneCount++;
		break;
	default:
		break;
	}
}

void Inventory::decBlockCount(GLuint type)
{
	switch (type)
	{
	case 1:
		dirtCount--;
		break;
	case 2:
		stoneCount--;
		break;
	default:
		break;
	}
}
