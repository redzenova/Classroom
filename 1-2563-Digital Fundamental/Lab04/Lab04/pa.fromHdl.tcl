
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name Lab04 -dir "C:/Users/Redzer0/Desktop/Classroom/1-2563-Digital Fundamental/Lab04/Lab04/planAhead_run_1" -part xc6slx9tqg144-3
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "C:/Users/Redzer0/Desktop/Classroom/1-2563-Digital Fundamental/Lab04/Lab04/Lab04sem.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {Lab04sem.vf}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top Lab04sem $srcset
add_files [list {Lab4Pin.ucf}] -fileset [get_property constrset [current_run]]
add_files [list {Lab04sem.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc6slx9tqg144-3
