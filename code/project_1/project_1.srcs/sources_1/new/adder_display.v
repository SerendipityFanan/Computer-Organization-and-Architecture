  `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/03/14 13:04:11
// Design Name: 
// Module Name: adder_display
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


module adder_display(
    //时钟与复位信号
    input clk,
    input resetn,    //后缀"n"代表低电平有效

    //拨码开关，用于选择输入数和产生cin
     input input_sel,
       input input_sel_2,
       input sw_cin,
       input sw_cin_2,
       output led_cout,
       output led_cout_2,
    
       reg  [31:0] adder_operand1;
       reg  [31:0] adder_operand2;
       reg  [31:0] adder_operand3;
       reg  [31:0] adder_operand4;
       wire        adder_cin;
       wire        adder_cin_2;    
       wire [31:0] adder_result  ;
       wire        adder_cout;
           wire        adder_cout_2;
       adder adder_module(
           .operand1(adder_operand1),
           .operand2(adder_operand2),
           .operand3(adder_operand3),
           .operand4(adder_operand4),
           .cin     (adder_cin     ),
           .cin_2    (adder_cin_2     ),
           .result  (adder_result  ),
           .cout    (adder_cout    ),
           .cout_2    (adder_cout_2    )
       );
       assign adder_cin = sw_cin;
       assign adder_cin_2 = sw_cin_2;
       assign led_cout  = adder_cout;
           assign led_cout_2  = adder_cout_2;
     always @(posedge clk)
       begin
           if (!resetn)
           begin
               adder_operand1 <= 32'd0;
           end
           else if (input_valid && !input_sel && !input_sel_2)//1
           begin
               adder_operand1 <= input_value;
           end
       end
       
       //当input_sel为1,input_sel_2=0时，表示输入数为加数2，即operand2
       always @(posedge clk)
       begin
           if (!resetn)
           begin
               adder_operand2 <= 32'd0;
           end
           else if (input_valid && input_sel && !input_sel_2) //2
           begin
               adder_operand2 <= input_value;
           end
       end
       //当input_sel为0,input_sel_2=1时，表示输入数为加数3，即operand3
       always @(posedge clk)
       begin
           if (!resetn)
           begin
               adder_operand3 <= 32'd0;
           end
           else if (input_valid && !input_sel && input_sel_2) //3
           begin
               adder_operand3 <= input_value;
           end
       end
        //当input_sel为1,input_sel_2=1时，表示输入数为加数4，即operand4
       always @(posedge clk)
       begin
           if (!resetn)
           begin
               adder_operand4 <= 32'd0;
           end
           else if (input_valid && input_sel && input_sel_2) //4
           begin
               adder_operand4 <= input_value;
           end
       end
    
       always @(posedge clk)
       begin
           case(display_number)
               6'd1 :
               begin
                   display_valid <= 1'b1;
                   display_name  <= "ADD_1";
                   display_value <= adder_operand1;
               end
               6'd2 :
               begin
                   display_valid <= 1'b1;
                   display_name  <= "ADD_2";
                   display_value <= adder_operand2;
               end
               6'd3 :
               begin
                   display_valid <= 1'b1;
                   display_name  <= "ADD_3";
                   display_value <= adder_operand3;
               end
               6'd4 :
               begin
                   display_valid <= 1'b1;
                   display_name  <= "ADD_4";
                   display_value <= adder_operand4;
               end
               6'd5 :
               begin
                   display_valid <= 1'b1;
                   display_name  <= "RESUL";
                   display_value <= adder_result;
               end
               default :
               begin
                   display_valid <= 1'b0;
                   display_name  <= 40'd0;
                   display_value <= 32'd0;
               end
           endcase
   end

//-----{输出到触摸屏显示}end
//----------------------{调用触摸屏模块}end---------------------//
endmodule

