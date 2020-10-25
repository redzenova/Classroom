
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name Lab05 -dir "C:/Users/Redzer0/Desktop/Classroom/1-2563-Digital Fundamental/Lab05/planAhead_run_2" -part xc6slx9tqg144-3
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "Lab05.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {Lab05.vf}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top Lab05 $srcset
add_files [list {Lab05.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc6slx9tqg144-3
