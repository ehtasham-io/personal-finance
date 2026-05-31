# 💰 Personal Finance Manager — C++

> A full-featured personal finance management system built in C++ using deep OOP principles.
> 13 classes, 27 source files, 24 menu options — a complete console-based finance application.

![Language](https://img.shields.io/badge/Language-C++-blue)
![Classes](https://img.shields.io/badge/Classes-13-purple)
![Course](https://img.shields.io/badge/Course-OOP-green)
![Status](https://img.shields.io/badge/Status-Completed-green)

---

## 🧭 What is it?

A console-based Personal Finance Manager that lets users register, log in securely,
track income and expenses, set budgets, manage savings goals, track investments,
and get AI-powered spending insights — all from a 24-option menu system.

---

## ✨ Features

### Core Finance
- **Income & Expense Tracking** — add, categorise, and display transactions
- **Recurring Transactions** — track monthly bills and subscriptions with frequency
- **Budget Management** — set category limits, track spending, get overrun alerts
- **Savings Goals** — set targets with deadlines, allocate funds, track progress

### Investment Module
- **SIP (Systematic Investment Plan)** — monthly investment with maturity calculation
- **FD (Fixed Deposit)** — lump sum investment with 7% return calculation

### Milestone Reward System
- 4 checkpoints: 25% → Bronze, 50% → Silver, 75% → Gold, 100% → Goal Achieved!

### Visualizations (ASCII)
- **Pie Chart** — spending breakdown by category
- **Trend Graph** — monthly expense trend
- **Budget Graph** — budget vs actual spending comparison

### AI & Smart Features
- **AI Chatbot** — keyword-based finance Q&A
- **Spending Analysis** — identifies highest spending category, alerts if >50% of total
- **Financial Tips** — rotating curated finance advice

### Security & Data
- **Password Hashing** — std::hash used for secure password storage (not plaintext)
- **Per-user Data Files** — username_transactions.csv, username_budgets.csv
- **CSV Export/Import** — full transaction portability
- **Binary Backup/Restore** — complete data backup system
- **XOR Encryption/Decryption** — file-level data protection

### Utility Modules
- Loan EMI Calculator
- Tax Estimator (slab-based)
- Currency Converter (USD/EUR/INR)
- Subscription Manager
- Insurance Planner
- Voice Command (simulated)

---

## 🏗️ Class Architecture

```
Transaction (base)
├── Income
├── Expenditure
└── RecurringTransaction

Investment (base)
├── SIP
└── FD

User
├── FinanceManager
│   ├── Transaction* (vector)
│   ├── Investment* (vector)
│   └── SavingsGoal (vector)
├── Budget (vector)
├── Report (vector)
└── Credential

Utils (namespace)
Category
```

---

## ⚙️ OOP Concepts Applied

| Concept | Where used |
|---------|-----------|
| Inheritance | Transaction→Income/Expenditure/Recurring, Investment→SIP/FD |
| Polymorphism | Virtual display() and maturityAmount() overrides |
| Encapsulation | Private members with public getters/setters across all classes |
| Abstraction | Transaction and Investment base classes |
| Composition | User contains FinanceManager, Budget, Credential |
| Namespaces | Utils namespace for utility functions |
| File I/O | fstream for CSV, binary backup, encryption |
| STL | vector, map, array, string across all modules |
| Header Guards | #ifndef guards in all 13 header files |

---

## 🚀 How to Run

### Prerequisites
- C++ compiler (g++ / MinGW / MSVC)
- C++11 or later

### Compile
```bash
g++ src/*.cpp -o finance -std=c++11
./finance
```

### First Run
1. Select **1. Register** → enter username and password
2. Select **2. Login** → enter credentials
3. Navigate the 24-option menu

---

## 📋 Menu Options

| # | Feature | # | Feature |
|---|---------|---|---------|
| 1 | Add Income | 13 | Import CSV |
| 2 | Add Expense | 14 | Backup Data |
| 3 | Recurring Transaction | 15 | Restore Data |
| 4 | Show Transactions | 16 | Pie Chart |
| 5 | Add Budget | 17 | Trend Graph |
| 6 | Show Budgets | 18 | Budget Graph |
| 7 | Add Savings Goal | 19 | Financial Tips |
| 8 | Allocate to Goal | 20 | AI Chatbot |
| 9 | Show Goals | 21 | Voice Command |
| 10 | Make Investment | 22 | Subscription Manager |
| 11 | Show Investments | 23 | Insurance Planner |
| 12 | Export CSV | 24 | Coming Soon |

---

## 🔮 Future Enhancements

- [ ] Graphical UI using Qt or SFML
- [ ] Real AI integration for spending predictions
- [ ] Database backend (SQLite)
- [ ] Mobile app companion
- [ ] Multi-currency real-time rates

---

## 📄 License

MIT License — free to use, modify, and distribute.

---

*Built with C++, OOP principles, and a vision for what personal finance tools should feel like.*
