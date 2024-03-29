## VGA-Console
This project was implemented on a Blackboard from [Real Digital](https://www.realdigital.org/). The board includes a Xilinx Zynq-7000 SoC with an ARM microprocessor and an Artix FPGA.

<img src="img/blackboard.png?raw=true" width="340" height="300">

The VGA Console IP enables the use of a VGA display as a console for the Blackboard. The system was designed using the Vivado IP Integrator tool. The programmable logic contains an AXI interface to receive data from the processor, and store it in memory. A 80 X 45 array of 7-bit ASCII character and 12-bit color data was stored in block RAM using the Xilinx Block Memory Generator IP. This utilized 2.5 36 kB BRAM tiles on the FPGA. To generate a VGA signal from the character array, a character generator ROM file from Real Digital was used, which generated another BRAM tile. The VGA Console IP output signals are routed through a VGA-HDMI converter module from Real Digital in order to drive the HDMI port on the Blackboard. In addition, the cursor's current position in the character array was outputted to the Blackboard's SSEG display for debugging purposes.

### System block diagram
![System Block Diagram](img/vga_console_system_bd.png?raw=true)

#### *Provided by Real Digital:*
* [HDMI/DVI Encoder IP](https://github.com/RealDigitalOrg/VivadoIP/tree/master/hdmi_tx_1.0)
* [char_rom.v block RAM module](https://www.realdigital.org/doc/93562a1dd6587887f4265d6ecac23929)


### Tests
<img src="img/HelloWorld.jpg?raw=true" width="600" height="450">
<img src="img/HelloHelloWorld.jpg?raw=true" width="600" height="450">
<img src="img/Count.jpg?raw=true" width="450" height="600">
