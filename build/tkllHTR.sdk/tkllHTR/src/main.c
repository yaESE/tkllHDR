//#include <stdlib.h>
//#include "xil_printf.h"
//#include "xuartps.h"
//#include "xparameters.h"
//#include "sleep.h"
//#include "mlp.h"
//#include "matrix.h"
//
//#define INPUT_SIZE			10
//#define BUFFER_SIZE 		(INPUT_SIZE*3 + 1)	// *3 since each number is represented as 'xxx', +1 for '\0' character
//#define IDLE_STATE 			1
//#define EXECUTION_STATE 	2
//#define RESULT_STATE 		3
//
//XUartPs Uart; // Instance of the UART Device
//
//static u8 SendBuffer[BUFFER_SIZE];	// Buffer for Sending Data
//static u8 RecvBuffer[BUFFER_SIZE];	// Buffer for Receiving Data
//
//int main(){
//	int state = IDLE_STATE;
//	int result = -1;
//	Matrix input = new_matrix(1, 784);
//
//	// Lookup configuration for the UART
//	XUartPs_Config* Config = XUartPs_LookupConfig(XPAR_XUARTPS_0_DEVICE_ID);
//
//	// Initialize UART with the above configuration
//	XUartPs_CfgInitialize(&Uart, Config, Config->BaseAddress);
//
//	// Set receive timeout to detect an idle connection
//	XUartPs_SetRecvTimeout(&Uart, 8);
//
//	while (1) {
//		switch (state) {
//			case IDLE_STATE:
//				// Reset
//				memset(RecvBuffer, 0, BUFFER_SIZE);
//				memset(SendBuffer, 0, BUFFER_SIZE);
//
//				// Wait until there is incoming data
//				while (!XUartPs_IsReceiveData(XPAR_XUARTPS_0_BASEADDR));
//
//				// Short delay to ensure the UART receive properly
//				usleep(1000);
//
//				///////////////////////////// DEBUG
//				int cnt;
//
//				// Receive data from UART
//				cnt = XUartPs_Recv(&Uart, RecvBuffer, BUFFER_SIZE);
//
//
//				xil_printf("Received bytes: %d\n\r", cnt);
//				// Transfer RecvBuffer to input matrix
//				for (int i = 0 ; i < INPUT_SIZE ; ++i){
//					input.at[0][i] = 0;
//					for (int j = i*3 ; j < i*3 + 3 ; ++j){
//						input.at[0][i] = input.at[0][i]*10 + RecvBuffer[j] - '0';
//					}
//				}
//
//				// Normalize input to 0-1
////				for (int i = 0 ; i < INPUT_SIZE ; ++i)
////					input.at[0][i] /= 255.0;
//
//				state = EXECUTION_STATE;
//				break;
//
//			case EXECUTION_STATE:
//				//result = MLP(input);
//				result = input.at[0][0];
//				state = RESULT_STATE;
//				break;
//
//			case RESULT_STATE:
//				for (int i = 0 ; i < INPUT_SIZE ; ++i){
//					for (int j = i*3 + 2 ; j >= i*3 ; --j){
//						SendBuffer[j] = (int)(input.at[0][i]) % 10 + '0';
//						input.at[0][i] = (int)(input.at[0][i]) / 10;
//					}
//				}
//				SendBuffer[BUFFER_SIZE-1] = '\n';
//				XUartPs_Send(&Uart, SendBuffer, BUFFER_SIZE);
//				state = IDLE_STATE;
//				break;
//
//			default:
//				state = IDLE_STATE;
//				break;
//		}
//	}
//	return 0;
//}




#include <stdlib.h>
#include "xil_printf.h"
#include "xuartps.h"
#include "xparameters.h"
#include "sleep.h"
#include "mlp.h"
#include "matrix.h"

int main(){

	return 0;
}
