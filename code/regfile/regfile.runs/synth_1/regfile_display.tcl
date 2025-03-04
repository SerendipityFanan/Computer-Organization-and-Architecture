# 
# Synthesis run script generated by Vivado
# 

create_project -in_memory -part xc7a200tfbg676-2

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir D:/Vivado/code/regfile/regfile.cache/wt [current_project]
set_property parent.project_path D:/Vivado/code/regfile/regfile.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property ip_output_repo d:/Vivado/code/regfile/regfile.cache/ip [current_project]
set_property ip_cache_permissions {read write} [current_project]
add_files -quiet D:/Vivado/code/multiply/lcd_module.dcp
set_property used_in_implementation false [get_files D:/Vivado/code/multiply/lcd_module.dcp]
read_verilog -library xil_defaultlib {
  D:/Vivado/code/regfile/regfile.srcs/sources_1/new/regfile.v
  D:/Vivado/code/regfile/regfile.srcs/sources_1/new/regfile_display.v
}
# Mark all dcp files as not used in implementation to prevent them from being
# stitched into the results of this synthesis run. Any black boxes in the
# design are intentionally left as such for best results. Dcp files will be
# stitched into the design at a later time, either when this synthesis run is
# opened, or when it is stitched into a dependent implementation run.
foreach dcp [get_files -quiet -all -filter file_type=="Design\ Checkpoint"] {
  set_property used_in_implementation false $dcp
}
read_xdc D:/Vivado/code/regfile/regfile.srcs/constrs_1/new/regfile.xdc
set_property used_in_implementation false [get_files D:/Vivado/code/regfile/regfile.srcs/constrs_1/new/regfile.xdc]


synth_design -top regfile_display -part xc7a200tfbg676-2


write_checkpoint -force -noxdef regfile_display.dcp

catch { report_utilization -file regfile_display_utilization_synth.rpt -pb regfile_display_utilization_synth.pb }
