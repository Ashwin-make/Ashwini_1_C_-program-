include <stdio.h>

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    int choice;
    float temperature, converted;

    do {
        printf("\n--- Temperature Conversion Program ---\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                converted = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, converted);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                converted = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, converted);
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
