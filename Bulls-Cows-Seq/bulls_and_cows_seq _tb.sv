module bulls_and_cows_seq_tb;
  
  logic clk;
  logic rst;
  logic [3:0] number_in;
  logic [3:0] secret_number_0; 
  logic [3:0] secret_number_1;
  logic [3:0] secret_number_2;
  logic [3:0] secret_number_3;
  logic [2:0] bulls;
  logic [2:0] cows;
  logic valid;
  logic win;
  int count;//to be removed
  logic bull_true;//to be removed



  bulls_and_cows_seq bNCS (.clk(clk), .rst(rst), .number_in(number_in), .secret_number_0(secret_number_0), .secret_number_1(secret_number_1), .secret_number_2(secret_number_2), .secret_number_3(secret_number_3), .bulls(bulls), .cows(cows), .valid(valid), .win(win), .count(count), .bull_true(bull_true)); //to be removed
  
  

//setup the clock
  initial begin
    clk =0;
    forever #15 clk = ~clk;
  end

//test the circuit
  initial begin
    rst = 1;
    assign secret_number_0 = 0;
    assign secret_number_1 = 1;
    assign secret_number_2 = 2;
    assign secret_number_3 = 3;
   @(posedge clk);
   
      rst = 0;
    
    
    $monitor("cows = %d		bulls = %d	number in = %d bull true = %b", cows, bulls,number_in,bull_true);
    $monitor("win = %b  valid = %b", win, valid);
    
    
    $display("Beginning...");
   
    //0123
    assign number_in = 0;
    @(posedge clk);
    assign number_in = 1;
    @(posedge clk);
    assign number_in = 2;
    @(posedge clk);
    assign number_in = 3;
    @(posedge clk);
    
    //3210
    rst = 1;
    @(posedge clk);
    rst = 0;
    assign number_in = 3;
    @(posedge clk);
    assign number_in = 2;
    @(posedge clk);
    assign number_in = 1;
    @(posedge clk);
    assign number_in = 0;
    @(posedge clk);
    
     //7891
    rst = 1;
    @(posedge clk);
    rst = 0;
    assign number_in = 7;
    @(posedge clk);
    assign number_in = 8;
    @(posedge clk);
    assign number_in = 9;
    @(posedge clk);
    assign number_in = 1;
    @(posedge clk);
    
     //8120
    rst = 1;
    @(posedge clk);
    rst = 0;
    assign number_in = 8;
    @(posedge clk);
    assign number_in = 1;
    @(posedge clk);
    assign number_in = 2;
    @(posedge clk);
    assign number_in = 0;
    @(posedge clk);
    
    
    //to stop infinite loop
    $display("STOP READING");
    assign number_in = 9;
  
  
  
  
  end

endmodule