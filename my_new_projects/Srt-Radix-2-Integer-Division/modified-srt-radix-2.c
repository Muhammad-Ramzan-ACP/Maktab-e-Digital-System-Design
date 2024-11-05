// Description: SRT Radix-2 Division. 
// Author: Muhammad Ramzan
// Date: 10.10.2024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INTEGER_SIZE 4
#define PR_SIZE      8

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
    int leading_ones  = 0; // Variable to store the count of leading ones -1 mean that it count sign bit also which is not a l
    if (originalDivisor > 0)
    {
        //int leading_zeros = 0; // Variable to store the count of leading zeros
        for (int i = (INTEGER_SIZE - 1); i >= 0; i--) {
            if ((originalDivisor >> i) & 1) { // Check if the bit at position i is 1
            break; // Exit the loop when the first 1 is found
        }
        leading_zeros++; // Increment the count of leading zeros
    }
    printf("Number of leading zeros in %d (4-bit): %d\n", originalDivisor, leading_zeros);
    }
    //===========================================================================================
    // =============================== normalize divisor by leading ones ========================
    //===========================================================================================
    else
    {
        for (int i = (INTEGER_SIZE - 1); i >= 0; i--) {
            if (!((originalDivisor >> i) & 1)) { // Check if the bit at position i is 0
                break; // Exit the loop when the first 0 is found
            }
            leading_ones++; // Increment the count of leading ones
        }
        printf("Number of leading ones in %d (5-bit): %d\n", originalDivisor, leading_ones);
    }
    int shifted_divisor;
    int neg_divisor;


    if (originalDivisor < 0)
    {
        // Shift the divisor by number of leading ones and add one more left shift
        shifted_divisor = originalDivisor << (leading_ones -1 ); // Shift left by leading_zeros 
        neg_divisor = (~shifted_divisor + 1);
        // Print normalized divisor in binary format (11 bits)
        printf("Normalized divisor of %d (5 bits) for a Signed Number: ", originalDivisor);
        for (int i = (INTEGER_SIZE-1); i >= 0; i--) { // Change to 11 bits for printing
            printf("%d", (shifted_divisor >> i) & 1);
        }
        printf("\n");
        //
        printf("2's Complement form of Normalize diviosor: ");
        for (int i = (INTEGER_SIZE-1); i >= 0; i--) {
            printf("%d", (neg_divisor >> i) & 1);
        }
        printf("\n");
    }
    else
    {
        // Shift the divisor by number of leading ones and add one more left shift
        shifted_divisor = originalDivisor << (leading_zeros-1); // Shift left by leading_zeros 
        neg_divisor = (~shifted_divisor + 1);
        // Print normalized divisor in binary format- (11 bits)
        printf("Normalized divisor of %d (5 bits) for a Signed Number: ", originalDivisor);
        for (int i = (INTEGER_SIZE-1); i >= 0; i--) { // Change to 11 bits for printing
            printf("%d", (shifted_divisor >> i) & 1);
        }
        printf("\n");
        //
        printf("2's Complement form of Normalize diviosor: ");
        for (int i = 4; i >= 0; i--) {
            printf("%d", (neg_divisor >> i) & 1);
        }
        printf("\n");
    }


    
    
    //================================================================================================
    //find quotient&remainder of original Dividedn nd divisor in terms of normalization(leading zeros) =======================
    //================================================================================================
    int Dividend5Bits;
    int normalize_remainder;
    if (originalDivisor > 0) //&& (originalDividend > 0)
    {
        // Normalize the partial remainder
        Dividend5Bits = originalDividend & 0x1FFFF;  // Apply masking to select lower 5-bits
        normalize_remainder = Dividend5Bits << (leading_zeros ); // Shift by leading zeros + 1 to add an extra 0
        // Print normalized partial remainder in binary format (11 bits)
        printf("Normalized partial remainder for Unsigned Divisor: ");
        for (int i = (PR_SIZE); i >= 0; i--) { // Change to 11 bits for printing
            printf("%d", (normalize_remainder >> i) & 1);
        }
        printf("\n");
    }
    else
    {
        // Normalize the partial remainder
        Dividend5Bits = originalDividend & 0x1FFFF;  // Apply masking to select lower 5-bits
        normalize_remainder = Dividend5Bits << (leading_ones ); // Shift by leading zeros + 1 to add an extra 0
        // Print normalized partial remainder in binary format (11 bits)
        printf("Normalized partial remainder for Signed Divisor: ");
        for (int i = (PR_SIZE); i >= 0; i--) { // Change to 11 bits for printing
            printf("%d", (normalize_remainder >> i) & 1);
        }
        printf("\n");
    }
    //===========================================================================================
    // ====================== perform shift operations and selection logic ======================
    //===========================================================================================
    int quotient;
    int quotient_sub;
    int final_quotient[INTEGER_SIZE];
    int final_quotient_result[INTEGER_SIZE];
    int Q_add;
    int Q_sub;
    int Q = 0; //initilize with zero to store quotient
    int R = 0; // Initialize R to store the final corrected remainder
    int MSB_Bit;
    int Fraction_Bit;

    int MSB_Bit_shifted_divisor;
    int magnitude_normalize_remainder;
    int BFS_MSB_Bit;
    int mag_MSB_Bit ;    
    int mag_Fraction_Bit;
    int upper_bits_signed_number;
    int lower_bits_signed_number;
    int addition_signed_number ; 
    int sign_divisor;
    int sign_normalize_remainder;
    //if ((originalDividend > 0) && ( originalDivisor > 0))
    for (int i = 0 ; i < 4 ; i++)
    {
        BFS_MSB_Bit = ((normalize_remainder >> PR_SIZE) & 1);
        normalize_remainder = normalize_remainder << 1;
        MSB_Bit = ((normalize_remainder >> PR_SIZE) & 1);
        Fraction_Bit = ((normalize_remainder >> (PR_SIZE - 1)) & 1);
        MSB_Bit_shifted_divisor = (shifted_divisor >> (INTEGER_SIZE - 1)) & 1;
        //printf("MSB of 01000 (5-bit): %d\n", MSB_Bit_shifted_divisor);
        printf("My Remainder will be = ");
        for (int i = (PR_SIZE); i >= 0; i--) { // Loop for 11 bits (0 to 10)
            printf("%d", (normalize_remainder >> i) & 1); // Print each bit of extracted
        }
        printf("\n"); 
        //int upper_bits_signed_number;
        //int lower_bits_signed_number;
        //int addition_signed_number ; 
        if (MSB_Bit == 1)
        {
            magnitude_normalize_remainder = (~normalize_remainder + 1);
            //normalize_remainder = normalize_remainder<<1;
            printf("Magnitude Remainder = ");
            for (int i = (PR_SIZE-1); i >= 0; i--) { // Loop for 11 bits (0 to 10)
                printf("%d", (magnitude_normalize_remainder >> i) & 1); // Print each bit of extracted
            }
            printf("\n"); 

            //mag_MSB_Bit = 
            mag_MSB_Bit      = ((magnitude_normalize_remainder >> PR_SIZE) & 1);
            mag_Fraction_Bit = ((magnitude_normalize_remainder >> (PR_SIZE - 1)) & 1);
            printf("mag_MSB :%d\n",mag_MSB_Bit);
            printf("mag_Fract :%d\n",mag_Fraction_Bit);
            printf("BFS_MSB_Bit : %d\n",BFS_MSB_Bit);
            printf("MSB_Bit_shifted_divisor : %d\n",MSB_Bit_shifted_divisor);

            if (mag_MSB_Bit == 0 && mag_Fraction_Bit == 0)
            {
                quotient = 0;
                final_quotient[i] = quotient;
                printf("Quotient is: %d\n",quotient);
                printf("Condition 1 True: \n");
            }
            else if ((mag_MSB_Bit == 0 && mag_Fraction_Bit == 1) && (BFS_MSB_Bit == MSB_Bit_shifted_divisor))
            {
                quotient = 1;
                printf("Quotient is: %d\n",quotient);
                final_quotient[i] = quotient;
                upper_bits_signed_number = (normalize_remainder >> 5) & 0b1111; // Extract upper bits

                lower_bits_signed_number = normalize_remainder & 0b000011111;
                addition_signed_number = upper_bits_signed_number + neg_divisor;

                normalize_remainder = (addition_signed_number << 5) | lower_bits_signed_number;
                printf("Condition 2 True: \n");
                //printf("UDP = ");
                //for (int i = 10; i >= 0; i--) { // Loop for 11 bits (0 to 10)
                //    printf("%d", (normalize_remainder >> i) & 1); // Print each bit of extracted
                //}
                //printf("\n"); 
            }
            else if ((mag_MSB_Bit == 0 && mag_Fraction_Bit == 1) && (BFS_MSB_Bit != MSB_Bit_shifted_divisor))
            {
                quotient = -1;
                quotient_sub = (~quotient + 1);
                final_quotient_result[i] = quotient_sub;
                printf("Quotient is: %d\n",quotient);
                upper_bits_signed_number = (normalize_remainder >> 5) & 0b1111; // Extract upper bits
                printf("\n"); 
                lower_bits_signed_number = normalize_remainder & 0b000011111;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << 5) | lower_bits_signed_number;
                printf("Condition 3 True: \n");
            }
            else if ((mag_MSB_Bit == 1 && mag_Fraction_Bit == 0) && (BFS_MSB_Bit == MSB_Bit_shifted_divisor))
            {
                quotient = 1;
                final_quotient[i] = quotient;
                printf("Quotient is: %d\n",quotient);
                upper_bits_signed_number = (normalize_remainder >> 5) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b000011111;
                addition_signed_number = upper_bits_signed_number + neg_divisor;
                normalize_remainder = (addition_signed_number << 5) | lower_bits_signed_number;
                printf("Condition 4 True: \n");
            }
            else if ((mag_MSB_Bit == 1 && mag_Fraction_Bit == 0) && (BFS_MSB_Bit != MSB_Bit_shifted_divisor))
            {
                quotient = -1;
                quotient_sub = (~quotient + 1);
                final_quotient_result[i] = quotient_sub;
                printf("Quotient is: %d\n",quotient);
                upper_bits_signed_number = (normalize_remainder >> 5) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b000011111;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << 5) | lower_bits_signed_number;
                printf("Condition 5 True: \n");
            }
        }
        else
        {
            if ( MSB_Bit == 0 && Fraction_Bit == 0)
            {
                quotient = 0;
                final_quotient[i] = quotient;
                printf("Quotient is: %d\n",quotient);
                printf("Condition 6 True: \n");
            }
            else if (( MSB_Bit == 0 && Fraction_Bit == 1 ) && (BFS_MSB_Bit == MSB_Bit_shifted_divisor))
            {
                quotient = 1;
                printf("Quotient is: %d\n",quotient);
                printf("Condition 7 True: \n");
                final_quotient[i] = quotient;
                upper_bits_signed_number = (normalize_remainder >> 5) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b000011111;
                addition_signed_number   = upper_bits_signed_number + neg_divisor;
                normalize_remainder = (addition_signed_number << 5) | lower_bits_signed_number;
            } 
            else if (( MSB_Bit == 0 && Fraction_Bit == 1 ) && (BFS_MSB_Bit != MSB_Bit_shifted_divisor))
            {
                quotient = -1;
                quotient_sub = (~quotient + 1);
                final_quotient_result[i] = quotient_sub;
                printf("Quotient is: %d\n",quotient);
                printf("Condition 9 True: \n");
                //final_quotient[i] = quotient;
                upper_bits_signed_number = (normalize_remainder >> 5) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b000011111;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << 5) | lower_bits_signed_number;
                
            }
        }
        Q_add = (Q_add << 1) | final_quotient[i];           // Shift Q left by 1 and add the new bit from final_quotient
        Q_sub = (Q_sub << 1) | final_quotient_result[i];           // Shift Q left by 1 and add the new bit from final_quotient
        Q = Q_add - Q_sub;
        // Print the final normalized remainder after all conditions have been checked
    printf("Final normalize remainder after MSB_Bit == 0 = ");
    for (int i = (PR_SIZE); i >= 0; i--) {
        printf("%d", (normalize_remainder >> i) & 1);
    }
        printf("\n");
    }
    //===========================================================================================
    // ===================================== correction logic ===================================
    //===========================================================================================
    if (originalDividend > 0)
    {
        sign_divisor = 0;
    }
    else
    {
        sign_divisor = 1;
    }

    upper_bits_signed_number = (normalize_remainder >> 5) & 0b1111; // Extract upper bits

    sign_normalize_remainder = ((normalize_remainder >> PR_SIZE) & 1);
    if (upper_bits_signed_number != 0) {  // Only apply correction if remainder is non-zero
        if (sign_normalize_remainder != sign_divisor)
        {
            printf("Correction logic will be applied:\n ");
            if (originalDividend > 0 && originalDivisor > 0)
            {
                Q = Q - 0x1;
                upper_bits_signed_number = (normalize_remainder >> 5) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b000011111;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << 5) | lower_bits_signed_number;

            }
            else
            {
                Q = Q + 0x1;
                upper_bits_signed_number = (normalize_remainder >> 5) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b000011111;
                addition_signed_number = upper_bits_signed_number + neg_divisor;
                normalize_remainder = (addition_signed_number << 5) | lower_bits_signed_number;
            }
        }
    }
    else
    {
        printf("No need of correcton");
    }
    //===========================================================================================
    // ===================================== correction logic ===================================
    //===========================================================================================

    R = (normalize_remainder >> 5) & 0b1111; // Extract upper bits
    if (originalDivisor > 0)
    {
        R = R >> (leading_zeros-1);
    }
    else
    {
        R = R >> (leading_ones-1);
    }
    printf("Correction Reainder:");
    for (int i = (INTEGER_SIZE); i >= 0; i--) {
        printf("%d", (R >> i) & 1);
    }
        printf("\n");


    printf("Final Quotient in binary: ");
    for(int i = (INTEGER_SIZE-1); i>=0 ; i--)
    {
        printf("%d", (Q >> i) & 1); // Print each bit of extracted
    }
    printf("\n");
    printf("Final Quotient in decimal: %d\n", Q); // This will print Q as an integer value
    // Print final remainder
    printf("Final Remainder in binary: ");
    for(int i = (INTEGER_SIZE); i >= 0; i--) {
        printf("%d", (R >> i) & 1); // Print each bit of remainder
    }
    printf("\n");
    printf("Final Remainder in decimal: %d\n", R); // Print R as an integer
}
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
