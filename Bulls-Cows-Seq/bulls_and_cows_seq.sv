module bulls_and_cows_seq
(
    input logic clk,
	input logic rst,
 	input logic [3:0] number_in,
	input logic [3:0] secret_number_0,
	input logic [3:0] secret_number_1,
	input logic [3:0] secret_number_2,
	input logic [3:0] secret_number_3,
	output logic [2:0] bulls,
	output logic [2:0] cows,
	output logic valid,
	output logic win,
    output int count, //to be removed
  	output logic bull_true //to be removed
);
  //internal signals
  
   //int count;				to be uncommened
   //logic bull_true;		to be uncommened
  
  //counter
  always_ff @(posedge clk) begin
    if(rst||count == 3) begin
    	count <= 0;
    end else 
    	count <= count + 1;
	
  end
  
  //bull_logic  
  always_ff @(posedge clk) begin
    if(rst ) begin
      bulls <= 0;
    end else begin
      if (bull_true)
        bulls <= bulls + 1;
    end
  end 
  
  
  always_comb begin  
    case(count)
    	0: begin
          if (secret_number_0 == number_in) begin
        	//bulls <= bulls + 1;
        	bull_true = 1;
      	  end else
        	bull_true = 0;
          
         end
        1: begin
          if (secret_number_1 == number_in) begin
        	//bulls <= bulls + 1;
        	bull_true = 1;
      	  end else
        	bull_true = 0;
         end
      
        2: begin
          if (secret_number_2 == number_in) begin
        	//bulls <= bulls + 1;
        	bull_true = 1;
      	  end else
        	bull_true = 0;
         end
        3: begin
          if (secret_number_3 == number_in) begin
        	//bulls <= bulls + 1;
        	bull_true = 1;
      	  end else
        	bull_true = 0;
         end
       
     
    endcase
  end

    

  
  //cow logic
  always_ff @(posedge clk) begin
    if (rst)
      cows <= 0;
    else begin
      if (number_in == secret_number_0 || number_in == secret_number_1 || number_in == secret_number_2 || number_in == secret_number_3)
        if(~bull_true)
        	cows <= cows + 1;
         
    end  
  end
  
  
  //output_logic
  always @(posedge clk) begin
    if (count == 3)
      valid <=1;
    else
      valid <= 0; 
  end
  
    always_comb begin
    if (bulls == 4)
      win <= 1;
    else
      win <=0;
  end
  
    
endmodule