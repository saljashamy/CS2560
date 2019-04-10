#include <stdio.h>

/**
 * @file 1-restaurant-bill.c
 * @author Saif Aljashamy
 * @date 10 April 2019
 * @brief calculate bill of restaurant meal
 *
 * @see https://github.com/saljashamy/CS2560/blob/master/hw2
 */

const float taxRate = 6.75; /**< tax rate **/
const float tipRate = 20;  /**< tip rate **/

/**
 * @brief calculates and returns total bill 
 * @param mealCharge meal cost
 * @param mealTax tax of meal cost
 * @param mealTip tip of total cost
 */
float calculateTotalBill(float mealCharge, float mealTax, float mealTip){
	return mealCharge + mealTax + mealTip;
}

/**
 * @brief calculates tax of meal cost
 * @param mealCharge meal cost
 */
float calculateTax(float mealCharge){
	return mealCharge*(taxRate/100);
}

/**
 * @brief calculates tip of total meal cost
 * @param mealCharge meal cost
 * @param mealTax tax of meal cost
 */
float calculateTip(float mealCharge, float mealTax){
	return (mealCharge + mealTax)*(tipRate/100);
}

/**
 * @brief prints bill 
 * @param mealCharge meal cost
 */
void printBill(float mealCharge){
	printf("meal charge: $%.2f\n", mealCharge);
	float mealTax = calculateTax(mealCharge);
	printf("tax        : $%.2f\n", mealTax);
	float mealTip = calculateTip(mealCharge, mealTax);
	printf("tip        : $%.2f\n", mealTip);
	float totalBill = calculateTotalBill(mealCharge, mealTax, mealTip);
	printf("total bill : $%.2f\n", totalBill);
}
