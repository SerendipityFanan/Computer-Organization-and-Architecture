
u
Command: %s
53*	vivadotcl2D
0synth_design -top adder32 -part xc7a200tfbg676-22default:defaultZ4-113h px� 
:
Starting synth_design
149*	vivadotclZ4-321h px� 
�
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2
	Synthesis2default:default2#
xc7a200t-fbg6762default:defaultZ17-347h px� 
�
0Got license for feature '%s' and/or device '%s'
310*common2
	Synthesis2default:default2#
xc7a200t-fbg6762default:defaultZ17-349h px� 
�
%s*synth2�
wStarting RTL Elaboration : Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 310.555 ; gain = 80.910
2default:defaulth px� 
�
synthesizing module '%s'638*oasys2
adder322default:default2U
?D:/Vivado/code/project_1/project_1.srcs/sources_1/new/adder32.v2default:default2
222default:default8@Z8-638h px� 
�
%done synthesizing module '%s' (%s#%s)256*oasys2
adder322default:default2
12default:default2
12default:default2U
?D:/Vivado/code/project_1/project_1.srcs/sources_1/new/adder32.v2default:default2
222default:default8@Z8-256h px� 
�
%s*synth2�
xFinished RTL Elaboration : Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 350.633 ; gain = 120.988
2default:defaulth px� 
D
%s
*synth2,

Report Check Netlist: 
2default:defaulth p
x
� 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
� 
u
%s
*synth2]
I|      |Item              |Errors |Warnings |Status |Description       |
2default:defaulth p
x
� 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
� 
u
%s
*synth2]
I|1     |multi_driven_nets |      0|        0|Passed |Multi driven nets |
2default:defaulth p
x
� 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished RTL Optimization Phase 1 : Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 350.633 ; gain = 120.988
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
W
Loading part %s157*device2$
xc7a200tfbg676-22default:defaultZ21-403h px� 
K
)Preparing netlist for logic optimization
349*projectZ1-570h px� 
>

Processing XDC Constraints
244*projectZ1-262h px� 
=
Initializing timing engine
348*projectZ1-569h px� 
�
Parsing XDC File [%s]
179*designutils2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default8Z20-179h px� 
�
No ports matched '%s'.
584*	planAhead2
clk2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
12default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
12default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
led_cout2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
22default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
22default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2

led_cout_22default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
32default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
32default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
resetn2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
42default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
42default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
	input_sel2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
52default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
52default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
input_sel_22default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
62default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
62default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
sw_cin2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
72default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
72default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
sw_cin_22default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
82default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
82default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
clk2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
102default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
102default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
led_cout2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
112default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
112default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2

led_cout_22default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
122default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
122default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
resetn2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
132default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
132default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
	input_sel2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
142default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
142default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
input_sel_22default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
152default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
152default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
sw_cin2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
162default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
162default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
sw_cin_22default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
172default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
172default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
lcd_rst2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
212default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
212default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
lcd_cs2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
222default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
222default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
lcd_rs2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
232default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
232default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
lcd_wr2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
242default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
242default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
lcd_rd2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
252default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
252default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2

lcd_bl_ctr2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
262default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
262default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[0]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
272default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
272default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[1]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
282default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
282default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[2]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
292default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
292default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[3]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
302default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
302default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[4]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
312default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
312default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[5]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
322default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
322default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[6]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
332default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
332default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[7]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
342default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
342default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[8]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
352default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
352default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[9]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
362default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
362default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[10]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
372default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
372default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[11]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
382default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
382default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[12]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
392default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
392default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[13]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
402default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
402default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[14]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
412default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
412default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[15]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
422default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
422default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
ct_int2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
432default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
432default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
ct_sda2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
442default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
442default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
ct_scl2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
452default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
452default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
ct_rstn2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
462default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
462default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
lcd_rst2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
482default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
482default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
lcd_cs2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
492default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
492default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
lcd_rs2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
502default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
502default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
lcd_wr2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
512default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
512default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
lcd_rd2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
522default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
522default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2

lcd_bl_ctr2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
532default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
532default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[0]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
542default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
542default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[1]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
552default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
552default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[2]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
562default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
562default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[3]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
572default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
572default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[4]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
582default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
582default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[5]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
592default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
592default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[6]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
602default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
602default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[7]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
612default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
612default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[8]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
622default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
622default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2"
lcd_data_io[9]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
632default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
632default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[10]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
642default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
642default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[11]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
652default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
652default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[12]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
662default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
662default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[13]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
672default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
672default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[14]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
682default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
682default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2#
lcd_data_io[15]2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
692default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
692default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
ct_int2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
702default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
702default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
ct_sda2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
712default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
712default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
ct_scl2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
722default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
722default:default8@Z17-55h px�
�
No ports matched '%s'.
584*	planAhead2
ct_rstn2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
732default:default8@Z12-584h px�
�
"'%s' expects at least one object.
55*common2 
set_property2default:default2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default2
732default:default8@Z17-55h px�
�
Finished Parsing XDC File [%s]
178*designutils2V
@D:/Vivado/code/project_1/project_1.srcs/constrs_1/new/mycons.xdc2default:default8Z20-178h px� 
H
&Completed Processing XDC Constraints

245*projectZ1-263h px� 
~
!Unisim Transformation Summary:
%s111*project29
%No Unisim elements were transformed.
2default:defaultZ1-111h px� 
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common24
 Constraint Validation Runtime : 2default:default2
00:00:002default:default2 
00:00:00.0032default:default2
625.0472default:default2
0.0002default:defaultZ17-268h px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
~Finished Constraint Validation : Time (s): cpu = 00:00:08 ; elapsed = 00:00:08 . Memory (MB): peak = 625.047 ; gain = 395.402
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
V
%s
*synth2>
*Start Loading Part and Timing Information
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
K
%s
*synth23
Loading part: xc7a200tfbg676-2
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished Loading Part and Timing Information : Time (s): cpu = 00:00:08 ; elapsed = 00:00:08 . Memory (MB): peak = 625.047 ; gain = 395.402
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
Z
%s
*synth2B
.Start Applying 'set_property' XDC Constraints
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished applying 'set_property' XDC Constraints : Time (s): cpu = 00:00:08 ; elapsed = 00:00:08 . Memory (MB): peak = 625.047 ; gain = 395.402
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished RTL Optimization Phase 2 : Time (s): cpu = 00:00:08 ; elapsed = 00:00:08 . Memory (MB): peak = 625.047 ; gain = 395.402
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
E
%s
*synth2-

Report RTL Partitions: 
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
W
%s
*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
L
%s
*synth24
 Start RTL Component Statistics 
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
� 
:
%s
*synth2"
+---Adders : 
2default:defaulth p
x
� 
Z
%s
*synth2B
.	   6 Input     34 Bit       Adders := 1     
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
O
%s
*synth27
#Finished RTL Component Statistics 
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
Y
%s
*synth2A
-Start RTL Hierarchical Component Statistics 
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
O
%s
*synth27
#Hierarchical RTL Component report 
2default:defaulth p
x
� 
<
%s
*synth2$
Module adder32 
2default:defaulth p
x
� 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
� 
:
%s
*synth2"
+---Adders : 
2default:defaulth p
x
� 
Z
%s
*synth2B
.	   6 Input     34 Bit       Adders := 1     
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
[
%s
*synth2C
/Finished RTL Hierarchical Component Statistics
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
H
%s
*synth20
Start Part Resource Summary
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s
*synth2m
YPart Resources:
DSPs: 740 (col length:100)
BRAMs: 730 (col length: RAMB18 100 RAMB36 50)
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
K
%s
*synth23
Finished Part Resource Summary
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
W
%s
*synth2?
+Start Cross Boundary and Area Optimization
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished Cross Boundary and Area Optimization : Time (s): cpu = 00:00:08 ; elapsed = 00:00:09 . Memory (MB): peak = 625.047 ; gain = 395.402
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
E
%s
*synth2-

Report RTL Partitions: 
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
W
%s
*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
R
%s
*synth2:
&Start Applying XDC Timing Constraints
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished Applying XDC Timing Constraints : Time (s): cpu = 00:00:14 ; elapsed = 00:00:15 . Memory (MB): peak = 642.539 ; gain = 412.895
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
F
%s
*synth2.
Start Timing Optimization
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
|Finished Timing Optimization : Time (s): cpu = 00:00:14 ; elapsed = 00:00:15 . Memory (MB): peak = 642.539 ; gain = 412.895
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
E
%s
*synth2-

Report RTL Partitions: 
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
W
%s
*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
E
%s
*synth2-
Start Technology Mapping
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
{Finished Technology Mapping : Time (s): cpu = 00:00:14 ; elapsed = 00:00:15 . Memory (MB): peak = 653.680 ; gain = 424.035
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
E
%s
*synth2-

Report RTL Partitions: 
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
W
%s
*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
?
%s
*synth2'
Start IO Insertion
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
Q
%s
*synth29
%Start Flattening Before IO Insertion
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
T
%s
*synth2<
(Finished Flattening Before IO Insertion
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
H
%s
*synth20
Start Final Netlist Cleanup
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
K
%s
*synth23
Finished Final Netlist Cleanup
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
uFinished IO Insertion : Time (s): cpu = 00:00:14 ; elapsed = 00:00:15 . Memory (MB): peak = 653.680 ; gain = 424.035
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
D
%s
*synth2,

Report Check Netlist: 
2default:defaulth p
x
� 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
� 
u
%s
*synth2]
I|      |Item              |Errors |Warnings |Status |Description       |
2default:defaulth p
x
� 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
� 
u
%s
*synth2]
I|1     |multi_driven_nets |      0|        0|Passed |Multi driven nets |
2default:defaulth p
x
� 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
O
%s
*synth27
#Start Renaming Generated Instances
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished Renaming Generated Instances : Time (s): cpu = 00:00:14 ; elapsed = 00:00:15 . Memory (MB): peak = 653.680 ; gain = 424.035
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
E
%s
*synth2-

Report RTL Partitions: 
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
W
%s
*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
L
%s
*synth24
 Start Rebuilding User Hierarchy
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished Rebuilding User Hierarchy : Time (s): cpu = 00:00:14 ; elapsed = 00:00:15 . Memory (MB): peak = 653.680 ; gain = 424.035
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
K
%s
*synth23
Start Renaming Generated Ports
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished Renaming Generated Ports : Time (s): cpu = 00:00:14 ; elapsed = 00:00:15 . Memory (MB): peak = 653.680 ; gain = 424.035
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
M
%s
*synth25
!Start Handling Custom Attributes
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished Handling Custom Attributes : Time (s): cpu = 00:00:14 ; elapsed = 00:00:15 . Memory (MB): peak = 653.680 ; gain = 424.035
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
J
%s
*synth22
Start Renaming Generated Nets
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished Renaming Generated Nets : Time (s): cpu = 00:00:14 ; elapsed = 00:00:15 . Memory (MB): peak = 653.680 ; gain = 424.035
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
K
%s
*synth23
Start Writing Synthesis Report
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
A
%s
*synth2)

Report BlackBoxes: 
2default:defaulth p
x
� 
J
%s
*synth22
+-+--------------+----------+
2default:defaulth p
x
� 
J
%s
*synth22
| |BlackBox name |Instances |
2default:defaulth p
x
� 
J
%s
*synth22
+-+--------------+----------+
2default:defaulth p
x
� 
J
%s
*synth22
+-+--------------+----------+
2default:defaulth p
x
� 
A
%s*synth2)

Report Cell Usage: 
2default:defaulth px� 
D
%s*synth2,
+------+-------+------+
2default:defaulth px� 
D
%s*synth2,
|      |Cell   |Count |
2default:defaulth px� 
D
%s*synth2,
+------+-------+------+
2default:defaulth px� 
D
%s*synth2,
|1     |CARRY4 |    18|
2default:defaulth px� 
D
%s*synth2,
|2     |LUT1   |    30|
2default:defaulth px� 
D
%s*synth2,
|3     |LUT3   |    32|
2default:defaulth px� 
D
%s*synth2,
|4     |LUT4   |     5|
2default:defaulth px� 
D
%s*synth2,
|5     |LUT5   |    31|
2default:defaulth px� 
D
%s*synth2,
|6     |LUT6   |    31|
2default:defaulth px� 
D
%s*synth2,
|7     |IBUF   |   130|
2default:defaulth px� 
D
%s*synth2,
|8     |OBUF   |    34|
2default:defaulth px� 
D
%s*synth2,
+------+-------+------+
2default:defaulth px� 
E
%s
*synth2-

Report Instance Areas: 
2default:defaulth p
x
� 
N
%s
*synth26
"+------+---------+-------+------+
2default:defaulth p
x
� 
N
%s
*synth26
"|      |Instance |Module |Cells |
2default:defaulth p
x
� 
N
%s
*synth26
"+------+---------+-------+------+
2default:defaulth p
x
� 
N
%s
*synth26
"|1     |top      |       |   311|
2default:defaulth p
x
� 
N
%s
*synth26
"+------+---------+-------+------+
2default:defaulth p
x
� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
�
%s*synth2�
�Finished Writing Synthesis Report : Time (s): cpu = 00:00:15 ; elapsed = 00:00:15 . Memory (MB): peak = 653.680 ; gain = 424.035
2default:defaulth px� 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
� 
r
%s
*synth2Z
FSynthesis finished with 0 errors, 0 critical warnings and 0 warnings.
2default:defaulth p
x
� 
�
%s
*synth2�
~Synthesis Optimization Runtime : Time (s): cpu = 00:00:09 ; elapsed = 00:00:11 . Memory (MB): peak = 653.680 ; gain = 149.621
2default:defaulth p
x
� 
�
%s
*synth2�
Synthesis Optimization Complete : Time (s): cpu = 00:00:15 ; elapsed = 00:00:15 . Memory (MB): peak = 653.680 ; gain = 424.035
2default:defaulth p
x
� 
B
 Translating synthesized netlist
350*projectZ1-571h px� 
g
-Analyzing %s Unisim elements for replacement
17*netlist2
1482default:defaultZ29-17h px� 
j
2Unisim Transformation completed in %s CPU seconds
28*netlist2
02default:defaultZ29-28h px� 
K
)Preparing netlist for logic optimization
349*projectZ1-570h px� 
u
)Pushed %s inverter(s) to %s load pin(s).
98*opt2
02default:default2
02default:defaultZ31-138h px� 
~
!Unisim Transformation Summary:
%s111*project29
%No Unisim elements were transformed.
2default:defaultZ1-111h px� 
�
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
122default:default2
682default:default2
682default:default2
02default:defaultZ4-41h px� 
^
%s completed successfully
29*	vivadotcl2 
synth_design2default:defaultZ4-42h px� 
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2"
synth_design: 2default:default2
00:00:152default:default2
00:00:172default:default2
669.9222default:default2
446.5862default:defaultZ17-268h px� 
�
 The %s '%s' has been generated.
621*common2

checkpoint2default:default2O
;D:/Vivado/code/project_1/project_1.runs/synth_1/adder32.dcp2default:defaultZ17-1381h px� 
�
sreport_utilization: Time (s): cpu = 00:00:00 ; elapsed = 00:00:00.015 . Memory (MB): peak = 669.922 ; gain = 0.000
*commonh px� 
�
Exiting %s at %s...
206*common2
Vivado2default:default2,
Thu Mar 28 12:05:53 20242default:defaultZ17-206h px� 


End Record