#include <stdio.h>


const float taxRate = 6.75;
const float tipRate = 20;

float calculateTotalBill(float mealCharge, float mealTax, float mealTip){
	return mealCharge + mealTax + mealTip;
}

float calculateTax(float mealCharge){
	return mealCharge*(taxRate/100);
}

float calculateTip(float mealCharge, float mealTax){
	return (mealCharge + mealTax)*(tipRate/100);
}

void printBill(float mealCharge){
	printf("meal charge: $%.2f\n", mealCharge);
	float mealTax = calculateTax(mealCharge);
	printf("tax        : $%.2f\n", mealTax);
	float mealTip = calculateTip(mealCharge, mealTax);
	printf("tip        : $%.2f\n", mealTip);
	float totalBill = calculateTotalBill(mealCharge, mealTax, mealTip);
	printf("total bill : $%.2f\n", totalBill);
}
