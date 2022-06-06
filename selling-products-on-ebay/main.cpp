/*You want to keep a track of how much profit you make from selling a product on Ebay.

Write a program that calculates the Fees charged, and Profit made from selling an item on Ebay.

The final value fee is calculated as 12.8% of the total amount of the sale (which includes
the item price, postage, taxes and any other applicable fees), plus a fixed charge of 30p per order.*/

#include <iostream>
#include <iomanip> 
using namespace std;

double  Calculate_Fee(double nSellingPrice, double nPostage);
double Banked(double nSellingPrice, double nPostage, double nFee);
double Calcualte_Profit(double nTotal, double nPostage, double nCostPrice);
void Display_Statement(double nFee, double nTotal, double nProfitMade);

int main()
{
    double nCostPrice, nSellingPrice, nPostage;
    double nFee, nTotal, nProfitMade;

    cout << "\n Enter Cost of item " << char(156);
    cin >> nCostPrice;

    cout << "\n Enter Selling price of item " << char(156);
    cin >> nSellingPrice;

    cout << "\n Enter Postage Cost " << char(156);
    cin >> nPostage;

    nFee = Calculate_Fee(nSellingPrice, nPostage);
    nTotal = Banked(nSellingPrice, nPostage, nFee);
    nProfitMade = Calcualte_Profit(nTotal, nPostage, nCostPrice);
    Display_Statement(nFee, nTotal, nProfitMade);


    return 0;
}

//Function calculates the Ebay Fees charged at 12.8%, plus a fixed charge of 30p per order.
double Calculate_Fee(double nSellingPrice, double nPostage)
{
    double nFeeCharged = (((nSellingPrice + nPostage) * 12.8) / 100) + 0.30;

    return nFeeCharged;
}

//Function Calculate the total amount sent to your bank via Ebay
double Banked(double nSellingPrice, double nPostage, double nFee)
{
    double nTotal = (nSellingPrice + nPostage) - nFee;

    return nTotal;
}

//Function Calculates the amount sent to the Back via Ebay
double Calcualte_Profit(double nTotal, double nPostage, double nCostPrice)
{
    double nProfit = nTotal - (nPostage + nCostPrice);

    return nProfit;
}

void Display_Statement(double nFee, double nTotal, double nProfitMade)
{
    cout << fixed << setprecision(2);  //sets output values to 2 decimal places
    
    cout << "\n Fee you will be charged by Ebay to you. " << char(156) << nFee;
    cout << "\n Money that will be sent to your Bank account " << char(156) << nTotal;
    cout << "\n Profit you will make after subtracting the Cost of the item " << char(156) << nProfitMade << "\n\n";

    return;
}

