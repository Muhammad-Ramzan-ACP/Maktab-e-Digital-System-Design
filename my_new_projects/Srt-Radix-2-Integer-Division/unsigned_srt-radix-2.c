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
        printf("%d", (dividend >> i) & 1);
    }
    printf("\n");

    // Conversion into binary for divisor
    printf("Binary Representation of %d in %d bits is: ", originalDivisor, INTEGER_SIZE);
    for (int i = INTEGER_SIZE - 1; i >= 0; i--) {
        printf("%d", (divisor >> i) & 1);
    }
    printf("\n");

    // Count number of leading zeros or ones
    int leading_zeros = 0;
    int leading_ones = 0;

    if (originalDivisor > 0) {
        for (int i = INTEGER_SIZE - 1; i >= 0; i--) {
            if ((originalDivisor >> i) & 1) {
                break;
            }
            leading_zeros++;
        }
        printf("Number of leading zeros in %d (4-bit): %d\n", originalDivisor, leading_zeros);
    } else {
        for (int i = INTEGER_SIZE - 1; i >= 0; i--) {
            if (!((originalDivisor >> i) & 1)) {
                break;
            }
            leading_ones++;
        }
        printf("Number of leading ones in %d (5-bit): %d\n", originalDivisor, leading_ones);
    }

    int shifted_divisor;
    int neg_divisor;

    if (originalDivisor < 0) {
        if (leading_ones > 1) {
            shifted_divisor = originalDivisor << (leading_ones - 1);
        } else {
            shifted_divisor = originalDivisor;
        }
        neg_divisor = ~shifted_divisor + 1;

        printf("Normalized divisor of %d (5 bits) for a Signed Number: ", originalDivisor);
        for (int i = INTEGER_SIZE - 1; i >= 0; i--) {
            printf("%d", (shifted_divisor >> i) & 1);
        }
        printf("\n");

        printf("2's Complement form of Normalized divisor: ");
        for (int i = INTEGER_SIZE - 1; i >= 0; i--) {
            printf("%d", (neg_divisor >> i) & 1);
        }
        printf("\n");
    } else {
        if (leading_zeros > 1) {
            shifted_divisor = originalDivisor << (leading_zeros - 1);
        } else {
            shifted_divisor = originalDivisor;
        }
        neg_divisor = ~shifted_divisor + 1;

        printf("Normalized divisor of %d (5 bits) for a Signed Number: ", originalDivisor);
        for (int i = INTEGER_SIZE - 1; i >= 0; i--) {
            printf("%d", (shifted_divisor >> i) & 1);
        }
        printf("\n");

        printf("2's Complement form of Normalized divisor: ");
        for (int i = INTEGER_SIZE - 1; i >= 0; i--) {
            printf("%d", (neg_divisor >> i) & 1);
        }
        printf("\n");
    }

    // Normalize partial remainder
    int Dividend5Bits;
    int normalize_remainder;
    if (originalDivisor > 0) {
        Dividend5Bits = originalDividend & 0x1FFFF;
        if (leading_zeros > 1) {
            normalize_remainder = Dividend5Bits << (leading_zeros - 1);
        } else {
            normalize_remainder = Dividend5Bits;
        }

        printf("Normalized partial remainder for Unsigned Divisor: ");
        for (int i = PR_SIZE - 1; i >= 0; i--) {
            printf("%d", (normalize_remainder >> i) & 1);
        }
        printf("\n");
    } else {
        Dividend5Bits = originalDividend & 0x1FFFF;
        if (leading_ones > 1) {
            normalize_remainder = Dividend5Bits << (leading_ones - 1);
        } else {
            normalize_remainder = Dividend5Bits;
        }

        printf("Normalized partial remainder for Signed Divisor: ");
        for (int i = PR_SIZE - 1; i >= 0; i--) {
            printf("%d", (normalize_remainder >> i) & 1);
        }
        printf("\n");
    }
//}
//
//int main() {
//    int dividend, divisor;
//    printf("Enter dividend: ");
//    scanf("%d", &dividend);
//    printf("Enter divisor: ");
//    scanf("%d", &divisor);
//    SRTDIVISION(dividend, divisor);
//    return 0;
//}

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
        BFS_MSB_Bit = ((normalize_remainder >> (PR_SIZE-1)) & 1);
        normalize_remainder = normalize_remainder << 1;
        MSB_Bit = ((normalize_remainder >> (PR_SIZE-1)) & 1);
        Fraction_Bit = ((normalize_remainder >> (PR_SIZE - 2)) & 1);
        MSB_Bit_shifted_divisor = (shifted_divisor >> (INTEGER_SIZE - 1)) & 1;
        //printf("MSB of 01000 (5-bit): %d\n", MSB_Bit_shifted_divisor);
        printf("My Remainder will be = ");
        for (int i = (PR_SIZE-1); i >= 0; i--) { // Loop for 11 bits (0 to 10)
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
            mag_MSB_Bit      = ((magnitude_normalize_remainder >> (PR_SIZE-1)) & 1);
            mag_Fraction_Bit = ((magnitude_normalize_remainder >> (PR_SIZE - 2)) & 1);
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
                upper_bits_signed_number = (normalize_remainder >> 4) & 0b1111; // Extract upper bits

                lower_bits_signed_number = normalize_remainder & 0b00001111;
                addition_signed_number = upper_bits_signed_number + neg_divisor;

                normalize_remainder = (addition_signed_number << 4) | lower_bits_signed_number;
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
                upper_bits_signed_number = (normalize_remainder >> 4) & 0b1111; // Extract upper bits
                printf("\n"); 
                lower_bits_signed_number = normalize_remainder & 0b00001111;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << 4) | lower_bits_signed_number;
                printf("Condition 3 True: \n");
            }
            else if ((mag_MSB_Bit == 1 && mag_Fraction_Bit == 0) && (BFS_MSB_Bit == MSB_Bit_shifted_divisor))
            {
                quotient = 1;
                final_quotient[i] = quotient;
                printf("Quotient is: %d\n",quotient);
                upper_bits_signed_number = (normalize_remainder >> 4) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b00001111;
                addition_signed_number = upper_bits_signed_number + neg_divisor;
                normalize_remainder = (addition_signed_number << 4) | lower_bits_signed_number;
                printf("Condition 4 True: \n");
            }
            else if ((mag_MSB_Bit == 1 && mag_Fraction_Bit == 0) && (BFS_MSB_Bit != MSB_Bit_shifted_divisor))
            {
                quotient = -1;
                quotient_sub = (~quotient + 1);
                final_quotient_result[i] = quotient_sub;
                printf("Quotient is: %d\n",quotient);
                upper_bits_signed_number = (normalize_remainder >> 4) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b00001111;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << 4) | lower_bits_signed_number;
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
                upper_bits_signed_number = (normalize_remainder >> 4) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b00001111;
                addition_signed_number   = upper_bits_signed_number + neg_divisor;
                normalize_remainder = (addition_signed_number << 4) | lower_bits_signed_number;
            } 
            else if (( MSB_Bit == 0 && Fraction_Bit == 1 ) && (BFS_MSB_Bit != MSB_Bit_shifted_divisor))
            {
                quotient = -1;
                quotient_sub = (~quotient + 1);
                final_quotient_result[i] = quotient_sub;
                printf("Quotient is: %d\n",quotient);
                printf("Condition 9 True: \n");
                //final_quotient[i] = quotient;
                upper_bits_signed_number = (normalize_remainder >> 4) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b00001111;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << 4) | lower_bits_signed_number;
                
            }
        }
        Q_add = (Q_add << 1) | final_quotient[i];           // Shift Q left by 1 and add the new bit from final_quotient
        Q_sub = (Q_sub << 1) | final_quotient_result[i];           // Shift Q left by 1 and add the new bit from final_quotient
        Q = Q_add - Q_sub;
        // Print the final normalized remainder after all conditions have been checked
    printf("Final normalize remainder after MSB_Bit == 0 = ");
    for (int i = (PR_SIZE-1); i >= 0; i--) {
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

    upper_bits_signed_number = (normalize_remainder >> 4) & 0b1111; // Extract upper bits

    sign_normalize_remainder = ((normalize_remainder >> (PR_SIZE-1)) & 1);
    if (upper_bits_signed_number != 0) {  // Only apply correction if remainder is non-zero
        if (sign_normalize_remainder != sign_divisor)
        {
            printf("Correction logic will be applied:\n ");
            if (originalDividend > 0 && originalDivisor > 0)
            {
                Q = Q - 0x1;
                upper_bits_signed_number = (normalize_remainder >> 4) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b00001111;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << 4) | lower_bits_signed_number;

            }
            else
            {
                Q = Q + 0x1;
                upper_bits_signed_number = (normalize_remainder >> 4) & 0b1111; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0b00001111;
                addition_signed_number = upper_bits_signed_number + neg_divisor;
                normalize_remainder = (addition_signed_number << 4) | lower_bits_signed_number;
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

    R = (normalize_remainder >> 4) & 0b1111; // Extract upper bits
    if (R & (1 << (INTEGER_SIZE - 1))) { // Check if MSB is 1
    R = R | (~((1 << INTEGER_SIZE) - 1)); // Sign extend to convert to negative
    }
    
    if ((originalDivisor > 0) && (leading_zeros > 0)) {
        R = R >> (leading_zeros - 1);
    } else if ((originalDivisor < 0) && (leading_ones > 0)) {
        R = R >> (leading_ones - 1);
    }

    //if (originalDivisor > 0)
    //{
    //    R = R >> (leading_zeros-1);
    //}
    //else
    //{
    //    R = R >> (leading_ones-1);
    //}
    // If MSB of R is 1, interpret R as a negative number
    // If MSB of R is 1, interpret R as a negative number
    //if (R & (1 << (INTEGER_SIZE - 1))) { // Check if MSB is 1
    //    R = R | (~((1 << INTEGER_SIZE) - 1)); // Sign extend to convert to negative
    //}
    

    printf("Correction Reainder:");
    for (int i = (INTEGER_SIZE-1); i >= 0; i--) {
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
    for(int i = (INTEGER_SIZE-1); i >= 0; i--) {
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
