#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INTEGER_SIZE 8
#define PR_SIZE      16

// Function for SRT division
void SRTDIVISION(int dividend, int divisor) {
    int originalDividend = dividend;  // Save original dividend
    int originalDivisor = divisor;    // Save original diviso
    int QUOTIENT  = originalDividend / originalDivisor;
    int REMAINDER = originalDividend % originalDivisor;
    int leading_zeros = 0;
    int leading_ones = 0;

    if (originalDivisor > 0) {
        for (int i = INTEGER_SIZE - 1; i >= 0; i--) {
            if ((originalDivisor >> i) & 1) {
                break;
            }
            leading_zeros++;
        }
    }
    else 
    {
        for (int i = INTEGER_SIZE - 1; i >= 0; i--) {
            if (!((originalDivisor >> i) & 1)) {
                break;
            }
            leading_ones++;
        }
    }

    int shifted_divisor;
    int neg_divisor;

    if (originalDivisor < 0) {
        if (leading_ones > 1) {
            shifted_divisor = originalDivisor << (leading_ones - 1);
        } else {
            shifted_divisor = originalDivisor;
        }
        neg_divisor = (~shifted_divisor) + 1;
    } 
    else 
    {
        if (leading_zeros > 1) {
            shifted_divisor = originalDivisor << (leading_zeros - 1);
        } else {
            shifted_divisor = originalDivisor;
        }
        neg_divisor = (~shifted_divisor) + 1;
    }

    // Normalize partial remainder
    int Dividend_n_Bits;
    int normalize_remainder;
    if (originalDivisor > 0) {
        Dividend_n_Bits = originalDividend & 0x1FFFF;
        if (leading_zeros > 1) {
            normalize_remainder = Dividend_n_Bits << (leading_zeros - 1);
        } else {
            normalize_remainder = Dividend_n_Bits;
        
        } 
    }
    else 
    {
        Dividend_n_Bits = originalDividend & 0x1FFFF;
        if (leading_ones > 1) {
            normalize_remainder = Dividend_n_Bits << (leading_ones - 1);
        } else {
            normalize_remainder = Dividend_n_Bits;
        }
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
    for (int i = 0 ; i < INTEGER_SIZE ; i++)
    {
        BFS_MSB_Bit = ((normalize_remainder >> (PR_SIZE-1)) & 1);
        normalize_remainder = normalize_remainder << 1;
        MSB_Bit = ((normalize_remainder >> (PR_SIZE-1)) & 1);
        Fraction_Bit = ((normalize_remainder >> (PR_SIZE - 2)) & 1);
        MSB_Bit_shifted_divisor = (shifted_divisor >> (INTEGER_SIZE - 1)) & 1;
        if (MSB_Bit == 1)
        {
            magnitude_normalize_remainder = (~normalize_remainder + 1);
            mag_MSB_Bit      = ((magnitude_normalize_remainder >> (PR_SIZE-1)) & 1);
            mag_Fraction_Bit = ((magnitude_normalize_remainder >> (PR_SIZE - 2)) & 1);
            if (mag_MSB_Bit == 0 && mag_Fraction_Bit == 0)
            {
                quotient = 0;
                final_quotient[i] = quotient;
            }
            else if ((mag_MSB_Bit == 0 && mag_Fraction_Bit == 1) && (BFS_MSB_Bit == MSB_Bit_shifted_divisor))
            {
                quotient = 1;
                final_quotient[i] = quotient;
                upper_bits_signed_number = (normalize_remainder >> INTEGER_SIZE) & 0xFF; // Extract upper bits

                lower_bits_signed_number = normalize_remainder & 0x00FF;
                addition_signed_number = upper_bits_signed_number + neg_divisor;

                normalize_remainder = (addition_signed_number << INTEGER_SIZE) | lower_bits_signed_number;
            }
            else if ((mag_MSB_Bit == 0 && mag_Fraction_Bit == 1) && (BFS_MSB_Bit != MSB_Bit_shifted_divisor))
            {
                quotient = -1;
                quotient_sub = (~quotient + 1);
                final_quotient_result[i] = quotient_sub;
                upper_bits_signed_number = (normalize_remainder >> INTEGER_SIZE) & 0xFF; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0x00FF;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << INTEGER_SIZE) | lower_bits_signed_number;
            }
            else if ((mag_MSB_Bit == 1 && mag_Fraction_Bit == 0) && (BFS_MSB_Bit == MSB_Bit_shifted_divisor))
            {
                quotient = 1;
                final_quotient[i] = quotient;
                upper_bits_signed_number = (normalize_remainder >> INTEGER_SIZE) & 0xFF; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0x00FF;
                addition_signed_number = upper_bits_signed_number + neg_divisor;
                normalize_remainder = (addition_signed_number << INTEGER_SIZE) | lower_bits_signed_number;
            }
            else if ((mag_MSB_Bit == 1 && mag_Fraction_Bit == 0) && (BFS_MSB_Bit != MSB_Bit_shifted_divisor))
            {
                quotient = -1;
                quotient_sub = (~quotient + 1);
                final_quotient_result[i] = quotient_sub;
                upper_bits_signed_number = (normalize_remainder >> INTEGER_SIZE) & 0xFF; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0x00FF;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << INTEGER_SIZE) | lower_bits_signed_number;
            }
        }
        else
        {
            if ( MSB_Bit == 0 && Fraction_Bit == 0)
            {
                quotient = 0;
                final_quotient[i] = quotient;
            }
            else if (( MSB_Bit == 0 && Fraction_Bit == 1 ) && (BFS_MSB_Bit == MSB_Bit_shifted_divisor))
            {
                quotient = 1;
                final_quotient[i] = quotient;
                upper_bits_signed_number = (normalize_remainder >> INTEGER_SIZE) & 0xFF; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0x00FF;
                addition_signed_number   = upper_bits_signed_number + neg_divisor;
                normalize_remainder = (addition_signed_number << INTEGER_SIZE) | lower_bits_signed_number;
            } 
            else if (( MSB_Bit == 0 && Fraction_Bit == 1 ) && (BFS_MSB_Bit != MSB_Bit_shifted_divisor))
            {
                quotient = -1;
                quotient_sub = (~quotient + 1);
                final_quotient_result[i] = quotient_sub;
                upper_bits_signed_number = (normalize_remainder >> INTEGER_SIZE) & 0xFF; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0x00FF;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << INTEGER_SIZE) | lower_bits_signed_number;
                
            }
        }
        Q_add = (Q_add << 1) | final_quotient[i];                 // Shift Q left by 1 and add the new bit from final_quotient
        Q_sub = (Q_sub << 1) | final_quotient_result[i];           // Shift Q left by 1 and add the new bit from final_quotient
        Q = Q_add - Q_sub;
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
    upper_bits_signed_number = (normalize_remainder >> INTEGER_SIZE) & 0xFF; // Extract upper bits
    sign_normalize_remainder = ((normalize_remainder >> (PR_SIZE-1)) & 1);
    if (upper_bits_signed_number != 0) {  // Only apply correction if remainder is non-zero
        if (sign_normalize_remainder != sign_divisor)
        {
            printf("Correction logic will be applied:\n ");
            if (originalDividend > 0 && originalDivisor > 0)
            {
                Q = Q - (0x01);
                upper_bits_signed_number = (normalize_remainder >> INTEGER_SIZE) & 0xFF; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0x00FF;
                addition_signed_number = upper_bits_signed_number + shifted_divisor;
                normalize_remainder = (addition_signed_number << INTEGER_SIZE) | lower_bits_signed_number;
            }
            else
            {
                Q = Q + (0x01);
                upper_bits_signed_number = (normalize_remainder >> INTEGER_SIZE) & 0xFF; // Extract upper bits
                lower_bits_signed_number = normalize_remainder & 0x00FF;
                addition_signed_number = upper_bits_signed_number + neg_divisor;
                normalize_remainder = (addition_signed_number << INTEGER_SIZE) | lower_bits_signed_number;
            }
        }
    }
    else
    {
        printf("No need of correcton:\n");
    }
    //===========================================================================================
    // ===================================== correction logic ===================================
    //===========================================================================================

    R = (normalize_remainder >> INTEGER_SIZE) & 0xFF; // Extract upper bits
    if (R & (1 << (INTEGER_SIZE - 1))) { // Check if MSB is 1
    R = R | (~((1 << INTEGER_SIZE) - 1)); // Sign extend to convert to negative
    }
    
    if ((originalDivisor > 0) && (leading_zeros > 0)) {
        R = R >> (leading_zeros - 1);
    } else if ((originalDivisor < 0) && (leading_ones > 0)) {
        R = R >> (leading_ones - 1);
    }
    printf("Final Quotient in decimal: %d\n", Q); // This will print Q as an integer value
    printf("\n");
    printf("Final Remainder in decimal: %d\n", R); // Print R as an integer
    if ((int)QUOTIENT == (int)Q && (int)REMAINDER == (int)R)
    {
        printf("Test is pass.\n");
    }
    else
    {
        printf("Failed Test\n");
    }
}
int main() {
    int dividend;
    int divisor;
    printf("Enter dividend: ");
    scanf("%d", &dividend);  // Use & to provide6 5xthe address
    printf("Enter divisor: ");
    scanf("%d", &divisor);   // Use & to provide the address
    SRTDIVISION(dividend, divisor);
    return 0;
}


