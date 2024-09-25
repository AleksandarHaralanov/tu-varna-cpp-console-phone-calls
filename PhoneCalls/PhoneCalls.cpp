#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct Subscription {
    string signerName, phoneNumber, contractNumber;
    int contractDuration{}, callShortest{}, callTotalDuration{}, callNationalDuration{}, callInternationalDuration{}, callsTotal{}, callNational{}, callInternational{};
    double monthlyTotalTax{}, monthlyNationalTax{}, monthlyInternationalTax{};
};

static void subscriptionCounter(Subscription* S, int& count, Subscription newSubscription) {
    S[count] = newSubscription;
    count++;
}

static void addSubscription(Subscription* S, int& count) {
    srand((unsigned int)time(NULL));
    Subscription newSubscription;
    string num = "+35987";
    int rand1 = 0, rand2 = 0, rand3 = 0, rand4 = 0, rand5 = 0, rand6 = 0, rand7 = 0;
    int year = 0, month = 0, day = 0, num2 = 0;

    cout << endl << "QUESTION: Name of the contract signer: ";
    cin.ignore();
    getline(cin, newSubscription.signerName);

    do {
        cout << endl << "QUESTION: Duration of contract (1 or 2 years): ";
        cin >> newSubscription.contractDuration;
        if (newSubscription.contractDuration < 1 || newSubscription.contractDuration > 2) {
            cout << endl << "SYSTEM MESSAGE: Invalid choice, please try again!" << endl;
        }
    } while (newSubscription.contractDuration < 1 || newSubscription.contractDuration > 2);

    cout << endl << "//////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl << endl;

    year = rand() % 21 + 2001;
    month = rand() % 12 + 1;
    day = rand() % 31 + 1;
    num2 = rand() % 99 + 1;

    ostringstream y_num, m_num, d_num, n_num;
    y_num << year;

    if (month <= 9) {
        m_num << setw(2) << setfill('0') << month;
    }
    else {
        m_num << month;
    }

    if (day <= 9) {
        d_num << setw(2) << setfill('0') << day;
    }
    else {
        d_num << day;
    }

    if (num2 <= 9) {
        n_num << setw(2) << setfill('0') << num2;
    }
    else {
        n_num << num2;
    }

    newSubscription.contractNumber = y_num.str() + m_num.str() + d_num.str() + n_num.str();

    for (int i = 0; i < count; i++) {
        if (newSubscription.contractNumber == S[i].contractNumber) {
            year = rand() % 21 + 2001;
            month = rand() % 12 + 1;
            day = rand() % 31 + 1;
            num2 = rand() % 99 + 1;

            ostringstream y_num, m_num, d_num, n_num;
            y_num << year;

            if (month <= 9) {
                m_num << setw(2) << setfill('0') << month;
            }
            else {
                m_num << month;
            }
            if (day <= 9) {
                d_num << setw(2) << setfill('0') << day;
            }
            else {
                d_num << day;
            }
            if (num2 <= 9) {
                n_num << setw(2) << setfill('0') << num2;
            }
            else {
                n_num << num2;
            }

            newSubscription.contractNumber = y_num.str() + m_num.str() + d_num.str() + n_num.str();
        }
    }
    cout << "SYSTEM MESSAGE: Program automatically generated ( " << newSubscription.contractNumber << " ) as a contract number for this subscription." << endl;

    rand1 = rand() % 9 + 1;
    rand2 = rand() % 9 + 1;
    rand3 = rand() % 9 + 1;
    rand4 = rand() % 9 + 1;
    rand5 = rand() % 9 + 1;
    rand6 = rand() % 9 + 1;
    rand7 = rand() % 9 + 1;

    ostringstream r_num1, r_num2, r_num3, r_num4, r_num5, r_num6, r_num7;
    r_num1 << rand1;
    r_num2 << rand2;
    r_num3 << rand3;
    r_num4 << rand4;
    r_num5 << rand5;
    r_num6 << rand6;
    r_num7 << rand7;

    newSubscription.phoneNumber = num + r_num1.str() + r_num2.str() + r_num3.str() + r_num4.str() + r_num5.str() + r_num6.str() + r_num7.str();

    for (int i = 0; i < count; i++) {
        if (newSubscription.phoneNumber == S[i].phoneNumber) {
            rand1 = rand() % 9 + 1;
            rand2 = rand() % 9 + 1;
            rand3 = rand() % 9 + 1;
            rand4 = rand() % 9 + 1;
            rand5 = rand() % 9 + 1;
            rand6 = rand() % 9 + 1;
            rand7 = rand() % 9 + 1;

            ostringstream r_num1, r_num2, r_num3, r_num4, r_num5, r_num6, r_num7;
            r_num1 << rand1;
            r_num2 << rand2;
            r_num3 << rand3;
            r_num4 << rand4;
            r_num5 << rand5;
            r_num6 << rand6;
            r_num7 << rand7;

            newSubscription.phoneNumber = num + r_num1.str() + r_num2.str() + r_num3.str() + r_num4.str() + r_num5.str() + r_num6.str() + r_num7.str();
        }
    }

    cout << "SYSTEM MESSAGE: Program automatically generated ( " << newSubscription.phoneNumber << " ) as a phone number for this subscription." << endl;

    subscriptionCounter(S, count, newSubscription);
    cout << "SYSTEM MESSAGE: Program successfully added subscription to counter!" << endl << endl;
}

static void makePhoneCalls(Subscription* S, int& count) {
    srand((unsigned int)time(NULL));
    int callType = 0;
    int callDuration = 0;

    system("cls");
    cout << "//////////////////////////////" << endl;
    cout << "//    RESULTS FROM CALLS    //" << endl;
    cout << "//////////////////////////////" << endl << endl;

    for (int i = 0; i < count; i++) {
        if (S[i].callsTotal < 20) {
            callType = rand() % 2 + 1;
            S[i].callsTotal += 1;

            if (callType == 1) {
                S[i].callNational += 1;
                callDuration = rand() % 3600 + 1;
                S[i].callNationalDuration += callDuration;
                cout << "// Phone Number: " << S[i].phoneNumber << "  // Call Type: National  // Call Duration: " << callDuration << " sec." << endl << endl;
            }
            else {
                S[i].callInternational += 1;
                callDuration = rand() % 3600 + 1;
                S[i].callInternationalDuration += callDuration;
                cout << "// Phone Number: " << S[i].phoneNumber << "  // Call Type: International  // Call Duration: " << callDuration << " sec." << endl << endl;
            }

            if (S[i].callsTotal == 1) {
                S[i].callShortest = callDuration;
            }
            else {
                if (callDuration < S[i].callShortest) {
                    S[i].callShortest = callDuration;
                }
            }
        }
        else {
            cout << "SYSTEM MESSAGE: ( " << S[i].phoneNumber << " ) has already made a maximum of 20 calls. Skipping." << endl << endl;
        }
    }

    system("pause");
}

static void calculateMonthlyTax(Subscription* S, int& count) {
    system("cls");
    cout << "//////////////////////////////" << endl;
    cout << "// RESULTS FROM CALCULATION //" << endl;
    cout << "//////////////////////////////" << endl << endl;

    for (int i = 0; i < count; i++) {
        double national = 0, international = 0;

        for (int a = 0; a < S[i].callNationalDuration; a++) {
            national += 0.1;
        }

        for (int b = 0; b < S[i].callInternationalDuration; b++) {
            international += 0.25;
        }

        S[i].monthlyTotalTax = national + international;

        cout << "// Phone Number: " << S[i].phoneNumber << "  // National Taxes: " << national << " lev.  // International Taxes: " << international << " lev.  // Total Taxes: " << S[i].monthlyTotalTax << " lev." << endl << endl;
    }

    system("pause");
}

static void showSubscriptions(Subscription* S, int& count) {
    system("cls");
    cout << "//////////////////////////" << endl;
    cout << "//  SUBSCRIPTIONS LIST  //" << endl;
    cout << "//////////////////////////" << endl << endl;

    for (int i = 0; i < count; i++) {
        cout << "// Signer Name: " << S[i].signerName << "  // Contract Number: " << S[i].contractNumber << "  // Contract Duration: ";
        if (S[i].contractDuration == 1) {
            cout << S[i].contractDuration << " year";
        }
        else {
            cout << S[i].contractDuration << " years";
        }
        cout << "  // Phone Number: " << S[i].phoneNumber << "  // National Calls: " << S[i].callNational << "  // International Calls: " << S[i].callInternational << "  // Monthly Tax: " << S[i].monthlyTotalTax << endl << endl;
    }

    cout << "///////////////////////////////////////////////////////////////////////////" << endl << endl;
    cout << "SYSTEM MESSAGE: Program successfully listed all subscriptions!" << endl << endl;
    system("pause");
}

static void showSubscriptionsWithExpiringContracts(Subscription* S, int& count) {
    system("cls");
    cout << "/////////////////////////////////////////////" << endl;
    cout << "//  SUBSCRIPTIONS WITH EXPIRING CONTRACTS  //" << endl;
    cout << "/////////////////////////////////////////////" << endl << endl;

    for (int i = 0; i < count; i++) {
        if (S[i].contractDuration == 1) {
            cout << "// Phone Number: " << S[i].phoneNumber << "  // Contract Duration: " << S[i].contractDuration << " year" << endl << endl;
        }
    }

    system("pause");
}

static void showSubscriptionsWithLeastMonthlyTax(Subscription* S, int& count) {
    double temp = INT_MAX;

    system("cls");
    cout << "/////////////////////////////////////////////" << endl;
    cout << "//  SUBSCRIPTION WITH MINIMAL MONTHLY TAX  //" << endl;
    cout << "/////////////////////////////////////////////" << endl << endl;

    for (int i = 0; i < count; i++) {
        if (S[i].monthlyTotalTax < temp) {
            temp = S[i].monthlyTotalTax;
        }
    }

    for (int j = 0; j < count; j++) {
        if (S[j].monthlyTotalTax == temp) {
            cout << "// Phone Number: " << S[j].phoneNumber << "  // Monthly Tax: " << temp << " lev." << endl << endl;
        }
    }

    system("pause");
}

static void showSubscriptionWithMostInternationalCalls(Subscription* S, int& count) {
    int temp = 0;

    system("cls");
    cout << "///////////////////////////////////////////////////" << endl;
    cout << "//  SUBSCRIPTIONS WITH MOST INTERNATIONAL CALLS  //" << endl;
    cout << "///////////////////////////////////////////////////" << endl << endl;

    for (int i = 0; i < count; i++) {
        if (S[i].callInternational > temp) {
            temp = S[i].callInternational;
        }
    }

    for (int i = 0; i < count; i++) {
        if (S[i].callInternational == temp) {
            cout << "// Phone Number: " << S[i].phoneNumber << "  // International Calls: " << temp << endl << endl;
        }
    }

    system("pause");
}

static void showSubscriptionWithShortestCall(Subscription* S, int& count) {
    int temp = INT_MAX;

    system("cls");
    cout << "///////////////////////////////////////" << endl;
    cout << "//  SUBSCRIPTION WITH SHORTEST CALL  //" << endl;
    cout << "///////////////////////////////////////" << endl << endl;

    for (int i = 0; i < count; i++) {
        if (S[i].callShortest < temp) {
            temp = S[i].callShortest;
        }
    }

    for (int i = 0; i < count; i++) {
        if (S[i].callShortest == temp) {
            cout << "// Phone Number: " << S[i].phoneNumber << "  // Call Duration: " << temp << " sec." << endl << endl;
        }
    }

    system("pause");
}

int main() {
    Subscription S[10];
    string choiceAdd;
    int choice;
    int subscriptions = 0;

    do {
        system("cls");
        cout << "//////////////////////////////" << endl;
        cout << "//           MENU           //" << endl;
        cout << "//////////////////////////////" << endl << endl;
        cout << "1# - Add one subscription" << endl;
        cout << "2# - Add multiple subscriptions" << endl;
        cout << "3# - Make phone calls" << endl;
        cout << "4# - Calculate monthly tax for all subscriptions" << endl;
        cout << "5# - Show all subscriptions" << endl;
        cout << "6# - Show subscription(s) with expiring contracts" << endl;
        cout << "7# - Show subscription(s) with minimal monthly tax" << endl;
        cout << "8# - Show subscription(s) with most international calls" << endl;
        cout << "9# - Show subscription with shortest call" << endl;
        cout << "10# - CLOSE PROGRAM" << endl << endl;

        do {
            cout << "Enter choice: ";
            cin >> choice;
        } while (choice < 1 || choice > 10);

        switch (choice) {
        case 1:
            if (subscriptions == 10) {
                system("cls");
                cout << "////////////////////////////////////////////////////////////////////" << endl;
                cout << "//     YOU REACHED THE MAXIMUM NUMBER OF ALLOWED SUBSCRIPTIONS    //" << endl;
                cout << "//                   RETURNING YOU TO MAIN MENU                   //" << endl;
                cout << "////////////////////////////////////////////////////////////////////" << endl << endl;
                system("pause");
            }
            else {
                do {
                    system("cls");
                    cout << "//////////////////////////////" << endl;
                    cout << "//    SINGLE SUBSCRIPTION   //" << endl;
                    cout << "//////////////////////////////" << endl;
                    addSubscription(S, subscriptions);
                    system("pause");

                    if (subscriptions == 10) {
                        system("cls");
                        cout << "////////////////////////////////////////////////////////////////////" << endl;
                        cout << "//          PROGRAM ADDED YOUR SUBSCRIPTION(S) TO COUNTER         //" << endl;
                        cout << "//                                                                //" << endl;
                        cout << "//     YOU REACHED THE MAXIMUM NUMBER OF ALLOWED SUBSCRIPTIONS    //" << endl;
                        cout << "//                   RETURNING YOU TO MAIN MENU                   //" << endl;
                        cout << "////////////////////////////////////////////////////////////////////" << endl << endl;
                        system("pause");
                    }
                    else if (subscriptions < 10) {
                        system("cls");
                        cout << "////////////////////////////////////////////////////////////////////" << endl;
                        cout << "//          PROGRAM ADDED YOUR SUBSCRIPTION(S) TO COUNTER         //" << endl;
                        cout << "//               YOU MAY ENTER " << 10 - subscriptions << " MORE SUBSCRIPTIONS               //" << endl;
                        cout << "//                                                                //" << endl;
                        cout << "//            WOULD YOU LIKE TO ADD MORE SUBSCRIPTIONS?           //" << endl;
                        cout << "//   ENTER (Y/y) TO ADD OR ANYTHING ELSE TO RETURN TO MAIN MENU   //" << endl;
                        cout << "////////////////////////////////////////////////////////////////////" << endl << endl;
                        cout << "Enter choice: ";
                        cin >> choiceAdd;
                    }
                } while (choiceAdd == "Y" || choiceAdd == "y");
            }
            break;

        case 2:
            if (subscriptions == 10) {
                system("cls");
                cout << "////////////////////////////////////////////////////////////////////" << endl;
                cout << "//     YOU REACHED THE MAXIMUM NUMBER OF ALLOWED SUBSCRIPTIONS    //" << endl;
                cout << "//                   RETURNING YOU TO MAIN MENU                   //" << endl;
                cout << "////////////////////////////////////////////////////////////////////" << endl << endl;
                system("pause");
            }
            else {
                do {
                    int n;
                    system("cls");
                    cout << "//////////////////////////////" << endl;
                    cout << "//  MULTIPLE SUBSCRIPTIONS  //" << endl;
                    cout << "//////////////////////////////" << endl << endl;
                    cout << "SYSTEM MESSAGE: Choose how many subscriptions to add: ";
                    cin >> n;
                    cout << endl << "//////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                    for (int i = 0; i < n; i++) {
                        addSubscription(S, subscriptions);
                    }

                    if (subscriptions == 10) {
                        system("cls");
                        cout << "////////////////////////////////////////////////////////////////////" << endl;
                        cout << "//          PROGRAM ADDED YOUR SUBSCRIPTION(S) TO COUNTER         //" << endl;
                        cout << "//                                                                //" << endl;
                        cout << "//     YOU REACHED THE MAXIMUM NUMBER OF ALLOWED SUBSCRIPTIONS    //" << endl;
                        cout << "//                   RETURNING YOU TO MAIN MENU                   //" << endl;
                        cout << "////////////////////////////////////////////////////////////////////" << endl << endl;
                        system("pause");
                    }
                    else if (subscriptions < 10) {
                        system("cls");
                        cout << "////////////////////////////////////////////////////////////////////" << endl;
                        cout << "//          PROGRAM ADDED YOUR SUBSCRIPTION(S) TO COUNTER         //" << endl;
                        cout << "//               YOU MAY ENTER " << 10 - subscriptions << " MORE SUBSCRIPTIONS               //" << endl;
                        cout << "//                                                                //" << endl;
                        cout << "//            WOULD YOU LIKE TO ADD MORE SUBSCRIPTIONS?           //" << endl;
                        cout << "//   ENTER (Y/y) TO ADD OR ANYTHING ELSE TO RETURN TO MAIN MENU   //" << endl;
                        cout << "////////////////////////////////////////////////////////////////////" << endl << endl;
                        cout << "Enter choice: ";
                        cin >> choiceAdd;
                    }
                } while (choiceAdd == "Y" || choiceAdd == "y");
            }
            break;

        case 3:
            makePhoneCalls(S, subscriptions);
            break;

        case 4:
            calculateMonthlyTax(S, subscriptions);
            break;

        case 5:
            showSubscriptions(S, subscriptions);
            break;

        case 6:
            showSubscriptionsWithExpiringContracts(S, subscriptions);
            break;

        case 7:
            showSubscriptionsWithLeastMonthlyTax(S, subscriptions);
            break;

        case 8:
            showSubscriptionWithMostInternationalCalls(S, subscriptions);
            break;

        case 9:
            showSubscriptionWithShortestCall(S, subscriptions);
            break;
        }
    } while (choice != 10);

    system("cls");
    cout << "//////////////////////////////" << endl;
    cout << "//     QUITTING PROGRAM     //" << endl;
    cout << "//////////////////////////////" << endl;
}
