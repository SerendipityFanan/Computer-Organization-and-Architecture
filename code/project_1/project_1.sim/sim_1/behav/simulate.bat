@echo off
set xv_path=D:\\Vivado\\Vivado\\2017.1\\bin
call %xv_path%/xsim testbench_behav -key {Behavioral:sim_1:Functional:testbench} -tclbatch testbench.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
