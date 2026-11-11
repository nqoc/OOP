#include "MBBankPayment.h"
#include "Utils.h"
#include <iostream>

MBBankPayment::MBBankPayment(const std::string& accNum, double initBalance)
    : BankAccountPayment("MBB", "MBBank", accNum, initBalance) {}

double MBBankPayment::calculateFee(double amount) const {
    // Phí bằng 0.2% số tiền thanh toán (amount * 0.002)
    return amount * 0.002;
}

void MBBankPayment::printReceipt(double amount, double fee) const {
    double totalDeducted = amount + fee;
    std::cout << "\n=======================================================\n";
    std::cout << "             NGÂN HÀNG TMCP QUÂN ĐỘI                   \n";
    std::cout << "                  MBBANK (MBB)                         \n";
    std::cout << "             \"Vững vàng tin cậy\"                      \n";
    std::cout << "=======================================================\n";
    std::cout << " Số tài khoản:           " << accountNumber << "\n";
    std::cout << " Số tiền chuyển:         " << Utils::formatCurrency(amount) << " VND\n";
    std::cout << " Phí giao dịch (0.2%):   " << Utils::formatCurrency(fee) << " VND\n";
    std::cout << " Tổng tiền khấu trừ:     " << Utils::formatCurrency(totalDeducted) << " VND\n";
    std::cout << " Số dư khả dụng còn lại: " << Utils::formatCurrency(balance) << " VND\n";
    std::cout << " Trạng thái:             THÀNH CÔNG\n";
    std::cout << "=======================================================\n\n";
}
