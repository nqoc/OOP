#include <iostream>
#include <memory>
#include <string>
#include "Utils.h"
#include "PaymentGateway.h"
#include "VCBPayment.h"
#include "TCBPayment.h"

// Hàm thực hiện kịch bản kiểm thử tự động
void runAutomatedTests(PaymentGateway& gateway) {
    std::cout << "\n=======================================================\n";
    std::cout << "         CHẠY KỊCH BẢN KIỂM THỬ TỰ ĐỘNG                \n";
    std::cout << "=======================================================\n";

    // Test Case 1: VCB - Phí cố định 1,100 VND
    std::cout << "\n>>> [TEST CASE 1] Vietcombank (VCB) - Phí cố định 1,100 VND\n";
    auto vcb = gateway.selectBank(1);
    if (vcb) {
        std::cout << "Thanh toán 100,000 VND từ tài khoản VCB:\n";
        vcb->pay(100000.0);
    }

    // Test Case 2: TCB - Miễn phí 0 VND
    std::cout << "\n>>> [TEST CASE 2] Techcombank (TCB) - Miễn phí giao dịch (0 VND)\n";
    auto tcb = gateway.selectBank(2);
    if (tcb) {
        std::cout << "Thanh toán 50,000 VND từ tài khoản TCB:\n";
        tcb->pay(50000.0);
    }

    // Test Case 3: Giao dịch thất bại do số dư không đủ
    std::cout << "\n>>> [TEST CASE 3] Giao dịch thất bại do số dư không đủ\n";
    if (tcb) {
        std::cout << "Tài khoản TCB cố gắng chuyển 999,999,999 VND:\n";
        tcb->pay(999999999.0);
    }

    std::cout << "=======================================================\n";
    std::cout << "             HOÀN THÀNH KỊCH BẢN KIỂM THỬ              \n";
    std::cout << "=======================================================\n\n";
}

// Xử lý luồng giao dịch thanh toán tương tác qua Terminal
void handlePaymentTransaction(PaymentGateway& gateway) {
    gateway.displaySupportedBanks();

    int bankCount = static_cast<int>(gateway.getBankCount());
    if (bankCount == 0) return;

    int bankChoice = Utils::readInt("\n>> Chọn ngân hàng để thanh toán (1 - " + std::to_string(bankCount) + ", hoặc 0 để hủy): ", 0, bankCount);
    if (bankChoice == 0) {
        std::cout << ">> Đã hủy giao dịch.\n";
        return;
    }

    auto selectedBank = gateway.selectBank(bankChoice);
    if (!selectedBank) {
        std::cout << "[!] Ngân hàng không hợp lệ!\n";
        return;
    }

    std::cout << "\n--> Bạn đã chọn: " << selectedBank->getBankName() 
              << " (" << selectedBank->getBankCode() << ")"
              << " | STK: " << selectedBank->getAccountNumber()
              << " | Số dư hiện tại: " << Utils::formatCurrency(selectedBank->getBalance()) << " VND\n";

    double amount = Utils::readDouble(">> Nhập số tiền cần thanh toán (VND): ", 1.0);

    double fee = selectedBank->calculateFee(amount);
    double totalDeducted = amount + fee;

    std::cout << "\n------------------ THÔNG TIN TẠM TÍNH ------------------\n";
    std::cout << " Số tiền chuyển:      " << Utils::formatCurrency(amount) << " VND\n";
    std::cout << " Phí giao dịch:       " << Utils::formatCurrency(fee) << " VND\n";
    std::cout << " Tổng số tiền cần trừ: " << Utils::formatCurrency(totalDeducted) << " VND\n";
    std::cout << " Số dư khả dụng:      " << Utils::formatCurrency(selectedBank->getBalance()) << " VND\n";
    std::cout << "--------------------------------------------------------\n";

    int confirm = Utils::readInt(">> Xác nhận thực hiện giao dịch? (1: Đồng ý, 2: Hủy): ", 1, 2);
    if (confirm != 1) {
        std::cout << ">> Giao dịch đã được hủy bởi người dùng.\n";
        return;
    }

    // Thực thi thanh toán thông qua đa hình
    selectedBank->pay(amount);
}

int main() {
    Utils::setupConsoleEncoding();

    // Khởi tạo cổng điều phối thanh toán PaymentGateway
    PaymentGateway gateway;

    // Nạp các ngân hàng ban đầu theo yêu cầu thiết kế
    gateway.addPaymentMethod(std::make_shared<VCBPayment>("1012345678", 500000.0));
    gateway.addPaymentMethod(std::make_shared<TCBPayment>("1903456789", 200000.0));

    while (true) {
        std::cout << "=======================================================\n";
        std::cout << "    HỆ THỐNG THANH TOÁN NGÂN HÀNG QUA TERMINAL (OOP)   \n";
        std::cout << "=======================================================\n";
        std::cout << " 1. Xem danh sách ngân hàng & số dư hiện tại           \n";
        std::cout << " 2. Thực hiện giao dịch thanh toán                     \n";
        std::cout << " 3. Chạy kịch bản kiểm thử tự động (Automated Demo)   \n";
        std::cout << " 0. Thoát chương trình                                 \n";
        std::cout << "=======================================================\n";

        int choice = Utils::readInt(">> Vui lòng chọn chức năng (0 - 3): ", 0, 3);

        switch (choice) {
            case 1:
                gateway.displaySupportedBanks();
                break;
            case 2:
                handlePaymentTransaction(gateway);
                break;
            case 3:
                runAutomatedTests(gateway);
                break;
            case 0:
                std::cout << "\n>> Cảm ơn bạn đã sử dụng hệ thống thanh toán. Tạm biệt!\n";
                return 0;
        }

        std::cout << "\nNhấn Enter để tiếp tục...";
        std::string temp;
        std::getline(std::cin, temp);
        std::cout << "\n";
    }

    return 0;
}
