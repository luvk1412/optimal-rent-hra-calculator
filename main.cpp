#include<bits/stdc++.h>
using namespace std;

double max_saving = 0;
double max_saving_rent = 0;


void calculate(int rent, int hra, int basic_salary, bool print, int months, int inital_yearly_earning){
	if(print) cout << "##### RENT : " << rent << endl;

	double bs_40_percent = 40.0/100 * basic_salary;
	double excess_rent = max(0.0, rent - (10.0/100 * basic_salary));


	double hra_exmpted = min(bs_40_percent, min(hra*1.0, excess_rent));


	double hra_money_saved = 30.0/100 * hra_exmpted;
	double yearly_hra_saved = hra_money_saved * months;

	double total_earning = inital_yearly_earning + rent * months;
	double total_earning_copy = total_earning;

	double money_given_on_income_tax = 0;
	total_earning -= 300000;
	if(total_earning >= 0){
		money_given_on_income_tax += 5.0/100 * min(200000.0, total_earning);
		total_earning -= 200000;
	}

	if(total_earning >= 0){
		money_given_on_income_tax += 20.0/100 * min(500000.0, total_earning);
		total_earning -= 500000;
	}

	if(total_earning >= 0){
		money_given_on_income_tax += 30.0/100 * total_earning;
	}

	double net_saving = yearly_hra_saved - money_given_on_income_tax;
	if(print){
		cout << "Monthly hra exempted: " << hra_exmpted << endl;
		cout << "Monthly hra_money_saved: " << hra_money_saved << endl;
		cout << "Yearly hra money_saved: " << yearly_hra_saved << endl;
		cout << "Yearly landloard income: " << total_earning_copy << endl;
		cout << "Yearly landloard tax: " << money_given_on_income_tax << endl;
		cout << "Net profit if rentee and landlord are same: " << net_saving << endl;
	}
	if(max_saving < net_saving){
		max_saving = net_saving;
		max_saving_rent = rent;
	}
}


int main(){
	int basic_salary;
	int hra;
	int rent;
	cin >> basic_salary >> hra >> rent;
	int inital_yearly_earning = 0;
	bool run_loop = true;
	bool print_all_rents_in_loop = false;
	int rent_month_count = 12;

	if(run_loop){
		for(int i = 1; i <= 100; ++i){
			rent = i * 1000;
			calculate(rent, hra, basic_salary, print_all_rents_in_loop, rent_month_count, inital_yearly_earning);
		}
		cout << "Max saving: " << max_saving << ", rent: " << max_saving_rent << endl;
		calculate(max_saving_rent, hra, basic_salary, true, rent_month_count, inital_yearly_earning);
	}else{
		calculate(rent, hra, basic_salary, true, rent_month_count, inital_yearly_earning);
	}


}
