# VGA-Console
This project was implemented on a Blackboard from [Real Digital](https://www.realdigital.org/). The board includes a Zynq-7000 SoC with an ARM microprocessor and an Artix FPGA.

<img src="img/blackboard.png?raw=true" width="343" height="301">

I designed the VGA Console IP, which enables the use of a VGA display as a console for the Blackboard. The programmable logic contains an AXI interface to receive data from the processor. 80 X 45 character data for the display was stored in block RAM on the FPGA, which was instantiated using the Xilinx Block Memory Generator IP. The VGA Console IP outputs a VGA signal, which was routed through a VGA-HDMI converter module from Real Digital to use the HDMI port on the Blackboard. In addition, the cursor's current position in the character array was outputted to the Blackboard's SSEG display for debugging purposes.

### System block diagram
![System Block Diagram](img/vga_console_system_bd.png?raw=true)

### *Provided by Real Digital:*
* [VGA-HDMI encoder IP](https://github.com/RealDigitalOrg/VivadoIP/tree/master/hdmi_tx_1.0)
* [char_rom.v block ram module](https://www.realdigital.org/doc/93562a1dd6587887f4265d6ecac23929)
