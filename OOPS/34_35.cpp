#include <iostream>
#include <string>

using namespace std;

class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
};

class CreditCardPayment : public PaymentStrategy {
public:
    CreditCardPayment(const string& cardNumber, const string& expiryDate, const string& cvv)
        : cardNumber_(cardNumber), expiryDate_(expiryDate), cvv_(cvv) {}

    void pay(double amount) override {
        cout << "Paid " << amount << " dollars using credit card " << cardNumber_ << endl;
    }

private:
    string cardNumber_;
    string expiryDate_;
    string cvv_;
};

class PayPalPayment : public PaymentStrategy {
public:
    PayPalPayment(const string& email) : email_(email) {}

    void pay(double amount) override {
        cout << "Paid " << amount << " dollars using PayPal account " << email_ << endl;
    }

private:
    string email_;
};

class ShoppingCart {
public:
    ShoppingCart(PaymentStrategy* paymentStrategy) : paymentStrategy_(paymentStrategy) {}

    void checkout(double amount) {
        paymentStrategy_->pay(amount);
    }

private:
    PaymentStrategy* paymentStrategy_;
};

int main() {
    CreditCardPayment* c = new CreditCardPayment("1234-5678-9876-5432", "12/24", "123");
    PayPalPayment* p = new PayPalPayment("user@example.com");

    ShoppingCart* s = new ShoppingCart(c);
    ShoppingCart* sp = new ShoppingCart(p);

    s->checkout(2000);
    sp->checkout(700);
    return 0;
}
