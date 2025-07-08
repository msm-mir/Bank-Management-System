# 🏦 Bank Management System (C++ with Qt GUI)

This project is a **bank management system** implemented in **C++** using the **Qt GUI framework**, as part of an Advanced Programming course. It simulates the basic banking operations and user account management in a simple, object-oriented manner with a graphical user interface.

## 🎯 Project Goal

The aim of this project is to simulate a **real-world banking system** and implement its functionalities using core C++ programming concepts like object-oriented programming (OOP), file handling, and user input validation. The system models real-life banking components such as users, accounts, and transactions.

---

## 💡 Features

### 👤 User Account Management
- **Sign up and log in** with a unique username and password
- Collect and store user information:
  - First name, last name, national ID, age
  - Unique credentials (username and password)

### 🏦 Bank Account Management
- Create up to **5 bank accounts** per user
- Choose account type: **Savings**, **Current**, or **Loan**
- Randomly generate:
  - **Card number**
  - **IBAN (Sheba number)**
  - **Account number**
  - **CVV2 code**
- Set:
  - **4-digit PIN**
  - Optional **static second password**
- Assign:
  - **Expiration date**: 3 years from creation
  - **Initial balance**: must be at least 50,000 Toman

### 💳 Card-to-Card Transfers
- Transfer funds by entering a valid **card number**
- Display recipient's **name and surname** before confirming
- Validate:
  - **Card expiration date**
  - **Transaction limit**:
    - Max 3,000,000 Toman per transaction
    - Max 6,000,000 Toman per 24 hours
- Support for:
  - **Static second password** for transfers under 100,000 Toman
  - **Dynamic second password** (generated per transaction) for transfers over 100,000 Toman
- Transfer **fee**: 1% of the amount

---

## 🛠 Technical Details
- Implemented in **C++**
- Uses **Qt framework** for GUI
- Uses **Linked Lists with Templates** to manage users and their bank accounts
- Simulates **realistic banking validations and constraints**

---

## 📁 Project Structure

```
/BankProject
├── main.cpp
├── BankAccount.h / .cpp
├── Card.h / .cpp
├── CardInfo.h / .cpp / .ui
├── ChangePassword.h / .cpp / .ui
├── ConfirmTransfer.h / .cpp / .ui
├── CreateBankAccount.h / .cpp / .ui
├── Form.h / .cpp/ .ui
├── List.h / .cpp
├── LoginSignin.h / .cpp / .ui / .qrc
├── MainPanel.h / .cpp / .ui
├── Panel.h / .cpp / .ui / .qrc
├── scr.pro
├── Temp.h / .cpp
├── Transfer.h / .cpp / .ui
├── User.h / .cpp
├── UserPanel.h / .cpp / .ui
├── ViewBalance.h / .cpp / .ui
└── README.md
```

---

## 🚀 How to Run

### Prerequisites:
- **Qt Creator IDE** (used to develop the entire project)
- **Qt libraries and dependencies**

### Steps:
1. Open the project in **Qt Creator**.
2. Configure the appropriate **Qt Kit**.
3. Build and run the project within the IDE.

---

## 📌 Notes
- The entire project was developed using **Qt Creator**
- The system requires Qt libraries to build and run correctly
- All generated card/account details are **randomized**
- Each user’s account list is stored using **templated linked lists**

---

## 👨‍💻 Author
- Developed as part of a C++ Advanced Programming course mini project
