/*
 * layers.h
 *
 *  Created on: Jun 23, 2019
 *      Author: dangn
 */

#ifndef SRC_LAYERS_H_
#define SRC_LAYERS_H_

#include "matrix.h"

Matrix weight(int row, int col, int id);
Matrix bias(int row, int col, int id);

#endif /* SRC_LAYERS_H_ */
