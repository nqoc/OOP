#ifndef VCB_PAYMENT_H
#define VCB_PAYMENT_H

#include "BankAccountPayment.h"

class VCBPayment : public BankAccountPayment {
public:
    // Constructor khởi tạo tài khoản Vietcombank
    VCBPayment(const std::string& accNum, double initBalance);

    // Ghi đè phương thức tính phí: Vietcombank thu phí cố định 1,100 VND / giao dịch
    double calculateFee(double amount) const override;

    // Ghi đè phương thức in biên lai đặc trưng Vietcombank
    void printReceipt(double amount, double fee) const override;
};

#endif // VCB_PAYMENT_H
