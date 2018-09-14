/* This program will help any user to obtain
 * his/her BMI in two measuring systems by asking
 * his/her weight and height using
 *
 * Author: Hugo Aguirre
 * Date: September 13, 2018
 * */

#include <stdio.h>
#include <math.h>

// this function will obtain the BMI in Metric system
void BMIm (double h, double w, double* BMI) {
    *BMI = w / pow(h,2);
}

// This function will obtain the BMI in Imperial system
void BMIi (double h, double w, double* BMI) {
    w = w * 0.453592;
    h = h * 0.3048;
    *BMI = w / pow(h,2);
}

// This function will show the user the reference about his BMI
void resultBMI (double BMI) {
    printf("Your BMI is: %lf \n", BMI);

    if (BMI < 18.5) printf("C´mon man, very low BMI, try eating more and healthier!\n");
    else {
        if (BMI >= 18.5 && BMI <= 24.9) printf("Excellent! Your BMI level is normal\n");
        if (BMI >= 25.0 && BMI <= 29.9) printf("Watch out! You are overweight, think twice before eating too much.\n");
        if (BMI >= 30.0) printf("Stop right there! You are obese, eat more greens and do some sports before thinking about a pizza");
    }

}

//variable declarations
int main(void) {
    double weight = 0.0;
    double height = 0.0;
    double BMI = 0.0;
    int option;

    // Here we input the menu with the options that can be selected
    printf("---Hello user, I will help you calculating your BMI---\n");
    printf("We are using 2 measuring options:\n");
    printf("Press 1 for metric system.\n");
    printf("Press 2 for imperial system.\n");
    printf("Press 0 to exit.\n\n");
    printf("Which one do you want?:\n");
    scanf("%i", &option);


    //we use switch to identify each case
    switch(option) {
        case 1:
            printf("Give me your height in meters: \n");
            scanf("%lf", &height);
            printf("Give me your weight in kilograms: \n");
            scanf("%lf", &weight);

            BMIm(height, weight, &BMI);
            break;

        case 2:
            printf("Give me your height in ft: \n");
            scanf("%lf", &height);
            printf("Give me your weight in pounds: \n");
            scanf("%lf", &weight);

            BMIi(height, weight, &BMI);
            break;

        default:
            printf("Invalid option, select option 1 or 2 to proceed!\n");
            return 0;

    }

    // We give the user his final BMI result
    resultBMI(BMI);


    return 0;
}