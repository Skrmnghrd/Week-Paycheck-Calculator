#include <stdio.h>

///simple earnings calculator

//const float k = 1.666666666667; //k is a constant from the formula, you don't actually need it because .5 is half an hour, no need for 30 min

typedef struct
{
  double hours_worked;
  double rate_per_hour;
  double overtime_rate;
  double overtime_hours;
  double deduction_percentage;
}payperiod;
void init_pay_period(payperiod * pp, double hours_worked, double hourly_rate, double deduction_percentage)
{
  //no need to call each one a pointer because the pointer already points to the structure itself?
  pp->hours_worked = hours_worked;
  pp->rate_per_hour = hourly_rate;
  pp->deduction_percentage = ((deduction_percentage*-1) + 100) / 100;
  pp->overtime_rate = (hourly_rate * 1.5);

  if(hours_worked > 40) //mas dako sya sa 40
  {
    double overtime_hours_worked = (hours_worked - 40);
    pp->overtime_hours = overtime_hours_worked;
  }
  /*
  printf("Hours Worked: %.2f\n", pp->hours_worked);
  printf("Rate/Hour: %.2f\n", pp->rate_per_hour);
  printf("Deduction: %.2f%%\n", pp->deduction_percentage);
  printf("Overtime Hours: %.2f\n", pp->overtime_hours);
  printf("Overtime Rate: %.2f\n", pp->overtime_rate);
  */
}
//functions declarations;
int time_calculator;
int overtime_calculator;
int main(void)
{
  double hours_worked;
  double hourly_rate;
  double deduction_percentage;
  double base_paycheck;
  double overtime_paycheck;

  double * POINTER_base_paycheck = &base_paycheck;
  double * POINTER_overtime_paycheck = &overtime_paycheck;
  
  payperiod january13; //change to user input
  printf("Please enter the number of hours worked: ");
  scanf("%lf", &hours_worked);
  //printf("%.2f", hours_worked);
  printf("Now, enter your hourly rate: ");
  scanf("%lf", &hourly_rate);

  printf("Enter deduction percentage. (eg 30, for 30\%%): ");
  scanf("%lf", &deduction_percentage);

  init_pay_period(&january13,hours_worked,hourly_rate, deduction_percentage);
  *POINTER_base_paycheck = ( ( (january13.hours_worked * january13.rate_per_hour) * january13.deduction_percentage) );
  *POINTER_overtime_paycheck = ( january13.overtime_rate * january13.overtime_hours);\
  printf("\n");
  printf("Your BASE paycheck would be \t\t\t\t\t\t$%.2f\n", base_paycheck);
  printf("Your OVERTIME rate is $%.2f and your earnings are:\t$%.2f \n", january13.overtime_rate, overtime_paycheck);
  printf("Your total paycheck for this week is: \t\t\t\t$%.2f\n", (overtime_paycheck + base_paycheck) );

  return 0;

}
