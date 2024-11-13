// Name   : Muhammad Ramzan
// Date   : 06/11/2024
// Module : test bench module of srt radix 2 for integer division

module srt_radix_2_division_tb();

    //===========================================================================================
    // ================================ Signal Declarations =====================================
    //===========================================================================================
    logic CLK;                  // Clock signal
    logic RST;                  // Reset signal
    logic START;                // Start signal for initiating the division
    logic [15:0] DIVISOR;       // Divisor input
    logic [15:0] DIVIDEND;      // Dividend input
    logic READY;                // Ready signal indicating division completion
    logic [15:0] QUOTIENT;      // Resulting quotient
    logic [15:0] REMAINDER;     // Resulting remainder

    //===========================================================================================
    // ========================== Instantiate the Unit Under Test (UUT) =========================
    //===========================================================================================
    datapath uut (
        .CLK(CLK),
        .RST(RST),
        .START(START),
        .DIVISOR(DIVISOR),
        .DIVIDEND(DIVIDEND),
        .READY(READY),
        .QUOTIENT(QUOTIENT),
        .REMAINDER(REMAINDER)
    );

    //===========================================================================================
    // ================================ Clock Generation =========================================
    //===========================================================================================
    initial begin
        CLK = 1;
        forever #10 CLK = ~CLK;
    end

    //===========================================================================================
    // =============================== Reset Task Definition ====================================
    //===========================================================================================
    task reset_task();
        begin
            RST <= #1 0;
            #10; 
            RST <= #1 1;
            #10;
        end
    endtask

    //===========================================================================================
    // =============================== Input Driver Task ========================================
    //===========================================================================================
    // Drive input signals with specified dividend and divisor values
    // This task initiates the reset and starts the division operation
    //===========================================================================================
    task drive_input(input logic [15:0] dividend, input logic [15:0] divisor);
        begin
            reset_task();                     // Reset the UUT before each operation
            START       <= #1 0;              // Start the division
            @(posedge CLK);
            START       <= #1 1;              // Start the division
            DIVIDEND    <= #1 dividend;       // Set dividend
            DIVISOR     <= #1 divisor;        // Set divisor
            @(posedge CLK);
            START       <= #1 0;
        end
    endtask

    //===========================================================================================
    // =============================== Output Monitor Task ======================================
    //===========================================================================================
    // Monitor output signals and check results against expected values
    // Uses assertions to verify correctness of QUOTIENT and REMAINDER values
    //===========================================================================================
    task monitor_output();
        logic [15:0] expected_quotient;
        logic [15:0] expected_remainder;
        begin
            expected_quotient = dividend / divisor;    // Calculate expected quotient
            expected_remainder = dividend % divisor;   // Calculate expected remainder

            @(posedge READY);
            @(posedge CLK);

            // Assertions with descriptive error messages
            assert(QUOTIENT == expected_quotient)
                else $error("FAIL: Expected Quotient=%0d, Got Quotient=%0d (Dividend=%0d, Divisor=%0d)", 
                            expected_quotient, QUOTIENT, dividend, divisor);

            assert(REMAINDER == expected_remainder)
                else $error("FAIL: Expected Remainder=%0d, Got Remainder=%0d (Dividend=%0d, Divisor=%0d)", 
                            expected_remainder, REMAINDER, dividend, divisor);

            // Additional checks for mathematical correctness
            assert(QUOTIENT * divisor + REMAINDER == dividend)
                else $error("FAIL: Invariant Check Failed: Quotient * Divisor + Remainder != Dividend (Dividend=%0d, Divisor=%0d)", 
                            dividend, divisor);

            assert(REMAINDER >= 0 && REMAINDER < divisor)
                else $error("FAIL: Remainder Out of Bounds: Expected 0 <= Remainder < %0d, Got %0d (Dividend=%0d, Divisor=%0d)", 
                            divisor, REMAINDER, dividend, divisor);

            // Display success message if all assertions pass
            $display("PASS: Dividend=%0d, Divisor=%0d -> Quotient=%0d, Remainder=%0d", 
                     dividend, divisor, QUOTIENT, REMAINDER);
        end
    endtask

    //===========================================================================================
    // =============================== Edge Case Testing Task ===================================
    //===========================================================================================
    // Tests boundary conditions such as maximum values, edge values, zero divisor, etc.
    // These test cases check for edge conditions that could cause issues such as overflow, 
    // divide-by-zero, and similar edge scenarios.
    //===========================================================================================
    task edge_case_tests();
        begin
            // Test edge cases with various dividend/divisor combinations
            drive_input(16'd32767, 16'd1);   // Large positive dividend, divisor 1
            drive_input(16'd32767, 16'd-1);  // Large positive dividend, negative divisor
            drive_input(16'd5, 16'd50);      // Small dividend, large divisor
            drive_input(16'd0, 16'd100);     // Dividend is 0, divisor is non-zero
            drive_input(16'd10, 16'd0);      // Zero divisor (should handle division by zero)
            drive_input(16'd-50, 16'd-10);   // Negative dividend and divisor
            drive_input(16'd10, 16'd0);      // Another division by zero case
        end
    endtask

    //===========================================================================================
    // =============================== Directed Testing Task ====================================
    //===========================================================================================
    // Executes specific test cases with known results for thorough verification
    // These cases test typical use-cases with simple values and predictable results.
    //===========================================================================================
    task directed_tests();
        begin
            // Test cases with known expected outcomes
            drive_input(16'd9, 16'd4);       // Dividend 9, divisor 4
            drive_input(16'd-9, 16'd4);      // Negative dividend, positive divisor
            drive_input(16'd-9, 16'd-4);     // Negative dividend and divisor
            drive_input(16'd100, 16'd7);     // Dividend 100, divisor 7
            drive_input(16'd20, 16'd3);      // Dividend 20, divisor 3
            drive_input(16'd100, 16'd7);     // Another test with same inputs
        end
    endtask

    //===========================================================================================
    // ================================ Randomized Testing Task =================================
    //===========================================================================================
    // Generates random dividend and divisor values within the range to test various cases
    // This ensures that a variety of combinations are tested.
    //===========================================================================================
    task random_test_cases();
        int i;
        for (i = 0; i < 20; i++) begin
            logic [15:0] rand_dividend = $urandom_range(1, 65535);
            logic [15:0] rand_divisor = $urandom_range(1, 65535);
            drive_input(rand_dividend, rand_divisor);
        end
    endtask

    //===========================================================================================
    // ================================ Main Testbench Process ==================================
    //===========================================================================================
    // Executes all test tasks in parallel using fork-join block
    //===========================================================================================
    initial begin
        $display("Starting Testbench for Restoring Division Module...");

        fork
            begin
                directed_tests();        // Directed Test Cases
                edge_case_tests();       // Edge Case Tests
                random_test_cases();     // Random Test Cases
                monitor_output();        // Monitor and check output
            end
        join

        $display("All tests completed.");
        $finish;
    end
endmodule
