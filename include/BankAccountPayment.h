#ifndef BANK_ACCOUNT_PAYMENT_H
#define BANK_ACCOUNT_PAYMENT_H

#include <string>

class BankAccountPayment {
protected:
    std::string bankCode;       // Mã định danh ngân hàng (VCB, TCB, MBB, ...)
    std::string bankName;       // Tên hiển thị của ngân hàng
    std::string accountNumber;  // Số tài khoản ngân hàng
    double balance;             // Số dư khả dụng nội bộ

public:
    // Constructor nhận vào số tài khoản và số dư ban đầu
    BankAccountPayment(const std::string& accNum, double initBalance);

    // Constructor mở rộng nhận đầy đủ thông tin (code, name, accNum, initBalance)
    BankAccountPayment(const std::string& code, const std::string& name, const std::string& accNum, double initBalance);

    // Virtual Destructor đảm bảo giải phóng an toàn bộ nhớ đa hình
    virtual ~BankAccountPayment() = default;

    // Các phương thức Getters
    std::string getBankCode() const;
    std::string getBankName() const;
    std::string getAccountNumber() const;
    double getBalance() const;

    // Phương thức thuần ảo (Pure Virtual Method) tính phí giao dịch
    virtual double calculateFee(double amount) const = 0;

    // Phương thức xử lý thanh toán
    virtual bool pay(double amount);

    // Phương thức in biên lai giao dịch thành công
    virtual void printReceipt(double amount, double fee) const;
};

#endif // BANK_ACCOUNT_PAYMENT_H
