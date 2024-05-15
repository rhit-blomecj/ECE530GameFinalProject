connect -url tcp:127.0.0.1:3121
source C:/ECE530/project/Zybo-Z7-20-HDMI-v2018.2-2_w_xpr/ECE530GameFinalProject/hdmi-demo-test/hdmi-demo-test.sdk/design_1_wrapper_hw_platform_0/ps7_init.tcl
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo Z7 210351B7C103A"} -index 0
rst -system
after 3000
targets -set -filter {jtag_cable_name =~ "Digilent Zybo Z7 210351B7C103A" && level==0} -index 1
fpga -file C:/ECE530/project/Zybo-Z7-20-HDMI-v2018.2-2_w_xpr/ECE530GameFinalProject/hdmi-demo-test/hdmi-demo-test.sdk/design_1_wrapper_hw_platform_0/design_1_wrapper.bit
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo Z7 210351B7C103A"} -index 0
loadhw -hw C:/ECE530/project/Zybo-Z7-20-HDMI-v2018.2-2_w_xpr/ECE530GameFinalProject/hdmi-demo-test/hdmi-demo-test.sdk/design_1_wrapper_hw_platform_0/system.hdf -mem-ranges [list {0x40000000 0xbfffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo Z7 210351B7C103A"} -index 0
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo Z7 210351B7C103A"} -index 0
dow C:/ECE530/project/Zybo-Z7-20-HDMI-v2018.2-2_w_xpr/ECE530GameFinalProject/hdmi-demo-test/hdmi-demo-test.sdk/hdmi_demo_test/Debug/hdmi_demo_test.elf
configparams force-mem-access 0
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo Z7 210351B7C103A"} -index 0
con
