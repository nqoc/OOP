#include "BankAccountPayment.h"
#include "Utils.h"
#include <iostream>

BankAccountPayment::BankAccountPayment(const std::string& accNum, double initBalance)
    : bankCode("UNKNOWN"), bankName("Unknown Bank"), accountNumber(accNum), balance(initBalance) {}

BankAccountPayment::BankAccountPayment(const std::string& code, const std::string& name, const std::string& accNum, double initBalance)
    : bankCode(code), bankName(name), accountNumber(accNum), balance(initBalance) {}

std::string BankAccountPayment::getBankCode() const {
    return bankCode;
}

std::string BankAccountPayment::getBankName() const {
    return bankName;
}

std::string BankAccountPayment::getAccountNumber() const {
    return accountNumber;
}

double BankAccountPayment::getBalance() const {
    return balance;
}

bool BankAccountPayment::pay(double amount) {
    if (amount <= 0) {
        std::cout << "\n[!] Giao dịch thất bại: Số tiền thanh toán phải lớn hơn 0 VND.\n";
        return false;
    }

    double fee = calculateFee(amount);
    double totalDeducted = amount + fee;

    if (balance >= totalDeducted) {
        balance -= totalDeducted;
        printReceipt(amount, fee);
        return true;
    } else {
        std::cout << "\n=======================================================\n";
        std::cout << "               GIAO DỊCH THẤT BẠI                      \n";
        std::cout << "=======================================================\n";
        std::cout << " [!] Lý do: Số dư tài khoản không đủ để thanh toán!\n";
        std::cout << " - Ngân hàng:            " << bankName << " (" << bankCode << ")\n";
        std::cout << " - Số tài khoản:         " << accountNumber << "\n";
        std::cout << " - Số tiền giao dịch:    " << Utils::formatCurrency(amount) << " VND\n";
        std::cout << " - Phí giao dịch:        " << Utils::formatCurrency(fee) << " VND\n";
        std::cout << " - Tổng tiền cần trừ:    " << Utils::formatCurrency(totalDeducted) << " VND\n";
        std::cout << " - Số dư hiện tại:       " << Utils::formatCurrency(balance) << " VND\n";
        std::cout << " - Số tiền còn thiếu:    " << Utils::formatCurrency(totalDeducted - balance) << " VND\n";
        std::cout << "=======================================================\n\n";
        return false;
    }
}

void BankAccountPayment::printReceipt(double amount, double fee) const {
    double totalDeducted = amount + fee;
    std::cout << "\n=======================================================\n";
    std::cout << "               BIÊN LAI GIAO DỊCH THÀNH CÔNG           \n";
    std::cout << "=======================================================\n";
    std::cout << " Ngân hàng xử lý:        " << bankName << " (" << bankCode << ")\n";
    std::cout << " Số tài khoản nguồn:     " << accountNumber << "\n";
    std::cout << " Số tiền chuyển:         " << Utils::formatCurrency(amount) << " VND\n";
    std::cout << " Phí giao dịch:          " << Utils::formatCurrency(fee) << " VND\n";
    std::cout << " Tổng tiền khấu trừ:     " << Utils::formatCurrency(totalDeducted) << " VND\n";
    std::cout << " Số dư khả dụng còn lại: " << Utils::formatCurrency(balance) << " VND\n";
    std::cout << " Trạng thái:             THÀNH CÔNG (SUCCESS)\n";
    std::cout << "=======================================================\n\n";
}
