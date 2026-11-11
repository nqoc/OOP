CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRCS = src/main.cpp \
       src/BankAccountPayment.cpp \
       src/VCBPayment.cpp \
       src/TCBPayment.cpp \
       src/MBBankPayment.cpp \
       src/PaymentGateway.cpp \
       src/Utils.cpp

TARGET = payment_system.exe

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
