List of HASP Device Driver Versions Since V4.02 (May, 2000)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This device driver installer supports the Win32 and Windows x64 platforms. 
The installer detects the operation system version at runtime before installing 
the relevant drivers.  

Upgrade Note
============
When upgrading the driver, make sure that no running service is currently using the
driver. Although the install program can terminate applications acessing the driver, 
it cannot terminate running services. If for example the HASP License Manager is running as a
service, you must stop the service before upgrading the driver.

The list below includes new HASP Device Driver features, improvements, bug fixes, and other 
relevant information. It is arranged in descending chronological order.


************************
V4.99.5.20  October 2005
************************

Problems Solved
================

Case TD 820:   Sporadic installer failures returned the following error message:
	    	   "Failed to start Aladdin Device Driver. Failed to start a service in the Service 
               Control Manager Database"

Case TD 2330:  Driver installation failed when run directly from an installation CD.

Case TD 2337:  PC Card drivers failed to update on Windows Server 2003.

Case TD 2366:  PC Card drivers failed to update or install on Windows 2000.


**********************
V4.98  September, 2005
**********************

New Features
============

Enhanced to support Windows x64 operation systems.


Known Issues
============

TD#2224: Protected Programs with either the Envelope's overlay support or data file 
         protection enabled, cannot open encrypted data when Symantec AntiVirus Corporate Edition 
         version 10.0.1.1000 (Scan engine version 51.1.0.15) runs in the background. This pertains 
         to the Windows 32-bit platform. 
         Workaround - Download and install the following file from Aladdin's FTP site
         ftp://ftp.ealaddin.com/pub/hasp/support/kb_files/SAV_10.zip 


All items listed below pertain to Windows 64-bit platforms.

Does not support HASP4 API versions older than version 8.0.

Data files cannot be protected using the Envelope program.

No verlay support for applications protected with the Envelope program.

No support for PC-CardHASP (PCMCIA-based HASP).


Problems Solved
===============
All items listed below pertain to Windows 32-bit platforms.

TD#2063: Blue screen displays when using 64-bit Hardware on
         Windows XP SP2 (32Bit) with McAfee 8.0 Enterprise running in the background.

TD#2052: When the size of the aksdrvsetup.log file was too big, the driver installer
         suspended.

TD#1994: Redundant copy of aksusb.sys created in the %windows%\system32\setup\aladdin directory.

TD#1968: Java programs converted to executables with exe4j once protected with Envelope could not
         run with recent HASP drivers.

TD#1948: Blue screen displayed on Windows 2003 SP1 when running .NET applications Enveloped with
         IMAGE_EMULATION enabled.

TD#1928: DataHASP encryption/decryption failed on Windows Server 2003 SP1 with McAfee Anti Virus v8
         installed.

TD#1925: Message "Can not install automatic data protection" displayed when application was restarted
         immediately after termination.

TD#1833: DataHASP protection error - "Unknown error" - displayed on Windows Server 2003.

TD#1008: When remotely logging to parallel HASP4 Net key, the API returns a hardware mismatch.

TD#1607: DataHASP files cannot be protected when AVG 7.0 Anti Virus is installed.

TD#1708: Driver crashes when running encrypted DataHASP files for protected programs on
         Win64 or Sempron machines with Win XP SP2 installed.

TD#1842: When running encrypted DataHASP files for protected programs, the program sometimes suspends when key is unplugged.

TD#1856: Protected programs with encrypted DataHASP files crash due to a threading error.

Wi#1796: Protected programs with encrypted DataHASP files do not work with McAfee Enterprise 8.0 when the overrun McAfee protection buffer is enabled.

TD#1047: Incorrect termination message when installing on Win 2000 platforms.

TD#1756: Cannot install drivers when another running windows setup is detected.

TD#1870: Reboot request even no update performed on Win9x platforms.

TD#1620: Driver Installation on x64 machines running Windows XP SP2 leads to API error: 0x160000.

TD#2049: Installer displays wrong version number of aksusb.sys.


************************
V4.96  December 17, 2004
************************

New Features
============

Win32 XP SP2 support on 64-bit extended systems.

Includes the HASP HL driver package with up-to-date USB drivers.


********************
V4.95  June 19, 2003
********************

New Features
============

Signed for Windows Server 2003


Problems Solved
================


Case TD 966:  The TimeHASP ID was corrupted after several thousand loops.

Case TD 981:  After printing, the HASP key was not accessible.

Known Limitations
=================
The -sourcepath installation switch is not supported in this release.
The -sp switch should be used in its place.

*********************
V4.92  May 2003
*********************

New Features
============

Security enhancements, especially when used in conjunction with API v8.01.


By default parallel port contention handling is enabled.

Enhanced handling of simultaneously connected USB keys having the same
passwords.

On Windows Server 2003, data protection (DataHASP) is by default
enabled.


Problems Solved
===============

Case 15940: The Hinstall added needless registry entries.

Case 3750:  DataHASP applications executed with Norton Antivirus running in the
            background crash the system.



*********************
V4.85  November 2002
*********************

New Features
============

Support for HL_Server USB


Problems Solved
===============
 
Case 310669:  WriteBlock on HASP PCMCIA failed sometimes when simultaneously
              accessing a second HASP PCMCIA.

Case 310670:  When using a parallel key at a printer port running on 3.3 volts,
              the key was occasionally not found, especially multiple keys were daisy-chained.

Case 310671:  Potential deadlock with USB keys when simultaneously using
              HL_PORTINF() in different threads.


************************
V4.81  October 30, 2002
************************

Problems Solved
================

Case 310655:  USB key isn't found after uninstall and reinstall while no key is connected.


************************
V4.80  October 14, 2002
************************

New Features
============

Enhanced security


************************
V4.75  May 21, 2002
************************

Problems Solved
================

Case 310635:  Wrong HDDVersion structure in driver install DLL. Please make sure to use latest 
              hiapi.h headerfile.

Case 310633:  Driver install DLL replaces aksusb.sys even if latest drivers are installed.
 
Case 310623:  New driver install mechanism fails on Windows 2000.

Case 310634:  HASP-Hardlock interference. Concurrent usage of HASP and Hardlock parallel keys 
              is blocked.

Case 3744:    HDD 4.70 does not install properly under some Windows 2000 and Windows XP PCs.

Case 310633:  Background checks fail after power mode Standby and Hibernate.

************************
V4.70  November 21, 2001
************************

New Features
============

New WinXP Microsoft signed driver akspccard.sys ver 1.01 to support
PCCard under WinXP.

Problems Solved
================

Case TD #600:  While accessing the PCCard detaching the card generated a blue screen.

************************
V4.65  November 21, 2001
************************

New Features
============

The new device driver fully supports Windows XP,
including WHQL driver signature.

Problems Solved
================

Case 3726:  DOS enveloped application cannot access USB key.

Case 3730:  Some notebook with IrDA port running Win98 can't find parallel HASP keys.


********************
V4.50 September 2001
********************

Support for Windows XP. This driver supports Windows XP. It is not signed by MS.
Installation procedure is usual.
When connecting a HASP USB to the computer, XP prompts you with
a warning that the driver is not signed. Click on the NEXT button and
then on the CONTINUE ANYWAY button.

Problems Solved
===============

Case 9357:  DataHASP does not work when all partitions are NTFS, and the PC has no floppy drive.

**************
V4.35 May 2001
**************

New Features
============

HASP4 Time USB support.
This driver version includes support for the new HASP4 Time USB keys. Please
note, that you need to unplug all USB keys under Windows 2000 in order to unload
the old driver. The new Aladdin USB driver will be loaded after driver installation
automatically if the first key is plugged.

HASP36 support.
Implemented support for HASP36 keys attached to an IBM compatible PC. Please note,
that HASP36 keys attached to NEC machines are not supported.

Popup on key removal.
The usual message box if a USB device is disconnected under Windows 2000 will
not be displayed anymore,


************************
V4.25 (HASP CD Rel 10.0)
************************

New Features
============

HASP keys connected to PCI parallel cards registered to the system will
be found on Windows 95/98/ME systems,
because drivers search all LPT ports.

ReadBlock and WriteBlock services on HASP USB keys are handled 40% faster.

Aladdin USB Support for Windows NT4. Since Microsoft Windows NT4 does not
support USB devices, Aladdin provides you this functionality with an
additional set of drivers using a proprietary USB stack.
The stack is available on a separate CD. Please contact your HASP sales
representative.


Problems Solved
================

Case 3713:  Running DOS RUS tools on Windows 98/ME caused reboot.

Case 5402:  Setting LptNum value to a non existing LPT port caused a blue screen.

Case 3692:  HASP PCCARD was not found after Windows 2000 hibernate.

Case 3709:  Application protected with both API function and envelope (using Data HASP)
            caused a blue screen after starting it several times.

Case 5677:  USB HASP4 keys without memory were not recognized by HDD 4.12


***********************
V4.12 (HASP CD Rel 9.0)
***********************

New Features
============

HASP keys connected to PCI parallel cards registered to the system will
be found on Windows NT4 and Windows 2000 systems,
because drivers search all LPT ports.

Installation switch HI_PORTDELAY is not used anymore, drivers include
automatic speed calibration instead.

NEC type parallel port is not supported anymore. Please use HDD V4.06
in case you are using a NEC type parallel port.


Problems Solved
================

Driver problems on SMP computers (e.g. dual Pentium) fixed.

Case 3701:  HASP4 Time keys returned incorrect values under some conditions.

Case 3676:  Listed available options for all switches in help window of hinstall.exe.

Case 3697:  InstallShield 5 sample now is correctly recompiled using the latest driver install DLL.


***********************
V4.06  March 25, 2000
***********************

new switches for parallel port configuration:

  - controlport         set control port registers
  - ecpdmaint           disable ECP-DMA-Interrupt

================
Problems Solved
================

HASP not found on Windows 2000.
Printing disturbed on Epson Stylus Pro 9000 after HASP key access

***********************
V4.02 (HASP CD Rel 8.0)
***********************

New Features
============

The new device driver fully supports the new HASP4 family of
HASP keys.

We further enhanced support for ECP printers. Please refer to the
descriptions in the HDD.HLP file for:

  - ecpretry
  - portallocfunctionality
  - portallocretrycount

For more about the HASP Device Driver custom API and HINSTALL,
refer to the HDD.HLP file.

================
Problems Solved
================

Case 3512:  Calling a HASP key while printing from an HP LaserJet 4050TN and
            several HP OfficeJet models caused the printer to be reset or
            output garbage. This is resolved in version 3.9x of the HASP Device Driver.


Trademarks
----------
Aladdin Knowledge Systems Ltd. (c) 1985 - 2005. All rights reserved.
