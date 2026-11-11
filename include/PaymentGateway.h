#ifndef PAYMENT_GATEWAY_H
#define PAYMENT_GATEWAY_H

#include <vector>
#include <memory>
#include "BankAccountPayment.h"

class PaymentGateway {
private:
    std::vector<std::shared_ptr<BankAccountPayment>> methods;

public:
    PaymentGateway() = default;

    // Thêm một phương thức thanh toán vào danh mục
    void addPaymentMethod(std::shared_ptr<BankAccountPayment> method);

    // Duyệt qua danh sách và in menu các ngân hàng được hỗ trợ ra màn hình
    void displaySupportedBanks() const;

    // Trả về đối tượng ngân hàng theo lựa chọn của người dùng (1-based index)
    std::shared_ptr<BankAccountPayment> selectBank(int index) const;

    // Lấy tổng số lượng ngân hàng hiện có trong cổng thanh toán
    size_t getBankCount() const;
};

#endif // PAYMENT_GATEWAY_H
