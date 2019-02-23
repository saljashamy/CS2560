#include <stdio.h>
#include <stdlib.h>

const float brokerCommissionRate = 2.00;
struct Portfolio portfolio;

struct Portfolio{
	int stockBuyAmount;
	int stockSellAmount;
	float stockBuyPrice;
	float stockSellPrice;
	float brokerBuyCommission;
	float brokerSellCommission;
	float profit;
};

void buyStock(int shares, float price){
	portfolio.stockBuyAmount = shares;
	portfolio.stockBuyPrice = price;
	portfolio.brokerBuyCommission = shares * price *(brokerCommissionRate/100);
}

void sellStock(int shares, float price){
	portfolio.stockSellAmount = shares;
	portfolio.stockSellPrice = price;
	portfolio.brokerSellCommission = shares * price *(brokerCommissionRate/100);
	portfolio.profit = (shares * price) - (portfolio.stockBuyAmount * portfolio.stockBuyPrice + portfolio.brokerBuyCommission + portfolio.brokerSellCommission);
}

void printPortfolioInfo(){
	printf("Paid amount for %d stocks at $%.2f : $%.2f\n", portfolio.stockBuyAmount, portfolio.stockBuyPrice, portfolio.stockBuyAmount * portfolio.stockBuyPrice);
	printf("Buy commission amount                 : $%.2f\n", portfolio.brokerBuyCommission);
	printf("Sell price                            : $%.2f\n", portfolio.stockSellPrice);
	printf("Sell commission amount                : $%.2f\n", portfolio.brokerSellCommission);
	printf("Profit                                : $%.2f\n", portfolio.profit);
}


