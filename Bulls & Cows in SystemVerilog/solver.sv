module solver (
	input clk,
	input rst,
	output logic [3:0] guessed_number_0,
	output logic [3:0] guessed_number_1,
	output logic [3:0] guessed_number_2,
	output logic [3:0] guessed_number_3,
	input logic [2:0] bulls,
	input logic frame_written,
    output logic write_frame,
    output logic done
);

logic [1:0] index;
logic [3:0] state;

logic [2:0] old_bulls;



//tip: always_ff παραλληλα καθε μερος του κωδικα. αν θελω να διορθωθει τοτε fsm για σειριακά ή άλλη λογική στην solver.



int guessed_number [4];
 
always_ff @(posedge clk) begin
	if (rst) begin
			state <= 0;
			index <= 0;
			done <= 0;
			old_bulls <= 0;
			write_frame <= 0;
			guessed_number<={0,0,0,0};
			guessed_number_0 <= 0;
			guessed_number_1 <= 0;
			guessed_number_2 <= 0;
			guessed_number_3 <= 0;
	end else begin 
		
		
			if (~done) begin
				case(state)
					0:begin
						old_bulls<=bulls;
						guessed_number[index] <= guessed_number[index]+1;
						state <=1;
					end
					1:begin
						guessed_number_0 <= guessed_number[0];
						guessed_number_1 <= guessed_number[1];
						guessed_number_2 <= guessed_number[2];
						guessed_number_3 <= guessed_number[3];
						
					
						state <=5;
					end
					2:begin
						
							
							if(bulls>old_bulls) begin
								index <= index+1;
							end 
							if(bulls<old_bulls) begin
								guessed_number[index]<= guessed_number[index]-1;
								index <= index+1;
							end
							state<=3;
						
					end
					3:begin
						guessed_number_0<=guessed_number[0];
						guessed_number_1<=guessed_number[1];
						guessed_number_2<=guessed_number[2];
						guessed_number_3<=guessed_number[3];
						state <= 4;
					end
					4:begin
						if(bulls == 4) begin
							done <=1;
						end
						state<=0;
					end
					
					
					5:begin
						if(~frame_written) begin
							write_frame<=1;
						end else begin
							write_frame<=0;
							state <=6;
						end
					end
					6:begin
						
						state <=7;
					end
					7:begin
							
						state <=2;
					end
					
					default: state <= 0;
					
				endcase
			end
			
	
			
		



	
	end








end

















endmodule