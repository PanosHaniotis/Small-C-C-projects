module top(
	input logic clk,
	input logic rst,
	input logic frame_written,
    output logic write_frame,
    output logic done,
	output logic hsync,
	output logic vsync,
	output logic [3:0] red,
	output logic [3:0] green,
	output logic [3:0] blue
	);
	
	logic [3:0] secret_number_0;
	logic [3:0] secret_number_1;
	logic [3:0] secret_number_2;
	logic [3:0] secret_number_3;
	logic [3:0] guessed_number_0;
	logic [3:0] guessed_number_1;
	logic [3:0] guessed_number_2;
	logic [3:0] guessed_number_3;
	logic [2:0]bulls;
	logic [2:0]cows;

			   
	bulls_and_cows bulls_and_cows_module(
				.secret_number_0(secret_number_0),
				.secret_number_1(secret_number_1),
				.secret_number_2(secret_number_2),
				.secret_number_3(secret_number_3),
				.guessed_number_0(guessed_number_0),
				.guessed_number_1(guessed_number_1),
				.guessed_number_2(guessed_number_2),
				.guessed_number_3(guessed_number_3),
				.bulls(bulls),
				.cows(cows),
				.win(win));

	PanelDisplay PanelDisplay_module(
				.clk(clk),	
                .rst(rst),
				.secret_number_0(secret_number_0),
				.secret_number_1(secret_number_1),
				.secret_number_2(secret_number_2),
				.secret_number_3(secret_number_3),
				.guessed_number_0(guessed_number_0),
				.guessed_number_1(guessed_number_1),
				.guessed_number_2(guessed_number_2),
				.guessed_number_3(guessed_number_3),
				.bulls(bulls),
				.cows(cows),
                .hsync(hsync), 
                .vsync(vsync), 
                .red(red), 
                .green(green), 
                .blue(blue));

	solver solver_module(
		.clk(clk),
		.rst(rst),
		.guessed_number_0(guessed_number_0),
		.guessed_number_1(guessed_number_1),
		.guessed_number_2(guessed_number_2),
		.guessed_number_3(guessed_number_3),
		.bulls(bulls),
		.frame_written(frame_written),
		.write_frame(write_frame),
		.done(done)
	);
	
	always_ff @(posedge clk) begin
		 if (rst) begin
			secret_number_0 <= 5;
			secret_number_1 <= 7;
			secret_number_2 <= 4;
			secret_number_3 <= 8;
		 end
	end
				
	
endmodule