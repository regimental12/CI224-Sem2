/*
 * Inventory.cpp
 *
 *  Created on: 27 Apr 2015
 *      Author: George
 */

#include "Inventory.h"


/**
 * Inventory constructor.
 * Initialises block counts to 0.
 */
Inventory::Inventory()
	:dirtCount(0),
	 stoneCount(0)
{

}

/**
 * Empty inventory destructor.
 *
 * @returns NULL
 */
Inventory::~Inventory() {

}

/**
 * Inventory method to get block count of a certain type.
 *
 * @param type - Type of block to get the count for.
 *
 * @return INT - number of blocks of passed in type.
 */
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

/**
 * Method to increment block count for a certain type.
 *
 * @param type - Type of block to increment count for.
 *
 * @return NULL
 */
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

/**
 * Method to decrement block count for a certain type.
 *
 * @param type - Type of block to decrement count for.
 *
 * @return NULL
 */
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
