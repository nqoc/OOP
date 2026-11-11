#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>

#ifdef _WIN32
#include <windows.h>
#endif

namespace Utils {

    std::string formatCurrency(double amount) {
        long long intPart = static_cast<long long>(std::floor(amount));
        double fracPart = amount - static_cast<double>(intPart);

        std::string numStr = std::to_string(intPart);
        std::string formatted = "";
        int count = 0;

        for (int i = static_cast<int>(numStr.length()) - 1; i >= 0; --i) {
            formatted = numStr[i] + formatted;
            count++;
            if (count % 3 == 0 && i != 0) {
                formatted = "," + formatted;
            }
        }

        // Nếu có phần thập phân đáng kể (> 0.001) thì thêm vào
        if (fracPart >= 0.005) {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(2) << fracPart;
            std::string fracStr = oss.str(); // e.g. "0.50"
            if (fracStr.length() > 1) {
                formatted += fracStr.substr(1); // e.g. ".50"
            }
        }

        return formatted;
    }

    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int readInt(const std::string& prompt, int minVal, int maxVal) {
        std::string line;
        while (true) {
            std::cout << prompt;
            if (!std::getline(std::cin, line)) {
                return minVal; // Trả về giá trị an toàn khi luồng input kết thúc (EOF)
            }
            // Bỏ khoảng trắng đầu/cuối
            size_t start = line.find_first_not_of(" \t\r\n");
            if (start == std::string::npos) {
                std::cout << ">> [Lỗi] Bạn chưa nhập gì. Vui lòng nhập lại!\n";
                continue;
            }
            size_t end = line.find_last_not_of(" \t\r\n");
            std::string trimmed = line.substr(start, end - start + 1);

            try {
                size_t pos = 0;
                int val = std::stoi(trimmed, &pos);
                if (pos == trimmed.length() && val >= minVal && val <= maxVal) {
                    return val;
                }
                std::cout << ">> [Lỗi] Giá trị phải là số nguyên từ " << minVal << " đến " << maxVal << ". Vui lòng nhập lại!\n";
            } catch (...) {
                std::cout << ">> [Lỗi] Dữ liệu không hợp lệ! Vui lòng nhập số nguyên.\n";
            }
        }
    }

    double readDouble(const std::string& prompt, double minVal) {
        std::string line;
        while (true) {
            std::cout << prompt;
            if (!std::getline(std::cin, line)) {
                return minVal; // Trả về giá trị an toàn khi EOF
            }
            size_t start = line.find_first_not_of(" \t\r\n");
            if (start == std::string::npos) {
                std::cout << ">> [Lỗi] Bạn chưa nhập gì. Vui lòng nhập lại!\n";
                continue;
            }
            size_t end = line.find_last_not_of(" \t\r\n");
            std::string trimmed = line.substr(start, end - start + 1);

            try {
                size_t pos = 0;
                double val = std::stod(trimmed, &pos);
                if (pos == trimmed.length() && val >= minVal) {
                    return val;
                }
                std::cout << ">> [Lỗi] Giá trị phải lớn hơn hoặc bằng " << formatCurrency(minVal) << ". Vui lòng nhập lại!\n";
            } catch (...) {
                std::cout << ">> [Lỗi] Dữ liệu không hợp lệ! Vui lòng nhập số hợp lệ.\n";
            }
        }
    }

    void setupConsoleEncoding() {
#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
#endif
    }
}
