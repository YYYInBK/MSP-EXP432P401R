SET PATH=D:\Keil 5--MDK\ARM\ARMCC\Bin;D:\VMware\bin\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;D:\pycharm\PyCharm Community Edition 2022.2.2\bin\pycharm64.exe;D:\matlab\runtime\win64;D:\matlab\bin;D:\matlab\polyspace\bin;c:\users\”»”Í—Ù\quartus\bin;D:\Mysql\mysql-8.0.32-winx64\bin;C:\Users\”»”Í—Ù\AppData\Local\Microsoft\WindowsApps;;D:\pycharm\PyCharm Community Edition 2022.3.3\bin;;D:\modelsim\win64;D:\vscode\Microsoft VS Code\bin
SET CPU_TYPE=MSP432P401R
SET CPU_VENDOR=Texas Instruments
SET UV2_TARGET=empty
SET CPU_CLOCK=0x00B71B00
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\startup_msp432p401r_uvision.__i"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\main.__i"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\system_msp432p401r.__i"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\led.__i"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\key.__i"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\delay.__i"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\baudrate_calculate.__i"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\sysinit.__i"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\usart.__i"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\tima.__i"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmCC" --Via "..\obj\tim32.__i"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\ArmLink" --Via "..\obj\empty.lnp"
"D:\Keil 5--MDK\ARM\ARMCC\Bin\fromelf.exe" "..\obj\empty.axf" --i32combined --output "..\obj\empty.hex"
fromelf --bin --output .\Build\empty.bin .\Build\empty.axf
