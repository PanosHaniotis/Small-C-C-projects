module bulls_and_cows(input logic [3:0] secret_number_0,
                      input logic [3:0] secret_number_1,
                      input logic [3:0] secret_number_2,
                      input logic [3:0] secret_number_3,
                      input logic [3:0] guessed_number_0,
                      input logic [3:0] guessed_number_1,
                      input logic [3:0] guessed_number_2,
                      input logic [3:0] guessed_number_3,
                      output logic [2:0] bulls,
                      output logic [2:0] cows,
                      output logic win);
					  
					  
  
always_comb begin
	bulls=0;
	cows =0;
	//----------------------------------------------
	if (secret_number_0 == guessed_number_0)begin
		bulls+=1;
	end else begin  
		if (guessed_number_0 == secret_number_1 || guessed_number_0 == secret_number_2 || guessed_number_0 == secret_number_3)begin
			cows+=1;
		end
	end
	//----------------------------------------------
	if (secret_number_1 == guessed_number_1)begin
		bulls+=1;
	end else begin
		if (guessed_number_1 == secret_number_0 || guessed_number_1 == secret_number_2 || guessed_number_1 == secret_number_3)begin
			cows+=1;
		end
	end
	//----------------------------------------------
	if (secret_number_2 == guessed_number_2)begin
		bulls+=1;
	end else begin  
		if (guessed_number_2 == secret_number_0 || guessed_number_2 == secret_number_1 || guessed_number_2 == secret_number_3)begin
		cows+=1;
		end
	end  
	//----------------------------------------------
	if (secret_number_3 == guessed_number_3)begin
		bulls+=1;
	end else begin  
		if (guessed_number_3 == secret_number_0 || guessed_number_3 == secret_number_1 || guessed_number_3 == secret_number_2)begin
			cows+=1;
		end
	end
		
		

	if(bulls==4)begin
		win=1;
	end else begin
		win=0;
	end
end
endmodule