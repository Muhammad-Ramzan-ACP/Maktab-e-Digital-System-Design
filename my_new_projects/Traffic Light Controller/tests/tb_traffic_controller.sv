module tb_traffic_controller();
    logic clk;
    logic rst;
    logic [2:0] light_M1;
    logic [2:0] light_Mt;
    logic [2:0] light_M2;
    logic [2:0] light_S;

    traffic_controller uut(
        .clk(clk),
        .rst(rst),
        .light_M1(light_M1),
        .light_Mt(light_Mt),
        .light_M2(light_M2),
        .light_S(light_S)
    );

    initial 
    begin
        clk = 1;
        forever #5 clk = ~clk;
    end
    initial begin
        rst <= #1 0;
        @(posedge clk);
        rst <= #1 1;
    end
endmodule


