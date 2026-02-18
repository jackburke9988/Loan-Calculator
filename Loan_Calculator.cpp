#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int numberOfPayments;
    double interestRate;
    double loanAmount;
    string loanType;

    // Loan Years + Rates
    const int AUTO_36_MONTHS = 36;
    const double AUTO_36_RATE = 7.29;

    const int AUTO_48_MONTHS = 48;
    const double AUTO_48_RATE = 8.10;
    
    const int AUTO_60_MONTHS = 60;
    const double AUTO_60_RATE = 7.99;

    // Loan Years + Rates
    const int HOME_15_YEARS = 15;
    const double HOME_15_RATE = 5.51;

    const int HOME_20_YEARS = 20;
    const double HOME_20_RATE = 6.46;
    
    const int HOME_30_YEARS = 30;
    const double HOME_30_RATE = 7.21;


    // Ask user for loan amount
    cout << "Enter amount to borrow: ";
    cin >> loanAmount;
    cout << endl;
    if (loanAmount < 0) {
        cout << "Error: Loan amount cannot be less than 0." << endl;
        exit(1);
    }


    // ----- Loan Types -----

    // Ask for loan type
    cout << "Enter type of loan (Enter: Auto or Home): ";
    cin >> loanType;
    cout << endl;


    // Check for loan type and ask for number of payments
    // If Auto loan
    if (loanType == "Auto" || loanType == "auto") {
        cout << "Enter number of months (Enter: " << AUTO_36_MONTHS << ", " << AUTO_48_MONTHS << ", or " << AUTO_60_MONTHS << "): ";
        cin >> numberOfPayments;
        cout << endl;

        // Error checking (Auto loan months) — use constants
        if (numberOfPayments == AUTO_36_MONTHS) {
            interestRate = AUTO_36_RATE;
        }
        else if (numberOfPayments == AUTO_48_MONTHS) {
            interestRate = AUTO_48_RATE;
        }
        else if (numberOfPayments == AUTO_60_MONTHS) {
            interestRate = AUTO_60_RATE;
        }
        else {
            cout << "Error: Number of months not recognized." << endl;
            exit(1);
        }

    // If Home loan
    } else if (loanType == "Home" || loanType == "home") {
        cout << "Enter number of years (Enter: " << HOME_15_YEARS << ", " << HOME_20_YEARS << ", or " << HOME_30_YEARS << "): ";
        cin >> numberOfPayments;
        numberOfPayments = numberOfPayments * 12;
        cout << endl;

        // Error checking (Home loan months) — use constants
        if (numberOfPayments == HOME_15_YEARS * 12) {
            interestRate = HOME_15_RATE;
        }
        else if (numberOfPayments == HOME_20_YEARS * 12) {
            interestRate = HOME_20_RATE;
        }
        else if (numberOfPayments == HOME_30_YEARS * 12) {
            interestRate = HOME_30_RATE;
        }
        else {
            cout << "Error: Number of years not recognized." << endl;
            exit(1);
        }

    // Error checking (Loan Type)
    } else {
        cout << "Error: Loan type not recognized." << endl;
        exit(1);
    }

    // if loan amount is above $200,000 add 3.5% to the APR
    if (loanAmount >= 200000) {
        interestRate += 3.5;
    }

    // ---------- Calculations ----------
    // convert stored percent-rate to usable values
    double annualRatePercent = interestRate;                  // keep for display (e.g. 7.29)
    double monthlyRate = annualRatePercent / 100.0 / 12.0;    // decimal monthly rate (e.g. 0.0729/12)
    double months = static_cast<double>(numberOfPayments);

    // Payment calculation (handle zero-rate as a special case)
    double monthlyPayment;
    if (monthlyRate == 0.0) {
        monthlyPayment = loanAmount / months;
    } else {
        double factor = pow(1.0 + monthlyRate, months);
        monthlyPayment = loanAmount * (monthlyRate * factor) / (factor - 1.0);
    }

    // Total paid and interest paid
    double totalPayment = monthlyPayment * months;
    double interestPaid = totalPayment - loanAmount;


    // ---------- Final Output ----------
    string header = "---- Loan Report for " + loanType + " Loan ----";
    cout << header << endl << endl;

    // formatted output
    cout << fixed << setprecision(2);
    cout << left  << setw(30) << "Loan Amount:"             << right << "$" << setw(12) << loanAmount << endl;
    cout << left  << setw(30) << "Annual Interest Rate:"    << right << "%" << setw(12) << annualRatePercent << endl;
    cout << left  << setw(30) << "Number of Payments:"      << right << setw(13) << numberOfPayments << endl;
    cout << left  << setw(30) << "Monthly Payment:"         << right << "$" << setw(12) << monthlyPayment << endl;
    cout << left  << setw(30) << "Total Payment:"           << right << "$" << setw(12) << totalPayment << endl;
    cout << left  << setw(30) << "Interest Paid:"           << right << "$" << setw(12) << interestPaid << endl;

    
    
    return 0;
}
