#include "PaymentGateway.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

void PaymentGateway::addPaymentMethod(std::shared_ptr<BankAccountPayment> method) {
    if (method) {
        methods.push_back(method);
    }
}

void PaymentGateway::displaySupportedBanks() const {
    if (methods.empty()) {
        std::cout << "\n[!] Hiện tại chưa có phương thức thanh toán ngân hàng nào được tích hợp.\n";
        return;
    }

    std::cout << "\n========================================================================================\n";
    std::cout << "                         DANH SÁCH NGÂN HÀNG HỖ TRỢ THANH TOÁN                         \n";
    std::cout << "========================================================================================\n";
    std::cout << std::left 
              << std::setw(6)  << "STT"
              << std::setw(8)  << "Mã NH"
              << std::setw(22) << "Tên Ngân Hàng"
              << std::setw(18) << "Số Tài Khoản"
              << std::right << std::setw(22) << "Số Dư Khả Dụng (VND)" 
              << "\n";
    std::cout << "----------------------------------------------------------------------------------------\n";

    for (size_t i = 0; i < methods.size(); ++i) {
        std::cout << std::left 
                  << std::setw(6)  << ("[" + std::to_string(i + 1) + "]")
                  << std::setw(8)  << methods[i]->getBankCode()
                  << std::setw(22) << methods[i]->getBankName()
                  << std::setw(18) << methods[i]->getAccountNumber()
                  << std::right << std::setw(22) << Utils::formatCurrency(methods[i]->getBalance())
                  << "\n";
    }
    std::cout << "========================================================================================\n";
}

std::shared_ptr<BankAccountPayment> PaymentGateway::selectBank(int index) const {
    // index truyền vào theo thứ tự hiển thị của người dùng (bắt đầu từ 1)
    if (index >= 1 && static_cast<size_t>(index) <= methods.size()) {
        return methods[index - 1];
    }
    return nullptr;
}

size_t PaymentGateway::getBankCount() const {
    return methods.size();
}
