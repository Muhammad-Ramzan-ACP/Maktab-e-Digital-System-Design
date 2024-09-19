module traffic_controller(
    input logic clk,
    input logic rst,
    output logic [2:0] light_M1,
    output logic [2:0] light_Mt,
    output logic [2:0] light_M2,
    output logic [2:0] light_S
);
    localparam S0 = 3'b000;
    localparam S1 = 3'b001;
    localparam S2 = 3'b010;
    localparam S3 = 3'b011;
    localparam S4 = 3'b100;
    localparam S5 = 3'b101;
    //define count for each state
    logic [3:0] count = 0;
    logic [2:0] n_state;
    logic [2:0] c_state;
    always_ff @(posedge clk or negedge rst) 
    begin
        if(!rst)
        begin
            c_state <= #1 S0;
        end
        else 
        begin
            c_state <= #1 n_state;
        end
    end
    always_ff @(posedge clk or negedge rst) 
    begin
        if(!rst)
        begin
            count <= #1 3'b0000;
        end
        else
        begin
            count <= #1 count + 1;
        end
    end
       
    //input logic
    always_comb 
    begin
        case(c_state)
            S0 : begin
                if(count < 7)
                begin
                    n_state = S1;
                end
                else
                begin
                    n_state = S0;
                end
            end
            S1 : begin
                if (count < 2)
                begin
                    n_state = S2;
                end
                else
                begin
                    n_state = S1;
                end
            end
            S2 : begin
                if (count < 5)
                begin
                    n_state = S3;
                end
                else
                begin
                    n_state = S2;
                end
            end
            S3 : begin
                if (count < 3)
                begin
                    n_state = S4;
                end
                else
                begin
                    n_state = S3;
                end
            end

            S4 : begin
                if (count < 2)
                begin
                    n_state = S5;
                end
                else
                begin
                    n_state = S4;
                end
            end
            S5 : begin
                if (count < 5)
                begin
                    n_state = S0;
                end
                else
                begin
                    n_state = S5;
                end
            end
        endcase
    end

//output logic

    always_comb 
    begin
        case(c_state)
            S0 : begin
                light_M1 = 3'b001;
                light_Mt = 3'b100;
                light_M2 = 3'b001;
                light_S  = 3'b100;
            end
            S1 : begin
                light_M1 = 3'b001;
                light_Mt = 3'b100;
                light_M2 = 3'b010;
                light_S  = 3'b100;
            end
            S2 : begin
                light_M1 = 3'b001;
                light_Mt = 3'b001;
                light_M2 = 3'b100;
                light_S  = 3'b100;
            end
            S3 : begin
                light_M1 = 3'b010;
                light_Mt = 3'b010;
                light_M2 = 3'b100;
                light_S  = 3'b100;
            end
            S4 : begin
                light_M1 = 3'b100;
                light_Mt = 3'b100;
                light_M2 = 3'b100;
                light_S  = 3'b001;
            end
            S5 : begin
                light_M1 = 3'b100;
                light_Mt = 3'b100;
                light_M2 = 3'b100;
                light_S  = 3'b010;
            end
        endcase
    end
endmodule


        
