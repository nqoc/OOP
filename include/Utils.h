#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Utils {
    // Định dạng số tiền thành chuỗi có dấu phân cách hàng nghìn (ví dụ: 1000000 -> 1,000,000)
    std::string formatCurrency(double amount);

    // Xóa bộ đệm bàn phím cin sau khi nhập dữ liệu lỗi hoặc sau cin >>
    void clearInputBuffer();

    // Nhập số nguyên an toàn trong đoạn [minVal, maxVal]
    int readInt(const std::string& prompt, int minVal, int maxVal);

    // Nhập số thực an toàn >= minVal
    double readDouble(const std::string& prompt, double minVal);

    // Thiết lập mã hóa UTF-8 cho console (trên Windows)
    void setupConsoleEncoding();
}

#endif // UTILS_H
