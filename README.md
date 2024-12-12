# Relay Module for XIAO

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/relay_module.jpg" /></div>

## Overview

The Relay Add On Module For XIAO is a smart module from Seeed Studio designed to control AC-powered appliances. It is characterized by the combination of XIAO, through the ESPHome access Home Assistant to control a variety of appliances, so that your home smarter!

### Key Features and Specifications

| Parameter               | Value           |
|-------------------------|----------------|
| Operating Voltage       | 5V             |
| Operating Current       | 1A           |
| Relay Life              | 100,000 Cycle   |
| Max Switching Voltage    | 250VAC       |
| Max Switching Current    | 10A             |
| Electrical endurance    | 1.5x10^4 OPS (10A 250VAC, Resistive load, at 85°C, 1s on 9s off)|

For more information, [click here to download PDF file](https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/relay_module.pdf).

## Getting Started

If you want to follow this tutorial through everything, you will need to prepare the following. Except for XIAO ESP32 C3, you can also use other ESP32 series products, like XIAO ESP32 C6 and XIAO ESP32 S3. The ultimate goal of this project is to control relay module in the Home Assistant.

<table align="center">
 <tr>
     <th>XIAO ESP32C3</th>
     <th>Relay Module</th>
 </tr>
    <tr>
     <td align="center"><div align="center"><img width ="130" src="https://files.seeedstudio.com/wiki/XIAO_WiFi/board-pic.png"/></div></td>
     <td align="center"><div align="center"><img width ="260" src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/13.jpg"/></div></td>
 </tr>
 <tr>
    <td align="center"><div class="get_one_now_container" style={{textAlign: 'center'}}>
        <a class="get_one_now_item" href="https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html">
        <strong><span><font color={'FFFFFF'} size={"4"}> Get One Now 🖱️</font></span></strong>
        </a>
    </div></td>
    <td align="center"><div class="get_one_now_container" style={{textAlign: 'center'}}>
        <a class="get_one_now_item" href="https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html">
        <strong><span><font color={'FFFFFF'} size={"4"}> Get One Now 🖱️</font></span></strong>
        </a>
    </div></td>
 </tr>
</table>

The content of this tutorial will broadly go through the following steps.

1. [Select your Home Assistant environment](#select-your-home-assistant-environment)
2. [Install and cofigure ESPHome in Home Assistant](#install-and-configure-esphome-in-home-assistant)
3. [Configure the XIAO ESP32C3 and ESPHome connection](#configure-the-xiao-esp32c3-and-esphome-connection)
4. [Add Relay Module to Home Assistant Dashboard](#add-relay-module-to-home-assistant-dashboard)

## Select your Home Assistant environment

In this routine, we will not expand on how to install the Home Assistant environment, we will assume that you already have a working Home Assistant device.

If you wish to learn how to install Home Assistant, then you can refer to the [official tutorial](https://www.home-assistant.io/installation/). We strongly recommend that you install Home Assistant using an x86 device as this is the most user friendly way for you to install Home Assistant with Supervised.

<div align="center"><img width={600} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/77.png" /></div>

According to the table above, it is most appropriate to install **Home Assistant OS** and **Home Assistant Supervised**, which will take a lot of hassle off your hands. If you are running Home Assistant on Docker with OpenWRT (e.g. using LinkStar H68K), please don't worry, we will also provide you with a detailed reference on how to do this.

We have also written how to install Home Assistant for some of Seeed Studio products, please refer to them.

- [Getting Started with Home Assistant on ODYSSEY-X86](https://wiki.seeedstudio.com/ODYSSEY-X86-Home-Assistant/)
- [Getting Started with Home Assistant on reTerminal](https://wiki.seeedstudio.com/reTerminal_Home_Assistant/)
- [Getting Started with Home Assistant on LinkStar H68K/reRouter CM4](https://wiki.seeedstudio.com/h68k-ha-esphome/)

## Install ESPHome in Home Assistant

### Step 1. Install ESPHome

- **Scenario 1: ESPHome installation under Home Assistant OS (with Add-on Store)**

If you have the Home Assistant OS installed, it has an Add-on Store, which makes it much easier to install ESPHome.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/79.png" /></div>


In the Add-on Store, you can search for and install ESPHome.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/80.png" /></div>

- **Scenario 2: ESPHome installed under Home Assistant under OpenWRT Docker/Docker (without Add-on Store)**

As we are installing the Home Assistant Container, we cannot simply download the ESPHome service via the Add-on Store, so a compromise is needed.

We need to download the ESPHome image.

```
esphome/esphome:latest
```

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/17.png" /></div>


On the page where the container is created, we need to make some simple settings.
- Container Name: your container name
- Docker Image: choose just downloaded **esphome** image
- Network: choose **host** mode
- Environment Variables(-e): your environment variable

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/18.png" /></div>


Once you have filled in the above, save and apply. You will see that the Container has been created. You also need to start it.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/19.png" /></div>


In order to achieve the same effect as downloading ESPHome in Home Assistant, we need to modify the configuration file under Home Assistant.

Go to the Home Assistant Container.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/55.png" /></div>


We go to the terminal in Home Assistant.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/56.png" /></div>


Enter the following command in the terminal.

```sh
vi configuration.yaml
```

Add following content to the end of `configuration.yaml`.

```
# Example configuration.yaml entry
panel_iframe:
  esphome:
    title: "ESPHome"
    url: "http://192.168.100.1:6052"
    icon: mdi:chip
```

Exit the docker container by type ```exit``` in the Home Assistant Container shell. Once this is done, we restart the Home Assistant  container.

Create a new browser page, enter address `http://homeassistant:8123/` and enter your Home Assistant account and you will see ESPHome appear in the toolbar on the left.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/57.png" /></div>

## Configure the XIAO ESP32C3 and ESPHome connection

### Step 2. Hardware connection

The goal of our tutorial is to control Relay Module in the Home Assistant dashboard. First we need to connect XIAO ESP32 C3 to the Relay Module like the following image.


:::tip
Antenna of XIAO is necessary, otherwise you cann't communicate to Home Assistant. Remember to install it.
:::

### Step 3. Keep the XIAO ESP32C3 and Home Assistant on the same LAN

I am sure that your Home Assistant has already done the work of getting into the network, for example by connecting to your device via a network cable. All you need to do then is simply to turn on a local network (e.g. WiFi) so that the XIAO ESP32C3 can also connect to this network.

I will use the LinkStar H68K as an example below. My aim is to get the XIAO connected to the LinkStar H68K's hotspot.

In the **Network** tab in OpenWRT, select **Wireless** --> **ADD**.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/58.png" /></div>


For **Transmit Power** in **Device Configuration**, select **auto**.

For the **Interface Configuration** settings, please fill in the following instructions.

- General Setup
    - Mode: Depends on how LinkStar accesses the internet. If you are using a cable connection then select **Client**, if you are connected to WiFi then select **Access Point**.
    - ESSID: Enter the name of your WiFi, please try not to have spaces or special characters.
    - Network: check **lan**.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/23.png" /></div>


- Wireless Security
    - Encryption: WPA2-PSK
    - Key: Enter the WiFi password you wish to set.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/24.png" /></div>



Once you have filled in the above information, click **Save and Apply** in the bottom right hand corner and wait a few moments for LinkStar to open a hotspot.

When no device is connected to this hotspot, it will be displayed as no signal.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/60.png" /></div>


All things considered, let's return to the Home Assistant page.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/61.png" /></div>


Click on the **NEW DEVICE**. Then click on **Continue**.

Under the new pop-up window, please enter the name of the application you wish to set up, as well as the name and password of the hotspot you have set up in LinkStar (Or your own WiFi). Make sure that the XIAO ESP32C3 and Home Assistant on the **same LAN**.

<div align="center"><img width={400} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/25.png" /></div>


Then click **Next**.

In the device type, please select **ESP32-C3**.

<div align="center"><img width={400} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/26.png" /></div>

Then click **Next**.

<span id="jump1">Click on the <strong>Encryption key</strong> and save it in a secure location, we will use this key in a later step.</span>

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/27.png" /></div>

Then click **SKIP**.

### Step 4. Change the XIAO ESP32C3 configuration yaml file

Then, we click on the device tab we just created, with the **EDIT** button in the bottom left corner.

<div align="center"><img width={400} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/28.png" /></div>


Please note that we need to make changes to this yaml file. Focus on the red box area where we need to change in the below image.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/1.png" /></div>

Please do not change the device name except the one you have configured, please refer to the code below for the rest of the content.

```css
esphome:
  name: xiao-esp32c3
  friendly_name: xiao_esp32c3

esp32:
  board: esp32-c3-devkitm-1
  framework:
    type: arduino

# Enable logging
logger:

# Enable Home Assistant API
api:
  encryption:
    key: "XehWbrfoYMdE4buwcVMDWQC9c/PB73eA+xlzSMeVSNw="

ota:
  - platform: esphome
    password: "2a6ebf121477090bfb2ef3ebc9f7e40f"

wifi:
  ssid: "Your ssid"
  password: "Your password"

  # Enable fallback hotspot (captive portal) in case wifi connection fails
  ap:
    ssid: "Xiao-Esp32C3 Fallback Hotspot"
    password: "9fpQ1nbukURw"

captive_portal:

# Define the relay switch
switch:
  - platform: gpio
    name: "Relay Control"
    pin: GPIO3 # XIAO use D1 pin to control the relay module, XIAO ESP32 C3 D1 pin corresponds to GPIO3. XIAO ESP32 C6 is GPIO1; XIAO ESP32 S3 is GPIO2.
```



Then, please click on the **Save** button in the top right corner.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/63.png" /></div>

### Step 5. Upload firmware to XIAO ESP32C3

- **Method 1: Compile and upload directly**

If you are using an x86 device and can see XIAO on the device port, then you can compile and upload the program to XIAO.

Connect XIAO to your device.

<div align="center"><img src="https://files.seeedstudio.com/wiki/ESPHome/49.png" style={{width:700, height:'auto'}}/></div>


Click on the three dots in the bottom right corner of the device bar and select **Install**.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/84.png" /></div>


Click **Plug into the computer running ESPHome Dashboard**.

<div align="center"><img width={500} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/85.png" /></div>


Select the connected port.

<div align="center"><img width={400} src="https://files.seeedstudio.com/wiki/ESPHome/18.png" /></div>

Now it will download all the necessary board packages and flash the ESPHome firmware into the XIAO ESP32C3. If the flashing is successful, you will see the following output.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/ESPHome/19.png" /></div>

If you are unable to find the port after connecting XIAO to your device, then you can try using the second method.

- **Method 2: Upload compiled firmware using the host**

Soft routes like LinkStar H68K do not support recognition of external MCU devices, we need to download the compiled firmware first and then upload the firmware via another PC.

Click on the **Install** button in the top right hand corner. Then select the last item **Manual download**.

<div align="center"><img width={500} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/30.png" /></div>


Select **Modern format**.

<div align="center"><img width={400} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/31.png" /></div>

It will then take a long time to download and compile, so please be patient. Once everything is ready, the firmware will be automatically downloaded to your computer.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/33.png" /></div>

To upload the firmware to XIAO ESP32C3 there are couple options here we show 2 ways of doing it:

- Option 1: using the [ESPhome Web tool](https://web.esphome.io/?dashboard_install) to upload.

Make sure you have the right drivers installed. Below are the drivers for common chips used in ESP devices.

1. CP2102 drivers: [Windows & Mac](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

2. CH342, CH343, CH9102 drivers: [Windowns](https://www.wch.cn/downloads/CH343SER_ZIP.html), [Mac](https://www.wch.cn/downloads/CH34XSER_MAC_ZIP.html)

3. CH340, CH341 drivers: [Windowns](https://www.wch.cn/downloads/CH341SER_ZIP.html), [Mac](https://www.wch.cn/downloads/CH341SER_MAC_ZIP.html)

Open the [ESPhome Web tool](https://web.esphome.io/?dashboard_install) with Chrome or Edge web browser.

Click **CONNECT**.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/34.png" /></div>

select the XIAO ESP32 serial port in the popup window.

<div align="center"><img width={400} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/64.png" /></div>

Click **INSTALL** and then select the `.bin` file downloaded from above steps.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/35.png" /></div>

<div align="center"><img width={400} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/38.png" /></div>


- Option 2: Using the [esphome-flasher tool](https://github.com/esphome/esphome-flasher).

If you are still unable to upload firmware using method one after installing the driver and changing browsers, then you can try using method two. Please refer to the official tutorial for specific installation methods and instructions.

:::tip
If you wish to observe the log messages of the XIAO ESP32C3, you can also view them through the View Logs button of this software.

<div align="center"><img width={500} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/41.png" /></div>
:::

Once the upload is complete, you can disconnect the XIAO ESP32C3 from the PC (unless you have a need to view the logs) and simply power the XIAO separately.

If all goes well, the XIAO ESP32C3 will search for and connect to the WiFi you have set up for it. 

Just like me, I use LinkStar H68K's network. You can find it in the network options and see the IP address assigned to it by LinkStar H68K.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/42.png" /></div>

Normally, at this point in Home Assistant, the status of the device will also change from offline to online.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/homs-xiaoc3-linkstar/65.png" /></div>

## Add Relay Module to Home Assistant Dashboard

### Step 6. Add relay to dashboard

Go to **setting**, and **Devices & services** 

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/5.png" /></div>

In the **Discovered** area, you will find XIAO, click **CONGFIUGE**

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/2.png" /></div>

**Paste the key** which from the yaml file you edit before.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/14.png" /></div>

<div align="center"><img width={500} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/3.png" /></div>

Select a area or leave it by default, click **FINISH**

<div align="center"><img width={500} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/4.png" /></div>

After that, click **Devices**, find **xiao_esp32c3**(you name it before) and click into it

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/6.png" /></div>

Here is ESPHome device page, you can add some automations and so on. Now we need to add it to dashboard, so click it.

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/7.png" /></div>

Click **NEXT** and click **ADD TO DASHBOARD**

<div align="center"><img width={500} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/8.png" /></div>

<div align="center"><img width={500} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/9.png" /></div>

Now, click **Overview** at left side

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/10.png" /></div>

You will see the Relay Control appear here

<div align="center"><img width={800} src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/11.png" /></div>

### Step 7. Use relay module to control a table lamp
We can click the switch to see if the relay work well. If you see the little green light on the board when you click the switch, it means work well! 

<div class="table-center">
<iframe width="800" height="450" src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/relay.mp4?autoplay=0" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>
</div>

<br></br>
I remodeled my little table lamp with this relay module. Cut the positive wire and plug it into each of the two ports of the relay module. You can see the affect in the below video. This relay module can't power XIAO, so please remember to use battery or USB cable to power XIAO.

:::warning
Please pay attention to the safety of electricity and do not touch the relays during power-on.
:::

<div class="table-center">
<iframe width="800" height="450" src="https://files.seeedstudio.com/wiki/XIAO/Gadgets/relay_module_for_xiao/light.mp4?autoplay=0" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>
</div>

<div style={{textAlign:'center'}}><img src="https://files.seeedstudio.com/wiki/XIAO_MG24/Pin/6.png" style={{width:1000, height:'auto'}}/></div>

Congratulations on successfully completing your journey on Relay Module For XIAO! Let's do more interesting remodels!
