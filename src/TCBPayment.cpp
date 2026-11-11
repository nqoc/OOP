#include "TCBPayment.h"
#include "Utils.h"
#include <iostream>

TCBPayment::TCBPayment(const std::string& accNum, double initBalance)
    : BankAccountPayment("TCB", "Techcombank", accNum, initBalance) {}

double TCBPayment::calculateFee(double amount) const {
    (void)amount;
    return 0.0; // Miễn phí hoàn toàn 0 VND
}

void TCBPayment::printReceipt(double amount, double fee) const {
    double totalDeducted = amount + fee;
    std::cout << "\n=======================================================\n";
    std::cout << "          NGÂN HÀNG TMCP KỸ THƯƠNG VIỆT NAM            \n";
    std::cout << "                 TECHCOMBANK (TCB)                     \n";
    std::cout << "               \"Vượt trội hơn mỗi ngày\"               \n";
    std::cout << "=======================================================\n";
    std::cout << " Số tài khoản:           " << accountNumber << "\n";
    std::cout << " Số tiền chuyển:         " << Utils::formatCurrency(amount) << " VND\n";
    std::cout << " Phí giao dịch (Ưu đãi): " << Utils::formatCurrency(fee) << " VND (MIỄN PHÍ)\n";
    std::cout << " Tổng tiền khấu trừ:     " << Utils::formatCurrency(totalDeducted) << " VND\n";
    std::cout << " Số dư khả dụng còn lại: " << Utils::formatCurrency(balance) << " VND\n";
    std::cout << " Trạng thái:             THÀNH CÔNG\n";
    std::cout << "=======================================================\n\n";
}
