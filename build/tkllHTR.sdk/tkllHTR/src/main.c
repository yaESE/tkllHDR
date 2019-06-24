/*
 * main.c
 *
 *  Created on: Jun 16, 2019
 *      Author: dangn
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xil_printf.h"
#include "sleep.h"
#include "mlp.h"
#include "operations.h"

#define INPUT_SIZE			784
#define BUFFER_SIZE 		(INPUT_SIZE*3 + INPUT_SIZE)
#define IDLE_STATE 			1
#define EXECUTION_STATE 	2
#define RESULT_STATE 		3

int main(){
	char buffer[BUFFER_SIZE];
	int state = IDLE_STATE;
	int result;
    double input[1][INPUT_SIZE];
    char* token;

	while (1) {
		switch (state) {
			case IDLE_STATE:
				gets(buffer);
				state = EXECUTION_STATE;
				break;
				
			case EXECUTION_STATE:
				token = strtok(buffer, ",");
				int i = 0;
				while (token != NULL){
					input[0][i] = 0;
					for (int j = 0 ; j < strlen(token) ; ++j)
						input[0][i] = input[0][i]*10 + token[j] - '0';
					token = strtok(NULL, ",");
					i++;
				}

				// Normalize input to 0-1
				for (int i = 0 ; i < INPUT_SIZE ; ++i)
					input[0][i] /= 255.0;







				/*----------------- FOR DEBUGGING PURPOSE -----------------*/
				//MLP(input);
				xil_printf("Begin MLP\n");





				double w0[UNIT_LAYER_INPUT][UNIT_LAYER_1] 	= WEIGHT_0;
				double b0[1][UNIT_LAYER_1] 					= BIAS_0;
				double w1[UNIT_LAYER_1][UNIT_LAYER_OUTPUT] 	= WEIGHT_1;
				double b1[1][UNIT_LAYER_OUTPUT] 			= BIAS_1;

				double hidden[1][UNIT_LAYER_1];
				MUL(hidden, input,  w0);
				ADD(hidden, hidden, b0);
				RELU(hidden);

				double output[1][UNIT_LAYER_OUTPUT];
				MUL(output, hidden, w1);
				ADD(output, output, b1);
				RELU(output);
				SOFTMAX(output);

				result = 0;
				for (int i = 0 ; i < LEN(output[0]) ; i++)
					if (output[0][i] > output[0][result])
						result = i;






				xil_printf("End MLP\n");

				/*----------------- FOR DEBUGGING PURPOSE -----------------*/






				state = RESULT_STATE;
				break;

			case RESULT_STATE:
				xil_printf("Result: %d\n", result);
				state = IDLE_STATE;
				break;

			default:
				state = IDLE_STATE;
				break;
		}
	}
	return 0;
}
