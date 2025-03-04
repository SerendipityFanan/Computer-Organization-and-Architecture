@echo off
set xv_path=D:\\Vivado\\Vivado\\2017.1\\bin
call %xv_path%/xelab  -wto 8753dd9ffda641b99db47444a110016d -m64 --debug typical --relax --mt 2 --maxdelay -L xil_defaultlib -L simprims_ver -L secureip --snapshot single_cycle_cpu_display_time_synth -transport_int_delays -pulse_r 0 -pulse_int_r 0 -pulse_e 0 -pulse_int_e 0 xil_defaultlib.single_cycle_cpu_display xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
