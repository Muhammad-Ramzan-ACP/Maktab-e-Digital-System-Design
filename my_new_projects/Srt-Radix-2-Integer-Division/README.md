# Integer Division by Radix-2

This project implements an **integer division algorithm** using the **radix-2 (binary) division** method. It divides two integers (a dividend and a divisor) using binary arithmetic operations such as shifting and subtraction. The algorithm mimics the way division is performed in binary systems and is optimized for both signed and unsigned integers.

## Key Features

- **Radix-2 Division**: Efficient integer division using binary arithmetic.
- **Signed and Unsigned Handling**: Supports both signed and unsigned integer division.
- **Hardware Optimization**: Designed for efficient hardware implementation, with careful handling of overflow and underflow conditions.

## Overview of the Algorithm

The Radix-2 division algorithm works by progressively shifting the dividend and divisor, adjusting the quotient and remainder at each step. The key operations are normalization, shifting, and sign-correction, which ensure that the division process proceeds efficiently.

### Pseudo-Code

For a detailed understanding of the algorithm, refer to the [helping document](docs/helping_documents/SRT_Division_Pseudocode.pdf), which includes the complete pseudo-code for the Radix-2 division process.

## Flowchart

The flowchart below illustrates the step-by-step process of signed division using **normalization**, **bit-shifting**, and **sign-correction** techniques.

<p align="center">
  <img src="docs/flowchart.png" alt="Signed Division Flowchart" />
</p>

### Example: Dividing `-8` by `-8`

Let's walk through the division of `-8` by `8` at the binary level using this algorithm.

#### Inputs:
- **Dividend (R)** = `-8` (in binary: `11000` for two's complement representation)
- **Divisor (D)** = `-8` (in binary: `11000` for two's complement representation)

| **Step**                  | **Partial Remainder**  | **Quotient Bits**     | **Comment/Action**                    |
|---------------------------|------------------------|-----------------------|---------------------------------------|
| **Normalization (R₀)**     | `1.11110000`           | `0000`                | Initial normalized dividend.          |
| **2R₀**                    | `1.11100000`           | `0000`                | Doubling `R₀`.                        |
| **|2R₀|**                  | `0.00100000`           | `000**0**`            | Taking absolute value of `2R₀` and less than 1/2, so `q = 0`. |
| **R₁**                     | `1.11100000`           | `000**0**`            | Subtracting divisor (adding `-D`).   |
| **2R₁**                    | `1.11000000`           | `000**0**`            | Doubling `R₁`.                        |
| **|2R₁|**                  | `0.01000000`           | `00**00**`            | Taking absolute value of `2R₁` and less than 1/2, so `q = 0`. |
| **R₂**                     | `1.11000000`           | `00**00**`            | Subtracting divisor (adding `-D`).   |
| **2R₂**                    | `1.10000000`           | `00**00**`            | Doubling `R₂`.                        |
| **|2R₂|**                  | `0.10000000`           | `0**001**`            | Two's complement applied, magnitude corrected, and greater than 1/2, same sign, so `q = 1`. |
| **R₃**                     | `1.10000000`           | `0**001**`            | Subtracting divisor (adding `-D`).   |
| **2R₃**                    | `1.00000000`           | `0**001**`            | Doubling `R₃`.                        |
| **|2R₃|**                  | `1.00000000`           | `001-1`               | Subtracting divisor, greater than 1/2, different sign, so `q = -1`. |
| **Final Correction Step**  | `0.00000000`           | `1`                   | **Correction step**: Adjust quotient to `1`, remainder becomes `0`. |

## System Design Overview

The system design consists of two main components:
1. **Control Unit**: Coordinates the entire division process, handling the logic for each step.
2. **Data Path**: Executes the division operations, including shifting and subtraction.

### Top Module Diagram

The **Top Module** integrates the Control Unit and Data Path, orchestrating the entire division process and managing the AXI interface signals.

<p align="center">
  <img src="docs/srt_top_module.png" alt="SRT Radix-2 Top Module" />
</p>

### Inputs and Outputs

#### Inputs:
- **Dividend**: The 32-bit input dividend value.
- **Divisor**: The 32-bit input divisor value.

#### Outputs:
- **Remainder**: The 32-bit remainder after division.
- **Quotient**: The 32-bit quotient resulting from the division.

## Pinout Diagram

This diagram illustrates how the **Control Unit** interacts with the **Data Path** and handles various status signals.

<p align="center">
  <img src="docs/pinout.png" alt="SRT Radix-2 Pinout" />
</p>

### Input Signals:
- **Dividend**: The 32-bit value to be divided.
- **Divisor**: The 32-bit value by which the dividend is divided.
- **Start**: A control signal (1 bit) to begin the division process.

### Output Signals:
- **Quotient**: The 32-bit quotient from the division operation.
- **Remainder**: The 32-bit remainder after the division.
- **Ready**: A control signal (1 bit) that indicates the division is complete and the result is ready.

### Control Signals from Controller to Data Path:
- **clear**: Clears or resets certain values in the data path.
- **sel_op**: Selects between different operations in the data path.
- **en_a, en_b, en_c**: Enable signals for various registers in the data path.
- **Q_corr**: Controls the quotient correction during division.
- **norm_sel**: Selects the normalization status.
- **pr_sel**: Manages the partial remainder selection.
- **q_sel_neg / q_sel_pos**: Selects between negative and positive quotient adjustments.

### Status Signals from Data Path to Controller:
- **before_shift**: Indicates the state before a shift operation.
- **shifted_msb**: Represents the most significant bit after a shift.
- **2’s_msb**: Shows the most significant bits in 2’s complement representation.
- **count_complete**: Indicates if the division count is complete.
- **norm_status**: Shows whether normalization is needed.
- **divisor_msb / Dividend_msb**: Represents the most significant bits of the divisor and dividend, respectively.

## Controller Diagram

The **Controller** diagram shows how the division process is coordinated and controlled step-by-step.

<p align="center">
  <img src="docs/state_diagram.png" alt="SRT Radix-2 Controller" />
</p>

## DataPath Diagram

The **Data Path** diagram illustrates how the division operations, such as shifting and subtraction, are executed.

<p align="center">
  <img src="docs/srt_datapath.png" alt="SRT Radix-2 DataPath" />
</p>

## Normalization Diagram

The **Normalization** process diagram explains the steps involved in normalizing the dividend before performing the division.

<p align="center">
  <img src="docs/normalization.png" alt="Normalization Step" />
</p>

## Running the Project

Follow the steps below to compile and run the project.

### 1. Clone the Repository

To get the complete code, clone the repository:

```bash
git clone https://github.com/codewithbisal/Integer-Division-Using-Radix-2.git
