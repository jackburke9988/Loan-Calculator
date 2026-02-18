# Loan Calculator

Program:  Loan calculator — computes monthly payment, total paid, and
          total interest for predefined Auto and Home loan terms.

Process:  Prompts for loan amount and loan type (Auto/Home). For Auto
          the user selects months (36, 48, 60); for Home the user selects
          years (15, 20, 30) which are converted to months. The program
          selects the fixed APR for the chosen term (adds 3.5% if amount
          >= $200,000), converts the APR to a monthly rate, and computes
          the monthly payment using the standard formula. Results are displayed
          in a formatted report.
          
Results:  Displays a loan report including: Loan Amount, Annual
          Interest Rate, Number of Payments, Monthly Payment, Total
          Payment, and Interest Paid. Performs input validation and
          prints an error message for invalid loan types or terms.

Class: CS2010
Section: 1003
Term: Spring 2026
Author: Jack Burke
