#include <iostream>
using namespace std;

void fullPriceProduct(){
    int priceProduct;
    int priceDilivery;
    double sale;
    cout << "Введите стоимость товара: ";
    cin >> priceProduct;
    cout << "Введите стоимость доставки: ";
    cin >> priceDilivery;
    cout << "Введите скидку в % ";
    cin >> sale;
    cout << "----Считаем----\n";
    double result = (priceProduct + priceDilivery) * (1 - (sale/100));
    cout << "Итоговая цена: " << result << " руб";
}

int main() {
    fullPriceProduct();
    return 0;
}