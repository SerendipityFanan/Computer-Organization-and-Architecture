//*************************************************************************
//   > 文件名: regfile_display.v
//   > 描述  ：寄存器堆显示模块，调用FPGA板上的IO接口和触摸屏
//   > 作者  : LOONGSON
//   > 日期  : 2016-04-14
//*************************************************************************
module regfile_display(
    //时钟与复位信号
    input clk,
    input resetn,    //后缀"n"代表低电平有效

    //拨码开关，用于产生写使能和选择输入数
    input wen,
    //input [2:0] input_sel,
      input [2:0] input_sel,
      
    //led灯，用于指示写使能信号，和正在输入什么数据
    output led_wen,
    output led_waddr,    //指示输入写地址
    output led_wdata,    //指示输入写数据
    output led_raddr1,   //指示输入读地址1
    output led_raddr2,   //指示输入读地址2

    //触摸屏相关接口，不需要更改
    output lcd_rst,
    output lcd_cs,
    output lcd_rs,
    output lcd_wr,
    output lcd_rd,
    inout[15:0] lcd_data_io,
    output lcd_bl_ctr,
    inout ct_int,
    inout ct_sda,
    output ct_scl,
    output ct_rstn
);
//-----{LED显示}begin
    assign led_wen    = wen;
    //assign led_raddr1 = (input_sel==2'd0);
    //assign led_raddr2 = (input_sel==2'd1);
   // assign led_waddr  = (input_sel==2'd2);
   // assign led_wdata  = (input_sel==2'd3);
  assign led_raddr1 = (input_sel==3'd0||input_sel==3'd1);
  assign led_raddr2 = (input_sel==3'd2||input_sel==3'd3);
  assign led_waddr = (input_sel==3'd4||input_sel==3'd5);
  assign led_wdata = (input_sel==3'd6||input_sel==3'd7);
  
//-----{LED显示}end

//-----{调用寄存器堆模块}begin
    //寄存器堆多增加一个读端口，用于在触摸屏上显示32个寄存器值
//wire [63:0] test_data;  
    wire [63:0] test_data;  
   // wire [4 :0] test_addr;
   wire [6 :0] test_addr;

    //reg  [4 :0] raddr1;
    reg  [3 :0] raddr1;
  //  reg  [4 :0] raddr2;
     reg  [3:0] raddr2;
   // reg  [4 :0] waddr;
   reg  [3 :0] waddr;
   
   // reg  [63:0] wdata;
    reg  [63:0] wdata;
    //wire [63:0] rdata1;
    wire [63:0] rdata1;
    //wire [63:0] rdata2;
    wire [63:0] rdata2;
    
    regfile rf_module(
        .clk   (clk   ),
        .wen   (wen   ),
        .raddr1(raddr1),
        .raddr2(raddr2),
        .waddr (waddr ),
        .wdata (wdata ),
        .rdata1(rdata1),
        .rdata2(rdata2),
        .test_addr(test_addr),
        .test_data(test_data)
    );
//-----{调用寄存器堆模块}end

//---------------------{调用触摸屏模块}begin--------------------//
//-----{实例化触摸屏}begin
//此小节不需要更改
    reg         display_valid;
    reg  [39:0] display_name;
    reg  [31:0] display_value;   
   wire [5:0] display_number;
    wire        input_valid;
   wire [31:0] input_value;
  // wire [63:0] input_value;

    lcd_module lcd_module(
        .clk            (clk           ),   //10Mhz
        .resetn         (resetn        ),

        //调用触摸屏的接口
        .display_valid  (display_valid ),
        .display_name   (display_name  ),
        .display_value  (display_value ),
        .display_number (display_number),
        .input_valid    (input_valid   ),
        .input_value    (input_value   ),

        //lcd触摸屏相关接口，不需要更改
        .lcd_rst        (lcd_rst       ),
        .lcd_cs         (lcd_cs        ),
        .lcd_rs         (lcd_rs        ),
        .lcd_wr         (lcd_wr        ),
        .lcd_rd         (lcd_rd        ),
        .lcd_data_io    (lcd_data_io   ),
        .lcd_bl_ctr     (lcd_bl_ctr    ),
        .ct_int         (ct_int        ),
        .ct_sda         (ct_sda        ),
        .ct_scl         (ct_scl        ),
        .ct_rstn        (ct_rstn       )
    ); 
//-----{实例化触摸屏}end

//-----{从触摸屏获取输入}begin
//根据实际需要输入的数修改此小节，
//建议对每一个数的输入，编写单独一个always块
    //32个寄存器显示在7~38号的显示块，故读地址为（display_number-1）
    //32个寄存器显示在13~38号的显示块，故读地址为（display_number-1）
   // assign test_addr = display_number-5'd7; 
   assign test_addr = display_number-8'd13; 
    //当input_sel为2'b00时，表示输入数为读地址1，即raddr1
    always @(posedge clk)
    begin
        if (!resetn)
        begin
            raddr1 <= 4'd0;
        end
        //else if (input_valid &&  input_sel==2'd0)
         else if (input_valid&&(input_sel==3'd0||input_sel==3'd1))
        begin
        //raddr1 <= input_value[4:0];
          raddr1[3:0] <= input_value[3:0];
        end
    end
    
    //当input_sel为2'b01时，表示输入数为读地址2，即raddr2
    always @(posedge clk)
    begin
        if (!resetn)
        begin
            raddr2 <= 4'd0;
        end
       // else if (input_valid && input_sel==2'd1)
       else if (input_valid&&(input_sel==3'd2||input_sel==3'd3) )
        begin
          //  raddr2 <= input_value[4:0];
              raddr2[3:0] <= input_value[3:0];
        end
    end
    
    //当input_sel为2'b10时，表示输入数为写地址，即waddr
    always @(posedge clk)
    begin
        if (!resetn)
        begin
            waddr  <=4'd0;
        end
        //else if (input_valid && input_sel==2'd2)
        else if (input_valid&&(input_sel==3'd4||input_sel==3'd5))
        begin
           // waddr  <= input_value[4:0];
              waddr[3:0]  <= input_value[3:0];
        end
    end
    
    //当input_sel为2'b11时，表示输入数为写数据，即wdata
    always @(posedge clk)
    begin
        if (!resetn)
        begin
            wdata  <= 64'd0;
        end
        //else if (input_valid && input_sel==2'd3)
        else if (input_valid )
        begin
           // wdata  <= input_value; 
             case(input_sel)
              3'd6:
              wdata[63:32]<=input_value; // 当 input_sel 为 0 时，输入 raddr1 的高 32 位
              3'd7:
              wdata[31:0]<= input_value; // 当 input_sel 为 1 时，输入 raddr1 的低 32 位
            default: 
            wdata <= wdata; // 其他情况下，保持不变
        endcase   
        end
    end
//-----{从触摸屏获取输入}end

//-----{输出到触摸屏显示}begin
//根据需要显示的数修改此小节，
//触摸屏上共有44块显示区域，可显示44组32位数据
//44块显示区域从1开始编号，编号为1~44，
    always @(posedge clk)
    begin
        //if (display_number >6'd6 && display_number <6'd39 )
       if (display_number >6'd12 && display_number <6'd45 )
        begin //块号7~38显示32个通用寄存器的值//13~38
            display_valid <= 1'b1;
            display_name[39:16] <= "REG";
            //display_name[15: 8] <= {4'b0011,3'b000,test_addr[4]};
            display_name[15: 8] <= {4'b0011,3'b0000};
            // display_name[7 : 0] <= {4'b0011,test_addr[3:0]};
            //if(display_number%2==0) 
            //  test_addr >>= 1;

          //  if(test_addr[4]==1)
            //if( display_number>8'd28)
           // begin
             display_name[7 : 0] <= {4'b0011,test_addr[4:1]};
           //  end
           //  else
          //  begin
           //   display_name[7 : 0] <= {4'b0011,1'b0,test_addr[3:1]};
            //  end
            if(test_addr%2==0)
            begin
            display_value       <= test_data[63:32];
            end
            else
            begin
            display_value       <= test_data[31:0];
          end
          end
        else
        begin
            case(display_number)
               // 6'd1|| : //显示读端口1的地址
                6'd1 : //显示读端口1的地址
                begin
                    display_valid <= 1'b1;
                    display_name  <= "RADD1";
                   // display_value[3] <= raddr1;
                   display_value<=32'b0;
                end
                //6'd2 : //显示读端口1读出的数据
                 6'd2 : //显示读端口1的地址
                begin
                    display_valid <= 1'b1;
                    display_name  <= "RADD1";
                    display_value <= raddr1;
                  // display_value<=32'b0;
                end
                6'd3 : 
                begin
                    display_valid <= 1'b1;
                    display_name  <= "RDAT1";
                    display_value <= rdata1[63:32];
                end
                6'd4 : 
                begin
                    display_valid <= 1'b1;
                    display_name  <= "RDAT1";
                    display_value <= rdata1[31:0];
                end
                //6'd3 : //显示读端口2的地址
                6'd5 : 
                begin
                    display_valid <= 1'b1;
                    display_name  <= "RADD2";
                   // display_value <= raddr2;
                   display_value<=32'b0;
                end
                6'd6 : 
                begin
                    display_valid <= 1'b1;
                    display_name  <= "RADD2";
                    display_value <= raddr2;
                end
              //  6'd4 : //显示读端口2读出的数据
              6'd7: 
                begin
                    display_valid <= 1'b1;
                    display_name  <= "RDAT2";
                    display_value <= rdata2[63:32];
                end
                6'd8 : 
                begin
                    display_valid <= 1'b1;
                    display_name  <= "RDAT2";
                    display_value <= rdata2[31:0];
                end
              //  6'd5 : //显示写端口的地址
              6'd9 : 
                begin
                    display_valid <= 1'b1;
                    display_name  <= "WADDR";
                    //display_value <= waddr;
                    display_value<=32'b0;
                end
                6'd10 : 
                begin
                    display_valid <= 1'b1;
                    display_name  <= "WADDR";
                    display_value <= waddr;
                end
               // 6'd6 : //显示写端口写入的数据
               6'd11: 
                begin
                    display_valid <= 1'b1;
                    display_name  <= "WDATA";
                    display_value <= wdata[63:32];
                end
                6'd12 : 
                begin
                    display_valid <= 1'b1;
                    display_name  <= "WDATA";
                    display_value <= wdata[31:0];
                end
                default :
                begin
                    display_valid <= 1'b0;
                    display_name  <= 40'd0;
                    display_value <= 32'd0;
                end
            endcase
        end
    end
//-----{输出到触摸屏显示}end
//----------------------{调用触摸屏模块}end---------------------//
endmodule
