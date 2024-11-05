// Description: SRT Radix-2 Division. 
// Author: Muhammad Ramzan
// Date: 10.10.2024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INTEGER_SIZE 5
#define PR_SIZE      10

// Function for SRT division
void SRTDIVISION(int dividend, int divisor) {
    int originalDividend = dividend;  // Save original dividend
    int originalDivisor = divisor;    // Save original divisor

    // Conversion into binary for dividend
    printf("Binary Representation of %d in %d bits is: ", originalDividend, INTEGER_SIZE);
    for (int i = INTEGER_SIZE - 1; i >= 0; i--) {
        // Output each bit of the dividend
        printf("%d", (dividend >> i) & 1);
    }
    printf("\n");
    //===========================================================================================
    // =============================== count number of leading zeros ============================
    //===========================================================================================

    // Conversion into binary for divisor
    printf("Binary Representation of %d in %d bits is: ", originalDivisor, INTEGER_SIZE);
    for (int i = INTEGER_SIZE - 1; i >= 0; i--) {
        // Output each bit of the divisor
        printf("%d", (divisor >> i) & 1);
    }
    printf("\n");

    
    //===========================================================================================
    // =============================== normalize divisor by leading zeros =======================
    //===========================================================================================

    // Count number of leading zeros
    int leading_zeros = 0; // Variable to store the count of leading zeros
    for (int i = (INTEGER_SIZE - 1); i >= 0; i--) {
        if ((originalDivisor >> i) & 1) { // Check if the bit at position i is 1
            break; // Exit the loop when the first 1 is found
        }
        leading_zeros++; // Increment the count of leading zeros
    }
    printf("Number of leading zeros in %d (5-bit): %d\n", originalDivisor, leading_zeros);
//

    //================================================================================================
    //find quotient&remainder of original Dividedn nd divisor in terms of normalization(leading zeros) =======================
    //================================================================================================

    // Normalize the dividend and divisor by shifting
    int normalize_originalDividend = originalDividend * (1 << leading_zeros);   // Multiplying by 2^leading_zeros
    int normalize_originalDivisor = originalDivisor   * (1 << leading_zeros);   // Multiplying by 2^leading_zeros
    //now we shall dind quotient and remainder

    int QUOTIENT  = normalize_originalDividend / normalize_originalDivisor;
    int REMAINDER = normalize_originalDividend % normalize_originalDivisor;
    // Output results
    printf("Normalized original dividend: %d\n", normalize_originalDividend);
    printf("Normalized original divisor: %d\n", normalize_originalDivisor);
    printf("Quotient: %d\n", QUOTIENT);
    printf("Remainder: %d\n", REMAINDER);


    //===========================================================================================
    // ====================== initialization of PR and shifting by L.zeros =======================
    //===========================================================================================

    // Normalize divisor by leading zeros
    int shifted_divisor;
    // Shift the divisor by number of leading zeros and add one more left shift
    shifted_divisor = originalDivisor << (leading_zeros ); // Shift left by leading_zeros 
    int neg_divisor = (~shifted_divisor + 1);


    // Print normalized divisor in binary format (11 bits)
    printf("Normalized divisor of %d (5 bits): ", originalDivisor);
    for (int i = (INTEGER_SIZE-1); i >= 0; i--) { // Change to 11 bits for printing
        printf("%d", (shifted_divisor >> i) & 1);
    }
    printf("\n");

    printf("2's Complement of Normalize divisor: ");
    for (int i = 4; i >= 0; i--) {
        printf("%d", (neg_divisor >> i) & 1);
    }
    printf("\n");




    //// Print normalized divisor in binary format (11 bits)
    //printf("Normalized divisor of %d (5 bits): ", originalDivisor);
    //for (int i = (INTEGER_SIZE-1); i >= 0; i--) { // Change to 11 bits for printing
    //    printf("%d", (shifted_divisor >> i) & 1);
    //}
    //printf("\n");

    // Normalize the partial remainder
    int Dividend5Bits = originalDividend & 0x1FFFF;  // Apply masking to select lower 5-bits
    int normalize_remainder = Dividend5Bits << (leading_zeros ); // Shift by leading zeros + 1 to add an extra 0

    // Print normalized partial remainder in binary format (11 bits)
    printf("Normalized partial remainder: ");
    for (int i = 10; i >= 0; i--) { // Change to 11 bits for printing
        printf("%d", (normalize_remainder >> i) & 1);
    }
    printf("\n");
    //===========================================================================================
    // ====================== perform shift operations and selection logic ======================
    //===========================================================================================
    int quotient;
    int final_quotient[INTEGER_SIZE];
    int Q = 0; //initilize with zero to store quotient
    int R = 0; // Initialize R to store the final corrected remainder
    for (int i = 0 ; i < INTEGER_SIZE ; i++)
    {
        normalize_remainder = normalize_remainder << 1;
        int MSB_Bit = ((normalize_remainder >> PR_SIZE) & 1);
        int Fraction_Bit = ((normalize_remainder >> (PR_SIZE - 1)) & 1);
        printf("My Remainder will be = ");
        for (int i = 10; i >= 0; i--) { // Loop for 11 bits (0 to 10)
            printf("%d", (normalize_remainder >> i) & 1); // Print each bit of extracted
        }
        printf("\n"); 
//        printf("MSB = %d , FB = %d\n", MSB_Bit, Fraction_Bit);


        if ((MSB_Bit == 1 && Fraction_Bit == 1) || (MSB_Bit == 0 && Fraction_Bit == 0))
        {
            quotient = 0;
            final_quotient[i] = quotient;
            printf("Quotient is: %d\n",quotient);
        }
        else if ((MSB_Bit == 0) && (Fraction_Bit == 1)) 
        {
            quotient = 1;
            final_quotient[i] = quotient;
            int upper_bits_partial_remainder   = (normalize_remainder >> 5) & 0b111111; // Extract bits 5 to 10 (6 bits)
            //printf("Extracted portion: ");
            //for (int i = 5; i >= 0; i--) {  // Loop for 6 bits
            //    printf("%d", (upper_bits_partial_remainder >> i) & 1); // Print each bit of extracted
            //}
            //printf("\n");
           int lower__bits_partial_remainder  = normalize_remainder & 0b00000011111;    // Get the remaining 5 bits (bits 0 to 4)
           int addition_neg_divisor = upper_bits_partial_remainder + neg_divisor;
           printf("Quotient is: %d\n",quotient);


           //printf("My Correction: ");
           //for (int i = 5; i >= 0; i--) {  // Loop for 6 bits
           //    printf("%d", (neg_divisor >> i) & 1); // Print each bit of extracted
           //}
           //printf("\n");
           
           normalize_remainder = (addition_neg_divisor << 5 ) | lower__bits_partial_remainder ;


        }
        else if ((MSB_Bit == 1) && (Fraction_Bit == 0)) 
        {
            quotient = -1;
            final_quotient[i] = quotient;
            int upper_bits_partial_remainder   = (normalize_remainder >> 5) & 0b111111; // Extract bits 5 to 10 (6 bits)
            int lower__bits_partial_remainder  = normalize_remainder & 0b00000011111;    // Get the remaining 5 bits (bits 0 to 4)
            int addition_neg_divisor = upper_bits_partial_remainder + shifted_divisor;
            normalize_remainder = (addition_neg_divisor << 5 ) | lower__bits_partial_remainder ;
            printf("Quotient is: %d\n",quotient);

        }
        //===========================================================================================
        // ====================== here is logic to print and store quotient =========================
        //===========================================================================================

        Q = (Q << 1) | final_quotient[i];           // Shift Q left by 1 and add the new bit from final_quotient




        //===========================================================================================
        // ====================== correction logic to check if reminder is negative =================
        //===========================================================================================
        if(i == (INTEGER_SIZE - 1))
        {   int corrected_remainder;
            int correction_bit = ((normalize_remainder >> (PR_SIZE - 1)) & 1);
            if(correction_bit == 1)
            {
                Q = Q - (00001);
                int last_upper_bits = (normalize_remainder >> 5) & 0b11111;
                int last_lower_bits = normalize_remainder & 0b00000011111;
                int last_addition_result = last_upper_bits + shifted_divisor;
                normalize_remainder = (last_addition_result <<5) | last_lower_bits;
                corrected_remainder = (normalize_remainder >> 5) & 0b11111;
                // Store corrected remainder in R
                R = corrected_remainder; 
                printf("Correct has been applied on Quotient and Remainder. \n");
                printf("My final 5-bit Remainder after Correction is: ");
                for (int i = (INTEGER_SIZE  -1); i >= 0; i--) {  // Loop for 6 bits
                    printf("%d", (corrected_remainder >> i) & 1); // Print each bit of extracted
                }
                printf("\n");
                //
                //printf("Correct has been applied on Quotient. \n");
        //        printf("Final Quotient after Correction is: ");
        //        for(int i = (INTEGER_SIZE-1); i>=0 ; i--)
        //        {
        //            printf("%d", (Q >> i) & 1); // Print each bit of extracted
        //        }
        //        printf("\n");

            }
            else
            {
                corrected_remainder = (normalize_remainder >> 5) & 0b11111;
                // Store corrected remainder in R
                R = corrected_remainder; 
                printf("My final 5-bit Remainder: ");
                for (int i = (INTEGER_SIZE  -1); i >= 0; i--) {  // Loop for 6 bits
                    printf("%d", (corrected_remainder >> i) & 1); // Print each bit of extracted
                }
                printf("\n");
            }
        }

    }

    //===========================================================================================
    // ====================== find quotient and remmainer both in binary & decimal ==============
    //===========================================================================================

    //printf("Final Quotient is: ");
    //for (int j = 0; j < (INTEGER_SIZE); j++) {  // Loop through quotient array from 0 to i
    //    printf("%d", final_quotient[j]);
    //}
    //printf("\n");

    printf("Final Quotient in binary: ");
    for(int i = (INTEGER_SIZE-1); i>=0 ; i--)
    {
        printf("%d", (Q >> i) & 1); // Print each bit of extracted
    }
    printf("\n");



    printf("Final Quotient in decimal: %d\n", Q); // This will print Q as an integer value

    // Print final remainder
    printf("Final Remainder in binary: ");
    for(int i = (INTEGER_SIZE-1); i >= 0; i--) {
        printf("%d", (R >> i) & 1); // Print each bit of remainder
    }
    printf("\n");

    printf("Final Remainder in decimal: %d\n", R); // Print R as an integer

    //===========================================================================================
    // ====================== check test cases either passed/failed =============================
    //===========================================================================================
    // Cast QUOTIENT and Q to integers, and compare them. Also, cast REMAINDER and R to integers, and compare them. 
    // If both QUOTIENT equals Q and REMAINDER equals R, print "Test is pass."
    if ((int)QUOTIENT == (int)Q && (int)REMAINDER == (int)R)
    {
        printf("Test is pass.\n");
    }

    else
    {
        printf("Failed Test\n");
    }




}


//===========================================================================================
// ================================== user defined values ===================================
//===========================================================================================

//}
//
int main() {
    int dividend;
    int divisor;

    // Input values
    printf("Enter dividend: ");
    scanf("%d", &dividend);  // Use & to provide6 5xthe address
    printf("Enter divisor: ");
    scanf("%d", &divisor);   // Use & to provide the address

    // Call the function
    SRTDIVISION(dividend, divisor);

    return 0;
}

//===========================================================================================
// ====================== apply random test cases within range of 1 to 31 ===================
//===========================================================================================

//int main() {
//    srand(time(0));  // Seed the random number generator
//
//    for (int i = 0; i < 100; i++) {
//        int dividend = rand() % 31 + 1;  // Random number between 1 and 31
//        int divisor = rand() % 31 + 1;   // Random number between 1 and 31
//        
//        // Call SRT division function with the generated dividend and divisor
//        printf("Test Case %d: \n", i + 1);
//        SRTDIVISION(dividend, divisor);
//    }
//
//    return 0;
//}
//


