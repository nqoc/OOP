#include "VCBPayment.h"
#include "Utils.h"
#include <iostream>

VCBPayment::VCBPayment(const std::string& accNum, double initBalance)
    : BankAccountPayment("VCB", "Vietcombank", accNum, initBalance) {}

double VCBPayment::calculateFee(double amount) const {
    (void)amount; // Phí cố định 1,100 VND không phụ thuộc số tiền
    return 1100.0;
}

void VCBPayment::printReceipt(double amount, double fee) const {
    double totalDeducted = amount + fee;
    std::cout << "\n=======================================================\n";
    std::cout << "         NGÂN HÀNG TMCP NGOẠI THƯƠNG VIỆT NAM          \n";
    std::cout << "                 VIETCOMBANK (VCB)                     \n";
    std::cout << "            \"Chung niềm tin, vững tương lai\"          \n";
    std::cout << "=======================================================\n";
    std::cout << " Số tài khoản:           " << accountNumber << "\n";
    std::cout << " Số tiền chuyển:         " << Utils::formatCurrency(amount) << " VND\n";
    std::cout << " Phí giao dịch cố định:  " << Utils::formatCurrency(fee) << " VND\n";
    std::cout << " Tổng tiền khấu trừ:     " << Utils::formatCurrency(totalDeducted) << " VND\n";
    std::cout << " Số dư khả dụng còn lại: " << Utils::formatCurrency(balance) << " VND\n";
    std::cout << " Trạng thái:             THÀNH CÔNG\n";
    std::cout << "=======================================================\n\n";
}
