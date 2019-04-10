#include <stdio.h>
#include <stdlib.h>

/**
 * @file 3-stock-trading.c
 * @author Saif Aljashamy
 * @date 10 April 2019
 * @brief stock's portfolio profits, commission and total stocks
 *
 * @see https://github.com/saljashamy/CS2560/blob/master/hw2
 */

const float brokerCommissionRate = 2.00; /**< broker commission percentage **/
struct Portfolio portfolio;

/**
 * @brief stock's portfolio struct
 */
struct Portfolio{
	int stockBuyAmount; /**< total stock shares purchased **/
	int stockSellAmount;  /**< total stock shares sold **/
	float stockBuyPrice;  /**< stock buy price **/
	float stockSellPrice;  /**< stock sell price **/
	float brokerBuyCommission;  /**< broker total buying commission **/
	float brokerSellCommission;  /**< broker total selling commission **/
	float profit; /**< total portfolio profit **/
};

/**
 * @brief buys n stocks at current price and calculates broker buying commission
 * @param shares total buy stocks
 * @param price buy price of stock
 */
void buyStock(int shares, float price){
	portfolio.stockBuyAmount = shares;
	portfolio.stockBuyPrice = price;
	portfolio.brokerBuyCommission = shares * price *(brokerCommissionRate/100);
}

/**
 * @brief sells n stocks at current price and calculate broker selling commission
 * @param shares total sell stocks
 * @param price sell price of stock
 */
void sellStock(int shares, float price){
	portfolio.stockSellAmount = shares;
	portfolio.stockSellPrice = price;
	portfolio.brokerSellCommission = shares * price *(brokerCommissionRate/100);
	portfolio.profit = (shares * price) - (portfolio.stockBuyAmount * portfolio.stockBuyPrice + portfolio.brokerBuyCommission + portfolio.brokerSellCommission);
}

/**
 * @brief print portfolio information profits, commission and total stocks
 */
void printPortfolioInfo(){
	printf("Paid amount for %d stocks at $%.2f : $%.2f\n", portfolio.stockBuyAmount, portfolio.stockBuyPrice, portfolio.stockBuyAmount * portfolio.stockBuyPrice);
	printf("Buy commission amount                 : $%.2f\n", portfolio.brokerBuyCommission);
	printf("Sell price                            : $%.2f\n", portfolio.stockSellPrice);
	printf("Sell commission amount                : $%.2f\n", portfolio.brokerSellCommission);
	printf("Profit                                : $%.2f\n", portfolio.profit);
}

