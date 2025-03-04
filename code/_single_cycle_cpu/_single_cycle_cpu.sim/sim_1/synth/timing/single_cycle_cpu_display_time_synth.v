// Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2017.1 (win64) Build 1846317 Fri Apr 14 18:55:03 MDT 2017
// Date        : Fri Jun 14 13:42:46 2024
// Host        : DESKTOP-V11BSCF running 64-bit major release  (build 9200)
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               D:/Vivado/code/_single_cycle_cpu/_single_cycle_cpu.sim/sim_1/synth/timing/single_cycle_cpu_display_time_synth.v
// Design      : adder
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xc7a200tfbg676-2
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

(* NotValidForBitStream *)
module adder
   (operand1,
    operand2,
    cin,
    result,
    cout);
  input [31:0]operand1;
  input [31:0]operand2;
  input cin;
  output [31:0]result;
  output cout;

  wire cin;
  wire cin_IBUF;
  wire cout;
  wire cout_OBUF;
  wire [31:0]operand1;
  wire [31:0]operand1_IBUF;
  wire [31:0]operand2;
  wire [31:0]operand2_IBUF;
  wire [31:0]result;
  wire [31:0]result_OBUF;
  wire \result_OBUF[11]_inst_i_1_n_0 ;
  wire \result_OBUF[11]_inst_i_1_n_1 ;
  wire \result_OBUF[11]_inst_i_1_n_2 ;
  wire \result_OBUF[11]_inst_i_1_n_3 ;
  wire \result_OBUF[11]_inst_i_2_n_0 ;
  wire \result_OBUF[11]_inst_i_3_n_0 ;
  wire \result_OBUF[11]_inst_i_4_n_0 ;
  wire \result_OBUF[11]_inst_i_5_n_0 ;
  wire \result_OBUF[15]_inst_i_1_n_0 ;
  wire \result_OBUF[15]_inst_i_1_n_1 ;
  wire \result_OBUF[15]_inst_i_1_n_2 ;
  wire \result_OBUF[15]_inst_i_1_n_3 ;
  wire \result_OBUF[15]_inst_i_2_n_0 ;
  wire \result_OBUF[15]_inst_i_3_n_0 ;
  wire \result_OBUF[15]_inst_i_4_n_0 ;
  wire \result_OBUF[15]_inst_i_5_n_0 ;
  wire \result_OBUF[19]_inst_i_1_n_0 ;
  wire \result_OBUF[19]_inst_i_1_n_1 ;
  wire \result_OBUF[19]_inst_i_1_n_2 ;
  wire \result_OBUF[19]_inst_i_1_n_3 ;
  wire \result_OBUF[19]_inst_i_2_n_0 ;
  wire \result_OBUF[19]_inst_i_3_n_0 ;
  wire \result_OBUF[19]_inst_i_4_n_0 ;
  wire \result_OBUF[19]_inst_i_5_n_0 ;
  wire \result_OBUF[23]_inst_i_1_n_0 ;
  wire \result_OBUF[23]_inst_i_1_n_1 ;
  wire \result_OBUF[23]_inst_i_1_n_2 ;
  wire \result_OBUF[23]_inst_i_1_n_3 ;
  wire \result_OBUF[23]_inst_i_2_n_0 ;
  wire \result_OBUF[23]_inst_i_3_n_0 ;
  wire \result_OBUF[23]_inst_i_4_n_0 ;
  wire \result_OBUF[23]_inst_i_5_n_0 ;
  wire \result_OBUF[27]_inst_i_1_n_0 ;
  wire \result_OBUF[27]_inst_i_1_n_1 ;
  wire \result_OBUF[27]_inst_i_1_n_2 ;
  wire \result_OBUF[27]_inst_i_1_n_3 ;
  wire \result_OBUF[27]_inst_i_2_n_0 ;
  wire \result_OBUF[27]_inst_i_3_n_0 ;
  wire \result_OBUF[27]_inst_i_4_n_0 ;
  wire \result_OBUF[27]_inst_i_5_n_0 ;
  wire \result_OBUF[31]_inst_i_1_n_0 ;
  wire \result_OBUF[31]_inst_i_1_n_1 ;
  wire \result_OBUF[31]_inst_i_1_n_2 ;
  wire \result_OBUF[31]_inst_i_1_n_3 ;
  wire \result_OBUF[31]_inst_i_2_n_0 ;
  wire \result_OBUF[31]_inst_i_3_n_0 ;
  wire \result_OBUF[31]_inst_i_4_n_0 ;
  wire \result_OBUF[31]_inst_i_5_n_0 ;
  wire \result_OBUF[3]_inst_i_1_n_0 ;
  wire \result_OBUF[3]_inst_i_1_n_1 ;
  wire \result_OBUF[3]_inst_i_1_n_2 ;
  wire \result_OBUF[3]_inst_i_1_n_3 ;
  wire \result_OBUF[3]_inst_i_2_n_0 ;
  wire \result_OBUF[3]_inst_i_3_n_0 ;
  wire \result_OBUF[3]_inst_i_4_n_0 ;
  wire \result_OBUF[3]_inst_i_5_n_0 ;
  wire \result_OBUF[7]_inst_i_1_n_0 ;
  wire \result_OBUF[7]_inst_i_1_n_1 ;
  wire \result_OBUF[7]_inst_i_1_n_2 ;
  wire \result_OBUF[7]_inst_i_1_n_3 ;
  wire \result_OBUF[7]_inst_i_2_n_0 ;
  wire \result_OBUF[7]_inst_i_3_n_0 ;
  wire \result_OBUF[7]_inst_i_4_n_0 ;
  wire \result_OBUF[7]_inst_i_5_n_0 ;
  wire [3:1]NLW_cout_OBUF_inst_i_1_CO_UNCONNECTED;
  wire [3:0]NLW_cout_OBUF_inst_i_1_O_UNCONNECTED;

initial begin
 $sdf_annotate("single_cycle_cpu_display_time_synth.sdf",,,,"tool_control");
end
  IBUF cin_IBUF_inst
       (.I(cin),
        .O(cin_IBUF));
  OBUF cout_OBUF_inst
       (.I(cout_OBUF),
        .O(cout));
  CARRY4 cout_OBUF_inst_i_1
       (.CI(\result_OBUF[31]_inst_i_1_n_0 ),
        .CO({NLW_cout_OBUF_inst_i_1_CO_UNCONNECTED[3:1],cout_OBUF}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(NLW_cout_OBUF_inst_i_1_O_UNCONNECTED[3:0]),
        .S({1'b0,1'b0,1'b0,1'b1}));
  IBUF \operand1_IBUF[0]_inst 
       (.I(operand1[0]),
        .O(operand1_IBUF[0]));
  IBUF \operand1_IBUF[10]_inst 
       (.I(operand1[10]),
        .O(operand1_IBUF[10]));
  IBUF \operand1_IBUF[11]_inst 
       (.I(operand1[11]),
        .O(operand1_IBUF[11]));
  IBUF \operand1_IBUF[12]_inst 
       (.I(operand1[12]),
        .O(operand1_IBUF[12]));
  IBUF \operand1_IBUF[13]_inst 
       (.I(operand1[13]),
        .O(operand1_IBUF[13]));
  IBUF \operand1_IBUF[14]_inst 
       (.I(operand1[14]),
        .O(operand1_IBUF[14]));
  IBUF \operand1_IBUF[15]_inst 
       (.I(operand1[15]),
        .O(operand1_IBUF[15]));
  IBUF \operand1_IBUF[16]_inst 
       (.I(operand1[16]),
        .O(operand1_IBUF[16]));
  IBUF \operand1_IBUF[17]_inst 
       (.I(operand1[17]),
        .O(operand1_IBUF[17]));
  IBUF \operand1_IBUF[18]_inst 
       (.I(operand1[18]),
        .O(operand1_IBUF[18]));
  IBUF \operand1_IBUF[19]_inst 
       (.I(operand1[19]),
        .O(operand1_IBUF[19]));
  IBUF \operand1_IBUF[1]_inst 
       (.I(operand1[1]),
        .O(operand1_IBUF[1]));
  IBUF \operand1_IBUF[20]_inst 
       (.I(operand1[20]),
        .O(operand1_IBUF[20]));
  IBUF \operand1_IBUF[21]_inst 
       (.I(operand1[21]),
        .O(operand1_IBUF[21]));
  IBUF \operand1_IBUF[22]_inst 
       (.I(operand1[22]),
        .O(operand1_IBUF[22]));
  IBUF \operand1_IBUF[23]_inst 
       (.I(operand1[23]),
        .O(operand1_IBUF[23]));
  IBUF \operand1_IBUF[24]_inst 
       (.I(operand1[24]),
        .O(operand1_IBUF[24]));
  IBUF \operand1_IBUF[25]_inst 
       (.I(operand1[25]),
        .O(operand1_IBUF[25]));
  IBUF \operand1_IBUF[26]_inst 
       (.I(operand1[26]),
        .O(operand1_IBUF[26]));
  IBUF \operand1_IBUF[27]_inst 
       (.I(operand1[27]),
        .O(operand1_IBUF[27]));
  IBUF \operand1_IBUF[28]_inst 
       (.I(operand1[28]),
        .O(operand1_IBUF[28]));
  IBUF \operand1_IBUF[29]_inst 
       (.I(operand1[29]),
        .O(operand1_IBUF[29]));
  IBUF \operand1_IBUF[2]_inst 
       (.I(operand1[2]),
        .O(operand1_IBUF[2]));
  IBUF \operand1_IBUF[30]_inst 
       (.I(operand1[30]),
        .O(operand1_IBUF[30]));
  IBUF \operand1_IBUF[31]_inst 
       (.I(operand1[31]),
        .O(operand1_IBUF[31]));
  IBUF \operand1_IBUF[3]_inst 
       (.I(operand1[3]),
        .O(operand1_IBUF[3]));
  IBUF \operand1_IBUF[4]_inst 
       (.I(operand1[4]),
        .O(operand1_IBUF[4]));
  IBUF \operand1_IBUF[5]_inst 
       (.I(operand1[5]),
        .O(operand1_IBUF[5]));
  IBUF \operand1_IBUF[6]_inst 
       (.I(operand1[6]),
        .O(operand1_IBUF[6]));
  IBUF \operand1_IBUF[7]_inst 
       (.I(operand1[7]),
        .O(operand1_IBUF[7]));
  IBUF \operand1_IBUF[8]_inst 
       (.I(operand1[8]),
        .O(operand1_IBUF[8]));
  IBUF \operand1_IBUF[9]_inst 
       (.I(operand1[9]),
        .O(operand1_IBUF[9]));
  IBUF \operand2_IBUF[0]_inst 
       (.I(operand2[0]),
        .O(operand2_IBUF[0]));
  IBUF \operand2_IBUF[10]_inst 
       (.I(operand2[10]),
        .O(operand2_IBUF[10]));
  IBUF \operand2_IBUF[11]_inst 
       (.I(operand2[11]),
        .O(operand2_IBUF[11]));
  IBUF \operand2_IBUF[12]_inst 
       (.I(operand2[12]),
        .O(operand2_IBUF[12]));
  IBUF \operand2_IBUF[13]_inst 
       (.I(operand2[13]),
        .O(operand2_IBUF[13]));
  IBUF \operand2_IBUF[14]_inst 
       (.I(operand2[14]),
        .O(operand2_IBUF[14]));
  IBUF \operand2_IBUF[15]_inst 
       (.I(operand2[15]),
        .O(operand2_IBUF[15]));
  IBUF \operand2_IBUF[16]_inst 
       (.I(operand2[16]),
        .O(operand2_IBUF[16]));
  IBUF \operand2_IBUF[17]_inst 
       (.I(operand2[17]),
        .O(operand2_IBUF[17]));
  IBUF \operand2_IBUF[18]_inst 
       (.I(operand2[18]),
        .O(operand2_IBUF[18]));
  IBUF \operand2_IBUF[19]_inst 
       (.I(operand2[19]),
        .O(operand2_IBUF[19]));
  IBUF \operand2_IBUF[1]_inst 
       (.I(operand2[1]),
        .O(operand2_IBUF[1]));
  IBUF \operand2_IBUF[20]_inst 
       (.I(operand2[20]),
        .O(operand2_IBUF[20]));
  IBUF \operand2_IBUF[21]_inst 
       (.I(operand2[21]),
        .O(operand2_IBUF[21]));
  IBUF \operand2_IBUF[22]_inst 
       (.I(operand2[22]),
        .O(operand2_IBUF[22]));
  IBUF \operand2_IBUF[23]_inst 
       (.I(operand2[23]),
        .O(operand2_IBUF[23]));
  IBUF \operand2_IBUF[24]_inst 
       (.I(operand2[24]),
        .O(operand2_IBUF[24]));
  IBUF \operand2_IBUF[25]_inst 
       (.I(operand2[25]),
        .O(operand2_IBUF[25]));
  IBUF \operand2_IBUF[26]_inst 
       (.I(operand2[26]),
        .O(operand2_IBUF[26]));
  IBUF \operand2_IBUF[27]_inst 
       (.I(operand2[27]),
        .O(operand2_IBUF[27]));
  IBUF \operand2_IBUF[28]_inst 
       (.I(operand2[28]),
        .O(operand2_IBUF[28]));
  IBUF \operand2_IBUF[29]_inst 
       (.I(operand2[29]),
        .O(operand2_IBUF[29]));
  IBUF \operand2_IBUF[2]_inst 
       (.I(operand2[2]),
        .O(operand2_IBUF[2]));
  IBUF \operand2_IBUF[30]_inst 
       (.I(operand2[30]),
        .O(operand2_IBUF[30]));
  IBUF \operand2_IBUF[31]_inst 
       (.I(operand2[31]),
        .O(operand2_IBUF[31]));
  IBUF \operand2_IBUF[3]_inst 
       (.I(operand2[3]),
        .O(operand2_IBUF[3]));
  IBUF \operand2_IBUF[4]_inst 
       (.I(operand2[4]),
        .O(operand2_IBUF[4]));
  IBUF \operand2_IBUF[5]_inst 
       (.I(operand2[5]),
        .O(operand2_IBUF[5]));
  IBUF \operand2_IBUF[6]_inst 
       (.I(operand2[6]),
        .O(operand2_IBUF[6]));
  IBUF \operand2_IBUF[7]_inst 
       (.I(operand2[7]),
        .O(operand2_IBUF[7]));
  IBUF \operand2_IBUF[8]_inst 
       (.I(operand2[8]),
        .O(operand2_IBUF[8]));
  IBUF \operand2_IBUF[9]_inst 
       (.I(operand2[9]),
        .O(operand2_IBUF[9]));
  OBUF \result_OBUF[0]_inst 
       (.I(result_OBUF[0]),
        .O(result[0]));
  OBUF \result_OBUF[10]_inst 
       (.I(result_OBUF[10]),
        .O(result[10]));
  OBUF \result_OBUF[11]_inst 
       (.I(result_OBUF[11]),
        .O(result[11]));
  CARRY4 \result_OBUF[11]_inst_i_1 
       (.CI(\result_OBUF[7]_inst_i_1_n_0 ),
        .CO({\result_OBUF[11]_inst_i_1_n_0 ,\result_OBUF[11]_inst_i_1_n_1 ,\result_OBUF[11]_inst_i_1_n_2 ,\result_OBUF[11]_inst_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI(operand1_IBUF[11:8]),
        .O(result_OBUF[11:8]),
        .S({\result_OBUF[11]_inst_i_2_n_0 ,\result_OBUF[11]_inst_i_3_n_0 ,\result_OBUF[11]_inst_i_4_n_0 ,\result_OBUF[11]_inst_i_5_n_0 }));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[11]_inst_i_2 
       (.I0(operand1_IBUF[11]),
        .I1(operand2_IBUF[11]),
        .O(\result_OBUF[11]_inst_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[11]_inst_i_3 
       (.I0(operand1_IBUF[10]),
        .I1(operand2_IBUF[10]),
        .O(\result_OBUF[11]_inst_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[11]_inst_i_4 
       (.I0(operand1_IBUF[9]),
        .I1(operand2_IBUF[9]),
        .O(\result_OBUF[11]_inst_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[11]_inst_i_5 
       (.I0(operand1_IBUF[8]),
        .I1(operand2_IBUF[8]),
        .O(\result_OBUF[11]_inst_i_5_n_0 ));
  OBUF \result_OBUF[12]_inst 
       (.I(result_OBUF[12]),
        .O(result[12]));
  OBUF \result_OBUF[13]_inst 
       (.I(result_OBUF[13]),
        .O(result[13]));
  OBUF \result_OBUF[14]_inst 
       (.I(result_OBUF[14]),
        .O(result[14]));
  OBUF \result_OBUF[15]_inst 
       (.I(result_OBUF[15]),
        .O(result[15]));
  CARRY4 \result_OBUF[15]_inst_i_1 
       (.CI(\result_OBUF[11]_inst_i_1_n_0 ),
        .CO({\result_OBUF[15]_inst_i_1_n_0 ,\result_OBUF[15]_inst_i_1_n_1 ,\result_OBUF[15]_inst_i_1_n_2 ,\result_OBUF[15]_inst_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI(operand1_IBUF[15:12]),
        .O(result_OBUF[15:12]),
        .S({\result_OBUF[15]_inst_i_2_n_0 ,\result_OBUF[15]_inst_i_3_n_0 ,\result_OBUF[15]_inst_i_4_n_0 ,\result_OBUF[15]_inst_i_5_n_0 }));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[15]_inst_i_2 
       (.I0(operand1_IBUF[15]),
        .I1(operand2_IBUF[15]),
        .O(\result_OBUF[15]_inst_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[15]_inst_i_3 
       (.I0(operand1_IBUF[14]),
        .I1(operand2_IBUF[14]),
        .O(\result_OBUF[15]_inst_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[15]_inst_i_4 
       (.I0(operand1_IBUF[13]),
        .I1(operand2_IBUF[13]),
        .O(\result_OBUF[15]_inst_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[15]_inst_i_5 
       (.I0(operand1_IBUF[12]),
        .I1(operand2_IBUF[12]),
        .O(\result_OBUF[15]_inst_i_5_n_0 ));
  OBUF \result_OBUF[16]_inst 
       (.I(result_OBUF[16]),
        .O(result[16]));
  OBUF \result_OBUF[17]_inst 
       (.I(result_OBUF[17]),
        .O(result[17]));
  OBUF \result_OBUF[18]_inst 
       (.I(result_OBUF[18]),
        .O(result[18]));
  OBUF \result_OBUF[19]_inst 
       (.I(result_OBUF[19]),
        .O(result[19]));
  CARRY4 \result_OBUF[19]_inst_i_1 
       (.CI(\result_OBUF[15]_inst_i_1_n_0 ),
        .CO({\result_OBUF[19]_inst_i_1_n_0 ,\result_OBUF[19]_inst_i_1_n_1 ,\result_OBUF[19]_inst_i_1_n_2 ,\result_OBUF[19]_inst_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI(operand1_IBUF[19:16]),
        .O(result_OBUF[19:16]),
        .S({\result_OBUF[19]_inst_i_2_n_0 ,\result_OBUF[19]_inst_i_3_n_0 ,\result_OBUF[19]_inst_i_4_n_0 ,\result_OBUF[19]_inst_i_5_n_0 }));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[19]_inst_i_2 
       (.I0(operand1_IBUF[19]),
        .I1(operand2_IBUF[19]),
        .O(\result_OBUF[19]_inst_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[19]_inst_i_3 
       (.I0(operand1_IBUF[18]),
        .I1(operand2_IBUF[18]),
        .O(\result_OBUF[19]_inst_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[19]_inst_i_4 
       (.I0(operand1_IBUF[17]),
        .I1(operand2_IBUF[17]),
        .O(\result_OBUF[19]_inst_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[19]_inst_i_5 
       (.I0(operand1_IBUF[16]),
        .I1(operand2_IBUF[16]),
        .O(\result_OBUF[19]_inst_i_5_n_0 ));
  OBUF \result_OBUF[1]_inst 
       (.I(result_OBUF[1]),
        .O(result[1]));
  OBUF \result_OBUF[20]_inst 
       (.I(result_OBUF[20]),
        .O(result[20]));
  OBUF \result_OBUF[21]_inst 
       (.I(result_OBUF[21]),
        .O(result[21]));
  OBUF \result_OBUF[22]_inst 
       (.I(result_OBUF[22]),
        .O(result[22]));
  OBUF \result_OBUF[23]_inst 
       (.I(result_OBUF[23]),
        .O(result[23]));
  CARRY4 \result_OBUF[23]_inst_i_1 
       (.CI(\result_OBUF[19]_inst_i_1_n_0 ),
        .CO({\result_OBUF[23]_inst_i_1_n_0 ,\result_OBUF[23]_inst_i_1_n_1 ,\result_OBUF[23]_inst_i_1_n_2 ,\result_OBUF[23]_inst_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI(operand1_IBUF[23:20]),
        .O(result_OBUF[23:20]),
        .S({\result_OBUF[23]_inst_i_2_n_0 ,\result_OBUF[23]_inst_i_3_n_0 ,\result_OBUF[23]_inst_i_4_n_0 ,\result_OBUF[23]_inst_i_5_n_0 }));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[23]_inst_i_2 
       (.I0(operand1_IBUF[23]),
        .I1(operand2_IBUF[23]),
        .O(\result_OBUF[23]_inst_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[23]_inst_i_3 
       (.I0(operand1_IBUF[22]),
        .I1(operand2_IBUF[22]),
        .O(\result_OBUF[23]_inst_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[23]_inst_i_4 
       (.I0(operand1_IBUF[21]),
        .I1(operand2_IBUF[21]),
        .O(\result_OBUF[23]_inst_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[23]_inst_i_5 
       (.I0(operand1_IBUF[20]),
        .I1(operand2_IBUF[20]),
        .O(\result_OBUF[23]_inst_i_5_n_0 ));
  OBUF \result_OBUF[24]_inst 
       (.I(result_OBUF[24]),
        .O(result[24]));
  OBUF \result_OBUF[25]_inst 
       (.I(result_OBUF[25]),
        .O(result[25]));
  OBUF \result_OBUF[26]_inst 
       (.I(result_OBUF[26]),
        .O(result[26]));
  OBUF \result_OBUF[27]_inst 
       (.I(result_OBUF[27]),
        .O(result[27]));
  CARRY4 \result_OBUF[27]_inst_i_1 
       (.CI(\result_OBUF[23]_inst_i_1_n_0 ),
        .CO({\result_OBUF[27]_inst_i_1_n_0 ,\result_OBUF[27]_inst_i_1_n_1 ,\result_OBUF[27]_inst_i_1_n_2 ,\result_OBUF[27]_inst_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI(operand1_IBUF[27:24]),
        .O(result_OBUF[27:24]),
        .S({\result_OBUF[27]_inst_i_2_n_0 ,\result_OBUF[27]_inst_i_3_n_0 ,\result_OBUF[27]_inst_i_4_n_0 ,\result_OBUF[27]_inst_i_5_n_0 }));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[27]_inst_i_2 
       (.I0(operand1_IBUF[27]),
        .I1(operand2_IBUF[27]),
        .O(\result_OBUF[27]_inst_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[27]_inst_i_3 
       (.I0(operand1_IBUF[26]),
        .I1(operand2_IBUF[26]),
        .O(\result_OBUF[27]_inst_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[27]_inst_i_4 
       (.I0(operand1_IBUF[25]),
        .I1(operand2_IBUF[25]),
        .O(\result_OBUF[27]_inst_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[27]_inst_i_5 
       (.I0(operand1_IBUF[24]),
        .I1(operand2_IBUF[24]),
        .O(\result_OBUF[27]_inst_i_5_n_0 ));
  OBUF \result_OBUF[28]_inst 
       (.I(result_OBUF[28]),
        .O(result[28]));
  OBUF \result_OBUF[29]_inst 
       (.I(result_OBUF[29]),
        .O(result[29]));
  OBUF \result_OBUF[2]_inst 
       (.I(result_OBUF[2]),
        .O(result[2]));
  OBUF \result_OBUF[30]_inst 
       (.I(result_OBUF[30]),
        .O(result[30]));
  OBUF \result_OBUF[31]_inst 
       (.I(result_OBUF[31]),
        .O(result[31]));
  CARRY4 \result_OBUF[31]_inst_i_1 
       (.CI(\result_OBUF[27]_inst_i_1_n_0 ),
        .CO({\result_OBUF[31]_inst_i_1_n_0 ,\result_OBUF[31]_inst_i_1_n_1 ,\result_OBUF[31]_inst_i_1_n_2 ,\result_OBUF[31]_inst_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI(operand1_IBUF[31:28]),
        .O(result_OBUF[31:28]),
        .S({\result_OBUF[31]_inst_i_2_n_0 ,\result_OBUF[31]_inst_i_3_n_0 ,\result_OBUF[31]_inst_i_4_n_0 ,\result_OBUF[31]_inst_i_5_n_0 }));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[31]_inst_i_2 
       (.I0(operand1_IBUF[31]),
        .I1(operand2_IBUF[31]),
        .O(\result_OBUF[31]_inst_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[31]_inst_i_3 
       (.I0(operand1_IBUF[30]),
        .I1(operand2_IBUF[30]),
        .O(\result_OBUF[31]_inst_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[31]_inst_i_4 
       (.I0(operand1_IBUF[29]),
        .I1(operand2_IBUF[29]),
        .O(\result_OBUF[31]_inst_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[31]_inst_i_5 
       (.I0(operand1_IBUF[28]),
        .I1(operand2_IBUF[28]),
        .O(\result_OBUF[31]_inst_i_5_n_0 ));
  OBUF \result_OBUF[3]_inst 
       (.I(result_OBUF[3]),
        .O(result[3]));
  CARRY4 \result_OBUF[3]_inst_i_1 
       (.CI(1'b0),
        .CO({\result_OBUF[3]_inst_i_1_n_0 ,\result_OBUF[3]_inst_i_1_n_1 ,\result_OBUF[3]_inst_i_1_n_2 ,\result_OBUF[3]_inst_i_1_n_3 }),
        .CYINIT(operand2_IBUF[0]),
        .DI(operand1_IBUF[3:0]),
        .O(result_OBUF[3:0]),
        .S({\result_OBUF[3]_inst_i_2_n_0 ,\result_OBUF[3]_inst_i_3_n_0 ,\result_OBUF[3]_inst_i_4_n_0 ,\result_OBUF[3]_inst_i_5_n_0 }));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[3]_inst_i_2 
       (.I0(operand1_IBUF[3]),
        .I1(operand2_IBUF[3]),
        .O(\result_OBUF[3]_inst_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[3]_inst_i_3 
       (.I0(operand1_IBUF[2]),
        .I1(operand2_IBUF[2]),
        .O(\result_OBUF[3]_inst_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[3]_inst_i_4 
       (.I0(operand1_IBUF[1]),
        .I1(operand2_IBUF[1]),
        .O(\result_OBUF[3]_inst_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[3]_inst_i_5 
       (.I0(operand1_IBUF[0]),
        .I1(cin_IBUF),
        .O(\result_OBUF[3]_inst_i_5_n_0 ));
  OBUF \result_OBUF[4]_inst 
       (.I(result_OBUF[4]),
        .O(result[4]));
  OBUF \result_OBUF[5]_inst 
       (.I(result_OBUF[5]),
        .O(result[5]));
  OBUF \result_OBUF[6]_inst 
       (.I(result_OBUF[6]),
        .O(result[6]));
  OBUF \result_OBUF[7]_inst 
       (.I(result_OBUF[7]),
        .O(result[7]));
  CARRY4 \result_OBUF[7]_inst_i_1 
       (.CI(\result_OBUF[3]_inst_i_1_n_0 ),
        .CO({\result_OBUF[7]_inst_i_1_n_0 ,\result_OBUF[7]_inst_i_1_n_1 ,\result_OBUF[7]_inst_i_1_n_2 ,\result_OBUF[7]_inst_i_1_n_3 }),
        .CYINIT(1'b0),
        .DI(operand1_IBUF[7:4]),
        .O(result_OBUF[7:4]),
        .S({\result_OBUF[7]_inst_i_2_n_0 ,\result_OBUF[7]_inst_i_3_n_0 ,\result_OBUF[7]_inst_i_4_n_0 ,\result_OBUF[7]_inst_i_5_n_0 }));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[7]_inst_i_2 
       (.I0(operand1_IBUF[7]),
        .I1(operand2_IBUF[7]),
        .O(\result_OBUF[7]_inst_i_2_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[7]_inst_i_3 
       (.I0(operand1_IBUF[6]),
        .I1(operand2_IBUF[6]),
        .O(\result_OBUF[7]_inst_i_3_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[7]_inst_i_4 
       (.I0(operand1_IBUF[5]),
        .I1(operand2_IBUF[5]),
        .O(\result_OBUF[7]_inst_i_4_n_0 ));
  LUT2 #(
    .INIT(4'h6)) 
    \result_OBUF[7]_inst_i_5 
       (.I0(operand1_IBUF[4]),
        .I1(operand2_IBUF[4]),
        .O(\result_OBUF[7]_inst_i_5_n_0 ));
  OBUF \result_OBUF[8]_inst 
       (.I(result_OBUF[8]),
        .O(result[8]));
  OBUF \result_OBUF[9]_inst 
       (.I(result_OBUF[9]),
        .O(result[9]));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule
`endif
