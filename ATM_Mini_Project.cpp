#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;

// Features of ATM Mini Project
// 1. User can Check the balance
// 2. User can withdraw cash
// 3. Users details 
// 4. Update Mobile Phone Number

// Class for ATM
class ATM
{
    private:
        long int acc_num;
        string name;
        int pin;
        double balance;
        string mobile;
    public:
        void setData(long int acc_num, string name, int pin, double balance, string mobile){
            this->acc_num = acc_num;
            this->name = name;
            this->pin = pin;
            this->balance = balance;
            this->mobile = mobile;
        }
        long int getAccNum(){
            return this->acc_num;
        }
        string getName(){
            return this->name;
        }
        int getPin(){
            return this->pin;
        }
        double getBalance(){
            return this->balance;
        }
        string getMobile(){
            return this->mobile;
        }

        void checkBalance(){
            cout << "Your Balance is: " << this->balance << endl;
            _getch();
        }
        void withdrawCash(double amount){
            if(amount > 0 && amount <= this->balance){
                this->balance -= amount;
                cout << "Please collect your cash" << endl;
                cout << "Your Remaining Balance is: " << this->balance << endl;
                _getch();
            }
            else{
                cout << "Invalid or Insufficient Amount" << endl;
                _getch();
            }
        }
        void ViewDetails(){
            cout << "Account Number: " << this->acc_num << endl;
            cout << "Name: " << this->name << endl;
            cout << "Balance: " << this->balance << endl;
            cout << "Mobile Number: " << this->mobile << endl;
            _getch();
        }
        void updateMobile(string old_mobile, string new_mobile){
            if(old_mobile == this->mobile){
                cout << "Enter New Mobile Number: ";
                cin >> new_mobile;
                this->mobile = new_mobile;
                cout << "Mobile Number Updated Successfully" << endl;
                _getch();
            }
            else{
                cout << "Invalid Mobile Number" << endl;
                _getch();
            }
        }


};



int main()
{
    int choice, account_num;
    int pin;
    double amount;
    string old_mob, new_mob;

    ATM user1;
    user1.setData(123456789, "Mubashar", 123, 10000, "03087031050");
    do
    {
        system("cls");
        cout << "**********Welcome to ATM**********" << endl;
        cout<< "Enter Account Number: ";
        cin >> account_num;
        cout << "Enter Pin: ";
        cin >> pin;
        if(account_num == user1.getAccNum() && pin == user1.getPin()){
            do
            {
                system("cls");
                cout << "==========Welcome Back " << user1.getName()<< "==========" << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Withdraw Cash" << endl;
                cout << "3. View Details" << endl;
                cout << "4. Update Mobile Number" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    user1.checkBalance();
                    _getch();
                    break;
                case 2:
                    cout << "Enter Amount: ";
                    cin >> amount;
                    user1.withdrawCash(amount);
                    _getch();
                    break;
                case 3:
                    user1.ViewDetails();
                    _getch();
                    break;
                case 4:
                    cout << "Enter Old Mobile Number: ";
                    cin >> old_mob;
                    user1.updateMobile(old_mob, new_mob);
                    _getch();
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    cout << "Invalid Choice" << endl;
                    _getch();
                    break;
                }
            } while (choice != 5);
        }
        else{
            cout << "Invalid Account Number or Pin" << endl;
            _getch();
        }

    } while (1);
    

 return 0;
}