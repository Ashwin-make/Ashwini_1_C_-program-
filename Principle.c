include <stdio.h>
int main(void) {
  float principle, rate, time, si;
  printf("Enter principle (amount): ");
  scanf("%f", &principle);
  printf("Enter time: ");
  scanf("%f", &time);
  printf("Enter rate: ");
  scanf("%f", &rate);
  si = (principle * rate * time) /100;
  printf("Simple Interest = %f\n" , si);
  return 0;
  
