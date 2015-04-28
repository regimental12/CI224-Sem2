/*
 * Inventory.h
 *
 *  Created on: 27 Apr 2015
 *      Author: George
 */

#ifndef SRC_INVENTORY_H_
#define SRC_INVENTORY_H_

#include "GL/gl.h"

class Inventory {
public:
	Inventory();
	~Inventory();

	int getBlockCount(GLuint type);
	void incBlockCount(GLuint type);
	void decBlockCount(GLuint type);
private:
	int dirtCount;
	int stoneCount;
};

#endif /* SRC_INVENTORY_H_ */
