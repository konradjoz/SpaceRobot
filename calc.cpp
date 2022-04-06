#include "hFramework.h"
//#include "hCloudClient.h"
#include <stddef.h>
#include <stdio.h>

using namespace hFramework;

void calculation(int n1, int n2, char oper) {
	switch (oper) {
	case '+':
		printf("%d + %d = %d\r\n", n1, n2, n1 + n2);
		break;
	case '-':
		printf("%d - %d = %d\r\n", n1, n2, n1 - n2);
		break;
	case '*':
		printf("%d * %d = %d\r\n", n1, n2, n1 * n2);
		break;
	case '/':
		printf("%d / %d = %d\r\n", n1, n2, n1 / n2);
		break;
	}
}

void hMain()
{
	sys.setLogDev(&Serial);	
    bool repeat = true;
	while (repeat == true) {
		printf("Order of Operation 'Int' 'operator' 'Int' (Excluding Divsion by Zero)\r\n");
		int num1 = 0;
		int num2 = 0;
		char operators[] = { '+', '-', '*', '/'};
		int operator_select = 0;
		
		printf("Enter an 1st integer (Btn1 - Addtion) and (Btn2 - Confirm Choice) \r\n");
		while (true){
			if (hBtn2.isPressed()) {
				printf("Confirmed Choice: %d", num1);
				break;
			}
			if (hBtn1.isPressed()) {
				num1++;
				printf("Int Count: %d \r\n", num1);
				hBtn1.waitForReleased();
			}
		}
		printf("Enter an operator (Btn1 - New Operator) and (Btn2 - Confirm Choice) \r\n");
		while (true){
			if (hBtn2.isPressed()) {
				if (operator_select == 0){
					printf("Selected Operator: (Default Operator) (+) \r\n");
				}
				break;
			}
			if (hBtn1.isPressed()) {
				if (operator_select == 4){
					operator_select = 0;
				}
				else{
					operator_select++;
				}

				printf("Selected Operator: %c \r\n", operators[operator_select]);
				hBtn1.waitForReleased();
			}
		}
		printf("Enter an 2nd integer (Btn1 - Addtion) and (Btn2 - Confirm Choice) \r\n");
		while (true){
			if (hBtn2.isPressed()) {
				if (num2 != 0) {
					printf("Confirmed Choice: %d", num2);
					break;
				}
				else {
					printf("Sorry division by 0 is not possible. Try Again.\r\n");
					continue;
				}
			}
			if (hBtn1.isPressed()) {
				num1++;
				printf("Int Count: %d \r\n", num1);
				hBtn1.waitForReleased();
			}
		}
		
		calculation(num1, num2, operators[operator_select]);

		printf("Continue using Calculator? [Btn1] - Yes, [Btn2] - No \r\n");
		while (true){
			if (hBtn2.isPressed()) {
				printf("Exiting Calculator...\r\n");
				repeat = false;
			}
			if (hBtn1.isPressed()) {
				printf("Continuing Calculator \r\n");
				break;
			}
		}
	}
}


