**[简体中文](./Help.md) | English**<br>
# TrafficMonitor Frequently Asked Questions
This is the page about the Frequently Asked Questions of TrafficMonitor. If you want to view the detailed introduction of the functions and usage of TrafficMonitor, please [click here](https://github.com/zhongyang219/TrafficMonitor/wiki) to go the the TraffinMonitor Wiki page (Only Chinese Available).

### 1. How to show the CPU and memory usage?

Right click the main window and check "Show More Info". If you also need to display the CPU and memory usage in the taskbar window, right click the taskbar window and check "CPU and Memory Usage" in the "Display Settings<img src="./Screenshots/images/item.png" style="zoom: 80%;" />" sub menu.
### 2. How do I set the color of each item in the taskbar window individually?
Select "Options" In the right-click menu, switch to "Taskbar Window Settings" tab, check "Specify colors for each item", and then click the color block on the right side of "Text Color " to pop up the dialog box for taskbar window color settings. <br>
If you do not check "Specify colors for each item", you can only set the uniform color for the text.
### 3. "Auto run when Windows start" dose not work
The auto run function of the program is achieved by creating the "TrafficMonitor" key in the registry path of "Computer\HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run".
If you encounter the problem of auto run dose not work, please check that the registry exists, and then check the program path is correct. If you move the location of the program, the auto run will be invalid because of the program location being invalid. In this case, you only need to uncheck "Auto run when Windows start" in the option settings, and then check it on.<br>

Note that some third-party security software may prevent TrafficMonitor from booting up automatically. Please try to allow TrafficMonitor to boot up automatically in the security software.

If you set the program to run as an administrator, the auto run function will also not work. Please try to remove running as an administrator.<br>

### 4. The program pops up the "Unable to Save Settings" message box.
If you encountered this problem, that means the program does not have permission to write data to its directory, causing the settings data cannot be saved. Try to move the program to another folder that has write permissions will save this problem. <br>
You can also change the save path of the configuration and data file to the C:\Users\\<username\>\AppData\Roaming\TrafficMonitor directory by the following steps. <br>
* Exit TrafficMonitor and restart TrafficMonitor as an administrator.
* Select "Options" in the right-click menu, switch to the "General Settings" tab, and select "Save to Appdata Directory" in "Configuration and data files".

If it still pops up the "Unable to Save Settings" message box, open the directory where the application is located, open the `global_cfg.ini` file. If it doesn't exist, create a new one, adding the following:

```
[config]
portable_mode = true
```

If the file cannot be created, you can create the file in a different location, such as the desktop, and then move to the directory where the program is located.

If the `global_cfg.ini` file already exists, change the value of `portable_mode` to `true` and save, then restart TrafficMonitor.

If `global_cfg.ini` does not have write permission, you can try copying the file to the desktop, and then copying it back to the original path to overwrite the original file after modified.

After these steps, this problem should not theoretically occur. If this problem still occurs, try to delete the file C:\Users\\<username\>\AppData\Roaming\TrafficMonitor\config.ini. This file will be regenerated after it is deleted. 

In version 1.79 and later, if the directory where the program located is not writable, the configuration and data files will be automatically saved to the "C:\Users\\<username\>\AppData\Roaming\TrafficMonitor" directory. At this time, "Options" -“General Settings”-“Save to the program directory” in “Configuration and data files” will not be available.

### 5. The suspension window can only be displayed on the main monitor when multiple monitors are present.
By default, the suspension window cannot be moved out of the screen boundaries. If you need to move the suspension window to other monitors, please right click the suspension window, select "Other Functions", check "Allow Out of Screen Boundaries". At this time the suspension window is no longer limited to the screen, it can be also move to any monitors. <br>
If you remove the extra monitor, then the suspension window may appear outside the screen area to cause the invisible. At this time, you only need to right click the the icon in the notification area, select "Other function", uncheck "Allow Out of Screen Boundaries", the suspension window will appear in the screen area again.
### 6. The net speed value is not fully displayed.
Because the width of each character in different fonts is not the same, in some cases, it does appear the problem of the net speed value is not fully displayed. If this problem occurs, open "Options"-"Taskbar Window Settings", and select a larger value in the "Number of digits" drop down list.
### 7. How to cancel after setting the mouse penetrate?
Right click the TrafficMonitor icon in the notification area, uncheck the "Mouse Penetrate".<br>
After the mouse penetrate is set, the suspension window will not be able to respond to any mouse messages, or pop-up right-click menu. But the menu can be poped up by right click the icon in notification area. The right-click menu of the main window and which of the notification area icon is exactly the same.<br>
In addition, even if you have previously set the hidden notify icon, when the "mouse penetrate" is set, the notify icon will also automatically appear to prevent the right-click menu cannot be displayed. <br>
Note: The notification area icon will be automatically displayed in the following situations: <br>
* After the "Mouse Penetrate" is set;
* Hide the main window without displaying the taskbar window;
* Close the taskbar window when the main window is hidden;
* Close the taskbar window when the "Mouse Penetrate" is set.
### 8. Problems with the taskbar window color in Windows 10 white taskbar theme
When using the white taskbar theme, you can click the "Preset" button in the "Taskbar Window Settings" and select "Light Mode" to set the taskbar color in light mode. As the picture shows:

<img src="./Screenshots/images/image2.jpg" style="zoom:80%;" />

At the same time, you may also check "Auto adapt to Windows 10 dark/light theme", the program will automatically switch the color preset when Windows 10 dark/light theme is changed. You can click the "Auto Adapt settings" button to configure which color preset to use for dark and light themes.

### 9. The taskbar windows cannot be displayed when the HDR is turned on in Windows 10

Some users have reported that turning on the HDR function in Windows 10 will cause the taskbar window to fail to display. Since I don't have a monitor that supports HDR, I can't investigate this problem, nor can I give a solution. If you encounter this problem, it is recommended to turn off the HDR function.

<br><br>

>If you have encountered any other problems, please click "Contact Author" in the "About" dialog box, or directly [click here](mailto:zhongyang219@hotmail.com) to send me an email.<br>
Please describe the problems you have encountered in detail, the error prompts, what operations you have tried, it is better to attach the screenshots and configuration files ("Options"-"General Settings"-"Open configuration file path"). <br>
Note: Please confirm the email address that you used before sending the email. If your email address is form like "Outlook_\<random string\>@outlook.com", then such email address is unable to reply.
This may be due to the fact that you are using a third-party e-mail address as the Microsoft account to log on to Windows. If this is the case, be sure to enclose the correct email address in the message.
