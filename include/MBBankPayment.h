#ifndef MBBANK_PAYMENT_H
#define MBBANK_PAYMENT_H

#include "BankAccountPayment.h"

class MBBankPayment : public BankAccountPayment {
public:
    // Constructor khởi tạo tài khoản MBBank
    MBBankPayment(const std::string& accNum, double initBalance);

    // Ghi đè phương thức tính phí: MBBank thu phí 0.2% số tiền thanh toán (amount * 0.002)
    double calculateFee(double amount) const override;

    // Ghi đè phương thức in biên lai đặc trưng MBBank
    void printReceipt(double amount, double fee) const override;
};

#endif // MBBANK_PAYMENT_H
