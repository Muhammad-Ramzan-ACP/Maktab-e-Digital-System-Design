#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


int  normalization (int8_t divisor);
void SRT(int8_t dividend,int8_t divisor);


int main(){

//
        //}
        SRT(3, 3);
    //}

    return 0;

}

// Function for counting bit for normalizing
int normalization(int8_t divisor) {
    int count = 0;
    if (divisor > 0) {
        
// For positive numbers, count leading zeros before the first '1'
        for (int i = 0; i < 8; i++) {
            if ((divisor & 0x80) == 0x80) {
                break;
            } else {
                count++;
                divisor <<= 1;
            }
        }
    } else {

// For negative numbers, count leading '1's before the first '0'
        for (int i = 0; i < 8; i++) {
            if ((divisor & 0x80) == 0) {
                break;
            } else {
                count++;
                divisor <<= 1;
            }
        }
    }
    return count-1;
}

// Function for SRT implementation
void SRT(int8_t dividend,int8_t divisor){

// Initialising the registers
    int8_t original_quot,original_remain;
    int step_normalize       = normalization(divisor);
    divisor                  = divisor << step_normalize;
    int8_t  Quotient         = 0;
    int8_t Remainder         = 0;
    int16_t temp_remainder   = 0;
    Remainder                = Remainder | dividend ; 
    int16_t Remainder_signext= (int16_t)Remainder;
    Remainder_signext        = Remainder_signext << step_normalize;
    int16_t Remainder_sign   = Remainder_signext;
    int8_t negative_divisor  = ~(divisor) + 1;
    int16_t divisor_add      = 0;
    int16_t divisor_subtract = 0;
    divisor_add              = (divisor_add | divisor ) << 8 ;
    divisor_subtract         = (divisor_subtract | negative_divisor) << 8 ;
    int16_t Quotient_add      = 0;
    int16_t Quotient_subtract = 0;
    __uint16_t divisor_msb   = divisor_add & 0x8000;
    __uint16_t remaind_msb;
    int16_t Remainder_mag    = 0;
    int16_t Quo_correc        = 0;
    

// Flag to check if we need to denormalize the remainder in the end or not
    int denormalize          = 0;
    if ( step_normalize == 0){
        denormalize = 0;
    } 
    else {
        denormalize = 1;

    }


// Srt Iterations
    for ( int iteration = 0; iteration < 8; iteration++ )
    {   
        remaind_msb     = Remainder_signext & 0x8000;
        temp_remainder  = Remainder_signext << 1;

// condition to check if shifted partial product is less than 1/2
        if ((temp_remainder & 0xC000) == 0x0000){
            Remainder_signext = Remainder_signext ;
            Quotient_add      = Quotient_add & 0xFE;
        }

// condition to check if shifted partial product is greater than 1/2
        else if ((temp_remainder & 0xC000) == 0x4000){
            if ( remaind_msb == divisor_msb){
                temp_remainder    = temp_remainder + divisor_subtract;
                Quotient_add      = Quotient_add | 0x01;
            }
            else{
                temp_remainder = temp_remainder + divisor_add;
                Quotient_subtract = Quotient_subtract | 0x01;
            }
        }

// condition when partial product is negative so we take the 2's compliment
        else if ((temp_remainder & 0x8000) == 0x8000){
            Remainder_mag  = (~temp_remainder) + 1;
            if ((Remainder_mag & 0xC000) == 0x0000){
                Remainder_signext = Remainder_signext;
                Quotient_add      = Quotient_add & 0xFE;
            }
            else if ((Remainder_mag & 0xC000) == 0x4000){
                if ( remaind_msb == divisor_msb){
                    temp_remainder    = temp_remainder + divisor_subtract;
                    Quotient_add      = Quotient_add | 0x01;
                }
                else{
                    temp_remainder = temp_remainder + divisor_add;
                    Quotient_subtract = Quotient_subtract | 0x01;
                }
            }
            else if ((Remainder_mag & 0xC000) == 0x8000){
                if ( remaind_msb == divisor_msb){
                    temp_remainder    = temp_remainder + divisor_subtract;
                    Quotient_add      = Quotient_add | 0x01;
                }
                else{
                    temp_remainder = temp_remainder + divisor_add;
                    Quotient_subtract = Quotient_subtract | 0x01;
                }

            }

        }
        Remainder_signext = temp_remainder;
        Quotient_add      = Quotient_add << 1;
        Quotient_subtract = Quotient_subtract << 1;
    }
    Quotient_add      = Quotient_add >> 1;
    Quotient_subtract = Quotient_subtract >> 1;
// Now logic for correction 
    if (((Remainder_sign & 0x8000 ) == (Remainder_signext & 0x8000))|| (Remainder_signext == 0)){
        Remainder_signext = Remainder_signext;
        Quo_correc        = 0;
    }
    else{
        if((dividend & 0x80) == (divisor & 0x80)){
            Quo_correc        = -1;
            Remainder_signext = Remainder_signext + divisor_add;
        }
        else{
            Quo_correc        = 1;
            Remainder_signext = Remainder_signext + divisor_subtract;

        }
    }
    

// Now logic for quotient calculation
Quotient = Quotient_add + ((~Quotient_subtract)+1) + Quo_correc;

//Now orginal remainder logic
if( denormalize){
        Remainder_signext    = Remainder_signext >> step_normalize;
    }
    else {
        Remainder_signext    = Remainder_signext;
    }
Remainder      = Remainder_signext >> 8 ;
divisor        = divisor >> step_normalize;
original_quot  = dividend / divisor;
original_remain= dividend % divisor;
if ((original_quot == Quotient) && ( original_remain == Remainder)){
    printf("pass\n");
}
else {
    printf("Dividend: %d, Divisor: %d => Quotient: %d, Remainder: %d\n", dividend, divisor, Quotient, Remainder);
}
}