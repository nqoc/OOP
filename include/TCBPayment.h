#ifndef TCB_PAYMENT_H
#define TCB_PAYMENT_H

#include "BankAccountPayment.h"

class TCBPayment : public BankAccountPayment {
public:
    // Constructor khởi tạo tài khoản Techcombank
    TCBPayment(const std::string& accNum, double initBalance);

    // Ghi đè phương thức tính phí: Techcombank miễn phí giao dịch (0 VND)
    double calculateFee(double amount) const override;

    // Ghi đè phương thức in biên lai đặc trưng Techcombank
    void printReceipt(double amount, double fee) const override;
};

#endif // TCB_PAYMENT_H
