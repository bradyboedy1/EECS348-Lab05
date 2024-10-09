#include <stdio.h>

float findAvg(float nums[], int sMonth, int eMonth);

int main() {
    FILE *inputFile;
    float nums[12];
    char months[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int sizeOfArray = 0;

    // Open and read input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    // Add the floats into the list from the inputFile
    while (fscanf(inputFile, "%f", &nums[sizeOfArray]) != EOF) {
        sizeOfArray++;
        
        // Stops user from entering more than 12 numbers
        if (sizeOfArray >= 12){
            break;
        }
    }

    fclose(inputFile);




    // Monthly Sales Report
    printf("\nMonthly Sales Report for 2024:\n");
    printf("\nMonth        Sales");

    for (int i = 0; i < sizeOfArray; i++) {
        printf("\n%-12s %.2f", months[i], nums[i]);
    }



    // Sales Summary Report
    float lowest = nums[0];
    int lowestIndex = 0;
    float highest = nums[0];
    int highestIndex = 0;

    for (int i = 1; i < sizeOfArray; i++) {
        if (nums[i] < lowest) {
            lowest = nums[i];
            lowestIndex = i;
        }

        if (nums[i] > highest) {
            highest = nums[i];
            highestIndex = i;
        }
    }

    printf("\n\n\nSales summary report:\n");
    printf("\nMinimum Sales: %.2f   (%s)\n", lowest, months[lowestIndex]);
    printf("Maximum Sales: %.2f   (%s)\n", highest, months[highestIndex]);

    float total = 0;
    for (int i=0; i<sizeOfArray; i++){
        total += nums[i];
    }

    float avg = total/sizeOfArray;
    printf("Average Sales: %.2f\n", avg);





    //Six month moving average
    printf("\n\nSix-Month moving average report:\n");
    printf("\nJanuary-June       %.2f", findAvg(nums, 0, 5));
    printf("\nFebruary-July      %.2f", findAvg(nums, 1, 6));
    printf("\nMarch-August       %.2f", findAvg(nums, 2, 7));
    printf("\nApril-September    %.2f", findAvg(nums, 3, 8));
    printf("\nMay-October        %.2f", findAvg(nums, 4, 9));
    printf("\nJune-November      %.2f", findAvg(nums, 5, 10));
    printf("\nJuly-December      %.2f\n", findAvg(nums, 6, 11));





    //Sales Report (highest to lowest)
    printf("\n\nSales report (highest to lowest):\n");
    float sortedNums[12];       // Copy array
    int sortedIndices[12];
    for (int i = 0; i < sizeOfArray; i++) {
        sortedNums[i] = nums[i];
        sortedIndices[i] = i;
    }

    for (int i=0; i < sizeOfArray-1; i++) {
        for (int j=0; j < sizeOfArray-i-1 ; j++) {
            if (sortedNums[j] < sortedNums[j + 1]) {
                // Trade values that are lesser
                float tempNum = sortedNums[j];
                sortedNums[j] = sortedNums[j + 1];
                sortedNums[j + 1] = tempNum;

                // sort corresponding indicies
                int tempIndex = sortedIndices[j];
                sortedIndices[j] = sortedIndices[j + 1];
                sortedIndices[j + 1] = tempIndex;
            }
        }
    }
    
    printf("\nMonth        Sales");

    for (int i = 0; i < sizeOfArray; i++) {
        printf("\n%-12s %.2f", months[sortedIndices[i]], sortedNums[i]);
    }

    return 0;
}

float findAvg(float nums[], int sMonth, int eMonth){
    float total = 0;
    for (int i = sMonth; i < eMonth + 1; i++){
        total += nums[i];
    }
    return total / 6;
}
