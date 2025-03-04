 `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/03/14 12:43:17
// Design Name: 
// Module Name: adder32
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module adder32(
   input  [31:0] operand1,
input  [31:0] operand2,
  input  [31:0] operand3,
  input  [31:0] operand4,
  input         cin,
  input         cin_2,
  output [31:0] result,
  output        cout,
  output        cout_2
    );
assign {cout,cout_2,result} = operand1 + operand2 + operand3 + operand4 + cin + cin_2;


endmodule
