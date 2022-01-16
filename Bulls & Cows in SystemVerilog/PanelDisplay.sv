module PanelDisplay(
	input logic clk,
	input logic rst,
	input logic[3:0] secret_number_0,
    input logic[3:0] secret_number_1,
    input logic[3:0] secret_number_2,
    input logic[3:0] secret_number_3,
    input logic[3:0] guessed_number_0,
    input logic[3:0] guessed_number_1,
    input logic[3:0] guessed_number_2,
    input logic[3:0] guessed_number_3,
    input logic[2:0] bulls,
    input logic[2:0] cows,
	output logic hsync,
	output logic vsync,
	output logic [3:0] red,
	output logic [3:0] green,
	output logic [3:0] blue);

  



//personalization//=============================================================================//
int position_offset = 200;
int background_color [3] = {5,5,5};
int color [3] = {0,3,0};

//==============================================================================================//


								
int printedArray [12];








//
logic [7:0] address;
logic [15:0] data;

digit_rom digit(.address(address),
				.data(data));
				
//-------------------------------				
logic [9:0] hc = 0;
logic [9:0] vc = 0;
logic [1:0] enable = 0;




logic bull_cow_offset = 0;
logic bull_cow_space = 0;

int row = 0;
int line = 0;
int address_c [4] = {0,0,0,0};
int data_c [4] = {0,0,0,0};

task Write(input int i [12]);
	begin
				
		if (hc >= (position_offset + row*30 + bull_cow_space*15  )&& hc < position_offset + row*30 + bull_cow_space*15  + 16  && vc >= position_offset + bull_cow_offset*50 + line*60  && vc < position_offset + line*60 + bull_cow_offset*50 + 16 ) begin
			
			if (i[(row+(line*4))] > 0 && i[(row+(line*4))] < 10) begin
				address = (i[(row+(line*4))]-1)*16 + address_c[row];
			end else begin
				address = 9*16 + address_c[row];
			end
			
			
				
				
			red = (data[15 - data_c[row]])? color [0] : background_color[0];
			green = (data[15 - data_c[row]])? color[1] : background_color[1];
			blue = (data[15 - data_c[row]])? color[2] : background_color[2];
			
			

			//data goes to 0 and address++ after 16 ticks.  
			if (data_c[row] < 15) begin
				data_c[row]++;
			end else begin
				data_c[row] = 0;
				
				if(address_c[row] < 15) begin
					address_c[row]++;
				end else begin
					address_c[row] = 0;
				end	
			end
			
			
			
			if (data_c[row] == 0) begin
				if (row<3) begin
					row++;
				end else begin
					if (address_c[row] == 0) begin
						if (line<2) begin
							line++;
						end else begin
							line = 0;
						end
					end
					row = 0;
				end	
			end
			
			//seperate bulls and cows from other numbers.
			if(row+line*4 > 7 && row+line*4 < 12 ) begin
				bull_cow_offset = 1;
				
				if(row+line*4 > 9 && row+line*4 < 12 ) begin
					bull_cow_space = 1;
				end else begin
					bull_cow_space = 0;
				end
			end else begin
				bull_cow_offset = 0;
				

			end
			
			
			
			
				
		end else begin
		
			green = background_color[0];
			blue = background_color[1]; 
			red = background_color[2];
		end
		
		
		
		
		
	end
endtask



always_ff @(posedge clk) begin
	if (rst) begin
		enable <= 0;
		hc <= 0;
		vc <= 0;
		vsync<=0;
		hsync<=0;
	end else begin 
	//25 Hz
		if (enable) begin
			enable <= 0;
		end
		else begin
	
			enable ++;
			
			if(hc == 799)
			begin
				hc <= 0;
				if(vc == 523)
					vc <= 0;
				else 
				vc ++;
			end else
				hc ++;
				
				
				
			vsync = (vc <= 491 | vc > 493 )? 1 : 0;
			

			hsync = (hc <= 656 | hc > 752 )? 1 : 0;
			
		end
	end
end




always_comb begin
  if(rst) begin
	red = 0;
	green = 0;
	blue = 0;
  end
  if (enable & hc <= 640 & vc <= 480 )
  begin
  
  
	printedArray = {guessed_number_0,guessed_number_1,guessed_number_2,guessed_number_3,secret_number_0,secret_number_1,secret_number_2,secret_number_3,0,bulls,0,cows};
  
  
	Write(printedArray);
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
		
		
		
	
	end else begin
		green = 0;
		blue = 0; 
		red = 0;
	end

end
endmodule


